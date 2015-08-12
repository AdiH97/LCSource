/************************************
  �������� 
  ������ ���: bs
  ������: 2004-11-19 ���� 8:02:59
  ����: ��ų ���� ��� ȿ��, ��ų ���� - ���� ���� �߰�
 ************************************/

#ifndef __GAME_Config_H__
#define __GAME_Config_H__

// ������ ����
//#define LC_KOR		0	// ����
//#define LC_TWN		1	// �븸 - ����
//#ifdef LC_TWN	
//#define LC_TWN2		2		// �븸 - õ�ϴ��, LC_TWN�� ���ÿ� �����ؾ� ��
//#endif
//#define LC_CHN		3	// �߱�
#define LC_TLD			4	// �±�
//#ifdef LC_TLD
//#define LC_TLD_ENG	5	// �±� ����
//#endif
//#define	LC_JPN			6 // �Ϻ�
//#define	LC_MAL			7 // �����̽þ�
//#ifdef LC_MAL
//#define	LC_MAL_ENG		8 // �����̽þ� ���� 
//#endif
//#define	LC_USA			9	// �̱�
//#define	LC_BRZ			10	// �����

// --- ������ ����

#define OLD_NETMSG						// TODO : �����
//#define TEST_SERVER						// �׽�Ʈ ������
// #define CLOSED_BETA_TEST				// Ŭ�� ����
// #define LC_BIG_ENDIAN				1 TODO : �� ����� ��񿡼��� ���
// #define PREOPEN_CHECK				// �������� �÷���
#define FORCE_START_ZONE				// ������ ���۽� ���� ������
// #define NOKICK_HACKUSER				// TODO : �� ���� ���� ���� ó���Ϸ��� �����
// #define NOCHECK_ATTACKSPEED			// TODO : ���ݼӵ� �˻� ���� ����
// #define CLEAR_ASSIST					// TODO : ���� ȿ�� ���� ����
// #define BLOCK_SUMMON_OTHERZONE_MOB	// TODO : �ٸ� ���� �� ��ȯ�� �������� �ּ� Ǯ��
//#define		BLOCK_PVP					// TODO : PVP �������� �ּ� Ǯ��

#define SERVER_VERSION			600		// ���� ���� ����
#define SERVER_MIN_VERSION		600		// �޽���, �����Ϳ��� �����ϴ� ���� ���� ����
#define SERVER_MAX_VERSION		700		// �޽���, �����Ϳ��� �����ϴ� �ְ� ���� ����
#define CONNECTOR_SERVER_NUM	888		// ������ ���� ��ȣ
#define LOGIN_SERVER_NUM		999		// �α��� ���� ��ȣ
#define MESSENGER_SERVER_NUM	777		// �޽��� ���� ��ȣ
#define BILL_SERVER_VERSION		"BillCruxV40" // �������� �������� ����
#define		GAMEID				1		// ��ī ���� ���̵� 1��
#define BILL_LOCATION_HOME		0		// �Ϲ�
#define	BILL_LOCATION_PCBANG	1		// ��ϵ� pc��

#define LOGIN_SERVER_OPEN_CHECK_FILENAME	"login.open"		// �α��� ���� ���� �˻� ���ϸ�

#define		GAMEID				1
#define		CPID				1
#define		ID_LENGTH			32
#define		MAX_PURCHASEITEM	10
#define		MAX_DEPOSITORY		25

#define	PLAYER_COUNT_NUM		9999	// ����ڼ� ���� ���α׷� ��ȣ

#define NUM_RESERVED_DESCS		5		// ���������� ����� ��ũ���� ��
#define MAX_PLAYING				50000	// �ִ� ���� ��
#define MAX_ZONES				20		// �ִ� �� ��
#define MAX_NOTICE				5

#define MAX_PACKET_HEAD		((int) (sizeof(short)) + (sizeof(int)) + (sizeof(short) ) )
#define MAX_PACKET_DATA		(MAX_PACKET_SIZE - MAX_PACKET_HEAD)
#define MAX_PACKET_SIZE 1000

// ���۰��� ���� ���
#define MAX_MESSAGE_TYPE		((int)(sizeof(unsigned char)))
#define MAX_MESSAGE_SIZE		1000
#define MAX_MESSAGE_DATA		(MAX_MESSAGE_SIZE - MAX_MESSAGE_TYPE)

#ifdef OLD_NETMSG
// Reliable(2) + Sequence(4) + ID(2) + TxSize(4)
#define MAX_HEADER_SIZE ((long)(sizeof(unsigned short) + sizeof(unsigned long) + sizeof(unsigned short) + sizeof(unsigned long)))
#else
#define MAX_HEADER_SIZE			((int)(sizeof(int)))
#endif
#define MAX_INPUTBUFFER_SIZE		((MAX_HEADER_SIZE + MAX_MESSAGE_SIZE) * 30)
#define MAX_OUTPUTBUFFER_SIZE		((MAX_MESSAGE_SIZE + MAX_HEADER_SIZE) * 300)
#define MAX_OUTPUTBUFFER_OUTUNIT	4096


#define PI       3.14159265358979323846f
#define PI_2     6.28318530717958623200f
#define PI_3_4	 2.35619449019234492884f	/* ((3 / 4) * PI) */
#define PI_HALF	 (PI / 2)

// �޽��� ó�� �뷮 : �� ƽ�� ��� �Է��� �ް� ��� �޽����� ó������ ����
#define PROC_MESSENGER_INPUT_PER_PASS	50	// ƽ�� �޽��� �Է� ó�� ��
#define PROC_MESSENGER_MSG_PER_PASS		50	// ƽ�� �޽��� �޽��� ó�� ��
#define PROC_HELPER_INPUT_PER_PASS		50	// ƽ�� �޽��� �Է� ó�� ��

// ������ ó�� �뷮 : �� ƽ�� ��� �Է��� �ް� ��� �޽����� ó������ ����
#define PROC_CONNECTOR_INPUT_PER_PASS	50	// ƽ�� ������ �Է� ó�� ��
#define PROC_CONNECTOR_MSG_PER_PASS		50	// ƽ�� ������ �޽��� ó�� ��

// �ð� ����
#ifdef __GAME_SERVER__
	#define OPT_USEC		100000				/* 10 passes per second */
#else
	#define OPT_USEC		50000				/* 20 passes per second */
#endif
#define PASSES_PER_SEC	(1000000 / OPT_USEC)
#define RL_SEC			* PASSES_PER_SEC

// ���� �ð����� ����
#define PULSE_REAL_SEC				(1 RL_SEC)				// ���� 1��
#define PULSE_REAL_MIN				(60 RL_SEC)				// ���� 1��
#define PULSE_REAL_TENMIN			(600 RL_SEC)			// ���� 10��
#define PULSE_REAL_HALF				(1800 RL_SEC)			// ���� 30��
#define	PULSE_REAL_HOUR				(3600 RL_SEC)			// ���� 1�ð�
#define PULSE_CONNECT_TIMEOUT		(3 * PULSE_REAL_MIN)	// �Է� ��� �ð�, ���� �ð� ���� �Է��� ������ ������ ����
#define PULSE_SAVE_PC				(10 * PULSE_REAL_MIN)	// �ڵ� ���� �ð�
#define PULSE_PCROOM_COUNT			(3 * PULSE_REAL_MIN)	// �Ǿ��� ������ �� ī��Ʈ �ֱ�
#define PULSE_TOTAL_COUNT			PULSE_REAL_MIN			// ��ü ���� �� ī��Ʈ �ֱ�
#define PULSE_NPC_AI				2						// NPC �ּ� AI ���� �ð� : 0.5��
#define	PULSE_NPC_REGEN				(15 RL_SEC)				// NPC ���� �ּ� ���� �ð� : ���� 30��
// TODO : DELETE #define PULSE_SAVECOUNT				(5 * PULSE_REAL_MIN)	// �������� ���� �÷��̾� �� ���� �ð�
// TODO : DELETE #define PULSE_SAVEMAXCOUNT			(2 * PULSE_REAL_MIN)	// �������� �ִ� ���� �÷��̾� �� ���� �ð�
#define PULSE_WARPDELAY				(10 * PULSE_REAL_SEC)	// �����̵� ������ : 10��
#define PULSE_BILLITEMREQ			(20 * PULSE_REAL_SEC)	// ���������� ���� ���� �ð� 20��  �̽ð��� ������ ���� Ǭ��.
#define PULSE_BILLITEMLISTREQ		(4 * PULSE_REAL_SEC)	// ���������� ����Ʈ ��û ���� �ð� �̽ð��� ������ ���� Ǭ��.
#define PULSE_WARPCOUNTDOWN			(5 * PULSE_REAL_SEC)	// �����̵� ī��Ʈ �ٿ� ���� : 5�� ������
#define PULSE_ASSIST_CHECK			PULSE_REAL_SEC			// ����ȿ�� �ð� ���� �˻� ������
#define PULSE_HACK_CHECK_TIMEOUT	(6 * PULSE_REAL_MIN)	// �޽� �޽��� Ÿ�Ӿƿ� 6��
#define PULSE_HACK_PULSE_REFRESH	PULSE_REAL_HOUR			// �� �˻� �޽� ���� �ֱ� 1�ð�
#define PULSE_HACK_PULSE_THRESHOLD	(15 * PULSE_REAL_SEC)	// �� �޽� ���� ���� 15��
#define PULSE_HACK_CLIENT_THRESHOLD	(55 * PULSE_REAL_SEC)	// �� �޽� Ŭ���̾�Ʈ �ּ� �ֱ� 55�� �̺��� ���� ������ ��!
#define PULSE_PKMODE_DELAY			(10 RL_SEC)				// PK��忡�� ��ȭ���� ��ȯ�� ������
#define PULSE_HACK_ATTACK_THRESHOLD	2						// ���� ���� ��� ����
#define	PULSE_HACK_ATTACK_COUNT		5						// ���� ��ī��Ʈ ������ ����
#define PULSE_ATTACKMODE_DELAY		(3 * PULSE_REAL_SEC)	// ���� ��� Ǯ���� ������ : ������ �������� �� �ð������� ���� ���̴�
#define PULSE_POST_REGEN_DELAY		(3 * PULSE_REAL_SEC)	// �������� �����ϱ� ������ ������
#define PULSE_PRODUCE_DELAY			(2 * PULSE_REAL_SEC)	// ���� ������
#define PULSE_PET_SYMPATHY_INCREASE	(5 * PULSE_REAL_MIN)	// �� ������ ���� ������
#define PULSE_PET_SYMPATHY_DECREASE	(PULSE_REAL_HOUR)		// �� ������ ���� ������
#define PULSE_PET_HUNGRY_DECREASE	(5 * PULSE_REAL_MIN)	// �� ����� ������
#define PULSE_AUTO_SKILL_DECREASE	(10 * PULSE_REAL_SEC)	// �ڵ� ��ų ���� �ð�
#define PULSE_KEY_CHANGE_THRESHOLD	(10 * PULSE_REAL_SEC)	// Ű ���� �Ӱ� �ð� : 10 ��
#define PULSE_KEY_CHANGE			(20 * PULSE_REAL_SEC)	// Ű ���� �ֱ� : 20 ��
#define	PULSE_SERVER_ALIVE			(2 * PULSE_REAL_MIN)	// ���� ���� ����̺� �޼��� Ÿ�� 
#define	PULSE_PCBANG_ITEM			(PULSE_REAL_HOUR)	// ��ϵ� PC�濡�� ������ ���� �ֱ�
#define PULSE_SAVECOUNT_NEW				5						// �������� ���� �÷��̾� �� ���� �ð�
#define PULSE_SAVEMAXCOUNT_NEW			2						// �������� �ִ� ���� �÷��̾� �� ���� �ð�


