#ifndef __ADBTHREAD_H__
#define __ADBTHREAD_H__

#include "Descriptor.h"
#include "Mutex.h"
#include "Server.h"

#define MAX_DB_Q  100000

class CCharDBQ
{
public:
	CCharDBQ();
	~CCharDBQ();

	CDescriptor*	m_desc[MAX_DB_Q];	// ��û ť
	CMutexObject	m_mutexobj;			// ���� ��ü

	int				m_head;				// ó��
	int				m_tail;				// ��
	bool			m_dbend;				// ���� ����
	bool			m_dbreqend;			// ���� ��û

	CDescriptor* GetFromQ();			// ť���� ���
	bool AddToQ(CDescriptor* d);		// ť�� �ֱ�
	void EraseQ(CDescriptor* d);		// ť �����

	bool IsFull()	{ return (m_head == (m_tail + 1) % MAX_DB_Q); }	// ���� á���� �˻�
	bool IsEmpty()	{ return (m_head == m_tail); }					// ������� �˻�
};

class CDBThread
{
public:
	CDBThread();
	~CDBThread();

	CCharDBQ		m_queue;			// ť
	char			m_t_buf[8192];	// for temp query
	char			m_buf[8192];	// for main query
	char			m_te_buf[1024];	// for temp string

	bool CreateThread();

#ifdef CIRCLE_WINDOWS
	static void RunThread(void* p);
#else
	static void* RunThread(void* p);
#endif

	void Run();

	void Wait300Millis()
	{
#ifdef CIRCLE_WINDOWS
		Sleep(300);
#else
		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 300000;
		select(0, (fd_set *) 0, (fd_set *) 0, (fd_set *) 0, &timeout);
#endif
	}

	void PingDB();
	bool UpdateChar(CDescriptor* d);		// ĳ���� ���� ����

	bool OnUserDB(CDescriptor* d);			// ĳ���� ������ ��� ��� : for menu
	bool OnNewCharDB(CDescriptor* d);		// ĳ���� ����
	bool OnDelCharDB(CDescriptor* d);		// ĳ���� ����
#ifdef ENABLE_CHARACTER_DELETE_DELAY
	bool OnDelCancelCharDB(CDescriptor* d);	// ĳ���� ���� ���
#endif // ENABLE_CHARACTER_DELETE_DELAY
	bool OnPlayCharDB(CDescriptor* d);		// �÷����� ĳ���� ���
	bool OnDisconnect(CDescriptor* d);		// ������ DB �ൿ

// ���θ�� ����Ʈ ������ ������ ���� �Լ�
	// �ɸ���, ��Ʈ�ʾ��̵�(4G : 0, NM : 1), ����(300���߿� 1��)
	void PromotionGive(CPC* pChar, int partner_id, bool lucky);

	////////////////
	// util function
	//static void BackSlash(char* des, const char* src);
	static void GetDateStr(char* buf);
	
	// �����ȵ� ���� ��ų ����
	void CheckSSkill( int & index, int &level, int & totoal_recover_sp);
};

#endif
