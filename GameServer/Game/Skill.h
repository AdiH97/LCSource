#ifndef __SKILL_H__
#define __SKILL_H__

#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "MessageType.h"
#include "Config.h"
#include "NetMsg.h"
#define NULL 0
#define SKILL_RATE_UNIT		100		// ��ų rate ���� 10000

////////////////////////
// ��ų ����
#define MAX_SKILL_LEARN_SKILL			3			// ��ų ���µ� �ʿ��� ��ų �ִ� ����
#define MAX_SKILL_LEARN_ITEM			3			// ��ų ���µ� �ʿ��� ������ �ִ� ����
#define MAX_SKILL_CHANGE				4			// �ϳ��� ��ų�� ���� ���� ��ȭ �ִ� ����
#define MAX_SKILL_NEED_ITEM				2			// ��ų ���� �Ҹ�Ǵ� ������ ����
#define MAX_SKILL_APP_MAGIC				3			// ��ų�� �������� ȿ�� ��
#define MAX_SKILL_USE_MAGIC				3			// ��ų�� ������� ȿ�� ��
#define MAX_SKILL_MAGIC					3			// ��ų�� ȿ�� ��
#define MAX_SKILL_LEVEL					10			// ��ų �ִ� ����
#define UNIT_SKILLPOINT					10000		// ��ų ����Ʈ ��� ����
#define MAX_SOUL_COUNT					10			// ����Ʈ ������ ��ȥ �ִ� ���� ����

#ifdef FACTORY_SYSTEM
#define FACTORY_UNION_REG_SKILL			655			// ���� ���� ��� ��ų ��ȣ
#endif

////////////
// ��ų ����
#define SKILL_CON_NORMAL				0			// �Ϲ� ����
#define SKILL_CON_READY					1			// ���� ����
#define SKILL_CON_FIRE					2			// �ߵ� ����

#ifdef ATTR_SYSTEM
// OLD ATTRIBUTE VARIABLE REUSE, Elenoa 2013.01.09
// �Ӽ� ���
#define	AT_NONE					0			// ��
#define	AT_FIRE					1			// ȭ
#define	AT_WATER				2			// ��
#define	AT_EARTH				3			// ��
#define	AT_WIND					4			// ǳ
#define	AT_DARK					5			// ��
#define	AT_LIGHT				6			// ��
#if 0 // NOT USE AT_ALL, Elenoa 2013.01.09
#define AT_ALL					99			// all
#endif
#define AT_LEVELMAX				5
#define AT_MASK			0xFL
#define AT_LVVEC		4
#define AT_MIX(a, l)	(((l) & AT_MASK) << AT_LVVEC) | ((a) & AT_MASK)
#define GET_AT_VAR(m)	((m) & AT_MASK)
#define GET_AT_LV(m)	(((m) >> AT_LVVEC) & AT_MASK)
#define AT_AD_MASK		0xFFL
#define AT_ADVEC		8
#define AT_ADMIX(a, d)	((((a) & AT_AD_MASK) << AT_ADVEC) | ((d) & AT_AD_MASK))
#define GET_AT_DEF(m)	((m) & AT_AD_MASK)
#define GET_AT_ATT(m)	(((m) >> AT_ADVEC) & AT_AD_MASK)
#endif // ATTR_SYSTEM

///////////
// ȿ�����

// ȿ�� Ÿ��
#define MT_STAT					0			// ����
// OLD ATTRIBUTE VARIABLE REUSE, Elenoa 2013.01.09
#define MT_ATTRIBUTE			1			// �Ӽ�����
#define MT_ASSIST				2			// ���º�ȭ
#define MT_ATTACK				3			// ����
#define MT_RECOVER				4			// ȸ��
#define MT_CURE					5			// ġ��
#define MT_OTHER				6			// �׿�
#define MT_REDUCE				7			// ����� ���
#define MT_IMMUNE				8			// �鿪

// ȿ�� ����Ÿ�� - ����
#define MST_STAT_ATTACK			0			// ����
#define MST_STAT_DEFENSE		1			// ���
#define MST_STAT_MAGIC			2			// ����
#define MST_STAT_RESIST			3			// ����
#define MST_STAT_HITRATE		4			// ����
#define MST_STAT_AVOID			5			// ȸ��
#define MST_STAT_CRITICAL		6			// ũ��
#define MST_STAT_ATTACKSPD		7			// ����
#define MST_STAT_MAGICSPD		8			// ����
#define MST_STAT_MOVESPD		9			// �̼�
#define MST_STAT_RECOVERHP		10			// HPȸ��
#define MST_STAT_RECOVERMP		11			// MPȸ��
#define MST_STAT_MAXHP			12			// �ִ�HP ����
#define MST_STAT_MAXMP			13			// �ִ�MP ����
#define MST_STAT_DEADLY			14			// ���鸮 Ȯ�� ����
#define MST_STAT_MAGICHITRATE	15			// ���� ����
#define MST_STAT_MAGICAVOID		16			// ���� ȸ��
#define MST_STAT_ATTACKDIST		17			// ���ݰŸ� ����
#define MST_STAT_ATTACK_MELEE	18			// �������� ����
#define MST_STAT_ATTACK_RANGE	19			// ���⸮���� ���� ����
#define MST_STAT_HITRATE_SKILL	20			// ��ų ���߷�
#define MST_STAT_ATTACK_80		21			// ���ݷ� 80
#define MST_STAT_MAXHP_450		22			// �ִ�HP ���� 450
#define MST_STAT_SKILLSPD		23			// ��ų ���� �ӵ�����
#define	MST_STAT_VALOR			24			// ��Ƽ������ ����Ͽ� ���ݷ� ���
#define MST_STAT_STATPALL		25			// ���� ����
#define MST_STAT_ATTACK_PER		26			// ���� %
#define MST_STAT_DEFENSE_PER	27			// ��� %
#define MST_STAT_STATPALL_PER	28			// ���� ���� %
#define MST_STAT_STR			29			// ��
#define MST_STAT_DEX			30			// ��ø
#define MST_STAT_INT			31			// ����
#define MST_STAT_CON			32			// ü��
//  [5/21/2009 KwonYongDae]
#define MST_STAT_HARD			33			// ���Ѱ���
#define MST_STAT_STRONG			34			// ������
#define MST_STAT_NPCATTACK		35			// NPC ���Ը� ����/���Ÿ� ���ݷ� ����
#define MST_STAT_NPCMAGIC		36			// NPC ���Ը� ���� ���ݷ� ����
#define MST_STAT_SKILLCOOLTIME	37			// ��ų ��Ÿ��
#define MST_STAT_DECREASE_MANA_SPEND 38		// �����Һ� ����

// ȿ�� ����Ÿ�� - �����̻�
#define MST_ASSIST_POISON		0			// ��
#define MST_ASSIST_HOLD			1			// Ȧ��
#define MST_ASSIST_CONFUSION	2			// ȥ��
#define MST_ASSIST_STONE		3			// ��ȭ
#define MST_ASSIST_SILENT		4			// ����
#define MST_ASSIST_BLOOD		5			// ����
#define MST_ASSIST_BLIND		6			// ����ε�
#define MST_ASSIST_STURN		7			// ����
#define MST_ASSIST_SLEEP		8			// ����
#define MST_ASSIST_HP			9			// HPȸ��
#define MST_ASSIST_MP			10			// MPȸ��
#define MST_ASSIST_MOVESPD		11			// �̼� ���
#define MST_ASSIST_HP_CANCEL	12			// HP��ȭ(0, MAX���� ���)
#define MST_ASSIST_MP_CANCEL	13			// MP��ȭ(0, MAX���� ���)
#define MST_ASSIST_DIZZY		14			// ������
#define MST_ASSIST_INVISIBLE	15			// �κ�����
#define MST_ASSIST_SLOTH		16			// ���ν� : �����϶�
#define MST_ASSIST_FEAR			17			// ���� : �ش� NPC�� ����
#define MST_ASSIST_FAKEDEATH	18			// ����ô
#define MST_ASSIST_PERFECTBODY	19			// Ÿ��ź ���� �ٵ�
#define MST_ASSIST_FRENZY		20			// Ÿ��ź ������
#define MST_ASSIST_DAMAGELINK	21			// �������ũ
#define MST_ASSIST_BERSERK		22			// ����ũ
#define MST_ASSIST_DESPAIR		23			// ����
#define MST_ASSIST_MANASCREEN	24			// ���� ��ũ��
#define MST_ASSIST_BLESS		25			// ����
#define MST_ASSIST_SAFEGUARD	26			// ��ȣ��(�����Ұ���)
#define MST_ASSIST_MANTLE		27			// ����
#define MST_ASSIST_GUARD		28			// ��� ��ȯ

#define MST_ASSIST_CHARGEATC	29			// ��ź(attack)
#define MST_ASSIST_CHARGEMGC	30			// ��ź(magic)

#define MST_ASSIST_DISEASE		31			// ����
#define MST_ASSIST_CURSE		32			// ����
#define MST_ASSIST_CONFUSED			33			// ���͸� ȥ���� �ɸ��� ��
#define MST_ASSIST_TAMING			34			// ���͸� �����ð� �Ʊ����� ����
#define MST_ASSIST_FREEZE			35			// ��� (���� ���� ����, �ɸ� ���� �̵� ����)
#define MST_ASSIST_INVERSE_DAMAGE	36			// �ǰݴ��ϸ� ������ ��ŭ HP ȸ��
#define MST_ASSIST_HP_DOT			37			// ���ӵ����� ����
#define MST_ASSIST_REBIRTH			38			// ��Ȱ
#define MST_ASSIST_DARKNESS_MODE	39			// �絵 ���
#define MST_ASSIST_AURA_DARKNESS	40			// ������ - ��ũ�Ͻ�
#define MST_ASSIST_AURA_WEAKNESS	41			// ������ - ��ũ�Ͻ�
#define MST_ASSIST_AURA_ILLUSION	42			// ������ - �Ϸ���
#define MST_ASSIST_MERCENARY		43		// ���͸� �뺴���� �ٲ�. //#ifdef SYSTEM_MONSTER_MERCENARY_CARD
#define MST_ASSIST_SOUL_TOTEM_BUFF	44		// ��� ����(����))�� ����(������)
#define MST_ASSIST_SOUL_TOTEM_ATTK	45		// ��� ����(����)�� ����(������)
#define MST_ASSIST_TRAP				46		// ���͸� Ʈ������
#define MST_ASSIST_PARASITE			47		// �з�����Ʈ ���� (������ ���·� ������ �������͸� ��ȯ�Ͽ� ������ ����)
#define MST_ASSIST_SUICIDE			48		// ���͸� ������Ŵ
#define MST_ASSIST_INVINCIBILITY	49		// ���� ���

// ȿ�� ����Ÿ�� - ����
#define MST_ATTACK_NORMAL		0			// �Ϲ� ����
#define MST_ATTACK_CRITICAL		1			// ũ��Ƽ�� ����
#define MST_ATTACK_DRAIN		2			// �巹�� : �� hp�� �������� ���
#define MST_ATTACK_ONESHOTKILL	3			// ���
#define MST_ATTACK_DEADLY		4			// ���鸮 ����
#define MST_ATTACK_HARD			5			// �ſ� ���� ����

// ȿ�� ����Ÿ�� - ȸ��
#define MST_RECOVER_HP			0			// HPȸ��
#define MST_RECOVER_MP			1			// MPȸ��
#define MST_RECOVER_STM			2			// ������ �� ���׹̳� ȸ��
#define MST_RECOVER_FAITH		3			// ������ �� �漺�� ȸ��
#define MST_RECOVER_EXP			4			// ����ġ ����
#define MST_RECOVER_SP			5			// ���õ� ����

// ȿ�� ����Ÿ�� - ġ��
#define MST_CURE_POISON			0			// ��
#define MST_CURE_HOLD			1			// Ȧ�� : TODO : ������� ����
#define MST_CURE_CONFUSION		2			// ȥ��
#define MST_CURE_STONE			3			// ��ȭ
#define MST_CURE_SILENT			4			// ����
#define MST_CURE_BLOOD			5			// ����
#define MST_CURE_REBIRTH		6			// ��Ȱ
#define MST_CURE_INVISIBLE		7			// �κ����� ���¸� ����
#define MST_CURE_STURN			8			// ���� ����
#define MST_CURE_SLOTH			9			// ���ν� ����
#define MST_CURE_NOTHELP		10			// not help�� assist�� ��� ����
#define MST_CURE_BLIND			11			// ����ε�

#define MST_CURE_DISEASE		12			// ���� ����
#define MST_CURE_CURSE			13			// ���� ����
#define MSG_CURE_ALL			14			// ����� ��� ���� <<-- MST_CURE_NOTHELP �� �ߺ�Ȯ�� �ʿ�
#define MST_CURE_INSTANTDEATH	15			// ���(������ ���� ����)

// ȿ�� ����Ÿ�� - �׿�
#define MST_OTHER_INSTANTDEATH	0			// ���
#define MST_OTHER_SKILLCANCEL	1			// ��ų ���� ���
#define MST_OTHER_TACKLE		2			// ��Ŭ
#define MST_OTHER_TACKLE2		3			// ��Ŭ2
#define MST_OTHER_REFLEX		4			// �ݻ� ����� (�Ϲ� ����, 25m��)
#define MST_OTHER_DEATHEXPPLUS	5			// ������ ����ġ �г�Ƽ �ٿ�
#define MST_OTHER_DEATHSPPLUS	6			// ������ SP �г�Ƽ �ٿ�
#define MST_OTHER_TELEKINESIS	7			// �ڷ�Ű�׽ý�
#define MST_OTHER_TOUNT			8			// Ÿ��Ʈ : ����Ʈ ����
#define MST_OTHER_SUMMON		9			// ��ȯ
#define MST_OTHER_EVOCATION		10			// ����
#define MST_OTHER_TARGETFREE	11			// Ÿ�� ����
#define MST_OTHER_CURSE			12			// Ÿ�� ���� �϶�
#define MST_OTHER_PEACE			13			// ��ȭ�� ¡ǥ
#define MST_OTHER_SOUL_DRAIN	14			// ��ȥ ���, ���� ä��
#define MST_OTHER_KNOCKBACK		15			// �˹�
#define MST_OTHER_WARP			16			// ����
#define MST_OTHER_FLY			17			// ����
#define MST_OTHER_EXP			18			// EXP
#define MST_OTHER_SP			19			// SP
#define MST_OTHER_ITEMDROP		20			// ������ �ٴڿ� ���
#define MST_OTHER_SKILL			21			// ��ų���
#define MST_OTHER_PK_DISPOSITION 22			// PK ���� ����Ʈ
//#ifdef AFFINITY_BOOSTER
#define MST_OTHER_AFFINITY		23			// ģȭ�� �ν���
//#endif  AFFINITY_BOOSTER

// ȿ�� ����Ÿ�� - ����� ���
#define MST_REDUCE_MELEE		0			// ���� ���� ���
#define MST_REDUCE_RANGE		1			// ���Ÿ� ���� ���
#define MST_REDUCE_MAGIC		2			// ���� ���� ���
#define MST_REDUCE_SKILL		3			// ��ų ���� ���

// ȿ�� ����Ÿ�� - �鿪
#define MST_IMMUNE_BLIND		0			// ����ε�

// ����� Ÿ��
#define MDT_ONLYPOWER			0			// ��ų ���¸�
#define MDT_ADDITION			1			// ���ȿ� ����
#define MDT_RATE				2			// ���ȿ� ������ ����

// ���� Ÿ��
#define MHT_CONSTANT			0			// ����
#define MHT_VARIABLE			1			// ����

////////////
// ��ų ���

// ��ų ����
#define ST_MELEE				0			// ����
#define ST_RANGE				1			// ���Ÿ�
#define ST_MAGIC				2			// ����
#define ST_PASSIVE				3			// �нú�
#define ST_PET_COMMAND			4			// �� Ŀ�ǵ�
#define ST_PET_SKILL_PASSIVE	5			// �� ��ų(�нú�)
#define ST_PET_SKILL_ACTIVE		6			// �� ��ų(��Ƽ��)
#ifdef NEW_GUILD
#define ST_GUILD_SKILL_PASSIVE	7			// ��� ��ų(�нú�)
#endif // NEW_GUILD
#ifdef FACTORY_SYSTEM
#define ST_SEAL					8			// ���� �ý��� ��ų(��ǥ)
#endif
//#ifdef SYSTEM_SUMMON_SKILL
#define ST_SUMMON_SKILL	9			// ���� ��ȯ ��ų
//#endif