// t_connect_XXX ���� �ֱ�
#define PERIOD_SAVE_COUNT			5		// ���� ����ڼ� 5�а��� ����
#define PERIOD_SAVE_MAX				2		// �ִ� ������ 2�а��� ����

// Variables for the output buffering system
#define MAX_SOCK_BUF            (12 * 1024) // Size of kernel's sock buf

#define MAX_ID_NAME_LENGTH			32		// ���̵�, �̸� ����
#define MAX_PWD_LENGTH				32		// ��ȣ ����
#define HOST_LENGTH					30		// ȣ��Ʈ �ּ� ���ڿ� ����
#define MAX_CHAR_NAME_LENGTH		50		// �ɸ��� �̸� ����
#define MAX_GUILD_NAME_LENGTH		50		// ��� �̸� ����	
#define MAX_ITEM_NAME_LENGTH		50		// ������ �̸����� 
#define MAX_STASH_PASSWORD_LENGTH	8		// â�� ��ȣ ����
#define FRIEND_MAX_MEMBER			50		// ģ�� ��� ��
#define	FRIEND_GROUP_MAX_NUMBER		10		// �׷� ��
#define MAX_GROUP_NAME_LENGTH		20		// �׷� �̸� ���� 
#define BLOCK_MAX_MEMBER			20		// �ִ� �� �ο��� 
#define	MAX_GIFT_MESSAGE_LENGTH		100		// ���� �޼��� ���� 100����Ʈ



// �������� ����ϴ� ���ڹ迭, CServer�� Run������ ���!!!
#define MAX_STRING_LENGTH		8192

#define DFLT_IP		NULL;				// ���� ������ ����

// ���� ���� ���
#define CON_PLAYING						0		// ���� ��
#define CON_CLOSE						1		// ���� ����
#define CON_MOVESERVER					2		// ���� �̵���
#define CON_MOVESERVER_WAIT				3		// ���� �̵���
#define CON_MENU						10		// �޴������� ����
#define CON_DISCONNECT					17		// ������ ���� ����
#define CON_WAIT_USER_DB				19		// ĳ���� ������ ��ٸ�
#define CON_WAIT_NEW_CHAR_DB			20		// ĳ���� ���� ��ٸ�
#define CON_WAIT_DEL_CHAR_DB			21		// ĳ���� ���� ��ٸ�
#define CON_WAIT_PLAY_CHAR_DB			22		// ĳ���� �� ���� ��ٸ�
#define CON_WAIT_DEL_CANCEL_CHAR_DB		26		// ĳ���� ���� ���
#define CON_GET_LOGIN					23		// �α��� �õ�
#define CON_PREPARE_PLAY				25		// ���� ���� �����
#define CON_WAIT_IDEN_MSG				30		// ���� ��ٸ�
#define CON_GET_IDEN_MSG				31		// ���� ��û

#define STATE(d)			((d)->m_connected)
#define WAITTING_DB(d)		((d)->m_bwaitdb)
#define UPDATING_DB(d)		((d)->m_updatedb)
#define PLAYMODE(d)			((d)->m_playmode)

// �ű� ���� �ɸ���, �������� ����, �±��ϰ�� ����
//Ŀ���� class CUser�� m_userFlag
#define NOVICE		( 1 << 0 )
#define	RECV_GIFT	( 1 << 1 )
#define ADULT		( 1 << 2 )
#define IS_CHARACTER	( 1 << 3 )

/////////////////////////////////////////////////////////////////////////////
// ������ ����
#if defined (LC_KOR)
#include "Config_KOR.inh"
#elif defined (LC_TWN)
#include "Config_TWN.inh"
#elif defined (LC_CHN)
#include "Config_CHN.inh"
#elif defined (LC_TLD)
#include "Config_TLD.inh"
#elif defined (LC_JPN)
#include "Config_JPN.inh"
#elif defined (LC_MAL)
#include "Config_MAL.inh"
#elif defined (LC_USA)
#include "Config_USA.inh"
#elif defined (LC_BRZ)
#include "Config_BRZ.inh"
#else
#include "Config_KOR.inh"
#endif
// ---- ������ ����
/////////////////////////////////////////////////////////////////////////////

// LC_TIME
#define	LCHOUR  150							// ���ǽð� 2�� 30��
#define	LCDAY	(LCHOUR * 24)					// 24�ð� 1��
#define	LCMON	(LCDAY * 30)					// �Ѵ� 30��
#define	LCYEAR	(LCMON * 12)					// 1�� 12��

#ifdef LC_TIME
#define OUTPUTDAY LCDAY
#else
#define OUTPUTDAY (60 * 60 * 24 )
#endif

// ��ų����Ʈ
#define MAX_SKILLPOINT		2000000000


// ������ ���
#define JOBCOUNT			6
#define JOB_TITAN			0
#define JOB_KNIGHT			1
#define JOB_HEALER			2
#define JOB_MAGE			3
#define JOB_ROGUE			4
#define JOB_SORCERER		5
#define JOB_PET				6


#define JOB2COUNT			12
#define JOB_2ND_HIGHLANDER		1		// ���̷���
#define	JOB_2ND_WARMASTER		2		// ��������
#define JOB_2ND_ROYALKNIGHT		1		// �ο�����Ʈ
#define	JOB_2ND_TEMPLEKNIGHT	2		// ���ó���Ʈ
#define JOB_2ND_ARCHER			1		// ��ó
#define	JOB_2ND_CLERIC			2		// Ŭ����
#define JOB_2ND_WIZARD			1		// ���ڵ�
#define	JOB_2ND_WITCH			2		// ��ġ
#define JOB_2ND_ASSASSIN		1		// �ӽ��
#define	JOB_2ND_RANGER			2		// ������
#define JOB_2ND_ELEMENTALLIST	1		// ������Ż ����Ʈ
#define JOB_2ND_SPECIALLIST		2		// ����� ����Ʈ

#define JOB_2ND_PET_HORSE			0	// ��
#define JOB_2ND_PET_DRAGON			1	// ��
#define JOB_2ND_PET_HORSE_MOUNT		2	// �� : Ż��
#define JOB_2ND_PET_DRAGON_MOUNT	3	// �� : Ż��


#define JOB_2ND_LEVEL			31		// ���� ����


// �� ��� ����
#define HAIR_TITAN			3
#define HAIR_KNIGHT			3
#define HAIR_HEALER			3
#define HAIR_MAGE			3
#define HAIR_ROGUE			3
#define HAIR_SORCERER		3


// �Ӹ� ��� ����
#define FACE_TITAN			3
#define FACE_KNIGHT			3
#define FACE_HEALER			3
#define FACE_MAGE			3
#define FACE_ROGUE			3
#define FACE_SORCERER		3


// �����ͺ��̽� ���� ����
#define DB_NOP					0		// DB No Operation...
#define DB_UPDATE				1		// Request DB Update...
#define DB_WAIT_SAVE			10		// Save Delay...
#define DB_END					11		// ���� ������ �α׾ƿ� �Ϸ� 



// ���� �α��� ����
#define	MAX_CHAR_COUNT			6		// �ִ� ���� ���� ĳ���� ��
#define MAX_SKILL				60		// ĳ���� �� �ִ� ��ų ����
#define MAX_ASSIST_HELP			12		// ���� ȿ�� : �̷ο� ��
#define MAX_ASSIST_CURSE		8		// ���� ȿ�� : �طο� ��
#define MAX_ASSIST_ABS			10		// ���� �ð� ����ȿ��
#define MAX_EXT_CHAR_COUNT		2		// ������������� �߰� �Ҽ� �ִ� ���Լ�


///////
// ��Ÿ
#define NO_CELL				(-100)		// ���� ���� �ȵ� ����
#define EPSILON				(1.0e-5f)	// Tolerance for FLOATs
#define CELL_SIZE			12.0f		// �� ���� attr ���� (m ����)
#define CELL_EXT			4			// ������ ��ġ�� �� ����
#define MULTIPLE_HEIGHTMAP	100.0f		// ���̸� �������� ��ġ
#define MAX_PLAYER_LIST		8192		// �ִ� ���� ������ ��

#ifdef FEEITEM
#define MAX_MEMPOS					15			// ��� ��� ��
#define MAX_MEMPOS_NORMAL			5			// ��� ��� ��
#else
#define MAX_MEMPOS					5			// ��� ��� ��
#define MAX_MEMPOS_NORMAL			5			// ��� ��� ��
#endif



///////////////////
// NPC ����

#define		MAX_NPC_SKILL			2
#define		MAX_NPC_DROPITEM		20
#define		MAX_NPC_PRODUCT			5
#define		MAX_NPC_DROPITEM_LOOP	4

