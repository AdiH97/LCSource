#ifndef __ADESCRIPTOR_H__
#define __ADESCRIPTOR_H__

#include "InputBuffer.h"
#include "InputQueue.h"
#include "OutputBuffer.h"
#include "UserList.h"

class CDescriptor  
{
public:
	CDescriptor();
	~CDescriptor();

	int			m_serverNo;					// ������ ���� ��ȣ
	int			m_gameId;					// ������ ������ ���� ���̵� 

	////////////
	// ���� ����
	socket_t	m_desc;						// file descriptor for socket
	char		m_host[HOST_LENGTH + 1];	// client ip
	CInputBuffer m_inBuf;					// Input Buffer
	CInputQueue m_inQ;						// Input Packet Queue
	COutputBuffer m_outBuf;					// Output Network Message Queue

	//////////
	// ƽ ����
	int			m_timestamp;				// player: total playing time,  mob: last attacked pulse

	////////////
	// ���� ����
	int			m_connected;				// CON_ ��� ���� ���� : ���� ����
	int			m_connectreq;				// ���� ��û ƽ ī��Ʈ
	int			m_logined;					// �α��� ���
	int			m_descnum;					// unique num assigned to desc
	bool		m_bclosed;

//#if !defined ( LC_TLD  ) //|| !defined ( LC_USA )
#if !defined ( LC_USA  ) && !defined ( LC_TLD )
	CUserList	m_userlist;
#endif
	
	////////////
	// ��ũ ����
	CDescriptor* m_pPrev;					// ����Ʈ ��ũ
	CDescriptor* m_pNext;


	void CloseSocket();						// ���� �ݱ�
	void FlushQueues();						// ť ����

	void WriteToOutput(CNetMsg& msg);		// ����
	int ProcessOutput();					// ���� ����
	static int WriteToDescriptor(socket_t desc, const char* buf, int length);

	int ProcessInput();						// �б� ����
	static ssize_t PerformSocketRead(socket_t desc, char* read_point, size_t space_left);

	bool GetLogin(CNetMsg& msg);			// ���� ��û ó��
};

#endif
