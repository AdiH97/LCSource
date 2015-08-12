#ifndef __ASERVER_H__
#define __ASERVER_H__

#include "ConfigFile.h"
#include "Descriptor.h"
#include "NetMsg.h"
#include "UserList.h"
#include "PrepayInfo.h"
#include "Log.h"

typedef struct _TimeStruct
{
	int		year;		// ���� �� ���ڸ� % 62
	int		month;		// ��
	int		day;		// ��
	int		hour;		// ��
	int		min;		// ��
	int		sec;		// ��
} TIMESTRUCT;

class CSectionInfo
{
	friend class CSectionList;
	friend void SendSectionList(CDescriptor* desc, int subno, int userindex);

	char			m_billguid[LEN_BILL_GUID];
	int				m_billsection;
	int				m_billhour;
	int				m_billvalue;
	char			m_billviewname[LEN_BILL_VIEWNAME];
	int				m_billevent;

	CSectionInfo*	m_prev;
	CSectionInfo*	m_next;

public:
	CSectionInfo()		{ memset(this, 0, sizeof(*this)); }
	~CSectionInfo()		{ memset(this, 0, sizeof(*this)); }

	void billguid(const char* billguid)			{ strcpy(m_billguid, billguid); }
	void billsection(int billsection)			{ m_billsection = billsection; }
	void billhour(int billhour)					{ m_billhour = billhour; }
	void billvalue(int billvalue)				{ m_billvalue = billvalue; }
	void billviewname(const char* billviewname)	{ strcpy(m_billviewname, billviewname); }
	void billevent(int billevent)				{ m_billevent = billevent; }

	const char* billguid()						{ return (const char*)m_billguid; }
	int billsection()							{ return m_billsection; }
	int billhour()								{ return m_billhour; }
	int billvalue()								{ return m_billvalue; }
	const char* billviewname()					{ return (const char*)m_billviewname; }
	int billevent()								{ return m_billevent; }
};

class CSectionList
{
	friend void SendSectionList(CDescriptor* desc, int subno, int userindex);

	CSectionInfo*		m_head;
	CSectionInfo*		m_tail;

public:
	CSectionList()		{ memset(this, 0, sizeof(*this)); }
	~CSectionList()		{ Reset(); }

	void Reset()
	{
		while (m_head)
		{
			CSectionInfo* p = m_head;
			m_head = m_head->m_next;
			delete p;
		}
		memset(this, 0, sizeof(*this));
	}

	void Add(const char* billguid, int billsection, int billhour, int billvalue, const char* billviewname, int billevent)
	{
		CSectionInfo* p = new CSectionInfo;
		p->billguid(billguid);
		p->billsection(billsection);
		p->billhour(billhour);
		p->billvalue(billvalue);
		p->billviewname(billviewname);
		p->billevent(billevent);

		if (m_head == NULL)
		{
			m_head = m_tail = p;
		}
		else
		{
			m_tail->m_next = p;
			p->m_prev = m_tail;
			m_tail = p;
		}
	}
};

class CServer
{
public:
	CServer();
	~CServer();

	////////////
	// ���� ����
	socket_t	m_ssock;			// ���� ����
	CDescriptor* m_desclist;		// ����� ���� ����Ʈ
	int			m_nDesc;			// ����Ʈ�� ���� ����
	fd_set		m_input_set;		// ��ũ���� ��
	fd_set		m_output_set;
	fd_set		m_exc_set;
	fd_set		m_null_set;

	////////////
	// ���� ����
	char*		m_serverpath;		// ��� ���
	CConfigFile	m_config;			// ���� ����

	int				m_locale;

	int			m_maxplayers;		// ��� ���� �ִ� �÷��̾� ��
	bool		m_bshutdown;		// ���� ����
	bool		m_nameserverisslow; // �� ���� ���ϱ�?
	bool		m_breboot;			// ����Ʈ
	TIMESTRUCT	m_serverTime;		// ���� �ð�

	CSectionList m_sectionlist;		// ����� ����Ʈ
	int			m_pulseSectionList;	// ����Ʈ ���� �ð�

	MYSQL		m_catalDB;			// īŻ�α� ���
	int			m_countCatalTable;	// īŻ�α� ���̺� ����

	//////////
	// ƽ ����
	int			m_pulse;			// ƽ ī����
	int			m_pulseServerTime;	// ���� �ð�

	////////////////
	// �ڵ����� ����
	int			m_pulseWarn;		// ��� ������ �ð�
	int			m_pulseRefresh;		// �ð� �����ϴ� �ð�


	/////////////////
	// ���� ȯ�� ����
	char* GetServerPath();			// ��� ���
	bool LoadSettingFile();			// ���� ���� �б�
	bool InitGame();				// ���� �ʱ�ȭ
	int GetMaxPlayers();			// ��� ���� �ִ� �÷��̾� �� ���ϱ�
	void SetServerTime();			// ���� �ð� ���� -> serverTime
	bool ConnectDB();


	/////////////////
	// ���� ���� ����
	socket_t InitSocket();								// ���� ���� �ʱ�ȭ
	static int SetSendbuf(socket_t s);					// �۽� ���� ũ�� ����
	struct in_addr* GetBindAddr();						// ���ε� �� �ּ� ����
	static void Nonblock(socket_t s);					// ��� ����


	/////////////////
	// ���� ���� ����
	void Run();				// ���� ����
	void Close();			// ���� ����
	static void ServerSleep(struct timeval* timeout);	// ���� ��� ����
	void HeartBeat();


	///////////////////////
	// Ŭ���̾�Ʈ ���� ����
	int NewDescriptor(int s);					// ���ο� Ŭ���̾�Ʈ ����
	void CloseSocket(CDescriptor* d);			// ��ũ���� ����
	void SendOutput(CDescriptor* d);			// ������ ������
	bool DisConnectLogedIn(CDescriptor* my_d);	// ���� ������ ó��

	/////////////////
	// ��� ó�� ����
	void CommandInterpreter(CDescriptor* d, CNetMsg& msg); // �� ó��


	////////////////
	// ���� ���� ����
//#if !defined ( LC_TLD  ) //|| !defined ( LC_USA )
#if !defined ( LC_USA  ) && !defined ( LC_TLD )
	void ReadSectionList();
#endif // #ifndef LC_TLD
};

//#if !defined ( LC_TLD  ) //|| !defined ( LC_USA )
#if !defined ( LC_USA  ) && !defined ( LC_TLD )
////////////////////
// Function name	: FindUser
// Description	    : desc���� userindex�� ���� ã��, ������ �߰�
CUser* FindUser(CDescriptor* desc, int subno, int userindex);
#endif

void PingDB();

extern CServer gserver;

#endif