// NPC FLAG --
#define		NPC_SHOPPER				(1 << 0)	// �������ο���?
#define		NPC_FIRSTATTACK			(1 << 1)	// ��������?
#define		NPC_ATTACK				(1 << 2)	// �ݰݰ���?
#define		NPC_MOVING				(1 << 3)	// �̵�����?
#define		NPC_PEACEFUL			(1 << 4)	// ��ȭ���� ��(��Ŭ������ ���� �� ��ų��)
#define		NPC_ZONEMOVER			(1 << 5)	// �� �̵������ִ� NPC
#define		NPC_CASTLE_GUARD		(1 << 6)	// ��ȣ��
#define		NPC_REFINER				(1 << 7)	// ���ݼ��� NPC
#define		NPC_QUEST				(1 << 8)	// Quest NPC
#define		NPC_CASTLE_TOWER		(1 << 9)	// ������ ��ȣ��
#define		NPC_MINERAL				(1 << 10)	// �̳׶�
#define		NPC_CROPS				(1 << 11)	// ���۹�
#define		NPC_ENERGY				(1 << 12)	// ������
#define		NPC_ETERNAL				(1 << 13)	// ����
#define		NPC_LORD_SYMBOL			(1 << 14)	// ������ ����
#define		NPC_REMISSION			(1 << 15)	// ���˺�
#define		NPC_EVENT				(1 << 16)	// �̺�Ʈ
#define		NPC_GUARD				(1 << 17)	// ���
#define		NPC_KEEPER				(1 << 18)	// â��
#define		NPC_GUILD				(1 << 19)	// ���
#define		NPC_MBOSS				(1 << 20)	// �غ���
#define		NPC_BOSS				(1 << 21)	// ����
#define		NPC_RESETSTAT			(1 << 22)	// ���� �ʱ�ȭ
#define		NPC_CHANGEWEAPON		(1 << 23)	// ���� ��ü
#define		NPC_WARCASTLE			(1 << 24)	// ���� NPC
#define		NPC_DISPLAY_MAP			(1 << 25)	// ������ ǥ�õǴ��� ����
#define		NPC_QUEST_COLLECT		(1 << 26)	// ���� ����Ʈ��
#define		NPC_PARTY				(1 << 27)	// ��Ƽ�� ǥ�ÿ� 
#define		NPC_RAID				(1 << 28)	// ���̵� ��

// NPC AI TYPE
#define		NPC_AI_NORMAL			0			// �Ϲ� NPC
#define		NPC_AI_TANKER			1			// �Ϲ� NPC
#define		NPC_AI_DAMAGEDEALER		2			// �Ϲ� NPC
#define		NPC_AI_HEALER			3			// �Ϲ� NPC


#define IS_NPC(ch)			(ch->m_type == MSG_CHAR_NPC)	// NPC �ΰ���?
#define TO_NPC(ch)			((ch == NULL) ? NULL : (IS_NPC(ch) ? (CNPC*)ch : (CNPC*)NULL))		// NPC�� ĳ����
#define IS_PC(ch)			(ch->m_type == MSG_CHAR_PC)		// PC �ΰ���?
#define TO_PC(ch)			((ch == NULL) ? NULL : (IS_PC(ch) ? (CPC*)ch : (CPC*)NULL))			// PC�� ĳ����
#ifdef ENABLE_PET
#define IS_PET(ch)			(ch->m_type == MSG_CHAR_PET)	// �ֿϵ����ΰ�?
#define TO_PET(ch)			((ch == NULL) ? NULL : (IS_PET(ch) ? (CPet*)ch : (CPet*)NULL))		// Pet�� ĳ����
#else
#define IS_PET(ch)			(false)
#define TO_PET(ch)			(NULL)
#endif
#define IS_ELEMENTAL(ch)	(ch->m_type == MSG_CHAR_ELEMENTAL)	// ��ȯ�� �ΰ�?
#define TO_ELEMENTAL(ch)	((ch == NULL) ? NULL : (IS_ELEMENTAL(ch) ? (CElemental*)ch : (CElemental*)NULL)) // ��ȯ���� ĳ����
#define GET_CHAR_TYPE(ch)	((char)(ch->m_type))
#define DEAD(ch)			(ch->m_hp <= 0)					// ĳ���� �׾�����?
#define IS_IN_CELL(ch)		(ch->m_cellX >= 0)				// ĳ���Ͱ� ���� ��ġ�� �ֳ���?

#define CMD_NUM 200						// �ִ� �޽��� ���� ��

#define GET_X(obj)			(obj->m_pos.m_x)
#define GET_Z(obj)			(obj->m_pos.m_z)
#define GET_H(obj)			((obj && obj->m_pArea) ? obj->m_pArea->GetHeight(GET_YLAYER(obj), GET_X(obj), GET_Z(obj)) : 0.0f)
#define GET_R(obj)			(obj->m_pos.m_r)
#define GET_YLAYER(obj)		(obj->m_pos.m_yLayer)


// �Ӽ��� ���
#define MAPATT_FIELD				0		// �̵�����
#define MAPATT_PEACEZONE			10		// �ǽ���
#define MAPATT_PRODUCT_PUBLIC		20		// ���� ���� �ü�
#define MAPATT_PRODUCT_PRIVATE		30		// ���� ���� �ü�
#define MAPATT_STAIR_UP				40		// ���� ���� ���
#define MAPATT_STAIR_DOWN			50		// �Ʒ��� ���� ���
#define MAPATT_WARZONE				60		// ���� ����
/////////////////////////////////////////////
// BANGWALL : 2005-07-18 ���� 11:24:48
// Comment : free pkzone
#define MAPATT_FREEPKZONE			70		// ���� ��������
#define MAPATT_BLOCK				255		// �̵� �Ұ�


///////////////////
// ������ ���� ���

// 050311 : bs : ���Ⱑ ����ϴ� ���ȿ� ���� ��� �߰�
#define USING_STR		0
#define USING_DEX		1
// --- 050311 : bs : ���Ⱑ ����ϴ� ���ȿ� ���� ��� �߰�
// ��ǰ Ÿ��
#define		CTYPE_CONSUME		0	// �Ҹ� ��ǰ
#define		CTYPE_TERM			1	// �Ⱓ ��ǰ
#define		CTYPE_POTION		2	// ����
#define		CTYPE_AVATA			3	// �ƹ�Ÿ
#define		CTYPE_WEAPON		4	// ����
#define		CTYPE_WEAR			5	// ����
#define		CTYPE_SET			6	// ��Ʈ ��ǰ
#define		CTYPE_PLATINUM			7	// �÷�Ƽ��, �����Ǹ� ��ǰ
// ��ǰ �÷��� 
#define		CATALOG_FLAG_NEW	 (1 << 0)	 // �Ż�ǰ
#define		CATALOG_FLAG_POP	 (1 << 1)	 // �α��ǰ
#define		CATALOG_FLAG_RESV1	 (1 << 3)	 // ���� �÷��� 
#define		CATALOG_FLAG_RESV2	 (1 << 4)	 // ���� �÷��� 
#define		CATALOG_FLAG_RESV3	 (1 << 5)	 // ���� �÷��� 
#define		CATALOG_FLAG_RESV4	 (1 << 7)	 // ���� �÷��� 
#define		CATALOG_FLAG_RESV5	 (1 << 8)	 // ���� �÷��� 
#define		CATALOG_FLAG_RESV6	 (1 << 9)	 // ���� �÷��� 
#define		CATALOG_FALG_TO_LIMIT(a, b) (b = 0 | (a >> 10)) 
#define		CATALOG_FALG_FROM_LIMIT(a, b) ( a = a | ( b << 10 ) )

#define		CATALOG_FLAG_MAX_LIMIT (2000000)

// Item Flag : �ֻ��� 1��Ʈ�� ��� �Ұ�!!!
// 6��Ʈ���� �ɸ�, ��, �Ϲ� ���ü��� ������, �÷�Ƽ�� ���ü��� �ٸ� �������� ������ ���
#define		PLATINUM_MAX_PLUS				127 
#define		FLAG_ITEM_PLATINUM_GET(a, b)	(b = a & PLATINUM_MAX_PLUS)
#define		FLAG_ITEM_PLATINUM_SET(a, b)	(a = ( (a &~ PLATINUM_MAX_PLUS) | b ))
#define		FLAG_ITEM_OPTION_ENABLE			(1 << 7)	// ������ �÷��׿� �ɼ��� ���� �� �ִ� ���¸� ����, Bit ����
#define		FLAG_ITEM_SEALED				(1 << 8)	// ������ ����
#define		FLAG_ITEM_SUPER_STONE_USED		(1 << 9)	// ���۰����� ���׷��̵� ����..//0627
#define		FLAG_ITEM_BOOSTER_ADDED			(1 << 10)	// �ν��� ���� ����
#define		FLAG_ITEM_SILVERBOOSTER_ADDED	(1 << 11)	// �ǹ��ν��� ���� ����
#define		FLAG_ITEM_GOLDBOOSTER_ADDED		(1 << 12)	// ���ν��� ���� ����
#define		FLAG_ITEM_PLATINUMBOOSTER_ADDED	(1 << 13)	// ���ν��� ���� ����
#define		FLAG_ITEM_COMPOSITION			(1 << 14)	// ������ �ռ� ����
#define		FLAG_ITEM_LENT					(1 << 15)	// �뿩�� ������

#define		FLAG_ITEM_RESERVED				(1 << 31)	// ����� �� ����ϸ� ���� �ȵ�!