// Ÿ���� ���
#define STT_SELF_ONE			0			// ����
#define STT_SELF_RANGE			1			// ���� ����
#define STT_TARGET_ONE			2			// Ÿ��
#define STT_TARGET_RANGE		3			// Ÿ�� ����
#define STT_PARTY_ONE			4			// ��Ƽ 1��
#define STT_PARTY_ALL			5			// ��Ƽ ��ü
#define STT_TARGET_D120			6			// Ÿ�� 120��
#define STT_TARGET_RECT			7			// Ÿ�� ���簢
#define STT_ELEMENTAL_ONE		8			// ������Ż ��� ��ų
#ifdef GUILD_SKILL
#define STT_GUILD_ALL			9			// ��� ��ü���� �ִ� HELP ��ų
#define STT_GUILD_ONE			10			// ��� �Ѹ��� �ִ� HELP ��ų
#define STT_GUILD_SELF_RANGE	11			// ������ ���� NPC���� �ִ� ATTACK SKILL
#endif // GUILD_SKILL

// �÷���
#define	SF_SINGLEMODE			(1 << 0)	// �̱۸��
#define	SF_HELP					(1 << 1)	// ������ �ִ� ��ų
#define	SF_NOTHELP				(1 << 2)	// �ز��� ��ų
#define SF_ABSTIME				(1 << 3)	// 060227 : bs : ����ð� ���
#define SF_NOTDUPLICATE			(1 << 4)	// 060227 : bs : �ߺ� ��� �Ұ� : �ߺ��Ǵ� ��ų�� ������ ������ ������� ����� �ȵ�
#define SF_NOCANCEL				(1 << 5)	// �ٸ� ��ų/����� ���� ��� �ȵ�
#define	SF_COMBO				(1 << 6)	// �ð�������� �����(��������, �����̵�, �׾��� �� �����)
#define	SF_LOGOUT				(1 << 7)	// �������� �� �����
#define SF_INSTANT				(1 << 8)	// 100420 : swkwon : ������ ��ų �α׾ƿ��Ҷ� ��ų ����Ʈ���� ������.
#define SF_GUILD				(1 << 9)	// 100615 : swkwon : ��彺ų
#define SF_INFINITE				(1 << 10)	// ���ѽ�ų - ��ų �ð��� ����Ǹ� �ٽ� ��ų�� �����
#define SF_ZONE					(1 << 11)	// ���̵��� ���� ����
#define SF_SUMMON_NPC			(1 << 12)	// summon Npc�� ����ϴ� ��ų���� üũ // üũ�ϸ� ����Ʈ�� �����ش�.
#define SF_NOTBLESS				(1 << 13)	// �÷��װ� ������ �Ҽ��� ������ ������ ���� �ʴ´�.

// ���/���� ����
#define SCT_DEATH				(1 << 0)	// ���
#define SCT_WEAPON				(1 << 1)	// �������
#define SCT_SITDOWN				(1 << 2)	// �ɱ�
#define SCT_PEACEZONE			(1 << 3)	// ��ȭ����
#define SCT_SHIELD				(1 << 4)	// ��������
#define SCT_STAND				(1 << 5)	// ����
#ifdef NIGHTSHADOW_SKILL
#define SCT_DARKNESS			(1 << 6)    // ����Ʈ ������ �絵 ��忡���� ����ϴ� ��ų���� Ȯ��
#endif // NIGHTSHADOW_SKILL
#define SCT_NO_COOL_TIME		(1 << 7)	// ��Ÿ�Ӱ��� ���� �Ұ�

// �����̻� ��Ʈ �ʵ� ��
#ifdef NIGHTSHADOW_SKILL
#define AST_POISON				((LONGLONG)1 << MST_ASSIST_POISON)		// ��
#define AST_HOLD				((LONGLONG)1 << MST_ASSIST_HOLD)			// Ȧ��
#define AST_CONFUSION			((LONGLONG)1 << MST_ASSIST_CONFUSION)		// Ȧ��
#define AST_STONE				((LONGLONG)1 << MST_ASSIST_STONE)			// ��ȭ
#define AST_SILENT				((LONGLONG)1 << MST_ASSIST_SILENT)		// ����
#define AST_BLOOD				((LONGLONG)1 << MST_ASSIST_BLOOD)			// ����
#define AST_BLIND				((LONGLONG)1 << MST_ASSIST_BLIND)			// ����ε�
#define AST_STURN				((LONGLONG)1 << MST_ASSIST_STURN)			// ����
#define AST_SLEEP				((LONGLONG)1 << MST_ASSIST_SLEEP)			// ����
#define AST_HP					((LONGLONG)1 << MST_ASSIST_HP)			// ü��
#define AST_MP					((LONGLONG)1 << MST_ASSIST_MP)			// ����
#define AST_MOVESPD				((LONGLONG)1 << MST_ASSIST_MOVESPD)		// �̼� ���
#define AST_HP_CANCEL			((LONGLONG)1 << MST_ASSIST_HP_CANCEL)		// HP��ȭ(0, MAX���� ���)
#define AST_MP_CANCEL			((LONGLONG)1 << MST_ASSIST_MP_CANCEL)		// MP��ȭ(0, MAX���� ���)
#define AST_DIZZY				((LONGLONG)1 << MST_ASSIST_DIZZY)			// ������
#define AST_INVISIBLE			((LONGLONG)1 << MST_ASSIST_INVISIBLE)		// �κ�������Ƽ
#define AST_SLOTH				((LONGLONG)1 << MST_ASSIST_SLOTH)			// ���ν�(�����϶�)
#define AST_FEAR				((LONGLONG)1 << MST_ASSIST_FEAR)			// ����
#define AST_FAKEDEATH			((LONGLONG)1 << MST_ASSIST_FAKEDEATH)		// ����ô�ϱ�
#define AST_PERFECTBODY			((LONGLONG)1 << MST_ASSIST_PERFECTBODY)	// Ÿ��ź ���� �ٵ�
#define AST_FRENZY				((LONGLONG)1 << MST_ASSIST_FRENZY)		// Ÿ��ź ������
#define AST_DAMAGELINK			((LONGLONG)1 << MST_ASSIST_DAMAGELINK)	// ������ ��ũ
#define AST_BERSERK				((LONGLONG)1 << MST_ASSIST_BERSERK)		// ����ũ
#define AST_DESPAIR				((LONGLONG)1 << MST_ASSIST_DESPAIR)		// ����
#define AST_MANASCREEN			((LONGLONG)1 << MST_ASSIST_MANASCREEN)	// ���� ��ũ��
#define AST_BLESS				((LONGLONG)1 << MST_ASSIST_BLESS)			// ����
#define AST_SAFEGUARD			((LONGLONG)1 << MST_ASSIST_SAFEGUARD)		// ��ȣ��
#define AST_MANTLE				((LONGLONG)1 << MST_ASSIST_MANTLE)		// ����
#define AST_GUARD				((LONGLONG)1 << MST_ASSIST_GUARD)			// ��� ��ȯ
//-- (-2) ��ź 2�� ������
#define AST_DISEASE				((LONGLONG)1 << (MST_ASSIST_DISEASE-2) )	// ����
#define AST_CURSE				((LONGLONG)1 << (MST_ASSIST_CURSE-2) )		// ��� ��ȯ
#define AST_CONFUSED			((LONGLONG)1 << MST_ASSIST_CONFUSED)		// ���͸� ȥ���� �ɸ��� ��
#define AST_TAMING				((LONGLONG)1 << MST_ASSIST_TAMING)			// ���͸� �����ð� �Ʊ����� ����
#define AST_FREEZE				((LONGLONG)1 << MST_ASSIST_FREEZE)			// ��� (���� ���� ����, �ɸ� ���� �̵� ����)
#define AST_INVERSE_DAMAGE		((LONGLONG)1 << MST_ASSIST_INVERSE_DAMAGE)	// �ǰݴ��ϸ� ������ ��ŭ HP ȸ��
#define AST_HP_DOT				((LONGLONG)1 << MST_ASSIST_HP_DOT)			// ���ӵ����� ����
#define AST_REBIRTH				((LONGLONG)1 << MST_ASSIST_REBIRTH)			// ������ �� ������ ������ �ٷ� ��Ȱ
#define AST_DARKNESS_MODE		((LONGLONG)1 << MST_ASSIST_DARKNESS_MODE)	// �絵 ���
#define AST_AURA_DARKNESS		((LONGLONG)1 << MST_ASSIST_AURA_DARKNESS)	// ������ - ��ũ�Ͻ�
#define AST_AURA_WEAKNESS		((LONGLONG)1 << MST_ASSIST_AURA_WEAKNESS)	// ������ - ��ũ�Ͻ�
#define AST_AURA_ILUSYON		((LONGLONG)1 << MST_ASSIST_AURA_ILLUSION)	// ������ - �Ϸ���
#define AST_MERCENARY			((LONGLONG)1 << MST_ASSIST_MERCENARY)		// ���͸� �뺴���� ����
#define AST_SOUL_TOTEM_BUFF		((LONGLONG)1 << MST_ASSIST_SOUL_TOTEM_BUFF)	// ���� ���� ������
#define AST_SOUL_TOTEM_ATTK		((LONGLONG)1 << MST_ASSIST_SOUL_TOTEM_ATTK)	// ���� ���� ������
#define AST_TRAP				((LONGLONG)1 << MST_ASSIST_TRAP)			// Ʈ��
#define AST_PARASITE			((LONGLONG)1 << MST_ASSIST_PARASITE)		// ����� ����
#define AST_SUICIDE				((LONGLONG)1 << MST_ASSIST_SUICIDE)			// ����
#define AST_INVINCIBILITY		((LONGLONG)1 << MST_ASSIST_INVINCIBILITY)	// ����

#else // NIGHTSHADOW_SKILL

