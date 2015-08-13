/************************************
  �������� 
  ������ ���: bs
  ������: 2004-11-18 ���� 10:57:23
  ����: ��ų�� ȿ�� ���뿡�� �̸� ���� Ȯ�� �� ���
 ************************************/

/************************************
  �������� 
  ������ ���: bs
  ������: 2004-11-17 ���� 3:22:34
  ����: CAssistList�� Apply �߰� - �� ���� �Լ�
 ************************************/

#ifndef __ASSIST_H__
#define __ASSIST_H__

#include "Config.h"
#include "Character.h"
class CNetMsg;


typedef struct _tagAssistValue {
       int attack;
       int defense;
       int magic;
       int resist;
       int hitrate;
       int avoid;
       int critical;
       int attackspeed;
       int magicspeed;
       int movespeed;
       int recoverhp;
       int recovermp;
       int maxhp;
       int maxmp;
       int deadly;
       int attfire;
       int attwater;
       int attearth;
       int attwind;
       int attdark;
       int attlight;
       int magichitrate;
       int magicavoid;
       int attackdist;
       int reduceMelee;
       int reduceRange;
       int reduceMagic;
       int reduceMeleeProb;
       int reduceRangeProb;
       int reduceMagicProb;
       int attack_dam_melee;
       int attack_dam_range;
       int hitrate_skill;
       bool immune_blind;
       int attack80;
       int maxhp450;
       int hard;
       int skillspd;
       int statpall;
       int statpall_per;
       int stronger_skill;
       int despair;
       int manascreen;
       int bless;
       int inverse_damage;
       int exp;
       int sp;
       int exp_rate;
       int sp_rate;
       int npcAttack;
       int npcMagic;
       int SkillCooltime;
       bool hcExpPlus;
       bool hcSPPlus;
       int hcReflex;
       int hcReflexProb;
       int hcDeathExpPlus;
       bool hcDeathSPPlus;
       MSG_CHAR_TYPE hcFearType;
       int hcFearIndex;
       bool hcAttackTower;
       bool hcExpPlus_836;
       bool hcSPPlus_837;
       bool hcDropPlus_838;
       bool hcSepDrop;
       bool hcSepExp;
       bool hcSepSP;
       bool hcSepNas;
       bool hcSepDrop_Cash;
       bool hcSepExp_Cash;
       bool hcSepSP_Cash;
       bool hcScrollDrop;
       bool hcScrollSP;
       bool hcScrollExp;
       bool hcExpPlus_S354;
       bool hcScrollDrop_5081;
       int hcDropPlus_Xmas2007;
       bool hcDropPlus_2141;
       int hcCashExpUp;
       int hcCashMaxHPUp;
       int hcCashMaxMPUp;
       bool hcExpPlus_S355;
       bool hcSPPlus_S356;
       bool hcDropPlus_S360;
       int hcExpPlusPer100;
       int hcSPPlusPer100;
       int hcDropPlusPer100;
       int hcExpPlus_398;
       int hcExpPlus_1975;
       int hcExpPlus_1976;
       int HitRate_2033;
       int Avoid_2034;
       bool hcCashPetExpUp_2358;
       bool hcCashPetExpUp_2359;
       bool bRorainOfLoveMagic;
       bool hcMPSteelPotion;
       bool hcHPSteelPotion;
       bool hcExpSPPlus_2354;
       int hcExpPlus_2388;
       int hcExpPlus_2389;
       int hcSPPlus_2390;
       bool hcDropPlus_2391;
       int hcEventHalloweenMaxHP;
       int hcEventHalloweenSpeed;
       int charge_attack;
       int charge_magic;
       bool hcAttackBerserker;
       int hcExplimitPlus;
       bool hcPlatinumDrop;
       bool hcPlatinumScroll;
       int hcLimitSP;
       int hcLimitEXP;
       int hcRandomExpUp;
       int hcRandomSpUp;
       int hcRandomDropUp;
       bool hcPetExpBoost;
       bool hcIrisFervor;
       int pkDispositionPointValue;
   } ASSISTVALUE;