// Item Proto flag
#define		ITEM_FLAG_COUNT		(1 << 0)	// �� �� �ִ� �������ΰ�
#define		ITEM_FLAG_DROP		(1 << 1)	// ���  ���� �������ΰ���
#define		ITEM_FLAG_UPGRADE	(1 << 2)	// ���׷��̵� ������ �������ΰ�
#define		ITEM_FLAG_EXCHANGE	(1 << 3)	// ��ȯ ���� �������ΰ���
#define		ITEM_FLAG_TRADE		(1 << 4)	// �Ÿ� ���� �������ΰ���
#define		ITEM_FLAG_BORKEN	(1 << 5)	// �ı� ���� �������ΰ���
#define		ITEM_FLAG_MADE		(1 << 6)	// ���� ���� �������ΰ���
#define		ITEM_FLAG_MIX		(1 << 7)	// ���� ������ : DB�� ����ȵ�
#define		ITEM_FLAG_CASH		(1 << 8)	// ���� ������
#define		ITEM_FLAG_LORD		(1 << 9)	// ���� ���� ������
#define		ITEM_FLAG_NO_STASH	(1 << 10)	// â�� ���� �Ұ��� ������
#define		ITEM_FLAG_CHANGE	(1 << 11)	// �ٸ� ������ ���������� ��ȯ ���� ����
#define		ITEM_FLAG_COMPOSITE	(1 << 12)	// ������ �ռ� ���� ����
#define		ITEM_FLAG_CASHMOON	(1 << 13)	// ĳ�� ������ �귿 ���� ���� 
#define		ITEM_FLAG_LENT		(1 << 14)	// �뿩�� ����
#define		ITEM_FLAG_RARE		(1 << 15)	// ���� ������

// ������ �з� TYPE
#define		ITYPE_WEAPON			0		// ����
#define		ITYPE_WEAR				1		// ��
#define		ITYPE_ONCE				2		// ��ȸ��
#define		ITYPE_SHOT				3		// źȯ
#define		ITYPE_ETC				4		// ��Ÿ
#define		ITYPE_ACCESSORY			5		// �Ǽ��縮
#define		ITYPE_POTION			6		// ����

// SUBTYPE : ����  --
#define		IWEAPON_NIGHT			0		// ��絵		����Ʈ
#define		IWEAPON_CROSSBOW		1		// ����			�α�
#define		IWEAPON_STAFF			2		// ������		������
#define		IWEAPON_BIGSWORD		3		// ���			Ÿ��ź
#define		IWEAPON_AXE				4		// ����			Ÿ��ź
#define		IWEAPON_SHORTSTAFF		5		// ��������		������
#define		IWEAPON_BOW				6		// Ȱ			����
#define		IWEAPON_SHORTGUM		7		// �ܰ�			�α�
#define		IWEAPON_MINING			8		// ä������		-
#define		IWEAPON_GATHERING		9		// ä������		-
#define		IWEAPON_CHARGE			10		// ��������		-
#define		IWEAPON_TWOSWORD		11		// �̵���		����Ʈ
#define		IWEAPON_WAND			12		// �ϵ�			����
#define		IWEAPON_SCYTHE			13		// ���̵�		�Ҽ���
#define		IWEAPON_POLEARM			14		// ����			�Ҽ���

// SUBTYPE : �� --
#define		IWEAR_HELMET			0		// �Ӹ�
#define		IWEAR_ARMOR				1		// ����
#define		IWEAR_PANTS				2		// ����
#define		IWEAR_GLOVE				3		// �尩
#define		IWEAR_SHOES				4		// �Ź�
#define		IWEAR_SHIELD			5		// ����

// SUBTYPE : ��ȸ�� --
#define		IONCE_WARP				0		// �̵�
#define		IONCE_PROCESS_DOC		1		// ���� ����
#define		IONCE_MAKE_TYPE_DOC		2		// ����� ���� ����
#define		IONCE_BOX				3		// ����
#define		IONCE_MAKE_POTION_DOC	4		// ���� ���� ����
#define		IONCE_CHANGE_DOC		5		// ���� �ֹ���
#define		IONCE_QUEST_SCROLL		6		// ����Ʈ ����
#define		IONCE_CASH				7		// ĳ�� ������
#define		IONCE_SUMMON			8		// ���� ��ȯ��
#define		IONCE_ETC				9		// ��Ÿ �ϵ��ڵ� ��ȸ�� ������

// IONCE_WARP : ����
#define		IONCE_WARP_RETURN		0		// Ư�� �� ��ȯ ��ġ
#define		IONCE_WARP_MEMPOS		1		// ���� ��ҷ� �̵�
#define		IONCE_WARP_MARGADUM_PVP	2		// �޶�ũ pvp �̵�
#define		IONCE_WARP_PARTYRECALL	3		// 060227 : bs : ��Ƽ����

// IONCE_BOX : ����
#define		IONCE_BOX_REMAKE		0		// ��Ȱ�ǻ���
#define		IONCE_BOX_ARCANE		1		// ����ǻ���
#define		IONCE_BOX_COLLECT_BUG	2		// ���� ä�� ����


// SUBTYPE : źȯ --
#define		ISHOT_ATKBULLET		0	// ���ú�
#define		ISHOT_MPBULLET		1	// ������
#define		ISHOT_ARROW			2	// ȭ��


// SUBTYPE : ��Ÿ --
#define		IETC_QUEST			0	// ����Ʈ��
#define		IETC_EVENT			1	// �̺�Ʈ��
#define		IETC_SKILLUP		2	// ��ų ���
#define		IETC_UPGRADE		3	// ����
#define		IETC_MATERIAL		4	// ���
#define		IETC_MONEY			5	// ��
#define		IETC_PRODUCT		6	// ����ǰ
#define		IETC_PROCESS		7	// ����ǰ
#define		IETC_OPTION			8	// �ɼ�
#define		IETC_SAMPLE			9	// �÷�
#define		IETC_TEXTURE		10	// �ؽ��� For Client
#define		IETC_MIX_TYPE1		11	// ��������1
#define		IETC_MIX_TYPE2		12	// ��������2
#define		IETC_MIX_TYPE3		13	// ��������3

// IETC_PROCESS ����1
#define		IETC_PROCESS_STONE			0	// ���� ����ǰ
#define		IETC_PROCESS_PLANT			1	// �Ĺ� ����ǰ
#define		IETC_PROCESS_ELEMENT		2	// ���� ����ǰ

// IETC_PROCESS ����2
#define		IETC_PROCESS_STONE_0		0	// ���� �� ����ǰ
#define		IETC_PROCESS_STONE_1		1	// ���� ���� ����ǰ
#define		IETC_PROCESS_STONE_2		2	// ���� ���� ����ǰ
#define		IETC_PROCESS_STONE_3		3	// ���� ��Ʈ ����ǰ
#define		IETC_PROCESS_STONE_4		4	// ���� ������ ����ǰ

#define		IONCE_PROCESS_PLANT_0		0	// ũ���� ����� ����ǰ
#define		IONCE_PROCESS_PLANT_1		1	// ũ���� �ٱ� ����ǰ
#define		IONCE_PROCESS_PLANT_2		2	// ũ���� �Ķ��� ����ǰ
#define		IONCE_PROCESS_PLANT_3		3	// ũ���� ���� ����ǰ
#define		IONCE_PROCESS_PLANT_4		4	// ũ���� �� ����ǰ

#define		IONCE_PROCESS_ELEMENT_0		0	// E��� ���� ����ǰ
#define		IONCE_PROCESS_ELEMENT_1		1	// D��� ���� ����ǰ
#define		IONCE_PROCESS_ELEMENT_2		2	// C��� ���� ����ǰ
#define		IONCE_PROCESS_ELEMENT_3		3	// B��� ���� ����ǰ
#define		IONCE_PROCESS_ELEMENT_4		4	// A��� ���� ����ǰ


// IETC_OPTION ����
#define		IETC_OPTION_TYPE_BLOOD	0	// ���� ��
#define		IETC_OPTION_TYPE_CLEAR	1	// ��ȭ��


// IETC_UPGRADE ����
#define		IETC_UPGRADE_GENERAL	0	// �Ϲ����ü�
#define		IETC_UPGRADE_SPECIAL	1	// ������ü�
#define		IETC_UPGRADE_SPECIAL_SUPER	2	// ���۰�����ü�//0627
#define		IETC_UPGRADE_BOOSTER	3	// �ν���
#define		IETC_UPGRADE_LUCKY		4	// ����� ��� ���ü�
#define		IETC_UPGRADE_PLATINUM	5	// �÷�Ƽ�� ���ü� 


// SUBTYPE : �Ǽ��縮
#define		IACCESSORY_CHARM		0	// ����
#define		IACCESSORY_MAGICSTONE	1	// ���ü�
#define		IACCESSORY_LIGHTSTONE	2	// ��¦�̴µ�
#define		IACCESSORY_EARING		3	// �Ͱ���
#define		IACCESSORY_RING			4	// ����
#define		IACCESSORY_NECKLACE		5	// �����
#define		IACCESSORY_PET			6	// �����

// SUBTYPE : ����
#define		IPOTION_STATE			0	// ����ġ��
#define		IPOTION_HP				1	// HPȸ��
#define		IPOTION_MP				2	// MPȸ��
#define		IPOTION_DUAL			3	// ���ȸ��
#define		IPOTION_STAT			4	// Stat���
#define		IPOTION_ETC				5	// ��Ÿ (�̵����)
#define		IPOTION_UP				6	// �������
#define		IPOTION_TEARS			7	// ����
#define		IPOTION_CRYSTAL			8	// ����

// IPOTION_TEARS ����
#define		IPOTION_TEARS_TYPE_SAFE		0	// ������ ����
#define		IPOTION_TEARS_TYPE_FORGIVE	1	// �뼭�� ����


#define MAX_INVENTORY_SIZE			100							// �� �� �ִ� ������ ����
#define ITEMS_PER_ROW				5							// �� �ٴ� �ִ� ������ ����
#define MAX_INVENTORY_ROWS			(MAX_INVENTORY_SIZE / ITEMS_PER_ROW)	// �ټ�
#define MAX_SERIAL_LENGTH			20							// �ø��� ��ȣ ����
#define MAX_ITEM_BUY				10							// �������� �ִ� �� �� �ִ� ������ ������ ��
#define MAX_ITEM_SELL				10							// ������ �ִ� �� �� �ִ� ������ ������ ��
#define	GROUND_ITEM_PULSE			(5 * PULSE_REAL_MIN)		// ���� ������ �������� �ð� 60s
#define	ITEM_PREPERENCE_PULSE		(30 * PULSE_REAL_SEC)		// ������ �켱�� ���� �ð� 10s