#define AST_POISON				(1 << MST_ASSIST_POISON)		// ��
#define AST_HOLD				(1 << MST_ASSIST_HOLD)			// Ȧ��
#define AST_CONFUSION			(1 << MST_ASSIST_CONFUSION)		// Ȧ��
#define AST_STONE				(1 << MST_ASSIST_STONE)			// ��ȭ
#define AST_SILENT				(1 << MST_ASSIST_SILENT)		// ����
#define AST_BLOOD				(1 << MST_ASSIST_BLOOD)			// ����
#define AST_BLIND				(1 << MST_ASSIST_BLIND)			// ����ε�
#define AST_STURN				(1 << MST_ASSIST_STURN)			// ����
#define AST_SLEEP				(1 << MST_ASSIST_SLEEP)			// ����
#define AST_HP					(1 << MST_ASSIST_HP)			// ü��
#define AST_MP					(1 << MST_ASSIST_MP)			// ����
#define AST_MOVESPD				(1 << MST_ASSIST_MOVESPD)		// �̼� ���
#define AST_HP_CANCEL			(1 << MST_ASSIST_HP_CANCEL)		// HP��ȭ(0, MAX���� ���)
#define AST_MP_CANCEL			(1 << MST_ASSIST_MP_CANCEL)		// MP��ȭ(0, MAX���� ���)
#define AST_DIZZY				(1 << MST_ASSIST_DIZZY)			// ������
#define AST_INVISIBLE			(1 << MST_ASSIST_INVISIBLE)		// �κ�������Ƽ
#define AST_SLOTH				(1 << MST_ASSIST_SLOTH)			// ���ν�(�����϶�)
#define AST_FEAR				(1 << MST_ASSIST_FEAR)			// ����
#define AST_FAKEDEATH			(1 << MST_ASSIST_FAKEDEATH)		// ����ô�ϱ�
#define AST_PERFECTBODY			(1 << MST_ASSIST_PERFECTBODY)	// Ÿ��ź ���� �ٵ�
#define AST_FRENZY				(1 << MST_ASSIST_FRENZY)		// Ÿ��ź ������
#define AST_DAMAGELINK			(1 << MST_ASSIST_DAMAGELINK)	// ������ ��ũ
#define AST_BERSERK				(1 << MST_ASSIST_BERSERK)		// ����ũ
#define AST_DESPAIR				(1 << MST_ASSIST_DESPAIR)		// ����
#define AST_MANASCREEN			(1 << MST_ASSIST_MANASCREEN)	// ���� ��ũ��
#define AST_BLESS				(1 << MST_ASSIST_BLESS)			// ����
#define AST_SAFEGUARD			(1 << MST_ASSIST_SAFEGUARD)		// ��ȣ��
#define AST_MANTLE				(1 << MST_ASSIST_MANTLE)		// ����
#define AST_GUARD				(1 << MST_ASSIST_GUARD)			// ��� ��ȯ
//-- (-2) ��ź 2�� ������
#define AST_DISEASE				(1 << (MST_ASSIST_DISEASE-2) )		// ����
#define AST_CURSE				(1 << (MST_ASSIST_CURSE-2) )		// ��� ��ȯ
#endif // NIGHTSHADOW_SKILL

#define SKILL_PARAM_MIN			75
#define SKILL_PARAM_MAX			125

#define SPARAM_NONE				0
#define SPARAM_STR				1
#define SPARAM_DEX				2
#define SPARAM_INT				3
#define SPARAM_CON				4

// �Ҽ��� �÷���
#define SSF_APP_CHARACTER		(1 << 0)	// ĳ����
#define SSF_APP_FIRE			(1 << 1)	// ��������
#define SSF_APP_WIND			(1 << 2)	// �ٶ�������
#define SSF_APP_EARTH			(1 << 3)	// ����������
#define SSF_APP_WATER			(1 << 4)	// ��������
#define SSF_APP_HELLOUND		(1 << 5)	// ����
#define SSF_APP_ELENEN			(1 << 6)	// ������
#define SSF_APP_APET			(1 << 7)	// ������ ��
#define SSF_APP_ALL				(SSF_APP_CHARACTER | SSF_APP_FIRE | SSF_APP_WIND | SSF_APP_EARTH | SSF_APP_WATER | SSF_APP_HELLOUND | SSF_APP_ELENEN | SSF_APP_APET)
#define SSF_USE_CHARACTER		(1 << 16)	// ĳ����
#define SSF_USE_FIRE			(1 << 17)	// ��������
#define SSF_USE_WIND			(1 << 18)	// �ٶ�������
#define SSF_USE_EARTH			(1 << 19)	// ����������
#define SSF_USE_WATER			(1 << 20)	// ��������
#define SSF_USE_HELLOUND		(1 << 21)	// ����
#define SSF_USE_ELENEN			(1 << 22)	// ������
#define SSF_USE_APET			(1 << 23)	// ������ ��
#define SSF_USE_ALL				(SSF_USE_CHARACTER | SSF_USE_FIRE | SSF_USE_WIND | SSF_USE_EARTH | SSF_USE_WATER | SSF_USE_HELLOUND | SSF_USE_ELENEN | SSF_USE_APET)

// --- skill

#if 0 // OLD ATTRIBUTE BLOCK, Elenoa 2013.01.09
class CAttributeData
{
	int m_water;		// ��
	int m_wind;			// ǳ
	int m_earth;		// ��
	int m_fire;			// ȭ
	int m_dark;			// ��
	int m_light;		// ��

public:
	CAttributeData() { Reset(); }

	void Reset() { memset(this, 0, sizeof(*this)); }
	void Add(int type, int val, bool bFromItem);

	int GetValue(int type) const;
};
#endif

class CCharacter;
class CPC;
//#ifdef ENABLE_PET
class CPet;
//#endif
class CAPet;

/////////////////////
// Class name	    : CMagicLevelProto
// Description	    : ȿ�� ������ ����
class CMagicLevelProto {
     int m_nPowerValue;
     int m_nHitrateValue;
   public:
     int GetSummonNpcIndex(void);
     CMagicLevelProto(int, int);
 };

/////////////////////
// Class name	    : CMagicProto
// Description	    : ȿ�� ����
class CMagicProto {
         int m_index;
         char m_maxlevel;
         char m_type;
         char m_subtype;
         char m_damagetype;
         char m_hittype;
         char m_attribute;
         int m_psp;
         int m_ptp;
         int m_hsp;
         int m_htp;
         int m_bTogel;
         CMagicLevelProto **m_levelproto;
       public:
         CMagicProto(int, char, char, char, char, char, char, int, int, int, int, int, CMagicLevelProto **);
         ~CMagicProto();
         const CMagicLevelProto * Level(char) const;
     };