/////////////////////
// Class name	    : CAssistData
// Description	    : ����ȿ��������
class CAssistData
{
public:
	int						m_index;		// �������� ��� ������ �ε���, �׿ܴ� -1
	const CSkillProto*		m_proto;		// ��ų
	int						m_level;		// ����
	int						m_remain;		// �����ð�
	bool					m_bHit[MAX_SKILL_MAGIC];	// ��ų�� ȿ�� ���� ����

	MSG_CHAR_TYPE			m_spellerType;	// ��ų ���� ĳ���� Ÿ��
	int						m_spellerIndex;	// ��ų ���� ĳ���� �ε���

	CAssistData*			m_prev;			// ��ũ
	CAssistData*			m_next;			// ��ũ

	CAssistData(MSG_CHAR_TYPE spellertype, int spellerindex, int itemidx, const CSkillProto* proto, int level, int remain, bool bHit[MAX_SKILL_MAGIC]);
};


/////////////////////
// Class name	    : CAssistList
// Description	    : ����ȿ������Ʈ
class CAssistList
{
	friend class CAssist;

public:
	CAssistList();
	~CAssistList();

private:
	CAssistData*			m_head;			// ���
	CAssistData*			m_tail;			// ����
	int						m_max;			// �ִ� ��
	int						m_count;		// ����
	int						m_abscount;		// ����ð� ���� ���� 


	/////////////////////
	// Function name	: max
	// Description	    : �ִ� �� ����
	void Max(int n);


	/////////////////////
	// Function name	: Add
	// Description	    : ����Ʈ�� �߰�
	// Argument         : CCharacter* spellchar
	//                  : ������ ĳ����
	// Argument         : int itemidx
	//                  : �������� ��� �ε���, �׿ܴ� -1
	// Argument         : const CSkillProto* proto
	//                  : �߰��� ��ų
	// Argument         : int level
	//                  : �߰��� ��ų�� ����
	// Argument         : bool bHit[MAX_SKILL_MAGIC]
	//                  : ȿ�� ���� ����
	// Argument         : int& remain
	//                  : ���� �ð�, -1�� ��ų ��ü �ð� ���
	bool Add(CCharacter* spellchar, int itemidx, const CSkillProto* proto, int level, bool bHit[MAX_SKILL_MAGIC], int& remain, int param, int nBlessAdd, int nBlessRate);


	/////////////////////
	// Function name	: CanApply
	// Description	    : ��ų ���� ���ɼ� �˻�
	// Argument         : const CSkillProto* proto
	//                  : ��ų
	// Argument         : int level
	//                  : ����
	bool CanApply(const CSkillProto* proto, int level);


	/////////////////////
	// Function name	: DelDuplicate
	// Description	    : �ߺ��Ǵ� ȿ�� ����
	// Argument         : const CSkillProto* proto
	//                  : �ߺ� �˻� ��� ��ų
	// Argument         : int level
	//                  : ����
	// Argument         : bool bSend
	//                  : ���� ������ �޽����� ���������� ����
	// Argument         : bool bNoCancelType
	// 060317 : bs      : SF_NOCANCEL �˻� ����
	void DelDuplicate(const CSkillProto* proto, int level, bool bSend, CCharacter* ch, bool bNoCancelType);


	/////////////////////
	// Function name	: DecreaseTime
	// Description	    : �ð� ����
	// Return type		: bool 
	//            		: �����Ǵ� ��ų�� �ִ��� ����
	bool DecreaseTime(CCharacter* ch, int* changestate);


	////////////////////
	// Function name	: Apply
	// Description	    : ȿ�� ����
	// Argument         : ASSISTVALUE* addition
	//                  : �������� ����Ǵ� ��ġ
	// Argument         : ASSISTVALUE* rate
	//                  : ������ ����Ǵ� ��ġ
	// Argument         : int* state
	//                  : ���� ��ȭ
	void Apply(CCharacter* ch, ASSISTVALUE* addition, ASSISTVALUE* rate, int* state);