// ������ ���׷��̵� ����
#define	ITEM_UPGRADE_RESULT_PLUS		0		// +1
#define	ITEM_UPGRADE_RESULT_MINUS		1		// -1
#define	ITEM_UPGRADE_RESULT_NOCHANGE	2		// 0
#define	ITEM_UPGRADE_RESULT_BROKEN		3		// ����
#define	ITEM_UPGRADE_PLATINUM_RESULT_PLUS 4		// �÷�Ƽ�� �÷����� �߶���

#define ITEM_UPGRADE_PROB_PLUS_VALUE		12			// 12���� ���� �Ǵ� ��ġ
#define ITEM_UPGRADE_PROB_PLUS_PENALTY_LEV	200			// ���׷��̵� ��ġ�� �������� Ȯ��
#define ITEM_UPGRADE_PROB_PLUS_PENALTY_MAX	4000		// ���׷��̵� �ִ� �������� Ȯ�� (40%) -> �ּ� ���� Ȯ�� ������ ���� ��
#define	ITEM_UPGRADE_PROB_GENERAL_PLUS		5000		// �Ϲ� ���ü� Ȯ�� 50%
#define ITEM_UPGRADE_PROB_SPECIAL_NOCHANGE	2000		// ��� ���ü� ���� Ȯ�� 20% (1 ~ 20)
#define ITEM_UPGRADE_PROB_SPECIAL_BROKEN	2700		// ��� ���ü� �ı� Ȯ�� 7% (21 ~ 30)
#define ITEM_UPGRADE_PROB_SPECIAL_PLUS		7700		// ��� ���ü� ���� �ִ� Ȯ�� 50% (31 ~ 80)

#define ITEM_UPGRADE_PENALTY_BROKEN			3			// �����ų� -1 ���� ������ ����� �Ѱ�

#define ITEM_UPGRADE_GENERAL_MINLEVEL		1			// �Ϲ����ü� �ּ� 1���� ����
#define ITEM_UPGRADE_GENERAL_MAXLEVEL		80			// 60���� ����

#define ITEM_REFINE_RESULT_TWO				0			// ���� �Ϲ� ���ü� 2��
#define ITEM_REFINE_RESULT_ONE				1			// �� �Ϲ� ���ü� 1��
#define ITEM_REFINE_RESULT_SPECIAL			2			// ��� ���ü� 1��


// �κ� ��ġ ����
#define INVENTORY_NORMAL			0	// �Ϲ� ��
#define INVENTORY_QUEST				1	// ����Ʈ ��
#define INVENTORY_EVENT				2	// �̺�Ʈ ��

// ���� ����
#ifdef ENABLE_PET
#define MAX_WEARING					11	// ĳ���� �� �ִ� ���� ��� �� : ���� ���� ���� ���� ���� �尩 �Ź� �Ǽ�1 �Ǽ�2 �Ǽ�3 �ֿϵ���
#else
#define MAX_WEARING					10	// ĳ���� �� �ִ� ���� ��� �� : ���� ���� ���� ���� ���� �尩 �Ź� �Ǽ�1 �Ǽ�2 �Ǽ�3
#endif
#define WEARING_NONE				-1	// ���� ����
#define WEARING_SHOW_START			1	// �ܺη� ���̴� ���� ��� ���� �ε���
#define WEARING_SHOW_END			6	// �ܺη� ���̴� ���� ��� �� �ε���
#define WEARING_HELMET				0	// ���� ��� ����
#define WEARING_ARMOR_UP			1
#define WEARING_WEAPON				2
#define WEARING_ARMOR_DOWN			3
#define WEARING_SHIELD				4
#define WEARING_GLOVE				5
#define WEARING_BOOTS				6
#define WEARING_ACCESSORY1			7
#define WEARING_ACCESSORY2			8
#define WEARING_ACCESSORY3			9
#ifdef ENABLE_PET
#define WEARING_PET					10
#endif
#ifndef ENABLE_PET
// Ŭ���̾�Ʈ���� �Ǽ��縮 ��ġ ������ �ʰ� ������� ��� (����Ŭ�� --)
#define WEARING_ACCESSORY_ANYWHERE	(MAX_WEARING)
#endif

#define GET_INVENTORY(ch, tab) ((tab == INVENTORY_NORMAL) ? &ch->m_invenNormal \
							  : (tab == INVENTORY_QUEST) ? &ch->m_invenQuest \
							  : (tab == INVENTORY_EVENT) ? &ch->m_invenEvent : NULL)

#define GET_TAB(type, subtype) ( (type != ITYPE_ETC) ? INVENTORY_NORMAL : (subtype == IETC_QUEST) ? INVENTORY_QUEST : (subtype == IETC_EVENT) ? INVENTORY_EVENT : INVENTORY_NORMAL)


/////////////////
// ��ȯ ���� ���

#define		MAX_EXCHANGE_ITEMS		10		// �ִ� ��ȯ ����


//////////////////////////
// ���� ���� 

#define		HATE_DECREASE_UNIT		100						// HATE ���� ����
#define		HATE_FIRST_ATTACK		1500					// ������ HATE ��ġ�� 1/10000 ����
#define		NPC_DISABLE_TIME		(PULSE_REAL_SEC * 3)	// npc ���� �� �Ⱥ��̸鼭 �����̴� �ð� : 3 sec
#define		NPC_ACTIVITY_DELAY		10						// npc �ൿ ������ 10 : 1��
#define		MAX_PENALTY_EXP_LEVEL	(7.01f)					// �������� ���� �ִ� ���Ƽ ����ġ : 7����
#define		MAX_PENALTY_SP_LEVEL	10						// �������� ���� �ִ� ���Ƽ SP : 10����
#define		DOWN_LEVEL_EXP			10						// ���� ���� ���� ������� ����ġ �϶� ��ġ %
#define		DOWN_LEVEL_SP			10						// ���� ���� ���� ������� SP �϶� ��ġ %
#define		UP_LEVEL_SP				5						// ���� ���� ���� ������� SP ��� ��ġ %
#define		MONEY_DROP_PROB			8000					// pc -> npc npc������ �� ��� Ȯ��
#define		UNIT_CEHCK_BLOCK		0.5f					// ���� ���ݽ� �� üũ ���� : 0.5m
#define		NPC_ATTACK_DELETE_PULSE	(PULSE_REAL_MIN * 3)	// ��������Pulse �ش�ð����� ���ݾ����� �� ���ø���Ʈ���� ����


#define		ACCESSORY_USED_ATTACK		10			// ���� �� �Ǽ��縮 ������ 10 ����
#define		ACCESSORY_USED_DEFENSE		10			// ��� �� �Ǽ��縮 ������ 10 ����
#define		ACCESSORY_USED_DEATH		200			// ��� �� �Ǽ��縮 ������ 200 ����

// ����� ����ġ �г�Ƽ
#define		DEATH_PENALTY_EXP_1		((double)0.00)			// 1 ~ 10
#define		DEATH_PENALTY_EXP_2		((double)0.05)			// 11 ~ 20
#define		DEATH_PENALTY_EXP_3		((double)0.03)			// 21 ~ 35
#define		DEATH_PENALTY_EXP_4		((double)0.02)			// 36 ~

// ����� SP �г�Ƽ
#define		DEATH_PENALTY_SP_1		((double)0.00)			// 1 ~ 10
#define		DEATH_PENALTY_SP_2		((double)0.05)			// 11 ~ 20
#define		DEATH_PENALTY_SP_3		((double)0.03)			// 21 ~ 35
#define		DEATH_PENALTY_SP_4		((double)0.02)			// 36 ~


// ���� �÷���
#define		HITTYPE_MISS			(1 << 0)		// ȸ��
#define		HITTYPE_WEAK			(1 << 1)		// ���ϰ�
#define		HITTYPE_NORMAL			(1 << 2)		// ����
#define		HITTYPE_STRONG			(1 << 3)		// ���ϰ�
#define		HITTYPE_HARD			(1 << 4)		// �ſ� ���ϰ�
#define		HITTYPE_CRITICAL		(1 << 5)		// ũ��Ƽ��
#define		HITTYPE_DEADLY			(1 << 6)		// �׵��� ���ϰ�

#define		HITTYPE_MAX_PROB_MISS		5000		// �̽�
#define		HITTYPE_MAX_PROB_WEAK		3000		// ��ũ
#define		HITTYPE_MAX_PROB_STRONG		3000		// ��Ʈ��
#define		HITTYPE_MAX_PROB_HARD		2000		// �ϵ�
#define		HITTYPE_MAX_PROB_CRITICAL	1500		// ũ��
#define		HITTYPE_MAX_PROB_DEADLY		1000		// ���鸮



// �⺻ ���� �Ÿ�
#define		ATTACK_RANGE_TITAN				2.3f	// Ÿ��ź
#define		ATTACK_RANGE_KNIGHT				2.3f	// ����Ʈ
#define		ATTACK_RANGE_HEALER				20.0f	// ����
#define		ATTACK_RANGE_MAGE				15.0f	// ������
#define		ATTACK_RANGE_ROGUE_1			2.3f	// �α� : �ܰ�
#define		ATTACK_RANGE_ROGUE_2			15.0f	// �α� : ����
#define		ATTACK_RANGE_SORCERER			3.0f	// �Ҽ���
#define		ATTACK_RANGE_SORCERER_HELLOUND	15.0f	// �Ҽ��� : ���� : ����
#define		ATTACK_RANGE_SORCERER_ELENEN	3.0f	// �Ҽ��� : ���� : ������



///////////////////////////
// ��Ƽ ����

#define		MAX_PARTY_MEMBER		8			// �ִ� ��Ƽ �ο�
#define		PARTY_PLUS_EXP			10			// ��Ƽ ��ɽ� �߰� ����ġ : 10%
#define		PARTY_PLUS_SP			10			// ��Ƽ ��ɽ� �߰� SP : 10%
#define		PARTY_PLUS_EXP_COUNT	5			// ��Ƽ �ο��� ���� �߰� ����ġ : 5%
#define		PARTY_PLUS_SP_COUNT		5			// ��Ƽ �ο��� ���� �߰� SP : 5%