/////////////////////
// Class name	    : CSkillLevelProto
// Description	    : ��ų ���� ����
class CSkillLevelProto
{
public:
	int m_needHP;
     int m_needMP;
     int m_needGP;
     int m_durtime;
     int m_hate;
     int m_needItemIndex[2];
     int m_needItemCount[2];
     int m_learnLevel;
     int m_learnSP;
     int m_learnSkillIndex[3];
     char m_learnSkillLevel[3];
     int m_learnItemIndex[3];
     int m_learnItemCount[3];
     int m_learnstr;
     int m_learndex;
     int m_learnint;
     int m_learncon;
     int m_appMagicIndex[3];
     char m_appMagicLevel[3];
     const CMagicProto *m_magic[3];
     char m_magicLevel[3];
     int m_learnGP;
   public:
	CSkillLevelProto(int, int, int, int, int, int *, int *, int, int, int *, char *, int *, int *, int, int, int, int, int *, char *, const CMagicProto **, char *, int);
};

/////////////////////
// Class name	    : CSkillProto
// Description	    : ��ų ����
class CSkillProto
{
   public:
     int m_index;
     char m_type;
     int m_flag;
     char m_maxLevel;
     float m_appRange;
     char m_targetType;
     char m_targetNum;
     int m_readyTime;
     int m_stillTime;
     int m_fireTime;
     int m_reuseTime;
     int m_selfparam;
     int m_targetparam;
     int m_applyState;
     int m_applyWeaponType0;
     int m_applyWeaponType1;
     int m_nAPetIndex;
     int m_soul_consum;
     int m_useWearing;
     int m_appWearing;
     int m_summonIDX;
   private:
     int m_job;
     int m_job2;
     float m_fireRange;
     float m_fireRange2;
     float m_minRange;
     int m_useState;
     int m_useWeaponType0;
     int m_useWeaponType1;
     int m_useMagicIndex[3];
     char m_useMagicLevel[3];
     int m_sorcerer_flag;
   public:
     CSkillLevelProto **m_levelproto;

#ifdef ATTACK_PET
	#ifdef NIGHTSHADOW_SKILL
		#ifdef SYSTEM_SUMMON_SKILL
	CSkillProto(int index, int job, int job2, char type, int flag, int sorcerer_flag, char maxLevel, float appRange, float fireRange, float fireRange2, float minRange, char targetType, char targetNum, int useState, int useWeaponType0, int useWeaponType1, int useMagicIndex[3], char useMagicLevel[3], int appState, int appWeaponType0, int appWeaponType1, int readyTime, int stillTime, int fireTime, int reuseTime, int selfparam, int targetparam, CSkillLevelProto** levelproto, int nAPetIndex, int soul_consum, int useWearing, int appWearing, int summonIdx );
		#else
	CSkillProto(int index, int job, int job2, char type, int flag, int sorcerer_flag, char maxLevel, float appRange, float fireRange, float fireRange2, float minRange, char targetType, char targetNum, int useState, int useWeaponType0, int useWeaponType1, int useMagicIndex[3], char useMagicLevel[3], int appState, int appWeaponType0, int appWeaponType1, int readyTime, int stillTime, int fireTime, int reuseTime, int selfparam, int targetparam, CSkillLevelProto** levelproto, int nAPetIndex, int soul_consum, int useWearing, int appWearing );
		#endif
	#else
	CSkillProto(int index, int job, int job2, char type, int flag, int sorcerer_flag, char maxLevel, float appRange, float fireRange, float fireRange2, float minRange, char targetType, char targetNum, int useState, int useWeaponType0, int useWeaponType1, int useMagicIndex[3], char useMagicLevel[3], int appState, int appWeaponType0, int appWeaponType1, int readyTime, int stillTime, int fireTime, int reuseTime, int selfparam, int targetparam, CSkillLevelProto** levelproto, int nAPetIndex );
	#endif // NIGHTSHADOW_SKILL
#else // ATTACK_PET
	CSkillProto(int index, int job, int job2, char type, int flag, int sorcerer_flag, char maxLevel, float appRange, float fireRange, float fireRange2, float minRange, char targetType, char targetNum, int useState, int useWeaponType0, int useWeaponType1, int useMagicIndex[3], char useMagicLevel[3], int appState, int appWeaponType0, int appWeaponType1, int readyTime, int stillTime, int fireTime, int reuseTime, int selfparam, int targetparam, CSkillLevelProto** levelproto);
#endif //ATTACK_PET

	~CSkillProto();

	const CSkillLevelProto* Level(char level) const;

	/////////////////////
	// Function name	: IsActive
	// Description	    : ��Ƽ�� ��ų �˻�
	bool IsActive() const;

	/////////////////////
	// Function name	: IsPassive
	// Description	    : �нú� ��ų �˻�
	bool IsPassive() const;

	/////////////////////
	// Function name	: IsSummon
	// Description	    : ���� ��ų �˻�
	bool IsSummon() const;

#ifdef FACTORY_SYSTEM
	bool IsSeal() const;
#endif

	////////////////////
	// Function name	: IsSameJob
	// Description	    : ���� �������� �˻�
	//bool IsSameJob(CPC* pc) const;
//#ifdef ENABLE_PET
	//bool IsSameJob(CPet* pet) const;
//#endif

#ifdef ATTACK_PET
	bool IsSameJob(CAPet* apet) const;
#endif //ATTACK_PET

