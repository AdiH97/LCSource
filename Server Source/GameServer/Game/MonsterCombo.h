// MonsterCombo.h: interface for the CMonsterCombo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MONSTERCOMBO_H__A0046A35_9FFA_4984_98CE_7C324A4237A6__INCLUDED_)
#define AFX_MONSTERCOMBO_H__A0046A35_9FFA_4984_98CE_7C324A4237A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define MAXCOMBOCASE		20
#define MAXEFFECT			5

class CArea;
class CNPC;

struct MOBTYPE
{
	int		npcidx;		// �⿬�ϴ� npc �ε���
	char	count;		// �⿬�ϴ� npc ī��Ʈ
};

struct MOBREGEN
{
	char		step;		// ���° �����ΰ�?
	char		typecount;	// �����Ǵ� ��Ÿ���� ����
	MOBTYPE*	mobtype;	// �����Ǵ� ��Ÿ��

	MOBREGEN()
	{
		step = 0;
		typecount = 0;
		mobtype = NULL;
	};

	~MOBREGEN()
	{
		step = 0;
		if(mobtype)
		{
			delete[] mobtype;
			mobtype = NULL;
		}
	}
};

struct PENALTY
{
	int index;
	int level;
};

struct EFFECTPOS
{
	CNPC*	npc;
	float	x;
	float	z;
	float	h;
};

class CMissionCaseProto
{
public:
	int		m_nIndex;
	int		m_nNas;
	int		m_nPoint;
	CLCString m_name;

	// ����
	int				m_nRegenCount;		// ���� �ܰ�
	MOBREGEN*		m_npcRegen;		// ���� ����

	// �г�Ƽ
	CLCList<PENALTY>	m_listPanalty;		// �г�Ƽ ������ ��ų�ε���

	bool			LoadProto();

	const MOBREGEN*		FindMobRegen(int step);

	CMissionCaseProto();
	~CMissionCaseProto();
	// ����ǰ
};

class CMIssionCaseList
{
public:
	CMIssionCaseList();
	~CMIssionCaseList();

	int					m_nCount;
	CMissionCaseProto*	m_proto;

	CMissionCaseProto*	FindProto(int index);
	bool				LoadList();

	static int CompIndex(const void* p1, const void* p2)
	{
		CMissionCaseProto* m1 = (CMissionCaseProto*)p1;
		CMissionCaseProto* m2 = (CMissionCaseProto*)p2;

		return (m1->m_nIndex - m2->m_nIndex);
	}
};

struct MISSION
{
	char			step;
	CMissionCaseProto*	proto;
	MISSION()
	{
		step = 0;
		proto = NULL;
	};
};


class CMonsterCombo  
{
public:
	CMonsterCombo();
	virtual ~CMonsterCombo();

	int		m_nIndex;
	int		m_bIsBattle;		// �ο򿩺�
	int		m_nExtra;			// �������� ���
	int		m_nStage;			// �������� ��������
	int		m_nRegenStep;		// �������� regen
	char	m_cPlayerCount;		// ����� �����Ϸ���

	int		m_pulseFirst;		// 1��° ����Ʈ
	int		m_pulseSecond;		// 2��° ����Ʈ
	
    int	    m_nTotalMission;
	char	m_cPlayerNum;		// stage�� �ִ� ��Ƽ����

	static int m_virtualIndex;

	// ����Ʈ ��ġ ����
	CLCList<EFFECTPOS> m_listEffect;

	MISSION*	m_case;
	CArea*		m_area;
	CNPC*		m_effectNPC[MAXEFFECT];

	void		SetArea(CArea*	area);
	char		Run();
	void		DeleteAllMob();

	// 0: �����������  1: ������������		2: ����
	char		NextNPCRegen();

	// �̼Ǽ���
	bool		SetMission(int step, int index);

	// step: ����������ȣ
	const MISSION*	FindMission(int step);

	// ���������� ������ȯ
	void RecallToStage();

	// �������� ����
	bool StartStage();
	
	// �г�Ƽ �ʱ�ȭ
	void ClearPenalty();

	// ���Ƽ ����
	void ApplyPenalty(int skillindex, int skilllevel);

	//  �������� NPC ����
	void GiftMobRegen();

	//  �̼����̽� �� ����Ʈ ���
	int GetTotalPoint();

	// 
	int GetMaxCoinCount(int count)
	{
		int temp;
		temp = (int)(0.5f * count);

		float temp2 = (float)(0.5f * count);
		float temp3;
		temp3 = temp2 - (float)temp;

		if(temp3 >= 0.5) 
		{
			temp += 1;
		}

		temp += m_nStage/15;

		if(temp < 1)
			temp = 1;

		return temp;
	}

	// �ұ�� �غ� ����Ʈ
	void FireEffectReady();
	void FireEffectReady2();

	// �ұ�� ���� ����Ʈ
	void FireEffectAct();

	// ����� ���
	int GetTotalNas();

	// ������ npc ����
	void ComboNPCRegen(/*char bContinue*/);

	// ���� �̼����̽� ���� ����
	void SetNextVar();

	// ���� �ʱ�ȭ
	void InitStageVar();

	// �ʱ�ȭ
	bool Init(int count);
	// �޺� �ε��� ����
	void SetVirtualIndex();

	// �������� �˸�
	void NoticeStage();

	// �޺����� �ִ� �÷��̾� �α� ���
	void PrintCharIndex();

	void InitAllVar();

	bool SetMonsterCombo(CPC* pc);
};


#endif // !defined(AFX_MONSTERCOMBO_H__A0046A35_9FFA_4984_98CE_7C324A4237A6__INCLUDED_)