// ��Ƽ ����ġ ��н�
#define		PARTY_EXP_DAMAGE		60			// ������ ���� ����ġ
#define		PARTY_EXP_SAME			20			// ��Ƽ �յ� ����ġ
#define		PARTY_EXP_LEVEL			20			// ���� ���� ����ġ
// ��Ƽ SP ��н�
#define		PARTY_SP_DAMAGE			60			// ������ ���� SP
#define		PARTY_SP_SAME			20			// ��Ƽ �յ� SP
#define		PARTY_SP_LEVEL			20			// ���� ���� SP




/////////////////////////
// character ���� ����

#define		NPC_RECOVER_PULSE		(PULSE_REAL_SEC * 3)		// npc ���� ȸ�� : 3��
#define		PC_RECOVER_PULSE		(PULSE_REAL_SEC * 3)		// pc ���� ȸ�� : 3��

#define		ASSIST_TYPE_SKILL		0		// ���� ���� : ��ų
#define		ASSIST_TYPE_ITEM		1		// ���� ���� : ������

#define		PLAYER_STATE_SITDOWN		(1 << 0)	// �ɱ�/����
#define		PLAYER_STATE_MOVING			(1 << 1)	// �̵�/����
#define		PLAYER_STATE_WARP			(1 << 2)	// ��ȯ ��
#define		PLAYER_STATE_PKMODE			(1 << 3)	// PK ���
#define		PLAYER_STATE_PKMODEDELAY	(1 << 4)	// PK ��� ���� ������
#define		PLAYER_STATE_RAMODE			(1 << 5)	// ������� ���
#define		PLAYER_STATE_CHANGE			(1 << 6)	// ������
#define		PLAYER_STATE_BILLITEM		(1 << 7)	// ���������� ������
#define		PLAYER_STATE_CASHITEM		(1 << 8)	// ĳ�������� ������

#ifdef NEW_PK
#define		RAMODE_USE_PULSE			(3 * PULSE_REAL_MIN)	// ������� ���� �ð� 30s
#else
#define		RAMODE_USE_PULSE			(30 * PULSE_REAL_SEC)	// ������� ���� �ð� 30s
#endif
#define		RAMODE_DELAY_PULSE			(5 * PULSE_REAL_SEC)	// ������� ���� �˸� 5s
#define		RAMODE_MAX_TARGET			8			// ������� ���� �ִ� 8

#ifdef PKMODE_LIMIT_LEVEL
#else
#define		PKMODE_LIMIT_LEVEL			15			// ���� ���� PK ����
#endif

#define		PK_NAME_CHAOSLEGION			(-5)
#define		PK_NAME_NECROKNIGHT			(-4)
#define		PK_NAME_OUTLAW				(-3)
#define		PK_NAME_FEARCASTER			(-2)
#define		PK_NAME_MURDERER			(-1)
#define		PK_NAME_NORMAL				( 0)
#define		PK_NAME_AVENGER				(+1)
#define		PK_NAME_LIGHTPORTER			(+2)
#define		PK_NAME_GUARDIAN			(+3)
#define		PK_NAME_SAINTKNIGHT			(+4)
#define		PK_NAME_DIVINEPROTECTOR		(+5)


/////////////////////////
// Quick Slot ����

#define		QUICKSLOT_PAGE_NUM		3		// 3������
#define		QUICKSLOT_MAXSLOT		10		// 10�� ����â F1-F10
#define		QUICKSLOT_TYPE_EMPTY	-1		// ���� �����
#define		QUICKSLOT_TYPE_SKILL	0		// ��ųŸ��
#define		QUICKSLOT_TYPE_ACTION	1		// �׼�Ÿ��
#define		QUICKSLOT_TYPE_ITEM		2		// ������Ÿ��


///////////////////////
// �޼��� ������ ��ũ��
#define SEND_Q(msg, desc)		{ if (desc != NULL) (desc)->WriteToOutput(msg); }

// �޽��� ���� �˻�
#define IS_RUNNING_MSGR			(!gserver.m_brunmessenger && gserver.m_messenger && !gserver.m_messenger->m_bclosed)

// ���� ���� �˻�
#define IS_RUNNING_HELPER		(!gserver.m_brunhelper && gserver.m_helper && !gserver.m_helper->m_bclosed)


////////////////////////
// ������ ���� ���� ����
#define CONN_WAIT_IDEN			0			// ���� �ý��� ���� ���
#define CONN_PLAYING			1			// �÷�����
#define CONN_CHANGE_SERVER		2			// ���� �̵� ��

#define IS_RUNNING_CONN			(!gserver.m_brunconnector && gserver.m_connector && !gserver.m_connector->m_bclosed)

#define LOGIN_STATE_FAIL		-1
#define LOGIN_STATE_NOT			0
#define LOGIN_STATE_SUCCESS		1
#define LOGIN_STATE_NOPLAY		2


///////////////////////
// ����, ȸ�� ���� ���
#define		MIN_HITRATE		1000		// �ּ� ���� 10%
#define		MAX_HITRATE		9500		// �ִ� ���� 95%
#define		MIN_CRITICAL	500			// �ּ� ũ��Ƽ�� 5%
#define		MAX_CRITICAL	6600		// �ִ� ũ��Ƽ�� 66%


// ��Ÿ ����Ʈ Ÿ��
#define	EFFECT_ETC_LEVELUP		0	// ������ ����Ʈ
#define	EFFECT_ETC_GOZONE		1	// go_zone ����Ʈ


// �׼� ����
#define ACTION_GENERAL			0	// �Ϲ�
#define ACTION_SOCIAL			1	// �Ҽ�
#define ACTION_PARTY			2	// ��Ƽ
#define ACTION_GUILD			3	// ���
#define ACTION_PET				4	// ��


#define	AGT_SITDOWN				3	// �ɱ⼭��
#define	AGT_PKMODE				23	// PK ����
#define AGT_PET_SITDOWN			37	// �� �ɱ�


///////////////////////
// �� ��ȣ
#define ZONE_START						0		// ���� ����
#define ZONE_DUNGEON1					1		// ���� 1
#define ZONE_SINGLE_DUNGEON1			2		// �̱� ���� 1
#define ZONE_DUNGEON2					3		// ���� 2
#define ZONE_DRATAN						4		// �ʵ� 2 ���ź
#define ZONE_SINGLE_DUNGEON2			5		// �̱� ���� 2
#define	ZONE_SINGLE_DUNGEON_TUTORIAL	6		// �̱� ���� 1 Ʃ�丮����
#define	ZONE_MERAC						7		// �޶�ũ
#define	ZONE_GUILDROOM					8		// ����
#define	ZONE_DUNGEON3					9		// ���� 3
#define	ZONE_SINGLE_DUNGEON3			10		// �̱� ���� 3
#define	ZONE_SINGLE_DUNGEON4			11		// �̱� ���� 4
#define ZONE_DUNGEON4					12		// ���� 4: ���ź
#define ZONE_FREE_PK_DUNGEON			13		// PK ����
#define ZONE_OXQUIZROOM					14		// OX �����
#define ZONE_EGEHA						15		// ������


///////////////////////////////////////
// Quest ����

// ������ Ÿ��
#define		QTYPE_KIND_REPEAT				0		// �ݺ��� ����Ʈ
#define		QTYPE_KIND_COLLECTION			1		// ������ ����Ʈ
#define		QTYPE_KIND_DELIVERY				2		// ������ ����Ʈ
#define		QTYPE_KIND_DEFEAT				3		// ���� ����Ʈ(�̱۴���1)
#define		QTYPE_KIND_SAVE					4		// ���� ����Ʈ(�̱۴���2)
#define		QTYPE_KIND_MINING_EXPERIENCE	5		// ä�� ü�� ����Ʈ
#define		QTYPE_KIND_GATHERING_EXPERIENCE	6		// ä�� ü�� ����Ʈ
#define		QTYPE_KIND_CHARGE_EXPERIENCE	7		// ���� ü�� ����Ʈ
#define		QTYPE_KIND_PROCESS_EXPERIENCE	8		// ���� ü�� ����Ʈ
#define		QTYPE_KIND_MAKE_EXPERIENCE		9		// ���� ü�� ����Ʈ
#define		QTYPE_KIND_TUTORIAL				10		// Ʃ�丮�� ����Ʈ


// ���ະ Ÿ��
#define		QTYPE_REPEAT_ONCE			0		// 1ȸ�� ����Ʈ
#define		QTYPE_REPEAT_UNLIMITED		1		// ���� ����Ʈ


// ���� Ÿ��
#define		QSTART_NPC					0		// NPC�� ���� ����
#define		QSTART_ITEM					1		// �������� ���� ����
#define		QSTART_LEVEL				2		// ���� ���� ���� ����
#define		QSTART_AREA					3		// Ư�������� �����Ͽ� ����


// ����Ʈ ���� ����
#define		QCONDITION_NPC				0		// NPC
#define		QCONDITION_ITEM				1		// ������
#define		QCONDITION_ITEM_NORMAL		2		// ������(�Ϲ�)

// ����Ʈ ���� ����
#define		QPRIZE_ITEM					0		// ������
#define		QPRIZE_MONEY				1		// ����
#define		QPRIZE_EXP					2		// ����ġ
#define		QPRIZE_SP					3		// ��ų����Ʈ
#define		QPRIZE_SKILL				4		// ��ų
#define		QPRIZE_SSKILL				5		// Ư����ų

#define		QUEST_MAX_PC				16		// ĳ���� ��Ƽ ����Ʈ 10�� -> 16
#define		QUEST_MAX_NEED_ITEM			5		// ����Ʈ �� �ʿ������ �ִ� 5

#define		QUEST_MAX_CONDITION			3		// ����Ʈ �������� �ִ� 3
#define		QUEST_MAX_CONDITION_DATA	4		// ����Ʈ �������� �ϳ��� �ΰ� ����Ÿ �ִ� 4
#define		QUEST_MAX_ITEM_DROP_MONSTER	3		// ���� ����Ʈ : ������ ��� ���� �ִ� 3

#define		QUEST_MAX_PRIZE				5		// ����Ʈ ���� �ִ� 5

#define		QUEST_MAX_NPC				50		// npc �ϳ��� �ִ� ����Ʈ ���� �� 50
#define		QUEST_MAX_PC_COMPLETE		100		// pc�� �Ϸ��� 1ȸ�� ����Ʈ �ִ� �� 100