	////////////////////
	// Function name	: GetFireRange
	// Description	    : �����Ÿ� �˻�, NPC�� 1��, PC�� ���⿡ ����
	float GetFireRange(CCharacter* ch) const;

	////////////////////
	// Function name	: CheckUseState
	// Description	    : ��� ���� �˻�
	// Return type		: int
	//                  : ��� �Ұ��ɽÿ� ������� ���� ��ȯ, -1�� magic �Ҵɿ���
	int CheckUseState(CCharacter* ch) const;

	// a_minRange
	float GetMinRange() const;

//#ifdef ENABLE_CHANGEJOB
	int Get2ndJob() const { return m_job2; }
//#endif

	// �Ҽ����� �÷��� Ȯ��
	int CheckSorcererFlag(int mask) const { return (m_sorcerer_flag & mask); }

	bool CheckAllowZone(char zoneindex) const;
	bool LoadAllowZone(const char* strZoneList);

private:
	struct SKILLALLOWZONE
	{
		char	count;
		char*	zoneindex;
		SKILLALLOWZONE(char nCount)
		{
			count = nCount;
			zoneindex = new char[nCount];
			memset(zoneindex, -1, sizeof(char) * nCount);
		}
		~SKILLALLOWZONE()
		{
			count = 0;
			if(zoneindex)
			{
				delete [] zoneindex;
				zoneindex = NULL;
			}
		}
	};

	SKILLALLOWZONE* m_allowzone;
};

/////////////////////
// Class name	    : CMagicProtoList
// Description	    : ȿ�� ���� ����Ʈ
class CMagicProtoList {
     CMagicProto **m_list;
     int m_count;
   public:
     CMagicProtoList(void);
     ~CMagicProtoList();
     bool Load(void);
     const CMagicProto * Find(int);
 };
// ���� ��ƼŸ�ٿ� ����ü
struct MultiTarget {
	CCharacter*		mtarget;
	char			mtargettype;
	int				mtargetindex;
	float			mdist;

	void Init( void ) // �ʱ�ȭ
	{
		mtarget = NULL;
		mtargetindex = 0;
		mtargettype = -1;
		mdist = 9999;
	}
	MultiTarget()
	{	Init();	}
};

/////////////////////
// Class name	    : CSkill
// Description	    : ��ų
class CSkill {
   public:
     const CSkillProto *m_proto;
     char m_level;
     int m_state;
     int m_usetime;
     MSG_CHAR_TYPE m_targetType;
     int m_targetIndex;
     int m_optionSkillProb;

     CSkill(const CSkillProto *, char);
     bool IsReady(CCharacter *);
     void Ready(CCharacter *);
     void Fire(void);
     void Cancel(CCharacter *);
 };

/////////////////////
// Class name	    : CSkillProtoList
// Description	    : ��ų ����Ʈ
class CSkillProtoList {
   private:
	 typedef std::map<int, CSkillProto*, std::less<int>, std::allocator<std::pair<int const, CSkillProto*> > > map_t;
     CSkillProtoList::map_t map_;
     CSkillProto **m_list;
     int m_count;

   public:
     CSkillProtoList(void);
     ~CSkillProtoList();
     bool Load(void);
     const CSkillProto * Find(int);
     CSkill * Create(int, int);
     void LearnAllSkill(CPC *);
 };

class CSkillListNode {
   private:
     CSkill *m_skill;
     CSkillListNode *m_prev;
     CSkillListNode *m_next;

   public:
     CSkillListNode(CSkill *);
     ~CSkillListNode();
     CSkillListNode * prev(void);
     void prev(CSkillListNode *);
     CSkillListNode * next(void);
     void next(CSkillListNode *);
     CSkill * skill(void);
     void skill(CSkill *);
 };

/////////////////////
// Class name	    : CSkillList
// Description	    : ĳ���� ��ų ����Ʈ
class CSkillList {
   private:
     CSkillListNode *m_head;
     CSkillListNode *m_tail;
     int m_count;
   public:
     int m_wearPos;

     void DeleteInstantSkill(int);
     CSkillList(void);
     ~CSkillList();
     bool Add(CSkill *&);
     CSkill * Find(int);
     int count(void);
     char * GetIndexString(char *);
     char * GetLevelString(char *);
     void * GetHeadPosition(void);
     CSkill * GetNext(void *&);
     int RemoveSkillFor2ndJob(void);
     void Clear(void);
     bool Remove(CSkill *);
     bool AddOptionSkill(CSkill *, int, int);
 };

typedef struct __tagSealSkillData {
       int nSkillIdx;
       CSkill *pSkill;
       LONGLONG llExp;
   } SEAL_SKILL_DATA; 

int ApplySkill(CCharacter* ch, CCharacter* tch, CSkill* skill, int itemidx, bool& bApply);
void ApplySkillParty(CPC* ch, CSkill* skill, int itemidx, bool& bApply);
int CalcSkillParam(const CCharacter* ch, const CCharacter* tch, int selfparam, int targetparam);

#ifdef EXPEDITION_RAID
void ApplySkillExped(CPC* ch, CSkill* skill, int itemidx, bool& bApply);
#endif //EXPEDITION_RAID
#ifdef GUILD_SKILL
void ApplySkillGuild(CPC* ch, CSkill* skill, int itemidx, bool& bApply);
#endif
#ifdef NEWYEAR_EVENT_2008
void ApplyNewYearSkill(CPC * ch, CPC * tch);
#endif // NEWYEAR_EVENT_2008
#endif
//