	/////////////////////
	// Function name	: DelAssist
	// Description	    : ����ȿ�� ����
	// Argument         : CAssistData* d
	//                  : 
	// Argument         : bool bNoCancelType
	// 060317 : bs      : SF_NOCANCEL �˻� ����
	void DelAssist(CAssistData* d, bool bSend, CCharacter* ch, bool bNoCancelType);


	////////////////////
	// Function name	: CheckApplyConditions
	// Description	    : ���� ���� �ٽ� �˻�
	void CheckApplyConditions(CCharacter* ch);
};


/////////////////////
// Class name	    : CAssist
// Description	    : ����ȿ��
class CAssist
{
public:
	CCharacter*				m_ch;			// ȿ�������ϴ� ĳ����
	CAssistList				m_help;			// �̷ο� ��
	CAssistList				m_curse;		// �طο� ��
	int						m_delaycheck;	// �˻� ������
	ASSISTVALUE				m_avAddition;	// �����Ǵ� ȿ�� ��ġ
	ASSISTVALUE				m_avRate;		// ������ ����Ǵ� ȿ�� ��ġ
	LONGLONG				m_state;		// ���� ��ȭ(���� ���)


	CAssist();


	/////////////////////
	// Function name	: Init
	// Description	    : �ʱ�ȭ
	void Init(CCharacter* ch);

	int GetAssistCount()	{ return m_help.m_count + m_curse.m_count + m_help.m_abscount; }

	int GetAssistHelpMax()		{ return m_help.m_max; }
	int GetAssistHelpCount()	{ return m_help.m_count; }


	/////////////////////
	// Function name	: Add
	// Description	    : ��ų ȿ�� �߰�
	// Argument         : CCharacter* spellchar
	//                  : ������ ĳ����
	// Argument         : int itemidx
	//                  : �������� ��� �ε���, �׿ܴ� -1
	// Argument         : const CSkillProto* proto
	//                  : ��ų
	// Argument         : int level
	//                  : ����
	// Argument         : bool bHit[MAX_SKILL_MAGIC]
	//                  : ȿ�� ���� ����
	// Argument         : bool bSend
	//                  : ���� ������ �޽����� ���������� ����
	// Argument         : int remain
	//                  : ���� �ð�, -1�� ��ų ��ü �ð� ���
	bool Add(CCharacter* spellchar, int itemidx, const CSkillProto* proto, int level, bool bHit[MAX_SKILL_MAGIC], bool bSend, int remain, int param, int nBlessAdd, int nBlessRate);


	/////////////////////
	// Function name	: DecreaseTime
	// Description	    : �ð� ����
	bool DecreaseTime();


	/////////////////////
	// Function name	: Apply
	// Description	    : ȿ�� ����
	void Apply();


	////////////////////
	// Function name	: ClearAssist
	// Description	    : ȿ�� ����
	// Argument         : bool bNoCancelType
	// 060317 : bs      : SF_NOCANCEL �˻� ����
	void ClearAssist(bool bSend, bool bByStone, bool bHelp, bool bCurse, bool bNoCancelType);


	////////////////////
	// Function name	: Find
	// Description	    : Ư�� ȿ���� ����Ǿ� �ִ��� �˻�
	bool Find(int magicindex, int magiclevel);

	void GetListString(bool bHelp, char* item, char* index, char* level, char* remain, char* hit0, char* hit1, char* hit2);

	CNetMsg& AppendAssistToNetMsg(CNetMsg& msg);