#ifdef QUEST_DATA_EXTEND
// ����Ʈ ���� ���
#define		QUEST_STATE_ALL				0		// ��ü ����Ʈ �˻���
#define		QUEST_STATE_INIT			1		// ����Ʈ �ʱ� ����
#define		QUEST_STATE_RUN				2		// ����Ʈ ���� ��
#define		QUEST_STATE_DONE			3		// ����Ʈ �Ϸ� ���� (���� �Ϸ�)
#define		QUEST_STATE_ABANDON			4		// ����Ʈ ���� ����
#endif // QUEST_DATA_EXTEND

#define		S2_TICKET_MOB_START			13		// �̱۴���2 ����� �ֱ� (���������) ������ ����
#define		S2_TICKET_MOB_END			27		// �̱۴���2 ����� �ֱ� (���������) ������ ��

#define		S2_TICKET_LEVEL_START		13		// �̱۴���2 ����� �ֱ� (������) pc���� ����
#define		S2_TICKET_LEVEL_END			27		// �̱۴���2 ����� �ֱ� (������) pc���� ��

#define		S2_TICKET_DROP_PROB			50		// �̱۴���2 ����� ��� Ȯ��

#define		S2_TICKET_QUEST_DONE		5		// 5ȸ ����Ʈ �Ϸ��ϸ� ����� ����



/////////////////////
// �̺�Ʈ ���� �����
// #define BETAEVENT						// Ŭ�� �̺�Ʈ


/////////////////////
// �ɼ� ���� �׸��
//
#define		OPTION_STR_UP				0		// �� ���
#define		OPTION_DEX_UP				1		// ��ø ���
#define		OPTION_INT_UP				2		// ���� ���
#define		OPTION_CON_UP				3		// ü�� ���
#define		OPTION_HP_UP				4		// ����� ���
#define		OPTION_MP_UP				5		// ���� ���

#define		OPTION_DAMAGE_UP			6		// ���� ���ݷ� ���
#define		OPTION_MELEE_DAMAGE_UP		7		// ���� �ٰŸ� ���ݷ� ���
#define		OPTION_RANGE_DAMAGE_UP		8		// ���� ���Ÿ� ���ݷ� ���
#define		OPTION_MELEE_HIT_UP			9		// ���� ���� ���߷� ���
#define		OPTION_RANGE_HIT_UP			10		// ���� ���Ÿ� ���߷� ���

#define		OPTION_DEFENSE_UP			11		// ���� ���� ���
#define		OPTION_MELEE_DEFENSE_UP		12		// ���� �ٰŸ� ���� ���
#define		OPTION_RANGE_DEFENSE_UP		13		// ���� ���Ÿ� ���� ���
#define		OPTION_MELEE_AVOID_UP		14		// ���� ���� ȸ���� ���
#define		OPTION_RANGE_AVOID_UP		15		// ���� ���Ÿ� ȸ���� ���

#define		OPTION_MAGIC_UP				16		// ���� ���ݷ� ���
#define		OPTION_MAGIC_HIT_UP			17		// ���� ���߷� ���
#define		OPTION_RESIST_UP			18		// ���� ���� ���
#define		OPTION_RESIST_AVOID_UP		19		// ���� ȸ���� ���

#define		OPTION_ALL_DAMAGE_UP		20		// ��ü ���ݷ� ��� (��������, ���ݹ���, ����)
#define		OPTION_ALL_HIT_UP			21		// ��ü ���߷� ��� (��������, ���ݹ���, ����)

#define		OPTION_ALL_DEFENSE_UP		22		// ��ü ���� ��� (��������, ���ݹ���, ����)
#define		OPTION_ALL_AVOID_UP			23		// ��ü ȸ���� ��� (��������, ���ݹ���, ����)

#define		OPTION_MP_STILL				24		// ���� ��ƿ
#define		OPTION_HP_STILL				25		// ����� ��ƿ

#define		OPTION_ATT_FIRE_UP			26		// ȭ�� �Ӽ� Ȯ�� ���
#define		OPTION_ATT_WATER_UP			27		// ���� �Ӽ� Ȯ�� ���
#define		OPTION_ATT_WIND_UP			28		// ��ǳ �Ӽ� Ȯ�� ���
#define		OPTION_ATT_EARTH_UP			29		// ���� �Ӽ� Ȯ�� ���
#define		OPTION_ALL_ATT_UP			30		// ��� �Ӽ� Ȯ�� ���

#define		OPTION_ATT_FIRE_DOWN		31		// ȭ�� �Ӽ� Ȯ�� ����
#define		OPTION_ATT_WATER_DOWN		32		// ���� �Ӽ� Ȯ�� ����
#define		OPTION_ATT_WIND_DOWN		33		// ��ǳ �Ӽ� Ȯ�� ����
#define		OPTION_ATT_EARTH_DOWN		34		// ���� �Ӽ� Ȯ�� ����
#define		OPTION_ALL_ATT_DOWN			35		// ��� �Ӽ� Ȯ�� ����

// ���� ���� �����ۿ� �ɼ�
#define		OPTION_MIX_STR				36		// ��
#define		OPTION_MIX_DEX				37		// ��ø
#define		OPTION_MIX_INT				38		// ����
#define		OPTION_MIX_CON				39		// ü��

#define		OPTION_MIX_ATTACK			40		// ����
#define		OPTION_MIX_MAGIC			41		// ����
#define		OPTION_MIX_DEFENSE			42		// ����
#define		OPTION_MIX_RESIST			43		// ����

#define		OPTION_MIX_STURN			44		// ����
#define		OPTION_MIX_BLOOD			45		// ����
#define		OPTION_MIX_MOVE				46		// ����
#define		OPTION_MIX_POISON			47		// ������
#define		OPTION_MIX_SLOW				48		// ���ο�
// -- ���� ���� �����ۿ� �ɼ�

#define		MAX_NUM_OPTION				49		// �ɼ� �� ����
#define		OPTION_VALUE_SHIFT			8		// 2byte ���� ���� 1Byte �ɼ� ��ȣ ������ 1Byte �ɼ� ����
#define		OPTION_MAX_LEVEL			7		// �ɼ� �ִ� ���� ���� 7

#define		MAX_ITEM_OPTION				5		// �����ۿ� �ٴ� �ִ� �ɼ�
#define		MAX_ACCESSORY_OPTION		5		// �Ǽ��縮�� ���� �� �ִ� �ִ� �ɼ� ��
#define		MAX_WEAPON_OPTION			5		// ���⿡ ���� �� �ִ� �ִ� �ɼ� ��
#define		MAX_ARMOR_OPTION			3		// ���� ���� �� �ִ� �ִ� �ɼ� ��
#define		MAX_ITEM_OPTION_DEL			3		// �ɼ��� ���� �� �ִ� �ɼ� ��


/////////////////
// ���� �ɼ� ����

// ���� ���
#define RARE_OPTION_GRADE_A			0
#define RARE_OPTION_GRADE_B			1
#define RARE_OPTION_GRADE_C			2
#define RARE_OPTION_GRADE_D			3
#define RARE_OPTION_GRADE_E			4

// ���� Ÿ��
#define RARE_OPTION_TYPE_WEAPON		0
#define RARE_OPTION_TYPE_ARMOR		1
#define RARE_OPTION_TYPE_ACCESSORY	2


/////////////////////////////
// Blood Point ����

#define		PC_BLOOD_POINT				5000	// �⺻ Blood Point
#define		ATTACK_BLOOD_POINT			15		// ���ݽ� ���� Blood Point
#define		DEFENSE_BLOOD_POINT			3		// ���� ���� Blood Point


///////////////////////////////
// ���� ���� �׸��
//
#define		MAX_PRODUCTS_FROM_NPC		5		// npc�� ����� ����ǰ �ִ� ��
#define		MAX_ACCEPTABLE				4		// npc �Ѹ����� ä�� ���� �ο�
#define		PER_DAMAGE_GET_PRODUCT		5		// 5 ������ ���� ����ǰ ���
#define		MAX_MAKE_ITEM_MATERIAL		10		// ������ ���۽� �ִ� ��� ��
#define		NPC_PRODUCE_DELETE_PULSE	(PULSE_REAL_SEC * 4)	// ���� ����Pulse �ش�ð����� ��������� �� ���ø���Ʈ���� ����

#define		MAX_ACCESSORY_MIX			3		// ��Ȱ�� ���ڿ� ���� ������ ��
#define		MAX_ARCANE_MIX				3		// ����� ���ڿ� ���� ������ ��

#define		ITEM_ARCANE_MATERIAL_UPGRADE		0	// ����� ���� ��� 0�� ���ü�
#define		ITEM_ARCANE_MATERIAL_ACCESSORY		1	// ����� ���� ��� 1�� �Ǽ��縮
#define		ITEM_ARCANE_MATERIAL_SAMPLE			2	// ����� ���� ��� 2�� �÷�

#define		MAKE_SAMPLE_ON_PROCESS_PROB		600		// ������ ������� ����� Ȯ�� 

#define		MAX_ITEM_MAKE_SUCCESS_PROB	8000	// ������ ���� �ִ� ������ 80%

#define		ETERNAL_PENALTY_PROB		30		// ������ �������� 20% ������
#define		PUBLIC_PENALTY_PROB			60		// �������� �������� 60% ������

#define		GetMakeProb(limitLevel, itemLevel) (limitLevel - itemLevel) * 250


/////////////////////////////
// Special Skill ����
//

// Special Skill Ÿ��
#define		SSKILL_MINING		0	// ä��
#define		SSKILL_GATHERING	1	// ä��
#define		SSKILL_CHARGE		2	// ����
#define		SSKILL_STONE		3	// �������ü�
#define		SSKILL_PLANT		4	// �Ĺ�������
#define		SSKILL_ELEMENT		5	// ����������

#define		SSKILL_MAKE_WEAPON	6	// ���� ���� ���
#define		SSKILL_MAKE_WEAR	7	// �� ���� ���
#define		SSKILL_MAKE_G_B		8	// �尩 ���� ���� ���
#define		SSKILL_MAKE_ARMOR	9	// ���� ���� ���� ���
#define		SSKILL_MAKE_H_S		10	// ���� ���� ���� ���


#define		SSKILL_MAX_LEVEL	5	// Special Skill �ִ� ����




//////////////////////////////////////
// ���� �ý��� ����
//

#ifdef TEST_SERVER

#define		TEACH_MAX_STUDENTS			8			// �ִ� �л� ��
#define		TEACH_LEVEL_TEACHER			18			// ���� ���� ����
#define		TEACH_LEVEL_STUDENT			4			// ���� ���� ����
#define		TEACH_LEVEL_SUCCESS			5			// ���� ���� ���� 
#define		TEACH_LIMIT_SEC				864000		// 10��
#define		TEACH_FAME_PRIZE			20			// ���� ��ġ
#define		TEACH_PRIZE_LEVEL			0			// 10000���� ���� ����

#else

#define		TEACH_MAX_STUDENTS			8			// �ִ� �л� ��
#define		TEACH_LEVEL_TEACHER			18			// ���� ���� ����
#define		TEACH_LEVEL_STUDENT			10			// ���� ���� ����
#define		TEACH_LEVEL_SUCCESS			20			// ���� ���� ���� 
#define		TEACH_LIMIT_SEC				864000		// 10��
#define		TEACH_FAME_PRIZE			10			// ���� ��ġ
#define		TEACH_PRIZE_LEVEL			9			// 10000���� ���� ����

#endif

#define		CANCELTEACHER				(1 << 0)	// ������ ����
#define		CANCELSTUDENT				(1 << 1)	// �л��� ����

///////////////
// �� ���� ���

#ifdef ENABLE_PET

#define PET_HORSE_QUEST_INDEX				106				// ������Ʈ �ε���
#define PET_DRAGON_QUEST_INDEX				109				// ������Ʈ �ε���
#define PET_BLUE_HORSE_QUEST_INDEX			145				// �Ķ� ������Ʈ �ε���
#define PET_PINK_DRAGON_QUEST_INDEX			146				// ��ũ ������Ʈ �ε���
#define PET_UNKOWN_HORSE_QUEST_INDEX		147				// �Ұ��縮 ������Ʈ �ε���
#define PET_UNKOWN_DRAGON_QUEST_INDEX		148				// �Ұ��縮 ������Ʈ �ε���

#define	PET_HORSE_EGG_INDEX				948				// �� �� �ε���
#define	PET_DRAGON_EGG_INDEX			949				// �� �� �ε���
#define	PET_BLUE_HORSE_EGG_INDEX		1707			// ��縻 �� �ε���
#define	PET_PINK_DRAGON_EGG_INDEX		1706			// ��ũ�� �� �ε���
#define	PET_UNKOWN_HORSE_EGG_INDEX		1709			// �Ұ����Ǹ� �� �ε���
#define	PET_UNKOWN_DRAGON_EGG_INDEX		1708			// �Ұ����ǿ� �� �ε���

#define PET_HORSE_ITEM_INDEX			871				// �� ������ �ε���
#define PET_DRAGON_ITEM_INDEX			872				// �� ������ �ε���
#define PET_BLUE_HORSE_ITEM_INDEX		1710			// �� ������ �ε���
#define PET_PINK_DRAGON_ITEM_INDEX		1711			// �� ������ �ε���
#define PET_UNKOWN_HORSE_ITEM_INDEX		1713			// �� ������ �ε���
#define PET_UNKOWN_DRAGON_ITEM_INDEX	1712			// �� ������ �ε���

#define PET_TYPE_HORSE					(0x10)		// ��
#define PET_TYPE_DRAGON					(0x20)		// ��
#define PET_TYPE_BLUE_HORSE				(0x30)		// �Ķ� ��
#define PET_TYPE_PINK_DRAGON			(0x40)		// ��ũ ��
#define PET_TYPE_UNKOWN_HORSE			(0x50)		// �Ұ����Ǹ�
#define PET_TYPE_UNKOWN_DRAGON			(0x60)		// �Ұ����ǿ�

#define PET_GRADE_CHILD		(0X01)		// �����
#define PET_GRADE_ADULT		(0X02)		// ������
#define PET_GRADE_MOUNT		(0X03)		// Ż��

#define PET_TYPE_MASK		(0xf0)		// Ÿ�� ����ũ
#define PET_GRADE_MASK		(0x0f)		// ��� ����ũ

#define PET_DEFAULT_HUNGRY		50		// ���� ����� ��ġ
#define PET_DEFAULT_SYMPATHY	50		// ���� ������ ��ġ
#define PET_DEFAULT_RUNSPEED	15.0f	// �⺻ �޸��� �ӵ�
#define PET_MAX_HUNGRY			100		// �ִ� ����� ��ġ
#define PET_MAX_SYMPATHY		100		// �ִ� ������
#define PET_MAX_HP				100		// �ִ� HP
#define PET_ADULT_LEVEL			16		// ������ ���� ����
#define PET_MOUNT_LEVEL			31		// Ż�� ���� ����

#define PET_MAX_LEVEL			60		// �� �ְ� ���� 60

#endif // #ifdef ENABLE_PET

///////////////////
// ��ȯ�� ���� ���

#define ELEMENTAL_FIRE			0		// ���� ����
#define ELEMENTAL_WIND			1		// �ٶ��� ����
#define ELEMENTAL_EARTH			2		// ������ ����
#define ELEMENTAL_WATER			3		// ���� ����

#define ELEMENTAL_ATTACK_SPEED	20		// �⺻ ����
#define ELEMENTAL_RUN_SPEED		8.0f	// �⺻ �̼�
#define ELEMENTAL_RECOVER_HP	1		// 3�ʿ� ��ȯ�� ü�� ȸ����

#define ELEMENTAL_ATTACK_RANGE_FIRE		2.0f	// ���ݰŸ� : ��������
#define ELEMENTAL_ATTACK_RANGE_WIND		7.0f	// ���ݰŸ� : �ٶ�������
#define ELEMENTAL_ATTACK_RANGE_EARTH	3.0f	// ���ݰŸ� : ����������
#define ELEMENTAL_ATTACK_RANGE_WATER	7.0f	// ���ݰŸ� : ��������

#ifdef BSTEST
#define SUMMON_DELAY			(PULSE_REAL_MIN * 0)	// ��ȯ ������
#else
#define SUMMON_DELAY			(PULSE_REAL_MIN * 5)	// ��ȯ ������
#endif // #ifdef BSTEST
#define SUMMON_DURATION			(PULSE_REAL_MIN * 7)	// ��ȯ ���ӽð�


/////////////////
// ���� ���� ���
#define EVOCATION_NONE			0		// ���� ����
#define EVOCATION_HELLOUND		1		// ���� ����
#define EVOCATION_ELENEN		2		// ������ ����

#ifdef BSTEST
#define EVOCATION_DELAY			(PULSE_REAL_MIN * 0)	// ���� ������
#else
#define EVOCATION_DELAY			(PULSE_REAL_MIN * 5)	// ���� ������
#endif // #ifdef BSTEST
#define EVOCATION_DURATION		(PULSE_REAL_MIN * 10)	// ���� ���ӽð�

////////////////////////////////////
// Event ����

////////////////////
// Latto Event ����
#define		LATTO_EVENT_UPGRADE_PROB		3000		// 10%
#define		LATTO_EVENT_BLOOD_PROB			3000		// 10%
#define		LATTO_EVENT_PARTY_PROB			5000		// 50%
#define		LATTO_EVENT_PROCESS_PROB		3000		// 30%
#define		LATTO_EVENT_EXPSP_PROB			3000		// 30%

#define		LATTO_EVENT_EXPSP_LEVEL			15			// 15 ����
#define		LATTO_EVENT_EXP_PERCENT			30			// ���� : 30%
#define		LATTO_EVENT_PARTY_LEVEL_MIN		5			// 5 ����
#define		LATTO_EVENT_PARTY_LEVEL_MAX		15			// 15 ����


#define		CHANGE_26LEVEL_GENERAL_STONE_PROB	800			// 26���� �Ϲ� ���ü� ���� Ȯ��
#define		CHANGE_SPECIAL_STONE_PROB			900			// ������ü� ���� Ȯ��
#define		CHANGE_22LEVEL_EVENT_WEAPON_PROB	1000		// 22���� �̺�Ʈ ���� (������) ���� Ȯ��
#define		CHANGE_31LEVEL_ARMOR_PROB			1100		// 31���� �� ���� (������) ���� Ȯ��
#define		CHANGE_ATTACK_UP_PROB				5300		// ���ݷ� ����� ���� Ȯ��
#define		CHANGE_DEFENSE_UP_PROB				9500		// ���� ����� ���� Ȯ��
#define		CAHNGE_50000NAS_PROB				10000		// 5�� ���� ���� Ȯ��


///////////////////////
// New Year Evnet ����
#define		NEWYEAR_EVENT_RICESOUP_DROP_PROB	1000	// 10%
#define		NEWYEAR_EVENT_RICEMANDO_DROP_PROB	1000	// 10%
#define		NEWYEAR_EVENT_RICESOUP_UP_EXP		12		// 120%
#define		NEWYEAR_EVENT_RICEMANDO_UP_SP		13		// 130%

#define CLIENT_OPTION_EFFECT	( 1 << 0 ) 
#define CLIENT_OPTION_WARP		( 1 << 1 ) 

#define GOLDENBALL_STATUS_NOTHING		0
#define GOLDENBALL_STATUS_VOTE			1
#define GOLDENBALL_STATUS_GIFT			2
#define GOLDENBALL_STATUS_VOTE_END		3
#define GOLDENBALL_TEAM_NAME_LENGTH		32
#define GOLDENBALL_BALL_INDEX			1482
#define GOLDENBALL_CARD_INDEX			1483


// t_cashItemdate �ʵ��
#define CASH_ITEM_DATE_FIELD_MEMPOS			"a_mempos_new"
#define CASH_ITEM_DATE_FIELD_CHAR_SLOT0		"a_charslot0_new"
#define CASH_ITEM_DATE_FIELD_CHAR_SLOT1		"a_charslot1_new"
#define CASH_ITEM_DATE_FIELD_STASHEXT		"a_stashext_new"


#endif