#ifndef __ACMD_H__
#define __ACMD_H__

#include "NetMsg.h"

class CPC;

#define CMD_NUM 200

typedef void (* LCCMDPROC)(CPC*, CNetMsg&);

class CCmd
{
public:
	CCmd();
	~CCmd();

	int				m_cmdType;
	int				m_minLevel;
	bool			m_bCanDoWhileWarp;		// ������ ����� �� �ִ� �޽����ΰ�?
	bool			m_bCanDoWhileDisable;	// disable ���¿����� ����� �� �ִ� �޽��� �ΰ�?
	LCCMDPROC		m_cmdFunc;
};

class CCmdList
{
public:
	CCmdList();
	~CCmdList();

	CCmd* m_cmd[CMD_NUM];
	int m_cnt;

	void AddMessage();
	void AddExMessage();

	bool Add(int cmdType, LCCMDPROC cmdFunc, int minlevel, bool bCanDoWhileWarp, bool bCanDoWhileDisable);
	void Sort(void);
	int Find(CPC* ch, int cmdType);
	void Run(int cmd_num, CPC* ch, CNetMsg& msg);
};

#endif