	// 060227 : bs : ����ð� ��� ����Ʈ
	////////////////////
	// Function name	: GetABSTimeTypeList
	// Description	    : ���� �ð� Ÿ���� ���� ����Ʈ�� �����´�
	// Return type		: int 
	//                  : �� ����
	// Argument         : int* nAssistABSItemIndex
	//                  : ������ �ε��� ����, NULL�̸� �����ʹ� ���� ������ ���Ѵ�
	// Argument         : int* nAssistABSSkillIndex = NULL
	//                  : ��ų �ε��� ����
	// Argument         : int* nAssistABSSkillLevel = NULL
	//                  : ��ų ���� ����
	// Argument         : char* nAssistABSHit0 = NULL
	//                  : ���� 0 ����
	// Argument         : char* nAssistABSHit1 = NULL
	//                  : ���� 1 ����
	// Argument         : char* nAssistABSHit2 = NULL
	//                  : ���� 2 ����
	// Argument         : int* nAssistABSEndTime = NULL
	//                  : ����ð� ����
	int GetABSTimeTypeList(int* nAssistABSItemIndex, int* nAssistABSSkillIndex = NULL, int* nAssistABSSkillLevel = NULL, char* nAssistABSHit0 = NULL, char* nAssistABSHit1 = NULL, char* nAssistABSHit2 = NULL, int* nAssistABSEndTime = NULL);


	////////////////////
	// Function name	: CancelSleep
	// Description	    : �������� ���
	void CancelSleep();


	////////////////////
	// Function name	: CureAssist
	// Description	    : level������ type�� �ش��ϴ� ��ų ���
	void CureAssist(int type, int level);
	void CureAssist(int flag);

	////////////////////
	// Function name	: CancelInvisible
	// Description	    : �κ���� Ǯ��
	void CancelInvisible();


	////////////////////
	// Function name	: CheckApplyConditions
	// Description	    : ���� ���� �ٽ� �˻�
	void CheckApplyConditions();

	/////////////////////
	// Function name	: CanApply
	// Description	    : ��ų ���� ���ɼ� �˻�
	// Argument         : const CSkillProto* proto
	//                  : ��ų
	// Argument         : int level
	//                  : ����
	bool CanApply(const CSkillProto* proto, int level);


	////////////////////
	// Function name	: FindByType
	// Description	    : Ư�� Ÿ���� ȿ���� ã��
	// Return type		: int 
	//                  : ã�� ȿ���� ����, ��ã���� 0
	// Argument         : int type
	//                  : ȿ�� Ÿ��
	// Argument         : int subtype
	//                  : ȿ�� ���� Ÿ��
	// Argument         : bool* outHelp = NULL
	//                  : help ����Ʈ���� ã������ true, �ƴϸ� false
	// Argument         : CAssistData** outData = NULL
	//                  : ã�� ȿ���� �ش��ϴ� CAssistdata*�� ����
	int FindByType(int type, int subtype, bool* outHelp = NULL, CAssistData** outData = NULL);


	////////////////////
	// Function name	: CancelFear
	// Description	    : MST_ASSIST_FEAR ����
	void CancelFear();


	////////////////////
	// Function name	: CancelFakeDeath
	// Description	    : MST_ASSIST_FAKEDEATH ����
	void CancelFakeDeath();


	// Ư�� ������ �ε����� ���� ������ ���
	void CureByItemIndex(int itemindex);

	// Ư�� ������ �ε����� ���� ������ �ִ��� ã��
	bool FindByItemIndex(int itemindex, CAssistData** outData = NULL);

	// Ư�� ��ų�ε����� ���� ã��, ��ų�� ������ 0, ������ ��ų���� ��ȯ
	int FindBySkillIndex(int skillindex);

	// Ư�� ��ų �ε����� ���� ������ ���
	void CureBySkillIndex(int nSkillIndex);

	void CancelDespair();
	void CancelManaScreen();
	void CancelBless();
#ifdef ADULT_SERVER_NEWITEM
	void CancelMantle();
#endif // ADULT_SERVER_NEWITEM

private:


	/////////////////////
	// Function name	: DelDuplicate
	// Description	    : �ߺ��Ǵ� ȿ�� ����
	// Argument         : const CSkillProto* proto
	//                  : �ߺ� �˻� ��� ��ų
	// Argument         : int level
	//                  : ����
	// Argument         : bool bSend
	//                  : ���� ������ �޽����� ���������� ����
	// Argument         : bool bNoCancelType
	// 060317 : bs      : SF_NOCANCEL �˻� ����
	void DelDuplicate(const CSkillProto* proto, int level, bool bSend, bool bNoCancelType);
};

#endif //__ASSIST_H__
