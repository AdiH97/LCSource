#ifndef __MSG_TYPE_H__
#define __MSG_TYPE_H__

// ���� 2��Ʈ�� ���� ����� ���� �������� ������ 0
// ���� 6��Ʈ�� �Ʒ��� �޽��� Ÿ������
// �޽��� �߰��ÿ��� ���ʿ� �߰�
// ������ Ÿ��
//		unsigned	u
//		char		c
//		int			n
//		long		l
//		short		s
//		LONGLONG	ll
//		float		f
//		double		d
//		string		str
typedef enum _tagSummonNpcType {SUMMON_NPC_TYPE_MERCENARY, SUMMON_NPC_TYPE_TOTEM, SUMMON_NPC_TYPE_BOMB_1, SUMMON_NPC_TYPE_BOMB_2, SUMMON_NPC_TYPE_BOMB_3};
typedef enum __tagMessageType
{
	MSG_UNKNOWN		= 0,		// unknown

	// ���� �޽���
	MSG_FAIL,					// ���� �߻� �˸�	: errcode(uc)
	MSG_DB,						// DB ����			: errcode(uc) ...


	// LOGIN ����
	MSG_LOGIN,					// LOGIN			: version(n) mode(uc) id(str) pw(str) nation(c) seed(n)
	MSG_MENU,					// MENU ȭ��		: mode(uc) ...
	MSG_START_GAME,				// ���� ����		:


	// ĳ���� ����
	MSG_STATUS,					// ĳ���� ����		: level(n) exp(ll) need_exp(ll) hp(n) maxhp(n) mp(n) maxmp(n) str(n) dex(n) int(n) con(n) opstr(n) opdex(n) opint(n) opcon(n) attack(n) magic(n) defense(n) resist(n) skillpoint(n) weight(n) maxweight(n) walkspeed(f) runspeed(f) attackspeed(c) magicspeed(c) pktitle(c) pkpenalty(n) pkcount(n) fame(n) attackrange(f) join_flag_merac(c) skillspeed(n) attrmap(uc) mountPet(c) evocationType(c) evocationRemain(n)

	MSG_APPEAR,					// ��Ÿ��			: PC : isNew(uc) type(c) index(n) name(str) job(c) job2(c) hairstyle(c) facestyle(c) x(f) z(f) h(f) r(f) yLayer(n) hp(n) maxHP(n) state(c) pkstate(c) pktitle(c) pluseffect(c) [wear_item_index(n) wear_item_plus(n)]:6 assist_state(n) assist_count(c) [itemidx(n) index(n) level(c) remain(n)]:count shoptype(c) shopname(str) guildindex(n) guildname(str) guildposition(n) mobindex(n) map_attr(uc) join_flag_merac(c) mountPet(c) evocationType(c) issupporter(c)
								//					: NPC: isNew(uc) type(c) index(n) vnum(n) x(f) z(f) h(f) r(f) yLayer(n) hp(n) maxHP(n) assist_state(n) assist_count(c) [itemidx(n) index(n) level(c) remain(n)]:count map_attr(uc)
								//					: Pet: isNew(uc) type(c) index(n) owner_index(n) owner_name(str) petTypeGrade(c) x(f) z(f) h(f) r(f) yLayer(n) hp(n) maxHP(n) map_attr(uc)
								//					: ��ȯ��: isNew(uc) type(c) index(n) elemental_type(c) owner_index(n) owner_name(str) x(f) z(f) h(f) r(f) yLayer(n) hp(n) maxHP(n) assist_state(n) assist_count(c) [itemidx(n) index(n) level(c) remain(n)]:count map_attr(uc) isbigsize(c)
	MSG_DISAPPEAR,				// �����			: type(c) index(n)
	MSG_AT,						// ��ġ ����		: index(n) name(str) job(c) job2(c) hair(c) face(c) zoneNo(n) areaNo(n) x(f) z(f) h(f) r(f) yLayer(n) userindex(n) guildoutdate(n) pluseffect(c) map_attr(uc)

	// 10
	MSG_INVENTORY,				// �κ��丮 ����	: resultArrange(c) tab_idx(c) row_idx(c) [item_idx(n) item_type(n) wear_pos(c) plus(n) flag(n) used(n) used_2(n) count(ll) option_count(c) {(option_type(c) option_level(c)} * option_count] * 5
								// ��ĭ�� item_idx�� -1�̰� ���Ĵ� ����, resultArrange ��Ʈ �ʵ�(0��Ʈ-����, 1��Ʈ-��)
								// used_2(n) �� COMPOSITE_TIME ���ø�
	MSG_WEARING,				// ���� ���� ����	: char_index(n) wear_pos(c) item_db_index(n) item_plus(n)

	// ĳ���� ���
	MSG_MOVE,					// �̵�				: chartype(c) movetype(uc) index(n) speed(f) x(f) z(f) h(f) r(f) y(n) map_attr(uc)

	// ���� ����
	MSG_ATTACK,					// ����				: attackchartype(c) attackcharindex(n) targetchartype(c) targetindex(n) attackType(c) multicount(c) multiindex(n:multicount)
	MSG_DAMAGE,					// ������ ����		: attackchartype(c) attackcharindex(n) attackerattacktype(c) targetcount(n) [targetchartypc(c) targetindex(n) hp(n) mp(n) damage(n) flag(c)] * targetcount �ݺ�

	// ä��
	MSG_CHAT,					// ä��				: chat_type(c) sender_index(n) sender_name(str) receiver_name(str) chat(str)

	// ������
	MSG_ITEM,					// ������ ����		: sub_type(uc) ...

	// �ý��� �޽���
	MSG_SYS,					// �ý��� �޽���	: sub_type(uc) ...

	// ���̵�
	MSG_GO_ZONE,				// ���̵�			: zone_no(n) extra(n) ip(str) port(n)
	MSG_GOTO,					// ���� ���� �̵�	: zone_no(n) x(f) z(f) h(f) r(f) y(n)

	// 20
	// ��ȯ
	MSG_EXCHANGE,				// ��ȯ ����		: sub_type(uc) ...

	// ��� ��� ����
	MSG_MEMPOS,					// ��� ��� ����	: sub_type(uc) ...

	// ȯ�� ����
	MSG_ENV,					// ȯ�� ����		: sub_type(uc) ...

	// ��� ��� ����
	MSG_GM,						// ��� ��� ����	: sub_type(uc) ...

	// ��Ƽ ����
	MSG_PARTY,					// ��Ƽ ����		: sub_type(uc) ...

	// Quick Slot ����
	MSG_QUICKSLOT,				// ������ ����		: sub_type(uc) ...

	// �̱۴��� NPC ����
	MSG_NPC_REGEN,				// NPC ���� ����	: index(n) dbIndex(n) x(f) z(f) h(f) r(f) yLayer(int) entityindex(n)

	// ��ų �޽���
	MSG_SKILL,					// ��ų ����		: subtype(uc) ...

	// ����/���� ���� �޽���
	MSG_ASSIST,					// ���� ���� �޽���	: subtype(uc) ...

	// PC ���� �޽���
	MSG_CHAR_STATUS,			// PC ���� �޽���	: chartype(c) inedx(n) hp(n) maxHP(n) mp(n) maxMP(n) pkstate(c) pktitle(c) state(n) state2(n)

	// 30
	// ĳ���� ��Ȱ �޽���
	MSG_PC_REBIRTH,				// pc ��Ȱ �޽���	:

	// ����Ʈ �޽���
	MSG_EFFECT,					// ����Ʈ �޽���	: subtype(uc) ...

	// EXP, SP �޽���
	MSG_EXP_SP,					// EXP,SP ȹ��		: exp(n) sp(n)

	// �׼�
	MSG_ACTION,					// �׼� ���		: charindex(n) type(c) action(n) state(c),
								//						targetcharindex(n) -> #ifdef EVENT_TLD_2007_SONGKRAN �϶��� ����

	// �α伭��
	MSG_LOGINSERV_PLAYER,		// ����ڼ� ����	: recentserver(n) recentsubnum(n) count(n) seqNo(n) serverno(n) subservercount(n) isrecommendserver(c) [subnum(n) playernum(n) ip_addr(str) portno(n)]... subservercount��ŭ �ݺ�

	// ����Ʈ
	MSG_QUEST,					// ����Ʈ ����		: subtype(uc) ...

	// ���� ����Ʈ ���
	MSG_STATPOINT,				// ��������Ʈ ���	: subtype(uc) ...

	// ���� �̵� ����
	MSG_WARP,					// �����̵� ����	: subtype(uc) ...

	// �޽� �˻� ����
	MSG_PULSE,					// �޽� ����		: pulse(n), nationalindex(c), tickDelayTime(f)

	// ������ ����
	MSG_RANDOM_PRODUCE,			// ������ ����		: npcindex(n)

	// 40
	// Special Skill ����
	MSG_SSKILL,					// Ư����ų ����	: subtype(uc) .....

	// PK ����
	MSG_PK,						// PK ����			: subtype(uc) ...

	// ��� ����
	MSG_GUILD,					// ��� ����		: subtype(uc) ...

	// �̺�Ʈ ����
	MSG_EVENT,					// �̺�Ʈ ����		: subtype(uc) ...

	// ���λ���
	MSG_PERSONALSHOP,			// ���� ����		: subtype(uc) ...

	// �������
	MSG_RIGHT_ATTACK,			// �������			: subtype(uc) target_type(c) target_index(n) 

	// â��
	MSG_STASH,					// â��				: subtype(uc) ...

	// ����
	MSG_CHANGE,					// ����				: subtype(uc) ...

	// �������̽� �ɼ�
	MSG_UI,						// UI �ɼǰ���		: subtype(uc) ...

	// ���� �ý���
	MSG_TEACH,					// ����				: subtype(uc) ...

	// 50
	// ��������
	MSG_CHANGEJOB,				// ���� ����		: subtype(uc) ...

	MSG_FRIEND,					//�޽��� ����.

	// �۽��� ������ ��Ƽ ���� �� ����(NPC)
	MSG_PD_ATTACK,				//����				: targetchartype(c) targetindex(n) attackType(c) multicount(c) multiindex(n:multicount) 
	MSG_PD_MOVE,				//����				: movetype(uc) speed(f) multicount(c) multiindex(n:multicount) x(f) z(f) h(f) r(f) y(n)

	// ���� ����
	MSG_SELECT_PRODUCE,			// ���� ����		: npc_server_index(n) itemdbindex(n)

	// ���� �޽����� ���� �޽����� ���� Ÿ������
	MSG_EXTEND,					// �޽��� Ȯ��		: exmsg(n) ...
								// do_Extend���� Movefirst�� exmsg�� �����Ƿ� ����Ÿ�� ó�� ��ƾ������ MoveFirst�� �ϸ� �ȵ�

	MSG_BILLINFO = 60,			// ���� ����		: SUBTYPE(UC) ...	
	MSG_TRADEAGENT,				// �ŷ� ����
	MSG_EXPEDITION,				// ������ 
	MSG_LOGOUT,					// �α׾ƿ� 
	MSG_FACTORY,				// ���� �ý���
	
	// -- �������

	// �޽���
	MSG_MSGR_CONNECT = 100,		// �޽��� ����		: version(n) server_num(n) subnum(n) count_zone(n) ( zone_num(n) * count_zone )
	MSG_MSGR_REQ,				// �޽��� ��û		: seq(n) server(n) subnum(n) zone(n) subtype(uc) ,,,
	MSG_MSGR_REP,				// �޽��� ����		: seq(n) server(n) subnum(n) zone(n) subtype(uc) ...

	// 60
	// ������
	MSG_CONN_CONNECT = 110,		// ������ ����		: version(n) server_no(n) subnum(n) server_ip(str) portno(n) count_zone(n) ( zone_num(n) * count_zone )
	MSG_CONN_REQ,				// ������ ��û		: subtype(uc) ...
	MSG_CONN_REP,				// ������ ����		: subtype(uc) ...

	// ����
	MSG_HELPER_CONNECT = 120,	// ���� ����		: version(n) server_no(n) subnum(n) server_ip(str) portno(n) count_zone(n) ( zone_num(n) * count_zone )
	MSG_HELPER_REQ,				// ���� ��û		: seq(n) server(n) subnum(n) zone(n) subtype(uc) ,,,
	MSG_HELPER_REP,				// ���� ����		: seq(n) server(n) subnum(n) zone(n) subtype(uc) ...
	MSG_HELPER_COMMAND,			// ���� ���		: subtype(n) ...

	MSG_GM_CHAT,				// GMTOOL ä��

} MESSAGETYPE;


// MSG_EXTEND
typedef enum __tagMsgExtendType
{
	MSG_EX_PET_STATUS,			// �ֿϵ��� ����	: index(n) petTypeGrade(c) level(n) exp(ll) needexp(ll) hp(n) maxhp(n) ability(n) hungry(n) maxhugry(n) sympathy(n) maxsympathy(n) x(f) z(f) h(f) r(f) y(n) mapatt(uc) remainRebirth(n)
								// Ŭ���̾�Ʈ ����Ʈ�� �ش� ���� ������ �߰� ������ ������Ʈ �ϵ��� �� ��
	MSG_EX_PET_CALL,			// �ֿϵչ� ȣ��	: index(n)
								// Client->Server
	MSG_EX_PET_MOUNT,			// �ֿϵ����� Ÿ��	: owner_index(n) mountPetTypeGrade(c)
								// Server->Client
	MSG_EX_PET_LEARN,			// �� ����			: skillindex(n) level(c:server) errorcode(n:server)
	MSG_EX_PET_SKILLLIST,		// �� ��ų ����Ʈ	: index(n) count(n) [skillindex(n) skilllevel(c)] ...
	MSG_EX_PET_RESET_SKILL,		// �� ��ų �ʱ�ȭ
	MSG_EX_PET_SELL_INFO,		// �� ��ȯ/�Ǹ� ����: ownerindex(n) petindex(n) petTypeGrade(c) level(n) exp(ll) needexp(ll) hp(n) maxhp(n) ability(n) hungry(n) maxhugry(n) sympathy(n) maxsympathy(n) remainRebirth(n)
	MSG_EX_PET_CHANGE_MOUNT,	// �� Ÿ�� ����		: errorcode(n:server)
	
	MSG_EX_NAMECHANGE,			// �̸� ����c->s	: item_idx(n) name(str)
								//			s->c	: errorcode(c) name(str) bguild(c)
	MSG_EX_CASHITEM,			// ������ ����		: subtype(uc) ...
	MSG_EX_PET_COMMAND,			// 10 �� �米����		: pet_index(n) command_skill_index(n) targettype(c) targetindex(n)
	MSG_EX_PET_MIX_ITEM,		// �� �̾��� ����	: 
								// Client->Server	: itemdbindex(n), method(n)
								// Server->Client	: errcode(n)
	MSG_EX_FRIENDNAMECHANGE,	// �̸����濡 ���� �޽��� �̸� ���� s->c : charindex(n) name(str)
	MSG_EX_PET_LEVELUP,			// �� ������		: petindex(n) typegrade(c) level(n)
	MSG_EX_PET_WARPTOWN,		// ������ ��ȯ		: 

	MSG_EX_CASTLE_MAP_RECENT,	// ������ �ֱ� ����	: lord_x(f) lord_z(f) lord_hp(n) lord_maxhp(n) tower_count(n) [tower_dbindex(n) tower_x(f) tower_z(f) tower_hp(n) tower_maxhp(n)]*count regen_x(f) regen_z(f) signal_sender_flag(n) signal_sender_index(n) signal_x(f) signal_z(f)
								// Ŭ���̾�Ʈ���� �������� �޽��� Ÿ�Ը�
								// sender_flag �� MSG_GUILD_POSITION_TYPE
	MSG_EX_CASTLE_MAP_SIGNAL,	// ������ �ñ׳�	: x(f) z(f) sender_flag(n:server) sender_index(n:server)

	MSG_EX_ELEMENTAL_STATUS,	// ��ȯ�� ����		: index(n) elementaltype(c) remain(n) hp(n) maxhp(n) attackspeed(c) magicspeed(c) skillspeed(n) walkspeed(f) runspeed(f) attackrange(f) x(f) z(f) h(f) r(f) ylayer(c) mapattr(uc) assist_state(n) assist_count(c) [itemidx(n) index(n) level(c) remain(n)]:count
	MSG_EX_ELEMENTAL_DELETE,	// ��ȯ�� ����		: index(n)

	MSG_EX_EVOCATION_START,		// ���� ����		: charindex(n) type(c)
	MSG_EX_EVOCATION_STOP,		// 20 ���� ��			: charindex(n)

	MSG_EX_GUILDMEMBERNAMECHANGE,// �̸����濡 ���� ��������� �̸� ���� s->c : charindex(n) name(str)

	MSG_EX_KEYCHANGE,			// ��ȣŰ ����		: key(unsigned int)

	MSG_EX_PET_CHANGE_ITEM,		// �� ������ ��ȯ	: errorcode(n:server)

	MSG_EX_PET_REBIRTH,			// �� ���� ����		: pet_index(n) errcode(n:server)

	MSG_EX_PARTY_RECALL,		// ��Ƽ ����		: subtype(n) ...

	MSG_EX_PARTY_MATCH,			// ��Ƽ ��Ī		: subtype(n) ...

	MSG_EX_STRING,				// Ŭ���̾�Ʈ �޼������ : outputtype(uc) stringIndex(n) argcount(n) argtype(n) arg
								// GS->C�� ���Ҷ��� : 
	MSG_EX_MESSENGER,			// �޽��� �߰� ��� : subtype(c)

	MSG_EX_HAIR_CHANGE,			// ��� ���� �޽��� : charindex(n) hairstyle(c)

	MSG_EX_PLAYER_STATE_CHANGE,	// 30 �÷��̾� ���� ���� : charindex(n) state(n)
	MSG_EX_PLAYER_REALIP,			// User real IP ���� : user_ip(s)

	MSG_EX_MEMPOSPLUS,			// �����̾� �޸� �� : sub_type(uc) ...									

	MSG_EX_NPROTECT,			// NPROTECT ���� �޽��� : gg_auth_index(n) gg_auth_val1(n) gg_auth_val2(n) gg_auth_val3(n)

	MSG_EX_PET_CHANGE_NAME,		// �� �̸� ���� : pet_index(n), name(str)
	MSG_EX_PET_CHANGE_COLOR,		// �� ����  ���� : pet_index(n), color( c );

	MSG_EX_GO_ZONE,				// �� �̵���� �߰� ��� : subtype(c) ...
	
	MSG_EX_CASTLE_WAR,			// ���ź ���� : subtype(uc) ...

	MSG_EX_SECURE_CARD,			// ȫ�� ���� ī�� : gs->cl s1(c), s2(c), s3(c), s4(c)   cl->gs s1(c), s2(c), s3(c), s4(c)
	
	MSG_EX_DVD,					// ���� ���� ����: subtype(uc) ...

	MSG_EX_ALTERNATE_MERCHANT,	// 40 �븮 ���� : subtype( uc ) ....

	MSG_EX_PET_TURNTO_NPC,		// �� NPC ���� (n)nPetIndex , (n)toNPC, (n)nOwnerIndex

	MSG_EX_MONSTERCOMBO,			// ���� �޺�

	MSG_EX_RESTART,				// Connector �� �ӽ� �н����� �����, �α׾ƿ� ��� 15�ʸ� ������ Ŭ���� ��Ʈ�� Connection����
	
	MSG_EX_CHAOSBALL,			// ī���� �� ��ȯ : row(n), col(n)

	MSG_EX_UPDATE_PLAYTIME,		// Client���� 10�� �������� PLAYTME ���� ��û

	MSG_EX_ATTACK_PET,			// attack pet ���� (c)subtype

	MSG_EX_EXTREME_CUBE,		// �ͽ�Ʈ�� ť��

	MSG_EX_INIT_SSKILL,			// Ư����ų�ʱ�ȭ

	MSG_EX_DISCONNECT_HACK_CHARACTER,	// �� ���� ���� : 

	MSG_EX_TRIGER_EVENT,		// Ʈ���� �̺�Ʈ �ý���

	//new by Falo
	MSG_EX_AFFINITY,			// ����

	MSG_EX_TUTORIAL,			// Ʃ�丮�� �ý���
	
	MSG_EX_LOADING_END,			// �ε��� �����κ��� �޴� �޽����� ���� �����ϴ� �κ�.	

	MSG_EX_RAID_INFO,			// �ͼӵ� �� ���� ǥ��

	MSG_EX_NPC_PORTAL_SCROLL,		// connie [2009/9/8] - NPC ã�� 
	
	MSG_EX_LUCKYDRAW_BOX,

	MSG_EX_TITLE_SYSTEM,			// ȣĪ

	MSG_EX_TAKE_AGAIN_QUEST_ITEM,	// [100208: selo] ����Ʈ ������ �ٽ� �ޱ�
	
	MSG_EX_LACARETTE,				// [100324 : sora] ��ī�� �ý���

	MSG_EX_COSTUME2,				// [100421 : kiny8216]�ڽ�Ƭ2 �ý���
	
	MSG_EX_DUNGEONTIME,				// ���� Ÿ��

	MSG_EX_SOCKET,					// socket system. [4/8/2010 rumist]
	
	MSG_EX_ATTENDANCE_EXP_SYSTEM,	// �⼮ �ý��� : �����⼮�ϼ�������ġREQ : (c)subtype 0:Ȯ��, 1:��������ޱ�/ REP (c) subtype 0:��������1:Ȯ��2:�⼮�Ϸ�3:����d������(n)accCount ������, (c)upExp �߰�����ġ

	MSG_EX_XTRAP,
	
	MSG_EX_TUTORIAL_RENEWER_2010,	// Ʃ�丮�� ����
	
	MSG_EX_RAID_SCENE,				// ��ĭ��� ���̵�

	MSG_EX_SUBJOB,					// [2010/08/25 : Sora] ADD_SUBJOB ��������(����ĳ��)

	// new:
	MSG_EX_LORDCOSTUME,

	MSG_EX_MONSTERMERCENARYCARD, // 69

	MSG_EX_FACEOFF, // 70

	MSG_EX_71, // 71

	MSG_EX_MSGBOX, // 72

	MSG_EX_LACABALL, // 73

	MSG_EX_ROYAL_RUMBLE, // 74

	MSG_EX_75, // 75  cash shop zeug?

	MSG_EX_76, // 76

	MSG_EX_RANKINGLIST, // 77

	MSG_EX_78, // 78

	MSG_EX_79, // 79

	MSG_EX_80, // 80

	MSG_EX_81, // 81

	MSG_EX_82, // 82

	MSG_EX_83, // 83

	MSG_EX_84, // 84

	MSG_EX_85, // 85

	MSG_EX_86, // 86

	MSG_EX_FGC, // 87

	MSG_EX_88, // 88

	MSG_EX_89, // 89

	MSG_EX_REFORM, // 90 Anvil
} MSG_EXTEND_TYPE;

typedef enum __tagMsgExTrigerEventType
{
	MSG_EX_TRIGER_EVENT_ERROR,					// ����	
	MSG_EX_TRIGER_EVENT_ALREADY_PLAY,			// �̹� ���� ��
	MSG_EX_TRIGER_EVENT_DONT_ENOUGH_CONDITION,			// ������ ������ �ȵ�
	MSG_EX_TRIGER_EVENT_ITEM_COMPOSITION,		// ������ ����
	MSG_EX_TRIGER_EVENT_ITEM_DROP,				// ������ ���
	MSG_EX_TRIGER_EVENT_OPEN_THE_DOOR,			// �� ����
	MSG_EX_TRIGER_EVENT_START_RAID,				// ���̵� ����
	MSG_EX_TRIGER_EVENT_MESSAGE_PRINT,			// ���� �޼��� ���
	MSG_EX_TRIGER_EVENT_SUMMON_NPC,				// npc ��ȯ
	MSG_EX_TRIGER_EVENT_USE_DEBUF,				// ����� �ɸ�
	MSG_EX_TRIGER_EVENT_ACTIVE_OBJECT,			// object Ȱ��ȭ
	MSG_EX_TRIGER_EVENT_REMOVE_NPC,				// npc �ڵ� ����
}MSG_EX_TRIGER_EVENT_TYPE;

typedef enum __tagMsgExInitSSkillErrorType
{
 MSG_EX_INIT_SSkill_ERROR_SUCCESS, // ����
 MSG_EX_INIT_SSkill_ERROR_FAIL,  // ����
} MSG_EX_INIT_SSkill_ERROR_TYPE;

typedef enum _tagMsgExExtremeCubeType
{
	MSG_EX_EXTREME_CUBE_PARTY,		// ��Ƽť�� ��ü�����
	MSG_EX_EXTREME_CUBE_PARTY_PERSON,	// ��Ƽť�� ���������
	MSG_EX_EXTREME_CUBE_GUILD,		// ���ť�� ��ü�����
	MSG_EX_EXTREME_CUBE_GUILD_PERSON,	// ���ť�� ���������
	MSG_EX_EXTREME_CUBE_STATE_REQ,		// ť����Ȳ â ȣ���
	MSG_EX_EXTREME_CUBE_STATE_REP,		// cubemaster(s), master_guildname(s), 
										// count(c), rank(c), guildname(s), guildmaster(s), cubepoint(n)
	MSG_EX_EXTREME_CUBE_COMPLETE,		// �Ϸ�ī��Ʈ count(c)
	MSG_EX_EXTREME_CUBE_ERROR,		// errortype
	MSG_EX_EXTREME_CUBE_STATE_PERSONAL_REQ,   // ť�� ��������Ʈ Ȯ�ν�
	MSG_EX_EXTREME_CUBE_STATE_PERSONAL_REP,   // 
}MSG_EX_EXTREME_CUBE_TYPE;


typedef enum _tagMsgExExtremeCubeErrorType
{
	MSG_EX_EXTREME_CUBE_ERROR_NOITEM,  // �������� ����
	MSG_EX_EXTREME_CUBE_ERROR_OVERCOUNT,  // ������������ ����
	MSG_EX_EXTREME_CUBE_ERROR_CANNOT_MOVE,  // �̵��Ұ�
	MSG_EX_EXTREME_CUBE_ERROR_CANNOT_CAHNGE_RATE, // ��������Ұ�
	MSG_EX_EXTREME_CUBE_ERROR_NOT_GUILD_CUBE_TIME, // ���ť��ð��ƴ�
	MSG_EX_EXTREME_CUBE_ERROR_NOT_PARTY_CUBE_TIME, // ��Ƽť��ð��ƴ�
	MSG_EX_EXTREME_CUBE_ERROR_PARTYCUBE,   // ��Ƽť�� ��
	MSG_EX_EXTREME_CUBE_ERROR_GUILDCUBE,   // ���ť�� ��
	MSG_EX_EXTREME_CUBE_ERROR_START_NOTICE,
	MSG_EX_EXTREME_CUBE_ERROR_END_NOTICE,
	MSG_EX_EXTREME_CUBE_ERROR_START_REMAINTIME,
	MSG_EX_EXTREME_CUBE_ERROR_END_REMAINTIME,
}MSG_EX_EXTREME_CUBE_ERROR_TYPE;


typedef enum __tagMsgExAttackPetErrorType
{
	MSG_SUB_STAT,				// CAHR STATE MSG 
	MSG_SUB_ITEM_WEAR,			// ������ �Ա� ���� ����
	MSG_SUB_ITEM_WEARING,		// ���� ��� ��ȭ �˸���
	MSG_SUB_REBIRTH,			// ��Ȱ ��û
	MSG_SUB_SKILLLIST,			// ��ų����Ʈ ��û
	MSG_SUB_SKILLLEAN,			// ��ų ����
	MSG_SUB_STATUP,				// ���� �ø���
	MSG_SUB_LEVELUP,			// ���� �� �˸���
	MSG_SUB_DELETE_EQUIP,		// ������ ���� ��� ����
	MSG_SUB_APET_INFO,			// �� ����
	MSG_SUB_ADDITEM_MSG,		// �� ����â�� ���� ITEM ����

	MSG_SUB_AI_LIST_REQ,		// AI ����Ʈ ��û
	MSG_SUB_AI_LIST_NTF,		// AI ����Ʈ ����		: count(n), ( ai_index(n), item_index(n), skill_index(n) )*n
	MSG_SUB_AI_ONOFF_REQ,		// AI Ȱ��ȭ ����       : enable(c)
	MSG_SUB_AI_ONOFF_REP,
	MSG_SUB_AI_UPDATE_REQ,		// AI ���� ��û			: count(n), ( ai_index(n), item_index(n), skill_index(n) )*n
	MSG_SUB_AI_UPDATE_REP,		// AI ���� ����         : errcode(uc), ai_index(n), item_index(n)
} MSG_EX_ATTACK_PET_ERRORTYPE;

typedef enum _tagMsgAPetErrorType
{
	MSG_APET_ERROR_OK,
	MSG_APET_ERROR,
	MSG_APET_ERR_NOT_HAVE_ITEM,		// ���� ���� ���� ������ : ai_index(n)
	MSG_APET_ERR_WRONG_AI			// �߸��� AI ���� : ai_index(n)
}MSG_APET_ERROR_TYPE;

typedef enum __tagMsgExChaosBallErrorType
{
	ERROR_CHAOSBALL_SUCCESS,				// ī���� �� ������ ����
	ERROR_ITEM_COUNT,						// ������ ���� ����
	ERROR_NOSPACE,							// �κ��丮�� �� ������ ����.
	ERROR_ITEM_FAULT						// ī���� �� ������ ����
} MSG_EX_CHAOSBALL_ERRORTYPE;

typedef enum __tagMsgExMonsterComboType
{
	MSG_EX_MONSTERCOMBO_EDIT_COMPLETE,			// �̼����̽� �����Ϸ�� count(c), index(n)
	MSG_EX_MONSTERCOMBO_EDIT_CANCEL,			// ��ҽ�
	MSG_EX_MONSTERCOMBO_EDIT_CONTEXT_REQ,		// ������ ���뺸���û
	MSG_EX_MONSTERCOMBO_EDIT_CONTEXT_REP,		// ������ ���뺸������ count(c), index(n)
	MSG_EX_MONSTERCOMBO_GOTO_COMBO,			// �����Ϸ��� �������� �� ��
	MSG_EX_MONSTERCOMBO_GOTO_COMBO_PROMPT,		// Ȯ�θ޽���
	MSG_EX_MONSTERCOMBO_GOTO_COMBO_CONFIRM,		// ��Ƽ���� Ȯ��, ��ҹ�ư ������ �� yesno(c): (yes 1 no 0),  bossindex(n)
	MSG_EX_MONSTERCOMBO_RECALL_TO_COMBO,		// ���濡�� ��Ƽ������ ��
	MSG_EX_MONSTERCOMBO_RECALL_TO_STAGE,		// ���������� ��������
	MSG_EX_MONSTERCOMBO_GIVEUP,			// ���� �޺� ����			zone(n), extra(n), npcidx(n)
	MSG_EX_MONSTERCOMBO_START,				// ���� �޺� ����
	MSG_EX_MONSTERCOMBO_MISSION_COMPLETE,		// nextstage(n), complete(c) 0: �̼ǽ���, 1: �̼Ǽ���
	MSG_EX_MONSTERCOMBO_GOTO_STAGE,			// ���濡�� ����������
	MSG_EX_MONSTERCOMBO_GOTO_WAITROOM,			// ������������ �������� ��
	MSG_EX_MONSTERCOMBO_NOTICE_STAGE,		// stage(n) ���۽� stage �ѹ��޽��� ����
	MSG_EX_MONSTERCOMBO_ERROR,				// ���� �޺� �������� error(c)
}MSG_EX_MONSTERCOMBO_TYPE;

 
typedef enum __tagMsgExMonserComboErrorType
{
	MSG_EX_MONSTERCOMBO_ERROR_EDIT_COMPLETE_OK,	// �����Ϸ�
	MSG_EX_MONSTERCOMBO_ERROR_EDIT_COMPLETE_FAIL,	// �����Ϸ� ����
	MSG_EX_MONSTERCOMBO_ERROR_MONEY,			// ��������
	MSG_EX_MONSTERCOMBO_ERROR_FULL,			// �޺��� ������ ���� ���
	MSG_EX_MONSTERCOMBO_ERROR_NOT_EDIT,		// �����Ϸᰡ �ȵ�
	MSG_EX_MONSTERCOMBO_ERROR_NOT_COMPLETE_STAGE,	// �������� �Ϸ���� �ʾ���
}MSG_EX_MONSTERCOMBO_ERROR_TYPE;


typedef enum __tagMsgExAlternateMerchant
{
	MSG_ALTERNATEMERCHANT_ERROR,						// ���λ��� ���� ����		: errorcode(uc)
	MSG_ALTERNATEMERCHANT_CHANGE,					// ���� ���� ��ȭ(����)		: charindex(n) shoptype(c)
	MSG_ALTERNATEMERCHANT_SELL_START,				// �ǸŽ���					: charindex(n) shoptype(c) shopname(str) [normal_count(c) normal_item(v:normal_count) pack_price(ll) pack_count(c) pack_item(v:pack_count)]:client
												// normal_item				: row(c) col(c) item_idx(n) item_db_idx(n) count(ll) price(ll)
												// pack_item				: row(c) col(c) item_idx(n) item_db_idx(n) count(ll)
	MSG_ALTERNATEMERCHANT_SELL_LIST,					// �ǸŸ���Ʈ ��û			: charindex(n) [ shoptype(c) normal_count(c) normal_item(v:normal_count) pack_price(ll) pack_count(c) pack_item(v:pack_count)]:server
												// normal_item				: item_idx(n) item_db_idx(n) plus(n) flag(n) option_count(c) ([option_type(c) option_level(c)]:option_count) count(ll) price(ll)
												// pack_item				: item_idx(n) item_db_idx(n) plus(n) flag(n) option_count(c) ([option_type(c) option_level(c)]:option_count) count(ll)
	MSG_ALTERNATEMERCHANT_BUY,						// ���ſ�û					: charindex(n) pack_buy(c) normal_count(c) ([normal_item_index(n) normal_item_count(ll)]:normal_count)
	
	MSG_ALTERNATEMERCHANT_END,					// �ǸŻ� ����
	MSG_ALTERNATEMERCHANT_PRODUCT_RECOVERY,		// ��ǰ ȸ�� :  
	MSG_ALTERNATEMERCHANT_PRODUCT_NAS,			// ���� ȸ�� :

}MSG_EX_ALTERNATE_MERCHANT_TYPE;

typedef enum __tagMsgExAlternateMerchatErrorType
{
	MSG_ALTERNATEMERCHANT_ERROR_OK,					// ����
	MSG_ALTERNATEMERCHANT_ERROR_INSUFF_SKILL,		// ��û ĳ���Ͱ� ��ų ��� ���϶�
	MSG_ALTERNATEMERCHANT_ERROR_INSUFF_WARP,		// ��û ĳ���Ͱ� ����(�̵���ġ) ���϶�
	MSG_ALTERNATEMERCHANT_ERROR_INSUFF_EXCHANGE,	// ��û ĳ���Ͱ� ��ȯ ���϶�
	MSG_ALTERNATEMERCHANT_ERROR_INSUFF_MONEY,		// ������ ���λ������� �ŷ��ϰ��� �Ҷ�
	MSG_ALTERNATEMERCHANT_ERROR_INSUFF_ETC,			// �׿� ������ ���� ���� ����(��Ŷ������� ��)
	MSG_ALTERNATEMERCHANT_ERROR_AREA,				// ���� ���� �Ұ��� �����϶�
	MSG_ALTERNATEMERCHANT_ERROR_DUPLICATION,			// �ϳ��� �������� ���� �� ����Ϸ� �� ��
	MSG_ALTERNATEMERCHANT_ERROR_NOTFOUND,			// ��� ĳ���Ͱ� ���� ��
	MSG_ALTERNATEMERCHANT_ERROR_NOTSELL,				// ��� ĳ���Ͱ� �Ǹ� ������ �ƴ� ��
	MSG_ALTERNATEMERCHANT_ERROR_NOTPACKAGE,			// ��� ĳ���Ͱ� ��Ű�� �ǸŰ� �ƴ� ��
	MSG_ALTERNATEMERCHANT_ERROR_MONEY,				// ������ ����
	MSG_ALTERNATEMERCHANT_ERROR_COUNT,				// ��� ���λ������� ��û �Ǹ�/���� ī��Ʈ�� Ŭ��
	MSG_ALTERNATEMERCHANT_ERROR_CANTPREMIUM,			// ������ �������� ��Ű�� ���� ���� �Ұ�
	MSG_ALTERNATEMERCHANT_ERROR_BUY_FULLINVENTORY,	// �κ��丮 �������� �� ��
	MSG_ALTERNATEMERCHANT_ERROR_ANYMORE_PET,			// �� ���� ������ �Ѿ ���
	MSG_ALTERNATEMERCHANT_ERROR_NOSPACE,				// �κ��� �������� �Ǹ� �Ұ� : �� ���� ���� ������ ����
	MSG_ALTERNATEMERCHANT_ERROR_NOCOLLECT_ITEM,			// ȸ�� �ȵ� �������� ����
	MSG_ALTERNATEMERCHANT_ERROR_TIMEOVER,				// �ð� ����
	MSG_ALTERNATEMERCHANT_ERROR_INSUFF_ALREADY,			// ���� NPC�� ������
	MSG_ALTERNATEMERCHANT_ERROR_HELPER_SERVER,			// ���� ���� ����
	MSG_ALTERNATEMERCHANT_ERROR_NOTITEM,				// ������ ����
	MSG_ALTERNATEMERCHANT_ERROR_WEIGHT_OVER,						// ���� �ʰ��� ã�� �� ����
	
}MSG_EX_ALTERNATE_MERCHANT_ERROR_TYPE;


typedef enum __tagMsgExCastleWarType
{
	MSG_CASTLE_CRISTAL_RESPOND_START,	// ���� ����	charindex(n), starttime(ll)	
	MSG_CASTLE_CRISTAL_RESPOND_END,		// ���� �Ϸ�	charindex(n)
	MSG_CASTLE_CRISTAL_RESPOND_FAIL,	// ���� ����	charindex(n)
	MSG_CASTLE_TOWER_CONTRAL,			// ������ Ÿ�� Ÿ�� ����		7*control(c)
	MSG_CASTLE_TOWER_CONTRAL_LIST,		// ����Ʈ Ÿ�� ���� ����Ʈ		7*control(c)
	MSG_CASTLE_TOWER_REINFORCE,			// ������ Ÿ�� ��ȭ ����		type(c), step(c)
	MSG_CASTLE_TOWER_REINFORCE_LIST,	// ������ Ÿ�� ��ȭ ����Ʈ		cl->gs type(C) | gs->cl type(c), step(c)
	MSG_CASTLE_TOWER_REPAIRE,			// ���� Ÿ�� ����				cl->gs idx(n) | gs->cl	idx(n)
	MSG_CASTLE_TOWER_REPAIRE_LIST,		// ���� Ÿ�� ���� ����			cl->gs idx(n) | gs->cl	money(n)
	MSG_CASTLE_TOWER_WARP_LIST,			// ���� ���� Ÿ�� ��ȿ ����Ʈ   cl->gs idx(n) | gs->cl  cnt(c) * idx(n)	
	MSG_CASTLE_QUARTERS_INSTALL,		// ��Ȱ���� ��ġ				cl->gs idx(n) | gs->cl  idx(n), gidx(n)
	MSG_CASTLE_QUARTERS_CRUSH,			// ��Ȱ ���� �ı�				gs->cl idx(n)
	MSG_CASTLE_QUARTERS_LIST,			// ��Ȱ ���� ����Ʈ				gs->cl 7*(nindex(n), gindex(n))
	MSG_CASTLE_WAIT_TIME,				// ��Ȱ ��� �ð�				gs->cl wait_time(n)
	MSG_EX_CASTLE_ERROR,
	MSG_CASTLE_OWNER_INFO,				// ���� ����					gs->cl gindex_dratan(n), gindex_merac(n)
} MSG_EX_CASTLE_WAR_TYPE;


typedef enum __tagMsgDVDInfoType
{
	MSG_DUNGEON_INFO,					// ���� ���� ��û
	MSG_MANAGEMENT,						// ���� ����
	MSG_DUNGEON_ENTER,					// ���� �̵� 
	MSG_GUILD_NAME_COLOR,				// ��� �̸� �� (n)charIndex, (c)Color
} MSG_DVD_INFO_TYPE;

typedef enum __tagMsgDVDInfoSubType		// ���� ���� ���� Ÿ��
{
	MSG_MANAGEMENT_MANAGER_CONFIRM,		// ���� ��û				
	MSG_MANAGEMENT_ENV_INFO,			// ���� ����ȯ�� ���� ��û
	MSG_MANAGEMENT_ENV_CHANGE,			// ���� ����ȯ�� ����
	MSG_MANAGEMENT_STATE_INFO,			// ���� ���� ���� ���� ��û
	MSG_MANAGEMENT_STATE_CHANGE,		// ���� ���� ���� ���� ����
	MSG_MANAGEMENT_TAX_INFO,			// ���� ���� ���� ��û
	MSG_MANAGEMENT_TAX_CHANGE,			// ���� ���� ���� ���� 
	MSG_MANAGEMENT_HUNTER_TAX_INFO,		// ���� ���Ƽ��� ��û 
	MSG_MANAGEMENT_HUNTER_TAX_CHANGE,	// ���� ���Ƽ��� ����
	MSG_MANAGEMENT_ETC,					// ��Ÿ ����
	MSG_DUNGEON_ENTER_FEE,				// ���� �̵� ��� ��û  REQ: NOT, REP: (ll) money
	MSG_DUNGEON_GO,						// �������� �̵� REQ: NOT 
} MSG_DVD_INFO_SUBTYPE;

typedef enum __tagMsgDVDInfoErrorType
{
	MSG_DVD_ERROR_OK,				// ����
	MSG_DVD_ERROR_CONFIRM,			// ���� ����
	MSG_DVD_ERROR_MONEY,			// ������
	MSG_DVD_ERROR_ZONE,				// �����̳� ���� ���� ����
	MSG_DVD_ERROR_GUILD,			// ��尡 ���ų�, ã�� �� ������
} MSG_DVD_INFO_ERROR_TYPE;


typedef enum __tagMsgExCastleErrorType
{
	MSG_EX_CASTLE_ERROR_NOT_JOIN,				// ���� �������� �ƴ�
	MSG_EX_CASTLE_ERROR_NOT_WAR,				// ������ ���� �ƴ�
	MSG_EX_CASTLE_ERROR_POS_FAIL,				// ��ġ �̻�
	MSG_EX_CASTLE_ERROR_MEM_5_FAIL,				// ���� �ο� �ڸ� ����
	MSG_EX_CASTLE_ERROR_NOT_OWNER,				// ���� ��� �ƴ�
	MSG_EX_CASTLE_ERROR_NOT_RESPOND,			// ���� ���� �ƴ�
	MSG_EX_CASTLE_ERROR_NOT_RESPOND_TIME,		// ���� �ð� ����
	MSG_EX_CASTLE_ERROR_NO_MONEY,				// �� ����
	MSG_EX_CASTLE_ERROR_NOT_ATTACK,				// ���� ��� �ƴ�
	MSG_EX_CASTLE_ERROR_NO_DATA,				// ������ �̻�
	MSG_EX_CASTLE_ERROR_NO_DIFFER,				// ���� �����Ϳ� ����
	MSG_EX_CASTLE_ERROR_NOT_BUY,				// �������� �ʾ���
	MSG_EX_CASTLE_ERROR_NO_NPC,					// ���� Ÿ��
	MSG_EX_CASTLE_ERROR_DEAD_NPC,				// ���� Ÿ��
	MSG_EX_CASTLE_ERROR_HAVE_NO_GUILD,			// ��� ���� �ƴ�
	MSG_EX_CASTLE_ERROR_USE_NPC,				// ����� ��Ȱ ����
	MSG_EX_CASTLE_ERROR_USE_NPC_OTHER,			// �̹� �ٸ� ��Ȱ���� �����
	MSG_EX_CASTLE_ERROR_NO_NPC2,					// ���� ��Ȱ ����
	MSG_EX_CASTLE_ERROR_DEAD_NPC2,				// ���� ��Ȱ����
	MSG_EX_CASTLE_ERROR_SAME_DATA,				// ���� ������
	MSG_EX_CASTLE_ERROR_NOT_BUY_NPC,			// ���̻� NPC�� ���� �Ҽ� �����ϴ�,
} MSG_EX_CASTLE_ERROR_TYPE;

typedef enum __tagMsgExMessengerType
{
	MSG_EX_MESSENGER_INVITE,	// �ش� �ɸ��� �ʴ� : makeCharIndex(n) chatIndex(n) charIndex(n)
								// chatIndex �� -1�̸� ��ȭ�� �߰�,
								// GS->C			: makeCharIndex(n) chatIndex(n) charName(str) 
	MSG_EX_MESSENGER_OUT,		// �ش� �ɸ��� ��ȭ�濡�� ���� : makeCharIndex(n) chatIndex(n)
								// GS->C			: makeCharIndex(n) chatIndex(n) charName(str) 
	MSG_EX_MESSENGER_CHARLIST,	// �ʴ���� �ɸ��Ϳ��� ����� ����Ʈ�� ���� 
								// GS->C			: makeCharIndex(n) chatIndex(n) count(n) charName(str)
	MSG_EX_MESSENGER_CHAT,		// charName�� ä�� �޼��� ���� : makeCharIndex(n) chatIndex(n) chat(str)
								// GS->C			: makeCharIndex(n) chatIndex(n) color(n) charName(str) chat(str) 
	MSG_EX_MESSENGER_GROUP_ADD,	// ģ�� �׷� �߰�	: groupName(str)
								// GS->C			: gIndex(n) groupName(str)  : gIndex �� -1�̸� �ߺ��� �̸� 
	MSG_EX_MESSENGER_GROUP_DEL,	// ģ�� �׷� ����	: gIndex(n)
								// GS->C			: gIndex(n) : gIndex �� -1�̸� �������� �ʴ� �׷�
	MSG_EX_MESSENGER_GROUP_CHANGE,	// ģ�� �׷� �̸����� : gIndex(n) newName(str)
								// GS->C			: gIndex(n) groupName(str)  : gIndex�� -1�̸� �ߺ��� �̸� 
	MSG_EX_MESSENGER_GROUP_MOVE,	// ģ�� �׷� �̵�	  : gIndex(n) charName(str) 
								// GS->C			: gIndex(n) charName(str)   : gIndex�� -1�̸� �������� �ʴ� �׷� 
	MSG_EX_MESSENGER_GROUP_LIST, // �׷� ����Ʈ ������ : count(n) gIndex(n) gName(str)

	MSG_EX_MESSENGER_CHATCOLOR_CHAGNE, // Į�� ���� : color(n)
	MSG_EX_MESSENGER_BLOCK,		// �ش����� ����	: name(str)
								// GS->C			: errcode(c) charIndex(n) name(str)
	MSG_EX_MESSENGER_RELEASE_BLOCK,	// �ش����� ����: charIndex(n)
								// GS->C			: errcode(c) charIndex(n) name(str)
	MSG_EX_MESSENGER_BLOCK_LIST, // ������ ����Ʈ   : count(n) charIndex(n) name(str)

	MSG_EX_MESSENGER_ONE_VS_ONE,	// 1:1 ��ȭ : sCharIndex(n) tCharIndex(n) chat(str)
	MSG_EX_MESSENGER_ONE_OFF_LINE,	// ���� ����������: sCharIndex(n), tCharIndex(n)
} MSG_EX_MESSENGER_TYPE;

typedef enum __tagMsgEMessengerErrorType
{
	MSG_EX_MESSENGER_SUCCESS,			// ����
	MSG_EX_MESSENGER_BLOCK_NOTCHAR,		// �ش� �ɸ��Ͱ� �����ϴ�
	MSG_EX_MESSENGER_BLOCK_INVALIDNAME,	// �̸��� �߸� �Է� �Ǿ����ϴ�
	MSG_EX_MESSENGER_NOMORE_BLOCK,		// ���̻� ���Ҽ� �����ϴ�
	MSG_EX_MESSENGER_ALREADY_BLOCK,		// �̹� ���Ǿ����ϴ�

} MSG_EX_MESSENGER_ERROR_TYPE;

typedef enum __tagMsgExStringOutputType
{
	MSG_EX_STRING_OUTPUT_WINDOW,		// â
	MSG_EX_STRING_OUTPUT_SYS,			// �ý���â
	MSG_EX_STRING_OUTPUT_NOTICE,		// ����
	MSG_EX_STRING_OUTPUT_CHAT,			// êâ
} MSG_EX_STRING_Output_TYPE;

typedef enum __tagMsgExStringArgType
{
	MSG_EX_STRING_CHAR,			// char
	MSG_EX_STRING_INT,			// int
	MSG_EX_STRING_LONGLONG,		// LONGLONG
	MSG_EX_STRING_STR,			// str(50)
} MSG_EX_STRING_ARG_TYPE;

typedef enum __tagMsgExPartyMatchType
{
	MSG_EX_PARTY_MATCH_REG_MEMBER_REQ,		// ��Ƽ ��Ī �Ϲ� ��� ��û : partyType(c)
	MSG_EX_PARTY_MATCH_REG_MEMBER_REP,		// ��Ƽ ��Ī �Ϲ� ��� ���� : errorcode(n)

	MSG_EX_PARTY_MATCH_REG_PARTY_REQ,		// ��Ƽ ��Ī ��Ƽ ��� ��û : comment(str) jobFlag(n) limitlevel(c)
	MSG_EX_PARTY_MATCH_REG_PARTY_REP,		// ��Ƽ ��Ī ��Ƽ ��� ���� : errorcode(n)

	MSG_EX_PARTY_MATCH_MEMBER_LIST_REQ,		// ��Ƽ ��Ī �Ϲ� ����Ʈ ��û : pageno(n) job(c) limitlevel(c) partytype(c)
											// job�� -1�̸� ��� ����, partytype�� -1�̸� ��� ������ ��Ƽ, pageno�� 0-based index
	MSG_EX_PARTY_MATCH_MEMBER_LIST_REP,		// ��Ƽ ��Ī �Ϲ� ����Ʈ ���� : pageno(n) count(n) [charindex(n) charname(str) leveldiff(c) zone(n) job(c) partytype(c)] * count
											// leveldiff�� 0�̸� +-2 ����, 1�̸� +-3�̻�

	MSG_EX_PARTY_MATCH_PARTY_LIST_REQ,		// ��Ƽ ��Ī ��Ƽ ����Ʈ ��û : pageno(n) job(c) limitlevel(c) partytype(c)
											// job�� -1�̸� ��� ����, partytype�� -1�̸� ��� ������ ��Ƽ, pageno�� 0-based index
	MSG_EX_PARTY_MATCH_PARTY_LIST_REP,		// ��Ƽ ��Ī ��Ƽ ����Ʈ ���� : pageno(n) count(n) [bossindex(n) leveldiff(c) zone(n) jobflag(n) partytype(c) limitlevel(c) comment(str)] * count
											// leveldiff�� 0�̸� +-2 ����, 1�̸� +-3�̻�

	MSG_EX_PARTY_MATCH_DEL_REQ,				// ��Ƽ ��Ī ��� ���� ��û
	MSG_EX_PARTY_MATCH_DEL_REP,				// ��Ƽ ��Ī ��� ���� ����

	MSG_EX_PARTY_MATCH_INVITE_REQ,			// ��Ƽ ��Ī �Ϲ� �ʴ� ��û : charindex(n)
	MSG_EX_PARTY_MATCH_INVITE_REP,			// ��Ƽ ��Ī �Ϲ� �ʴ� ���� : errorcode(n) partytype(c) bossindex(n) bossname(str) destindex(n) destname(str)

	MSG_EX_PARTY_MATCH_JOIN_REQ,			// ��Ƽ ��Ī ��Ƽ ���� ��û : bossindex(n)
	MSG_EX_PARTY_MATCH_JOIN_REP,			// ��Ƽ ��Ī ��Ƽ ���� ���� : errorcode(n) partytype(c) bossindex(n) bossname(str) charindex(n) charname(str) charjob(c)
	MSG_EX_PARTY_MATCH_JOIN_ALLOW,			// ��Ƽ ��Ī ��Ƽ ���� ��� : reqindex(n)
	MSG_EX_PARTY_MATCH_JOIN_REJECT,			// ��Ƽ ��Ī ��Ƽ ���� ���� : reqindex(n)
											// reqindex�� ������ ��û�� ����� ��� �ڽ��� index, ��Ƽ���� ��� ������ ��û�� ����� �ε��� �̴�

} MSG_EX_PARTY_MATCH_TYPE;

typedef enum __tagMsgExPartyMatchErrorType
{
	MSG_EX_PARTY_MATCH_ERROR_REG_MEMBER_OK,					// ��Ƽ ��Ī �Ϲ� ��� ����
	MSG_EX_PARTY_MATCH_ERROR_REG_MEMBER_ALREADY_PARTY,		// �̹� ��Ƽ �����ڰ� ��� ��û
	MSG_EX_PARTY_MATCH_ERROR_REG_MEMBER_ALREADY_REG,		// �̹� ��ϵ� ĳ��

	MSG_EX_PARTY_MATCH_ERROR_REG_PARTY_OK,					// ��Ƽ ��Ī ��Ƽ ��� ����
	MSG_EX_PARTY_MATCH_ERROR_REG_PARTY_NO_BOSS,				// ��Ƽ���� �ƴ� ����� ��û��
	MSG_EX_PARTY_MATCH_ERROR_REG_PARTY_FULL,				// ��Ƽ �ο� ������
	MSG_EX_PARTY_MATCH_ERROR_REG_PARTY_ALREADY_REG,			// �̹� ��ϵ� ��Ƽ

	MSG_EX_PARTY_MATCH_ERROR_INVITE_OK,
	MSG_EX_PARTY_MATCH_ERROR_INVITE_NOT_FOUND,				// ��Ƽ ��Ī�� ���� ����� �ʴ�
	MSG_EX_PARTY_MATCH_ERROR_INVITE_LEVEL,					// ��Ƽ Ÿ���� PARTY_TYPE_BATTLE �϶� ���� �˻翡 ��������
	MSG_EX_PARTY_MATCH_ERROR_INVITE_NOBOSS,					// ��Ƽ���� �ƴ� ����� ��û��
	MSG_EX_PARTY_MATCH_ERROR_INVITE_DIFF_TYPE,				// ��Ƽ Ÿ���� ���� ����
	MSG_EX_PARTY_MATCH_ERROR_INVITE_ALREADY_TARGET,			// ����� �̹� ��Ƽ ��
	MSG_EX_PARTY_MATCH_ERROR_INVITE_FULL,					// ��Ƽ �ο��� �ʰ�
	MSG_EX_PARTY_MATCH_ERROR_INVITE_ALREADY_REQUEST,		// �ٸ� ������� ��û ���϶�

	MSG_EX_PARTY_MATCH_ERROR_JOIN_OK,
	MSG_EX_PARTY_MATCH_ERROR_JOIN_ALREADY_TARGET,			// ������ ��û�� ���� �̹� �ٸ� ��Ƽ�� ���� ��
	MSG_EX_PARTY_MATCH_ERROR_JOIN_NOT_FOUND,				// ���� �Ϸ��� �ϴ� ��Ƽ�� ��Ī ���̺� ����
	MSG_EX_PARTY_MATCH_ERROR_JOIN_LEVEL,					// ��Ƽ Ÿ���� PARTY_TYPE_BATTLE�̰� ���� �˻翡 ������
	MSG_EX_PARTY_MATCH_ERROR_JOIN_LIMIT_LEVEL,				// ���� ���� ���ǿ� ������
	MSG_EX_PARTY_MATCH_ERROR_JOIN_JOB,						// ���� ������
	MSG_EX_PARTY_MATCH_ERROR_JOIN_FULL,						// �ο� ������
	MSG_EX_PARTY_MATCH_ERROR_JOIN_ALREADY_REQUEST,			// ���� �ʴ� ��û�ڰ� �־ �Ұ���

} MSG_EX_PARTY_MATCH_ERROR_TYPE;

typedef enum __tagMsgExPartyRecallType
{
	MSG_EX_PARTY_RECALL_NOTICE,				// ���ݿ�û�� Ȯ�� �޽���, ��Ƽ���鿡�� ��ȯ�޽����� ���½��ϴ�.
	MSG_EX_PARTY_RECALL_PROMPT,				// ���ݴ���� Ȯ�� �޽���	: request_char_index(n) request_char_name(str)
											// XXXX��Ƽ������ ��ȯ�޽����� �����Խ��ϴ�. ��ȯ�� ���Ͻðڽ��ϱ�?
	MSG_EX_PARTY_RECALL_CONFIRM,			// ���� ����				: request_char_index(n) request_char_name(str) yes_or_no(c)
											// yes_or_no - yes(1), no(0)
	MSG_EX_PARTY_RECALL_CANCEL,				// ���� �źν�				: request_char_index(n) request_char_name(str) target_char_index(n) target_char_name(str)
} MSG_EX_PARTY_RECALL_TYPE;

typedef enum __tagMsgExPetRebirthErrorType
{
	MSG_EX_PET_REBIRTH_ERROR_OK,			// ����
	MSG_EX_PET_REBIRTH_ERROR_NOMONEY,		// ���� ����
	MSG_EX_PET_REBIRTH_ERROR_NOPET,			// �� ���� ����
	MSG_EX_PET_REBIRTH_ERROR_NODEAD,		// �� �������
} MSG_EX_PET_REBIRTH_ERROR_TYPE;

typedef enum __tagMsgExPetChangeItem
{
	MSG_EX_PET_CHANGE_ITEM_ERROR_OK,		// ������ ȹ��
	MSG_EX_PET_CHANGE_ITEM_ERROR_NOITEM,	// ������ ȹ�� ����, �길 ������
	MSG_EX_PET_CHANGE_ITEM_ERROR_FAIL,		// ��ȯ ���� : ���� �̴�
} MSG_EX_PET_CHANGE_ITEM_ERROR_TYPE;

typedef enum _tagMsgExPetChangeName
{
	MSG_EX_PET_CHANGE_NAME_ERROR_OK,	// �̸� ���� ����
	MSG_EX_PET_CHANGE_NAME_ERROR_FAIL,	// Pet �̸� ���� ����
	MSG_EX_PET_CHANGE_NAME_ERROR_ITEM,	// �������� ����
	MSG_EX_PET_CHANGE_NAME_ERROR_NOPET, // Pet ���� ����
	MSG_EX_PET_CHANGE_NAME_ERROR_DUPLICATE, // Pet �̸� �ߺ�
}MSG_EX_PET_CHANGE_NAME_ERROR_TYPE;

typedef enum __tagMsgExPetMixItemErrorType
{
	MSG_EX_PET_MIX_ITEM_ERROR_OK,		// ����
	MSG_EX_PET_MIX_ITEM_ERROR_FAIL,		// ����
	MSG_EX_PET_MIX_ITEM_ERROR_NOITEM,	// ������
	MSG_EX_PET_MIX_ITEM_ERROR_NOMIX,	// ���չ� ����
} MSG_EX_PET_MIX_ITEM_ERROR_TYPE;

typedef enum __tagMsgExCashItemType
{
	MSG_EX_CASHITEM_BALANCE_REQ,		// ĳ�� ���� ��û
	MSG_EX_CASHITEM_BALANCE_REP,		// ĳ��				: errorCode(uc) cashBalance(n)
	MSG_EX_CASHITEM_PURCHASE_REQ,		// ���� ��û		: count(n) ctid(n) 
	MSG_EX_CASHITEM_PURCHASE_REP,		// ����				: errorCode(uc) cashBalance(n)
	MSG_EX_CASHITEM_BRING_REQ,			// ��������			: count(n) idx(n) ctid(n)
	MSG_EX_CASHITEM_BRING_REP,			// ����				: errorCode(uc) 
	MSG_EX_CASHITEM_PURCHASELIST_REQ,	// ������ ��ǰ ���
	MSG_EX_CASHITEM_PURCHASELIST_REP,   // ����				: count(n) idx(n) ctid(n)
	MSG_EX_CASHITEM_PURCHASEHISTORY_REQ,// ���ų���			: y(n) m(c) d(c)
	MSG_EX_CASHITEM_PURCHASEHISTORY_REP,// ����				: errorcode(uc) count(n) ctid(n)
	MSG_EX_CASHITEM_MOONSTONE_START,	// �������� ���� Ȯ��: tab_idx(c) row_idx(c) col_idx(c) item_idx(n)
										//					   result(uc) grade(c)
	MSG_EX_CASHITEM_MOONSTONE_STOP,		// �������� �����ϰ� ���޿�û							   
	MSG_EX_CASHITEM_GIFT_REQ,			// ���� ������ ��û	: charName(str) Msg(str) count(n) idx(n) ctid(n)
	MSG_EX_CASHITEM_GIFT_REP,			//			����	: errcode(uc) 
	MSG_EX_CASHITEM_GIFT_SENDHISTORY_REQ,  // ���� ���� ����Ʈ ��û : y(n) m(c) d(c)
	MSG_EX_CASHITEM_GIFT_SENDHISTORY_REP,  // ����				: errorcode(uc) count(n) ctid(n) recvcharName(str)
	MSG_EX_CASHITEM_GIFT_RECVHISTORY_REQ,  // ���� ���� ����Ʈ ��û : y(n) m(c) d(c)
	MSG_EX_CASHITEM_GIFT_RECVHISTORY_REP,  // ����				: errorcode(uc) count(n) ctid(n) sendcharName(str)
	MSG_EX_CASHITEM_GIFT_RECVLIST_REQ,	   // ���� ���� ����Ʈ ��û
	MSG_EX_CASHITEM_GIFT_RECVLIST_REP,		// ����				: listflag(c) count(n) idx(n) ctid(n) date(un) sendcharName(str) msg(str)
	MSG_EX_CASHITEM_GIFT_RECV_REQ,			// ���� �ޱ�		: count(n) idx(n) ctid(n)
	MSG_EX_CASHITEM_GIFT_RECV_REP,			// ���� �ޱ�		: errCode(uc)
	MSG_EX_CASHITEM_GIFT_NOTICE,			// ������ �����Ͽ����ϴ�
	
	//�����ý���
	MSG_EX_CASHITEM_CUPON_REQ,				// ���� ���� ����Ʈ ��û
	MSG_EX_CASHITEM_CUPON_REP,				// ���� ���� ����Ʈ ����  : error code(c) ���� ���� ��(n) { ���� �̸�(str), ����ID(n), ���� �ݾ�(n) } ...
	MSG_EX_CASHITEM_PURCHASE_WITH_COUPON_REQ, //  �������� ���� �ϱ� : cash, ����ID(n) , couponAmount(n), Count(n) { stid(n) }... requestCash(n)
	MSG_EX_CASHITEM_PURCHASE_WITH_COUPON_REP, // �������� �����ϱ� ���� : error code(c) cashBalance(n)
} MSG_EX_CASHITEM_TYPE;

typedef enum _tagExCashItemMoonstoneErrorType
{
	MSG_EX_CASHITEM_MOONSTONE_ERROR_SUCCESS,				// ���������� ����
	MSG_EX_CASHITEM_MOONSTONE_ERROR_NOITEM,					// ��ȯ�� �������� �����ϴ�.
	MSG_EX_CASHITEM_MOONSTONE_ERROR_INVEN,					// �κ��丮�� �����մϴ�
	MSG_EX_CASHITEM_MOONSTONE_ERROR_CANTUSE_CASHMOON,		// ĳ�� �������� ����Ҽ� �ִ� �������� �ƴմϴ�.
} MSG_EX_CASHITEM_MOONSTONE_ERROR_TYPE;

typedef enum __tagMsgExCashItemErrorType
{
	MSG_EX_CASHITEM_ERROR_SUCCESS,				// ����
	MSG_EX_CASHITEM_ERROR_LACKCASH,				// ����ĳ�� ����
	MSG_EX_CASHITEM_ERROR_NOTUSER,				// �ش����� ����
	MSG_EX_CASHITEM_ERROR_NOTITEM,				// �������� �ʴ� ��ǰ�Դϴ�
	MSG_EX_CASHITEM_ERROR_DB,					// DB����
	MSG_EX_CASHITEM_ERROR_PACKET,				// ��Ŷ ����
	MSG_EX_CASHITEM_ERROR_ETC,					// ��Ÿ ����
	MSG_EX_CASHITEM_ERROR_OVERITEM,				// ���� ��ǰ ���� �ʰ�(10��)
	MSG_EX_CASHITEM_ERROR_NOSPACE,				// ���Ź�ǰ �������� ���� ����
	MSG_EX_CASHITEM_ERROR_LACKINVEN,			// �ɸ��� �κ� ����
	MSG_EX_CASHITEM_ERROR_CONN,					// Ŀ���� ���� ����
	MSG_EX_CASHITEM_ERROR_BILL,					// ���� ���� ����
	MSG_EX_CASHITEM_ERROR_NOTACCOUNT	= 12,			// ���� ���� ���� 
	MSG_EX_CASHITEM_ERROR_NOTHAVECT,			// ���� ������ ǰ��
	MSG_EX_CASHITEM_ERROR_GIFT_WRONGCHAR,		// �����ÿ� �ش� �ɸ��Ͱ� �����ϴ�
	MSG_EX_CASHITEM_ERROR_GIFT_SUCCESS,			// ���������� ����
	MSG_EX_CASHITEM_ERROR_GIFTRECV_SUCCESS,		// ���� ���� ��ǰ���� �κ��丮�� �Ű�����
	MSG_EX_CASHITEM_ERROR_GIFT_NOCTID,			// ���� ��ǰ�� �����ϴ�
} MSG_EX_CASHITEM_ERROR_TYPE;

typedef enum __tagMsgExNamechangeErrorType
{
	MSG_EX_NAMECHANGE_ERROR_SUCCESS,		// ����
	MSG_EX_NAMECHANGE_ERROR_DUPLICATE,		// �ߺ��̸�
	MSG_EX_NAMECHANGE_ERROR_HELPER,			// ���� ���� ����
	MSG_EX_NAMECHANGE_ERROR_INVALID,		// �߸��� �Է�
	MSG_EX_NAMECHANGE_ERROR_NOTGUILDBOSS,	// ������� �ƴ�
} MSG_EX_NAMECHANGE_ERROR_TYPE;

typedef enum __tagMsgExPetLearnErrorType
{
	MSG_EX_PET_LEARN_ERROR_OK,		// ����
	MSG_EX_PET_LEARN_ERROR_WEAR,	// �� ������
	MSG_EX_PET_LEARN_ERROR_POINT,	// �������Ʈ ����
	MSG_EX_PET_LEARN_ERROR_LEVEL,	// ���� ����
	MSG_EX_PET_LEARN_ERROR_ITEM,	// ������ ����
	MSG_EX_PET_LEARN_ERROR_AUTO,	// �ڵ� �����
} MSG_EX_PET_LEARN_ERROR_TYPE;

typedef enum __tagMsgExPetChangeMountErrorType
{
	MSG_EX_PET_CHANGE_MOUNT_ERROR_OK,		// ����
	MSG_EX_PET_CHANGE_MOUNT_ERROR_LEVEL,	// ���� ����
	MSG_EX_PET_CHANGE_MOUNT_ERROR_WEAR,		// �������
	MSG_EX_PET_CHANGE_MOUNT_ERROR_GRADE,	// �̹� ����Ʈ Ÿ���� ��
} MSG_EX_PET_CHANGE_MOUNT_ERROR_TYPE;

typedef enum _tagMsgMemposPlusType
{
	MSG_EX_MEMPOSPLUS_LIST,		// ������ ����Ʈ ����	: count(uc) [slot(c) zone(n) x(f) z(f) comment(str)] �ݺ� busetime(n)
	MSG_EX_MEMPOSPLUS_WRITE,	// ������ ����		: slot(c) comment(str) zone(n) x(f) z(f)
	MSG_EX_MEMPOSPLUS_MOVE,		// ��� ��ҷ� �̵�		: slot(c)
} MSG_MEMPOSPLUS_TYPE;

// ���� �޽��� ����
typedef enum __tagMsgFailType
{
	// �Ϲ�
	MSG_FAIL_MANY_CONNECT,					// ���� ��û�� ����
	MSG_FAIL_WRONG_VERSION,					// ���� ����
	MSG_FAIL_WRONG_CHAR,					// �߸��� ���� ����
	MSG_FAIL_WRONG_PASSWORD,				// ��ȣ�� �߸��� ���� ����
	MSG_FAIL_ALREADY_CONNECT,				// �̹� ������ ���̵� (�� ������ �� ����)
	MSG_FAIL_CONNECT_SERVER,				// ���� ����
	MSG_FAIL_BLOCK_CHAR,					// ĳ���� ��
	MSG_FAIL_CHECK_CHAR,					// ���� ����
	MSG_FAIL_SYSTEM_ERROR,					// �ý��� ����
	MSG_FAIL_NOT_EXIST_CHAR,				// ĳ���� ����

	// �����ͺ��̽� ����
	MSG_FAIL_DB_ALREADY_NAME,				// 10 �ߺ��� �̸�
	MSG_FAIL_DB_NEW_CHAR,					// �� ĳ���� ���� ����
	MSG_FAIL_DB_FULL_CHAR,					// ���Կ� ���ڸ� ����
	MSG_FAIL_DB_NOT_EXIST_CHAR,				// �ش� ���Կ� ĳ�� ����
	MSG_FAIL_DB_UNKNOWN,					// �˼����� ����

	// ���� ����
	MSG_FAIL_BILLING_NOT_PAY,				// �̿� ���� Ȯ�� �ȵ�
	MSG_FAIL_BILLING_NOT_RIGHT,				// ��� ���� ����
	MSG_FAIL_BILLING_TIME_OUT,				// ���� �Ⱓ ������ ����
	MSG_FAIL_BILLING_ALREADY_CONNECT,		// �ߺ� ���� (�ټ��� ������ ���� ��)
	MSG_FAIL_BILLING_OVER_IP,				// ���ӹ� ��� ���� ������ ���� �ʰ�
	MSG_FAIL_BILLING_TIME_NOT_ENOUGH,		// 20 ���� �Ⱓ ����
	MSG_FAIL_BILLING_TIME_OUT_DISCONNECT,	// ���� �ð� ����
	MSG_FAIL_BILLING_OTHER,					// �׿�
	MSG_FAIL_BILLING_WRONGPW,				// ���̵� �н����� ����
	MSG_FAIL_BILLING_BLOCKED,				// ���� ��


	// �޽��� ����
	MSG_FAIL_MSGR_TIMEOUT_WHISPER,			// �ӼӸ� Ÿ�� �ƿ�
	MSG_FAIL_MSGR_NOT_FOUND_CHAR,			// �Ӹ� ��ȭ ��밡 ����

	// �α伭�� ����
	MSG_FAIL_LOGIN_SERVER,					// ���� ����
	MSG_FAIL_LOGINSERV_MANY_CONNECT,		// ���� ��û�� ����
	MSG_FAIL_LOGINSERV_WRONG_VERSION,		// ���� ����
	MSG_FAIL_LOGINSERV_WRONG_CHAR,			// 30 �߸��� ���� ����
	MSG_FAIL_LOGINSERV_WRONG_PASSWORD,		// ��ȣ�� �߸��� ���� ����
	MSG_FAIL_LOGINSERV_ALREADY_CONNECT,		// �̹� ������ ���̵� (�� ������ �� ����)
	MSG_FAIL_LOGINSERV_BLOCK_CHAR,			// ĳ���� ��
	MSG_FAIL_LOGINSERV_CHECK_CHAR,			// ���̵�/��ȣ Ʋ��
	MSG_FAIL_LOGINSERV_SYSTEM_ERROR,		// �ý��� ����
	MSG_FAIL_LOGINSERV_NOT_EXIST_CHAR,		// ĳ���� ����
	MSG_FAIL_LOGINSERV_NO_SERVICE,			// ���� �Ⱓ�� �ƴ�
	
	MSG_FAIL_WRONG_IDENTIFICATION,			// �ֹι�ȣ Ʋ��
	//�׽�Ʈ ����
	MSG_FAIL_TEST_WRONG,					// Test �޼���  ��,���� �̵� ����
	MSG_NOT_IN_ZONE,						// 40 ĳ���Ͱ� ���� ����
	MSG_FAIL_ENABLE_AREA,					// Enable area msg error
	MSG_FAIL_CANNT_ENABLE_AREA,				// area can't enable msg error

	MSG_FAIL_LOGINSERV_NOT_ADULT,			// �̼����ڴ� �����Ҽ� ���� �ð��Դϴ�
	MSG_FAIL_NOTLEVEL_FORDELETE,			// ����� �ִ� ������ �ƴ� 

	MSG_FAIL_DB_DELETE_DELAY_CHAR,			// ���� ��� ĳ���ͷ� ���� ���� ��û��

	MSG_FAIL_SCARD_NOT_MATCHING,			// ���� ī�� ���� ����

	MSG_FAIL_LOGINSERV_BLOCK_USER,			// �н�����3�� Ʋ���� ��

	MSG_FAIL_LOGINSERV_BLOCK_ACCOUNT,		// ������
	MSG_FAIL_LOGINSERV_USE_SECURE_SYSTEM,	// ��ȭ���� �ý��� ���

	MSG_FAIL_END_MSG,						// ��� MSG_FAIL_TYPE�� �޽����� �̺��� �տ� �־�� ��
} MSG_FAIL_TYPE;


// �α��� ����
typedef enum __tagMsgLoginType
{
	MSG_LOGIN_NEW,				// ó�� ����
	MSG_LOGIN_RE,				// ���� �̵�
	MSG_LOGIN_GM,				// GMTOOL ����
} MSG_LOGIN_TYPE;


// �޴� ����
typedef enum __tagMsgMenuType
{
	MSG_MENU_NEW,				// NEW CHARACTER		: mode(uc) name(str) job(c) hairstyle(c) facestyle(c)
	MSG_MENU_DEL,				// DELETE CHARACTER		: mode(uc) index(n) ident(str) bcanceldelete(c)
								// ident				: �ֹι�ȣ
								// bcanceldelete		: ���� ��ҽ� 1, ������ 0
	MSG_MENU_START,				// START				: mode(uc) index(n)
} MSG_MENU_TYPE;


// �̵� ����
typedef enum __tagMsgMoveType
{
	MSG_MOVE_WALK,				// �ȱ�
	MSG_MOVE_RUN,				// �ٱ�
	MSG_MOVE_PLACE,				// ��ǥ
	MSG_MOVE_STOP,				// ����
#ifdef NIGHT_SHADOW
	MSG_MOVE_FLY,				// ����
#endif //NIGHT_SHADOW
} MSG_MOVE_TYPE;


// ĳ���� ���� ����
typedef enum __tagMsgCharType
{
	MSG_CHAR_UNKNOWN = -1,		// �� �� ����
	MSG_CHAR_PC = 0,			// �÷��̾� ĳ����
	MSG_CHAR_NPC,				// NPC
	MSG_CHAR_PET,				// �ֿϵ���
	MSG_CHAR_ELEMENTAL,			// ������Ż ��ȯ��
	MSG_CHAR_APET,				// ������ �ֿϵ���
} MSG_CHAR_TYPE;


// DB ���� �޽���
typedef enum __tagMsgDBType
{
	MSG_DB_SUCCESS,				// ��û ó�� ����			: 
	MSG_DB_OK,					// ĳ���� ���� �б� ����	: zone(n)
	MSG_DB_CHAR_EXIST,			// ĳ���� ����				: index(n) name(str) job(c) job2(c) hair(c) face(c) level(n) exp(ll) needexp(ll) sp(n) hp(n) maxHP(n) mp(n) maxMP(n) [wearing_index(n) wearing_plus(n)]:6 deletedelayremain(n)
								// deletedelay : time_t�� ���, 0�� �ƴϸ� ���� ����� ĳ����, 0�̸� �Ϲ� ĳ����
	MSG_DB_CHAR_END,			// ĳ���� ���� ��			: slot1remain(n) slot2remain(n) seed(n)
	MSG_DB_OTHER_SERVER,		// �ٸ� ���� ���� ĳ��		: zone(n) ip(str) port(n)
} MSG_DB_TYPE;


// ä�ð���
typedef enum __tagMsgChatType
{
	MSG_CHAT_SAY,				// �Ϲ� ä��
	MSG_CHAT_PARTY,				// ��Ƽ ��ȭ
	MSG_CHAT_GUILD,				// ��� ��ȭ
	MSG_CHAT_TRADE,				// �Ÿ� ��ȭ
	MSG_CHAT_WHISPER,			// �Ϳ���
	MSG_CHAT_SHOUT,				// ��ġ��
	MSG_CHAT_NOTICE,			// ��� �˸� �޽��� : ���� �� ���� ��� ĳ������ ����
	MSG_CHAT_GM,				// ��� ä��
	MSG_CHAT_MESSENGER,			// �޽��� ä��
	MSG_CHAT_LORD,				// ���� ����
	MSG_CHAT_RANKER,			// ��Ŀ ��
	MSG_CHAT_RANKER_CONN,		// ��Ŀ ���� job(c) name(str)
	MSG_CHAT_NOTICE_SERVERDOWN,	// ����
	MSG_CHAT_GM_WHISPER,
	MSG_CHAT_GM_SAY, 
	MSG_CHAT_GMTOOL,
	MSG_CHAT_NOTICE_PRESSCORPS,		// ���ڴ� ����
	MSG_CHAT_EXPEDITION,		// ������ ä��	
} MSG_CHAT_TYPE;


// ������ ����
typedef enum __tagMsgItemType
{
	MSG_ITEM_USE,				// ������ ���			: tab_idx(c) row_idx(c) col_idx(c) item_idx(n) extra1(n)
	MSG_ITEM_TAKE,				// ������ �ݱ�			: char_type(c) char_idx(n) item_idx(n)
	MSG_ITEM_THROW,				// ������ ������		: tab_idx(c) row_idx(c) col_idx(c) item_idx(n) count(ll)
	MSG_ITEM_ARRANGE,			// ������ ����			: tab_idx(c)
	MSG_ITEM_DELETE,			// ������ ����			: tab_idx(c) row_idx(c) col_idx(c) item_idx(n) count(ll)
	MSG_ITEM_WEAR,				// ������ ��Ż			: wear_pos(c) tab_idx1(c) row_idx1(c) col_idx1(c) item_idx1(n) tab_idx2(c) row_idx2(c) col_idx2(c) item_idx2(n)
	MSG_ITEM_SWAP,				// ������ ��ġ ����		: tab_idx(c) row_idx1(c) col_idx1(c) row_idx2(c) col_idx2(c)
	MSG_ITEM_ADD,				// ������ ����			: tab_idx(c) row_idx(c) col_idx(c) item_idx(n) item_db_idx(n) wear_pos(c) plus(n) flag(n) used(n), used_2(n) count(ll) option_count(c) [option_type(c) option_level(c)] * option_count
								// COMPOSITE_TIME ���� used_2(n) �߰�
	MSG_ITEM_UPDATE,			// ������ ����			: tab_idx(c) row_idx(c) col_idx(c) item_idx(n) plus(n) flag(n) used(n) used_2(n) count(ll) change_count(ll) option_count(c) [option_type(c) option_level(c)] * option_count
								// COMPOSITE_TIME ���� used_2(n) �߰�
	MSG_ITEM_DROP,				// 10 ������ ���			: item_idx(n) item_db_idx(n) count(ll) x(f) z(f) h(f) r(f) ylayer(n) char_type(c) char_index(n)
	MSG_ITEM_APPEAR,			// ������ �þ� ��		: item_idx(n) item_db_idx(n) count(ll) x(f) z(f) h(f) r(f) ylayer(n)
	MSG_ITEM_DISAPPEAR,			// ������ �þ� ��		: item_idx(n)
	MSG_ITEM_BUY,				// ������ ����			: npc_idx(n) price(ll) item_count(n) item_db_idx(n) count(ll)....�ݺ�
	MSG_ITEM_SELL,				// ������ �Ǹ�			: npc_idx(n) price(ll) item_count(n) tab_idx(c) row_idx(c) col_idx(c) count(ll)...�ݺ�
	MSG_ITEM_UPGRADE_REQ,		// ������ ���� ��û		: row_idx1(c) col_idx1(c) plus(n) row_idx2(c) col_idx2(c) level(n)
	MSG_ITEM_UPGRADE_REP,		// ������ ���� ����		: result(uc)
	MSG_ITEM_REFINE_REQ,		// ���ü� ��ȯ ��û		: row(c) col(c)
	MSG_ITEM_REFINE_REP,		// ���ü� ��ȯ ����		: result(uc)
	MSG_ITEM_OPTION_ADD_REQ,	// ������ �ɼ� ��û		: row_idx1(c) col_idx1(c) wear_pos(c) row_idx2(c) col_idx2(c)
	MSG_ITEM_OPTION_ADD_REP,	// 20 ������ �ɼ� ���		: result(uc)
	MSG_ITEM_OPTION_DEL_REQ,	// ������ �ɼ� ��û		: row_idx1(c) col_idx1(c) wear_pos(c) row_idx2(c) col_idx2(c)
	MSG_ITEM_OPTION_DEL_REP,	// ������ �ɼ� ���		: result(uc)
	MSG_ITEM_PROCESS_REQ,		// ������ ���� ��û		: use_row_idx(c) use_col_idx(c) make_db_idx(n) material_count(n) [tab(c) row(c) col(c) count(ll)].. �ݺ�
	MSG_ITEM_PROCESS_REP,		// ������ ���� ���		: result(uc)
	MSG_ITEM_MAKE_REQ,			// ������ ���� ��û		: use_row_idx(c) use_col_idx(c) make_db_idx(n) material_count(n) [tab(c) row(c) col(c) count(ll)].. �ݺ�
	MSG_ITEM_MAKE_REP,			// ������ ���� ���		: result(uc)
	MSG_ITEM_MIX_REQ,			// �Ǽ��縮 ���� ��û:	: use_row_idx(c) use_col_idx(c) row_idx1(c) col_idx1(c) row_idx2(c) col_idx2(c) row_idx3(c) col_idx3(c)
	MSG_ITEM_MIX_REP,			// �Ǽ��縮 ���� ���	: result (uc)
	MSG_ITEM_GET,				// ������ ������(ǥ��)	: char_name(str) item_db_idx(n) item_count(ll)
	MSG_ITEM_ARCANE_REQ,		// 30 ����� ���� ��û:	: use_row_idx(c) use_col_idx(c) row_idx1(c) col_idx1(c) row_idx2(c) col_idx2(c) row_idx3(c) col_idx3(c)
	MSG_ITEM_ARCANE_REP,		// ����� ���� ���		: result (uc)
	MSG_ITEM_CHANGEWEAPON_REQ,	// ���� ��ȯ ��û		: row(c) col(c) itemindex(n) changetype(n)
	MSG_ITEM_CHANGEWEAPON_REP,	// ���� ��ȯ ����		: old_itemdbindex(n) new_itemdbindex(n)
								// ���� ���ڶ�� ��� old == -1
								// �߸��� ��ȯ�� ��û�ϸ� new == -1
	MSG_ITEM_PROCESS_NPC,		// NPC�� ���� ����		: processItemDBIndex(n) count(n) errcode(n:s)
	MSG_ITEM_ADD_BOOSTER,		// ���� ������ �ν��� ���� : flag(n)
								// Ŭ���̾�Ʈ->����		: �ν��� ������ ���� �ε���
								// ����->Ŭ���̾�Ʈ		: �����ڵ�
	MSG_ITEM_MIX_WARITEM,		// ���� ������ ����		: Ŭ���̾�Ʈ -> ����	: row_type1(c) col_type1(c) row_type2(c) col_type2(c) row_type3(c) col_type3(c)
								//						: ���� -> Ŭ���̾�Ʈ	: errcode(n)
	MSG_ITEM_USE_PROLONG,		// c->s ������ ���Ⱓ ����	: tab_idx(uc) row_idx(uc) col_idx(uc) item_idx(n) extra1(n)
								// s->c						?	: item_idx(n) busetime(n) bprolong(c)
	MSG_ITEM_USE_ERROR,			// errorcode(uc)

	MSG_ITEM_LEND_WEAPON,		// ���� �뿩			: itemdbindex(n) errorcode(n:s)

	MSG_ITEM_LEVELDOWN,			// 40 ���� �ж�		   :  row1(c) col1(c) row2(c) col2(c)
								// MSG_ITEM_LEVELDOWN_ERROR_TYPE : errorcode(n)

	MSG_ITEM_TARGET,			// Ÿ���ϴ� ������ ��� : tab_idx(c) row_idx(c) col_idx(c) item_idx(n) chartype(c) charindex(n)

	MSG_ITEM_EXCHANGE_EQUIP_REQ,	// ���� ��ȯ ��û		: row(c) col(c) itemindex(n) changetype(n)
	MSG_ITEM_EXCHANGE_EQUIP_REP,	// ���� ��ȯ ����		: old_itemdbindex(n) new_itemdbindex(n)


	MSG_ITEM_USE_GROCERY_BUY,		// ��ȭ�� �������� �̿��� ������ ���� : price(ll) item_count(n) item_db_idx(n) count(ll)....�ݺ�
	MSG_ITEM_USE_GROCERY_SELL,		// ��ȭ�� �������� �̿��� ������ �Ǹ� : price(ll) item_count(n) tab_idx(c) row_idx(c) col_idx(c) count(ll)...�ݺ�

	MSG_ITEM_USE_WARPDOC,		// �̵��ֹ��� ����ϱ� zone(n), npcidx(n)
	MSG_ITEM_USE_PRESSCORPS,	// ��ī���ڴ� Ȯ���� subtype(c) >> item_idx(n) >> msg(str)
	
	MSG_ITEM_END_MSG,			// MSG_ITEM_TYPE ������ �޽���
} MSG_ITEM_TYPE;

typedef enum _tagItemLendWeaponErrorType
{
	MSG_ITEM_LEND_WEAPON_ERROR_OK,				// ���� �뿩 : ����
	MSG_ITEM_LEND_WEAPON_ERROR_FULLINVEN,		// ���� �뿩 : �κ� ���� ����
	MSG_ITEM_LEND_WEAPON_ERROR_NOMONEY,			// ���� �뿩 : ������ ����
	MSG_ITEM_LEND_WEAPON_ERROR_FAIL,			// ���� �뿩 : ���� ( �߸��� DB �ε��� ��û�� Ŭ���̾�Ʈ ���� )
	MSG_ITEM_LEND_TIMEOUT,						// ���� �뿩 : ����
} MSG_ITEM_LEND_WEAPON_ERROR_TYPE;				

typedef enum _tagItemUseErrorType
{
	MSG_ITEM_USE_ERROR_REVIVAL_EXP,			// ��Ȱ �ֹ��� ������ ����ġ ���� �ֹ��� ��� �Ҽ� ����
	MSG_ITEM_USE_ERROR_REVIVAL_SP,			// ��Ȱ �ֹ��� ������ ���õ� ���� �ֹ����� ����Ҽ� ����
	MSG_ITEM_USE_ERROR_SUMMON_NOTALLOWZONE, // �ǽ����̹Ƿ� ���� ���� �ֹ����� ����Ҽ� ����
	MSG_ITEM_USE_ERROR_EXP_SP,				// ����ġ �ֹ��� ������ ���õ� ��� ����
	MSG_ITEM_USE_ERROR_SP_EXP,				// ���õ� ������ ����ġ ��� ����.
	MSG_ITEM_USE_ERROR_PLATINUM_SPECIAL,	// �÷�Ƽ�� ���ü� ������ �Ϸ� 
	MSG_ITEM_USE_ERROR_PLATINUM_SPECIAL_EXPIRE, // ���Ⱓ�� ���� �Ǿ ȿ���� �����
	MSG_ITEM_USE_ERROR_EXPUP,				// ������ ������ ������Դϴ�. �׷��� ����Ͻðڽ��ϱ�?
	MSG_ITEM_USE_ERROR_IDENTIFY_RARE_OK,	// ���� ������ �ɼ� Ȯ�� ����
	MSG_ITEM_USE_ERROR_IDENTIFY_RARE_FAIL,	// ���� ������ �ɼ� Ȯ�� ����
	MSG_ITEM_USE_ERROR_WARN_PARTYRECALL,	// ���� �� ���� �������� ��Ƽ���� ���� �Ϻ� ���� �ȵ��� ���
	MSG_ITEM_USE_ERROR_SUMMON_GUARD,		// ��񺴼�ȯ ����
} MSG_ITEM_USE_ERROR_TYPE;

typedef enum _tagItemMixWarItemErrorType
{
	MSG_ITEM_MIX_WARITEM_ERROR_OK,			// ���� ����
	MSG_ITEM_MIX_WARITEM_ERROR_NOTFOUND,	// ��� ����
} MSG_ITEM_MIX_WARITEM_ERROR_TYPE;

typedef enum _tagMSG_ITEM_LEVELDOWN_ERROR_TYPE	// ���� �϶� �ֹ���
{
	MSG_ITEM_LEVELDOWN_ERROR_OK,			// ����
	MSG_ITEM_LEVELDOWN_ERROR_ALREADY,		// �̹� ���� �϶�
	MSG_ITEM_LEVELDOWN_ERROR_NOEQUIP,		// ��� �ƴ�
	MSG_ITEM_LEVELDOWN_ERROR_SCROLL,		// �ֹ��� �ƴ�
}MSG_ITEM_LEVELDOWN_ERROR_TYPE;

typedef enum _tagItemAddBoosterErrorType
{
	MSG_ITEM_ADD_BOOSTER_ERROR_OK,		// ����
	MSG_ITEM_ADD_BOOSTER_ERROR_USED,	// ������ ����
	MSG_ITEM_ADD_BOOSTER_ERROR_ALREADY,	// �̹� �پ� ����
} MSG_ITEM_ADD_BOOSTER_ERROR_TYPE;

typedef enum _tagItemProcessNPCErrorType
{
	MSG_ITEM_PROCESS_NPC_ERROR_OK,		// ����
	MSG_ITEM_PROCESS_NPC_ERROR_FAIL,	// ����
	MSG_ITEM_PROCESS_NPC_ERROR_COUNT,	// ī��Ʈ ����
	MSG_ITEM_PROCESS_NPC_ERROR_NOHAVE,	// ��� ����
	MSG_ITEM_PROCESS_NPC_ERROR_MONEY,	// ���� ����
} MSG_ITEM_PROCESS_NPC_ERROR_TYPE;

typedef enum _tagProcessResult
{
	MSG_PROCESS_FAIL_SYSTEM,			// �־�� �ȵǴ� ������ ����
	MSG_PROCESS_FAIL_MATERIAL,			// ��� ���� ����
	MSG_PROCESS_FAIL_NO_SSKILL,			// ���� ��ų ����
	MSG_PROCESS_FAIL_OVER_WEIGHT,		// ���� �ʰ��� ���� ���� ����
	MSG_PROCESS_FAIL_PROB,				// Ȯ�� ����
	MSG_PROCESS_SUCCESS,				// ���� ����
} MSG_ITEM_PROCESS_RESULT;

typedef enum _tagMakeResult
{
	MSG_MAKE_FAIL_SYSTEM,				// �־�� �ȵǴ� ������ ����
	MSG_MAKE_FAIL_MATERIAL,				// ��� ���� ����
	MSG_MAKE_FAIL_NO_SSKILL,			// ���� ��ų ����
	MSG_MAKE_FAIL_ITEM_LEVEL,			// ���� ��ų�� ���� �Ұ��� ������ (����)
	MSG_MAKE_FAIL_OVER_WEIGHT,			// ���� �ʰ��� ���� ���� ����
	MSG_MAKE_FAIL_PROB,					// Ȯ�� ����
	MSG_MAKE_SUCCESS,					// ���� ����
} MSG_ITEM_MAKE_RESULT;

typedef enum _tagItemMixResult
{
	MSG_MIX_FAIL_SYSTEM,				// �־�� �ȵǴ� ����
	MSG_MIX_FAIL_REMAKEBOX,				// ��Ȱ�� ���� ���� ����
	MSG_MIX_FAIL_ACCESSORY,				// ���� �Ǽ��縮 ������ ���� ����
	MSG_MIX_SUCCESS,					// ���� ����
} MSG_ITEM_MIX_RESULT;

typedef enum _tagItemArcaneResult
{
	MSG_ARCANE_FAIL_SYSTEM,				// �־�� �ȵǴ� ����
	MSG_ARCANE_FAIL_ARCANEBOX,			// ����� ���� ���� ����
	MSG_ARCANE_FAIL_MATERIAL,			// ��� ���� ���� (��ᰡ ��ġ�� ���ų� ������)
	MSG_ARCANE_FAIL_UPGRADE,			// ���ü� ����
	MSG_ARCANE_FAIL_ACCESSORY,			// �Ǽ��縮 ����
	MSG_ARCANE_FAIL_SAMPLE,				// �÷� ����
	MSG_ARCANE_SUCCESS,					// ���� ����
} MSG_ITEM_ARCANE_RESULT;

typedef enum _tagItemOptionAddResult
{
	MSG_OPTION_ADD_ERROR_SYSTEM,		// �־�� �ȵǴ� ����
	MSG_OPTION_ADD_ERROR_WEAR,			// ������ �����۾����
	MSG_OPTION_ADD_ERROR_KIND,			// ���⳪ ���� �����ϴ�
	MSG_OPTION_ADD_ERROR_ENABLE,		// �ɼ��� ���� �� �ִ� �������� �ƴϴ�
	MSG_OPTION_ADD_ERROR_MAX,			// �ִ� �ɼ� �� �ʰ�
	MSG_OPTION_ADD_SUCCESS,				// �ɼ� ���̱� ����
	MSG_OPTION_BLOOD_SWEAT_FRUIT_ADD_SUCCESS //�ǿ� ���� ������ ����Ͽ� ���� �ɼ� ���̱⿡ ����
} MSG_ITEM_OPTION_ADD_RESULT;

typedef enum _tagItemOptionDelResult
{
	MSG_OPTION_DEL_ERROR_SYSTEM,		// �־�� �ȵǴ� ����
	MSG_OPTION_DEL_ERROR_WEAR,			// ������ �����۾����
	MSG_OPTION_DEL_ERROR_KIND,			// ���⳪ ���� �����ϴ�
	MSG_OPTION_DEL_ERROR_NUM,			// �ɼ�3�� �̻� �־�� ����� �ִ�
	MSG_OPTION_DEL_SUCCESS,				// �ɼ� ����� ����
} MSG_ITEM_OPTION_DEL_RESULT;

typedef enum _tagFactoryType
{
	MSG_FACTORY_ERROR,					// ���� ����				: errorcode(uc)
	MSG_FACTORY_LEARN,					// ������ ���۱�� ����	: factory_index(n), exp(ll)
	MSG_FACTORY_ITEM_LIST,				// ���� ���� ������ ����Ʈ	: seal_type(c), item_type(c), count(n), [factory_index(n) * n]
	MSG_FACTORY_ITEM_MAKE,				// ������ ����				: factory_index(n), skill_index(n), skill_exp(ll) 
} MSG_FACTORY_TYPE;

typedef enum _tagFactoryErrorType
{
	MSG_FACTORY_ERROR_SYSTEM,
	MSG_FACTORY_ERROR_ALREADY_REG,		// �̹� ���
	MSG_FACTORY_ERROR_SKILL,			// �ʿ��� ��ų ����
	MSG_FACTORY_ERROR_NAS,				// ���� ����
	MSG_FACTORY_ERROR_EXP,				// ���õ� ����
	MSG_FACTORY_ERROR_ITEM,				// ��� ������ ����
	MSG_FACTORY_ERROR_INVEN,			// �κ� ����
} MSG_FACTORY_ERROR_TYPE;


typedef enum __tagMsgExAffinityType
{
	MSG_EX_AFFINITY_CONNECT_REQ,		// ���� ģ�� �α�		: npcidx(n)
	MSG_EX_AFFINITY_ITEM_CONTRIBUTE_REQ,	// ģȭ�� ������ ���	: npcidx(n) clientPoint(n) item_count(n) tab_idx(c) row_idx(c) col_idx(c) count(n) 												
	MSG_EX_AFFINITY_ITEM_CONTRIBUTE_REP,	// ģȭ�� ������ ��� ����	: affinityidx(n) point(n)	
	MSG_EX_AFFINITY_SHOPUSE_REQ,		// ���� �̿��û		: npcidx(n) 
	MSG_EX_AFFINITY_SHOPUSE_REP,		// ���� �̿�����		: npcidx(n) 
	MSG_EX_AFFINITY_GIFTINFO_REQ,		// ������������ ��û	: npcidx(n)
	MSG_EX_AFFINITY_GIFTINFO_REP,		// ������������ ����	: point(n) itemidx(n) item_count(n)
	MSG_EX_AFFINITY_GIFT_REQ,			// �����ޱ� ��û		: npcidx(n)
	MSG_EX_AFFINITY_GIFT_REP,			// �����ޱ� ����	
	MSG_EX_AFFINITY_UPDATE_POINT,		// ����Ʈ����		: affinityidx(n) poiny(n)
	MSG_EX_AFFINITY_LISTINFO,			// ģȭ�� ����Ʈ ����	: affinity_count(n) affinityidx(n) point(n)
	MSG_EX_AFFINITY_ADDINFO,			// ģȭ�� �߰� ����		: affinityidx(n)
	MSG_EX_AFFINITY_ERROR,				// ģȭ������ ERROR �޽��� : errortype(uc)
	MSG_EX_AFFINITY_REWARD_NOTICE,		// ���� �˸� : noticecount(c) npcidx(n)		[100322: selo] �߰���
}MSG_EX_AFFINITY_TYPE;

typedef enum __tagMsgExAffinityErrorType
{
	MSG_EX_AFFINITY_ERROR_CONNECT_SUCCESS,   // ģȭ�� ���� ����
	MSG_EX_AFFINITY_ERROR_CONNECT_NOMONEY,   // ��������
	MSG_EX_AFFINITY_ERROR_CONNECT_ALREADY,   // �̹̼��� ģ������
 
	MSG_EX_AFFINITY_ERROR_ITEM_CONTRIBUTE_MAX,  // ģȭ�� ����Ʈ �ִ�� á��
	MSG_EX_AFFINITY_ERROR_ITEM_CONTRIBUTE_MISSMATCH, // ��� ������ ������
 
	MSG_EX_AFFINITY_ERROR_USESHOP_POINT,   // �����̿� ����Ʈ ����
	MSG_EX_AFFINITY_ERROR_GIFTINFO_NOITEM,   // ������� �������� ����
	MSG_EX_AFFINITY_ERROR_GIFTINFO_NOPOINT,   // ����Ʈ�������� ���� ������
	MSG_EX_AFFINITY_ERROR_GIFT_NOSPACE,   // �κ��� ������ ���� ������ ����.
	MSG_EX_AFFINITY_ERROR_GIFT_MAXWEIGHT,   // �κ� ���� �ʰ�

	MSG_EX_AFFINITY_ERROR_NOT_CONNECTED,   // ģȭ���� ����Ǿ����� �ʴ�.
}MSG_EX_AFFINITY_ERROR_TYPE;


typedef enum _tagMsgMsgrType
{
	MSG_MSGR_WHISPER_REQ,			// �Ӹ� ��û		: sender_index(n) sender_name(str) receiver_name(str) chat(str)
	MSG_MSGR_WHISPER_REP,			// �Ӹ� ����		: sender_index(n) sender_name(str) receiver_name(str) chat(str)
	MSG_MSGR_WHISPER_TIMEOUT,		// �Ӹ� Ÿ�Ӿƿ�	: sender_index(n) sender_name(str)
	MSG_MSGR_WHISPER_NOTFOUND,		// ��� ����		: sender_index(n) sender_name(str)
	MSG_MSGR_GUILDCHAT,				// ��� ä��		: sender_index(n) sender_name(str) receiver_guild_index(n) chat(str)
	MSG_MSGR_NOTICECHAT,			// ��� ä��		: chat(str)
	MSG_MSGR_LOGOUT_REQ,			// �α׾ƿ� ��û	: id(str)
	MSG_MSGR_PLAYER_COUNT_REQ,		// PC �� ���� ��û	: req_char(n)
	MSG_MSGR_PLAYER_COUNT_REP,		// PC �� ���� ����	: req_char(n) count_zone(n) [zone_num(n) pc_count(n) produce_count(n) shop_count(n) play_count(n)]
	MSG_MSGR_LOGOUT_REP,			// �α׾ƿ� ����	: success(c) id(str)
	MSG_MSGR_RESERVE_060406_1,		// 10
	MSG_MSGR_RESERVE_060406_2,		// 
	MSG_MSGR_ENDGAME_REQ,			// ��ü ���� �ٿ�	: 
	MSG_MSGR_OBSERVER,				// ������ �޽��� ���� : chat(str)
	MSG_MSGR_DOUBLE_EVENT_REQ,		// ���� �̺�Ʈ ��û	: start(c)
	MSG_MSGR_LATTO_EVENT_REQ,		// ��� �̺�Ʈ ��û	: start(c)
	MSG_MSGR_DOUBLE_EXP_EVENT_REQ,	// ����ġ �ι� �̺�Ʈ ��û : char_index(n) cmd(n)
									// cmd				: 0: start, 1: ing, 2: stop
	MSG_MSGR_NEWYEAR_EVENT_REQ,		// ���� �̺�Ʈ ��û : start(c)
	MSG_MSGR_VALENTINE_EVENT_REQ,	// �߷�Ÿ�ε��� �̺�Ʈ ��û : start(c)
	MSG_MSGR_WHITEDAY_EVENT_REQ,	// ȭ��Ʈ���� �̺�Ʈ ��û : start(c)
	MSG_MSGR_LETTER_EVENT_REQ,		// 20 ȭ��Ʈ���� �̺�Ʈ ��û : start(c)
	MSG_MSGR_DOUBLE_EXP_EVENT_REP,	// ����ġ �ι� �̺�Ʈ ���� : char_index(n) server_no(n) subno(n) cmd(n)

	MSG_MSGR_MESSENGERCHAT_REQ,		// �޽���ä�� ��û		: sender_index(n) sender_name(str) receiver_index(n) receiver_name(str) chat(str)
	MSG_MSGR_MESSENGERCHAT_REP,		// �޽���ä�� ����		: sender_index(n) sender_name(str) receiver_index(n) receiver_name(str) chat(str)
	MSG_MSGR_MESSENGERCHAT_NOTFOUND,
	MSG_MSGR_EVENT_REQ,				// �̺�Ʈ ����		: thisserver(n) thissubno(n) charindex(n) eventcmd(str) flag(n)
	MSG_MSGR_CHAT_LORD,				// ���� ����		: charindex(n) charname(n) chatmsg(str)

	MSG_MSGR_OPEN_BETA_EVENT_REQ,	// �±� ���º�Ÿ �̺�Ʈ char_index(n) cmd(n)
									// cmd				: 0: start, 1: ing, 2: stop
	MSG_MSGR_OPEN_BETA_EVENT_REP,	//	: char_index(n) server_no(n) subno(n) cmd(n)
	MSG_MSGR_FLOWER_EVENT_REQ,		// �±� �ö�� �̺�Ʈ : ���º�Ÿ�� ����
	MSG_MSGR_FLOWER_EVENT_REP,		// 30

	MSG_MSGR_MARGADUM_PVP_REQ,		// �±� : �������� PVP(���� ���� ����) cmd :  0: free 1:16~25, 2: 26~35, 3: 36~
	MSG_MSGR_MARGADUM_PVP_REP,		// 

	MSG_MSGR_DOUBLE_EVENT_REP,		// �����̺�Ʈ ���� 

	MSG_MSGR_EVENT_OX,				// OX �̺�Ʈ		: subtype(n) ...

	MSG_MSGR_REBOOT_REQ,			// ���� ���� �޼���

	MSG_MSGR_RECOMMEND,				// ��õ ���� ����		: gmcharindex(n) recommendserver(n)
	MSG_MSGR_RECOMMEND_MOONSTONE,	// ��õ ���� ������ ��÷: charindex(n) charname(str)

	MSG_MSGR_MESSENGER_ADD_CONFIRM,	// �޽��� ��ȭ��/ �ɹ� �߰� : makeCharIndex(n) chatIndex(n) charName(str)
	MSG_MSGR_MESSENGER_ADD,			// �޽��� ��ȭ��/ �ɹ� �߰� : makeCharIndex(n) chatIndex(n) charName(str)
	MSG_MSGR_MESSENGER_DEL,			// 40 �޽��� ��ȭ��/ �ɹ� ���� : makeCharIndex(n) chatIndex(n) charName(str)
	MSG_MSGR_MESSENGER_CHAT,			// �޽��� ��ȭ��/ �ɹ� ���� : makeCharIndex(n) chatIndex(n) chat(str)

	MSG_MSGR_EVENT_GOLDENBALL,		// ��纼 �̺�Ʈ	: subtype(n) ...

	MSG_MSGR_LOGIN_SERVER,			// �α��� ���� ���� : code(n)
									// code : 0-close, 1-open, 2-reboot
	MSG_MSGR_MESSENGER_ONE_VS_ONE,	// 1:1 ä�� : sCharindex(n), tCharindex(n) chatColor(n) sName(str) chat(str)

	MSG_MSGR_EVENT_SETTING_REQ,		// �̺�Ʈ ���� �޽���

	MSG_MSGR_CHANCE_EVENT_REQ,		// ���� �̺�Ʈ ��û
	MSG_MSGR_CHANCE_EVENT_REP,		// ���� �̺�Ʈ ����

	MSG_MSGR_GMTOOL_KICKID_REQ,		// ������ ű��û
	MSG_MSGR_GMTOOL_KICKID_REP,
	MSG_MSGR_GMTOOL_CHATMONITOR_REQ,	//  50 ������ ĳ���� ���� ��û
	MSG_MSGR_GMTOOL_CHATMONITOR_REP,
	MSG_MSGR_GMTOOL_CHATMONITOR_NOTICE,
	MSG_MSGR_GMTOOL_CHATMONITOR_OFF,
	MSG_MSGR_GMTOOL_CHATMONITOR_NOTICE_PARTY,
	MSG_MSGR_GMTOOL_CHATMONITOR_PARTY_OFF,
	MSG_MSGR_GMTOOL_CHATMONITOR_NOTICE_GUILD,
	MSG_MSGR_GMTOOL_CHATMONITOR_GUILD_OFF,
	MSG_MSGR_GM_WHISPER_REQ,
	MSG_MSGR_GM_WHISPER_REP,
	MSG_MSGR_GM_WHISPER_NOTFOUND,	// 60
	MSG_MSGR_GMTOOL_CHATMONITOR_NOTICE_WHISPER,
	MSG_MSGR_GM_LOOPCOUNT_REQ,
	MSG_MSGR_GM_LOOPCOUNT_REP,
	MSG_MSGR_GM_RELOADGMIP_REP,
	MSG_MSGR_GMTOOL_SILENCE_REQ,
	MSG_MSGR_GMTOOL_SILENCE_REP,
	MSG_MSGR_GMTOOL_WHIPER_REQ,
	MSG_MSGR_GMTOOL_WHISPER_NOTFOUND,
	MSG_MSGR_GMTOOL_WHISPER_REP,

	MSG_MSGR_DOUBLE_ITEM_EVENT_REQ,		// 70 ���� �̺�Ʈ ��û	: start(c)
	MSG_MSGR_DOUBLE_ITEM_EVENT_REP,		// ���� �̺�Ʈ ����
	
	MSG_MSGR_DOUBLE_PET_EXP_EVENT_REQ,	// �� ����ġ �ι� �̺�Ʈ ��û : char_index(n) cmd(n)
	MSG_MSGR_DOUBLE_PET_EXP_EVENT_REP,	// �� ����ġ �ι� �̺�Ʈ ���� : char_index(n) server_no(n) subno(n) cmd(n)

	MSG_MSGR_DOUBLE_ATTACK_EVENT_REQ,	// ����, ���� ���ݷ� �ι� �̺�Ʈ ��û : char_index(n) cmd(n)
	MSG_MSGR_DOUBLE_ATTACK_EVENT_REP,	// ����, ���� ���ݷ� �ι� �̺�Ʈ ���� : char_index(n) server_no(n) subno(n) cmd(n)

	MSG_MSGR_GMTOOL_KICK_REQ,
	MSG_MSGR_GMTOOL_KICK_REP,

	MSG_MSGR_GMTOOL_SHUTDOWN,

	MSG_MSGR_EVENT_DROPITEM_REQ,
	MSG_MSGR_EVENT_DROPITEM_REP,		// 80
	
	MSG_MSGR_SET_EXPLIMIT,			// ����ġ ���� ���� (n)Server (n)limit

	MSG_MSGR_DOUBLE_EVENT_AUTO_REQ, // ���� �̺�Ʈ �ڵ�
	MSG_MSGR_DOUBLE_EVENT_AUTO_REP, // ���� �̺�Ʈ �ڵ�

	MSG_MSGR_UPGRADE_EVENT_REQ,		// ������ü� Ȯ�����
	MSG_MSGR_UPGRADE_EVENT_REP,		// ������ü� Ȯ�����

	MSG_MSGR_END_MSG,				// �� � �޽��� �޽����� �̺��� �۾ƾ� �Ѵ�
} MSG_MSGR_TYPE;

typedef enum _tagMsgMsgrEventGoldenballType
{
	MSG_MSGR_EVENT_GOLDENBALL_VOTE,	// ��纼 �̺�Ʈ ���� ����	: gmcharindex(n) team1(str) team2(str) year(n) month(n) day(n) hour(n) minute(n)
	MSG_MSGR_EVENT_GOLDENBALL_GIFT,	// ��纼 �̺�Ʈ ���� ����	: gmcharindex(n) team1(str) team1score(n) team2(str) team2score(n) year(n) month(n) day(n) hour(n) minute(n) endVoteTime(n)
	MSG_MSGR_EVENT_GOLDENBALL_END,	// ��纼 �̺�Ʈ ����		: gmcharindex(n) 
} MSG_MSGR_EVENT_GOLDENBALL_TYPE;

typedef enum _tagMsgMsgrEventOXType
{
	MSG_MSGR_EVENT_OX_SET_START,	// ���ۼ���				: gmcharindex(n) year(n) mon(n) day(n) hour(n) min(n)
	MSG_MSGR_EVENT_OX_END,			// ����					: gmcharindex(n)
	MSG_MSGR_EVENT_OX_QUIZ,			// ����					: gmcharindex(n) quizno(n) sec(n)
} MSG_MSGR_EVENT_OX_TYPE;

typedef enum _tagMsgSysType
{
	MSG_SYS_WHISPER_NOTFOUND,		// �Ӹ� ��� ����		:
	MSG_SYS_TIMEOUT,				// Ÿ�� �ƿ� �߻�		:
	MSG_SYS_CANNOT_WEAR,			// ���� ����			:
	MSG_SYS_FULL_INVENTORY,			// �κ��丮 ���� ��		: tab_index(c)
	MSG_SYS_CUSTOM,					// Ŀ���� �޽���		: msg(str)
	MSG_SYS_SHORT_MONEY,			// �� ���� ������		:
	MSG_SYS_SHOP_CANCEL,			// ���� �ŷ� ���		:
	MSG_SYS_EXCHANGE_NOTFOUND,		// ��ȯ ��� ����		:
	MSG_SYS_EXCHANGE_ALREADY,		// �̹� ��ȯ ��			:
	MSG_SYS_NOT_OWNER_ITEM,			// ������ �켱���� ����
	MSG_SYS_OVER_WEIGHT,			// 10 ���԰� ���� ����
	MSG_SYS_UPGRADE_NOCONDITION,	// ������ �ȸ¾� ���׷��̵� ���� (�Ϲ����ü� ������ ���� ����)
	MSG_SYS_MAKE_REFINE_KIND,		// ���⳪ ���� �ƴ� �ٸ��� ���ü����� ��ȯ�Ϸ��� ��
	MSG_SYS_MAKE_REFINE_WEARING,	// �԰� �ִ� ���������� ���ü� ��ȯ �Ұ���
	MSG_SYS_MAKE_REFINE_PLUS,		// Plus ���� ���õǾ� �ִ� ������ ���ü� ��ȯ �Ұ���
	MSG_SYS_MEMPOS_CANT_WRITE,		// ��� ��� ��ġ ��� �Ұ��� ��
	MSG_SYS_LAYERDUNGEON_FULL,		// ���̾� �� ���� ���� ���� �Ұ�
	MSG_SYS_CANT_WARP_STATE,		// �̵� ��ġ �Ұ��� : ĳ���� ����(���/�ɱ�/��ų����/��Ƽ��û/��ȯ)
	MSG_SYS_CANT_WARP_OTHER,		// �̵� ��ġ �Ұ��� : �ٸ���ġ�̿�
	MSG_SYS_MEMPOS_OTHERZONE,		// �ٸ� �����δ� ��� ��� �̵� �Ұ�
	MSG_SYS_SINGLEDUNGEON_FULL,		// 20 �̱۴��� �� ����
	MSG_SYS_MAKE_REFINE_SHORT,		// ���ü� ���鶧 �� ������
	MSG_SYS_PRODUCE_NOTOOL,			// ���굵���� ����
	MSG_SYS_PRODUCE_WEAR_TOOL,		// ���굵���� �����Ͻÿ�
	MSG_SYS_PRODUCE_MATCH_TOOL,		// �´� ���굵���� �����Ͻÿ�
	MSG_SYS_PRODUCE_MAXUSE_TOOL,	// ���굵�� �� ����
	MSG_SYS_PRODUCE_MAX_ACCEPTABLE,	// ���� ���� �ο� �ʰ�
	MSG_SYS_PRODUCE_NO_SSKILL,		// �ش��ϴ� ���� ��ų�� ����!!
	MSG_SYS_PROCESS_DOC_NOT_SSKILL,	// �������� ���µ� ������ų�� ����
	MSG_SYS_WARNING_WEIGHT,			// ���� �ʰ� ���
	MSG_SYS_BLOODITEM,				// 30 ���� �ɼ� ���� ����	: itemdbindex(n)
	MSG_SYS_MAKE_REFINE_CANNOT,		// ��� �������� ���ü� ��ȯ �Ұ���
	MSG_SYS_PKMODE_LIMITLEVEL,		// PK ������ �Ұ����� ����
	MSG_SYS_CANTCHAT_INVISIBLE,		// �κ����� ���¿����� �Ϲ� ä�� �Ұ�
	MSG_SYS_SHORT_FAME,				// ��ġ ����
	MSG_SYS_FRIEND_NOTFOUND,        // �޽��� ��밡 ���������� ����. 
	MSG_SYS_UPGRADE_CANT_SUPERSTONE,// ���۰����� �̹� ����� ������//0627
	MSG_SYS_UPGRADE_CANT_14LEVEL,   // 14���� �����ۿ��� ���۰����� ������
	MSG_SYS_FAME_NOT_ENOUGH,		// ��ġ �����ؼ� ���� ���� ���޹��� ����
	MSG_SYS_INVEN_NOT_ENOUGH,		// �κ��� �������� ���� ���� ���޹��� ����
	MSG_SYS_NO_MORE_SUPERSTONE,		// 40 ���̻� ���� ������ ���޹��� ����(7�� �� ���� ����)
	MSG_SYS_CAN_RECEIVE_SUPERSTONE,	// Ư�� ��ġ�� �����ؼ� ���۰����� ������ ����.
	MSG_SYS_APPEAR_NOVICE,			// �ʺ��ڰ� ��������.
	MSG_SYS_NOTICE,					// ���ӳ� �̺�Ʈ ����//0704
	MSG_SYS_MEMPOS_CASTLE,			// �������߿��� ������������ ���̵� �Ұ�
	MSG_SYS_PET_CANT_SUMMON,		// ��ȯ �Ұ��� ����
	MSG_SYS_PET_CANT_MOUNT,			// ����Ʈ �Ұ��� ����
	MSG_SYS_PRODUCE_NO_MONEY,		// ����� ���� �Ұ�
	MSG_SYS_PRODUCE_CANNT_BOOST,	// �ν��ͷδ� ���� ���� �Ұ�
	MSG_SYS_INVALID_CHAR,			// �߸��� ���ڰ� ���ԵǾ����ϴ�
	MSG_SYS_CANNOT_DUPLICATION,		// 50 ������ �ߺ� ��� �Ұ� : new_item(n) cur_item(n)
	MSG_SYS_UPGRADE_CANT_6LEVEL_LUCKY, // ����� ���ü��� 6�̻��� �����ۿ� �߸��� ����.
	MSG_SYS_PET_NOT_HAVE_ONEMORE,	// �ϳ� �̻��� ���� �����Ҽ� �����ϴ�.
	MSG_SYS_TARGET_PKLIMITLEVEL,	// Ÿ���� PVP ������ ���� �ʾƼ� �����Ҽ� ����
	MSG_SYS_NOT_ADULT,				// ������ �ƴϸ� 10�ÿ� �����Ѵ� �޼���
	MSG_SYS_NOTTIME_GOZONE,			// ������ �̵��Ҽ� �ִ� �ð��� �ƴմϴ�.
	MSG_SYS_CANNOT_WEAR_DEADPET,	// 060221 : bs : ����� �� ���� �Ұ� : petindex(n) remainRebirth(n)
	MSG_SYS_ITEMCOMPOSITED,			// ������ �ռ� ����
	MSG_SYS_EXPIRE_ITEMCOMPOSITE,	// ������ �ռ� ���� : itemdbindex(n)
	MSG_SYS_CANNOT_RESET_MOUNT,		// �� ����Ʈ Ÿ�� ��� �Ұ�
	MSG_SYS_RESET_MOUNT,			// 60 �� ����Ʈ Ÿ�� ���
	MSG_SYS_CANNOT_SEPARATE_ITEM,	// ���յ� �ǻ��� �ƴ� ������ �и� ��û��
	MSG_SYS_SEPARATE_ITEM,			// ���յ� �ǻ� ���� : itemdbindex(n)
	MSG_SYS_RAIDMOB_REGEN,			// ���̵� ���� ���� �˸� : npcdbindex(n) x(f) z(f)
	MSG_SYS_TIMEOUT_LUCKY_ACCESSORY,// ��Ű �Ǽ����� ���Ⱓ ���� : itemdbindex(n)
	MSG_SYS_CHANGE_LUCKY_BOX,		// ��Ű ��ο� ���� ��ȯ ���� : itemdbindex(n)
	MSG_SYS_CANNOT_HAVE_DUPLICATE,	// ������ �ߺ��ؼ� ���� �� ����
	MSG_SYS_MATCHSEX,				// ������ ���� �ʽ��ϴ�.  [3/8/2007 KwonYongDae] EVENT_WHITEDAY_2007

	MSG_SYS_MEMPOSPLUS_OPEN,		// �����̾� �޸𸮺� ����
	MSG_SYS_PKMODE_CANDO,			// PK�� ������ ������ �Ǿ����ϴ�.
	MSG_SYS_NO_AUTO_ITEM,			// 70 ����Ҽ� �ִ� ������ �����ϴ�.
	MSG_SYS_EGEHA_MINLEVEL,			// ������ �̵��Ҽ� �ִ� �ּҷ���
	MSG_SYS_IRISPOINT_ALARM,		// ���̸��� �Ŵ��� %d �� ȹ���Ͽ����ϴ�. (n)Count
	MSG_SYS_FACTORY_EXP,			// ���õ��� xxx����Ͽ����ϴ�. (ll)sealskill_exp
	MSG_SYS_END_MSG,				// MSG_SYS_TYPE�� ������ �޽���
} MSG_SYS_TYPE;

typedef enum _tagMsgExchangeType
{
	MSG_EXCHANGE_REQ,			// ��ȯ �ൿ 		: req_type(uc) src_index(n) src_name(str) dest_index(n) dest_name(str)
	MSG_EXCHANGE_ITEM,			// ������ ���/����	: action(uc) item_index(n) item_db_index(n) plus(n) flag(n) used(n) used_2(n) count(ll)
								// COMPOSITE_TIME ���� used_2(n) �߰�
} MSG_EXCHANGE_TYPE;

typedef enum _tagMsgExchangeReqType
{
	MSG_EXCHANGE_REQ_REQ,			// ��ȯ ��û	
	MSG_EXCHANGE_REQ_REP,			// ��ȯ ����
	MSG_EXCHANGE_REQ_REJECT,		// ��ȯ ����/���
	MSG_EXCHANGE_REQ_REJECT_SRC,	// ��ȯ ����/��� - ��û�� ���
	MSG_EXCHANGE_REQ_REJECT_DEST,	// ��ȯ ����/��� - ��û���� ���
	MSG_EXCHANGE_REQ_READY,			// �غ� �Ϸ�
	MSG_EXCHANGE_REQ_READY_SRC,		// �غ� �Ϸ� - ��û�� ���
	MSG_EXCHANGE_REQ_READY_DEST,	// �غ� �Ϸ� - ��û���� ���
	MSG_EXCHANGE_REQ_FULL_SRC,		// �κ��丮 ���� - ��û�� ���
	MSG_EXCHANGE_REQ_FULL_DEST,		// �κ��丮 ���� - ��û���� ���
	MSG_EXCHANGE_REQ_OK,			// Ȯ��
	MSG_EXCHANGE_REQ_OK_SRC,		// Ȯ�� - ��û�� ���
	MSG_EXCHANGE_REQ_OK_DEST,		// Ȯ�� - ��û���� ���
	MSG_EXCHANGE_REQ_SRC_PET_ANYMORE,		// �� ���� ���� - ��û�� ���
	MSG_EXCHANGE_REQ_DEST_PET_ANYMORE,		// �� ���� ���� - ��û���� ���
} MSG_EXCHANGE_REQ_TYPE;

typedef enum _tagMsgExchangeItemAction
{
	MSG_EXCHANGE_ITEM_ADD,			// ������ �߰� - ��� �ʵ� ���
	MSG_EXCHANGE_ITEM_ADD_SRC,		// ������ �߰� - ��û�� ���, ��� �ʵ� ���
	MSG_EXCHANGE_ITEM_ADD_DEST,		// ������ �߰� - ��û���� ���, ��� �ʵ� ���
	MSG_EXCHANGE_ITEM_DEL,			// ������ ���� - ACTION/ITEM INDEX/COUNT
	MSG_EXCHANGE_ITEM_DEL_SRC,		// ������ ���� - ��û�� ���, ACTION/ITEM INDEX/COUNT ���
	MSG_EXCHANGE_ITEM_DEL_DEST,		// ������ ���� - ��û���� ���, ACTION/ITEM INDEX/COUNT ���
	MSG_EXCHANGE_ITEM_UPDATE_SRC,	// ������ ���� ���� - ��û�� ���, ACTION/ITEM INDEX/COUNT ���
	MSG_EXCHANGE_ITEM_UPDATE_DEST,	// ������ ���� ���� - ��û���� ���, ACTION/ITEM INDEX/COUNT ���
} MSG_EXCHANGE_ITEM_ACTION;

typedef enum _tagMsgMemposType
{
	MSG_MEMPOS_LIST,			// ������ ����Ʈ ����	: count(uc) [slot(c) zone(n) x(f) z(f) comment(str)] �ݺ� busetime(n)
	MSG_MEMPOS_WRITE,			// ������ ����		: slot(c) comment(str) zone(n) x(f) z(f)
	MSG_MEMPOS_MOVE,			// ��� ��ҷ� �̵�		: slot(c)
} MSG_MEMPOS_TYPE;

typedef enum _tagMsgEnvType
{
	MSG_ENV_TAX_CHANGE,			// ���� ����	: zone(n) sellrate(n) buyrate(n)
	MSG_ENV_WEATHER,			// ���� ����	: weather(n)
	MSG_ENV_TIME,				// �ð� �˸�	: year(n) mon(c) day(c) hour(c) min(c) sec(c)
} MSG_ENV_TYPE;

typedef enum _tagMsgGMType
{
	MSG_GM_WHOAMI,				// ��� ���� Ȯ�� : level(uc)
	MSG_GM_COMMAND,				// ��� ���	: command(str)
} MSG_GM_TYPE;

typedef enum _tagMsgPartyType
{
	MSG_PARTY_INVITE,			// ��Ƽ �ʴ�			: party_type(c) src_index(n) src_name(str) : Ŭ���̾�Ʈ���� ������ �ö��� dest�� ����
	MSG_PARTY_ALLOW,			// �ʴ� ����			: 
	MSG_PARTY_REJECT,			// �ʴ� ����/��� ��û	: 
	MSG_PARTY_REJECT_SRC,		// �ʴ� ����/��� ����	: 
	MSG_PARTY_REJECT_DEST,		// �ʴ� ����/��� ����	: 
	MSG_PARTY_ADD,				// ��Ƽ�� �߰�			: is_boss(c) char_index(n) char_name(str) job(c) job2(c) level(n) cur_hp(n) max_hp(n) cur_mp(n) max_mp(n) x(f) z(f) ylayer(c) zone(n)
	MSG_PARTY_QUIT,				// ��Ƽ Ż��			: char_index(n)
	MSG_PARTY_KICK,				// ��Ƽ�� �߹�			: char_index(n)
	MSG_PARTY_END,				// ��Ƽ ��ü			: 
	MSG_PARTY_MEMBER_INFO,		// ��Ƽ�� ����			: char_index(n) level(n) cur_hp(n) max_hp(n) cur_mp(n) max_mp(n) x(f) z(f) h(f) r(f) ylayer(c) zone(n)
	MSG_PARTY_ERROR,			// ��Ƽ ���� ����		: errorcode(c)
	MSG_PARTY_ASSISTINFO,		// ��Ƽ�� ���� ȿ�� ����: char_index(n) assist_state(n:s) assist_count(c:s) [itemidx(n:s) index(n:s) level(c:s) remain(n:s)]:count
	MSG_PARTY_CHANGEBOSS,		// ��Ƽ�� ����	C->S	: charname(str)
								// S->C			        : bossname(str) newbossindex(n) newname(str) bmandate(c)
	MSG_PARTY_EMPTY,			// ��Ƽ ����			: 
	MSG_PARTY_CHANGETYPE,		//						: party_type(c)

	MSG_PARTY_ENDPARTY_REQ,			// ��Ƽ ���� ��û
	MSG_PARTY_INZONE_CLEAR_REQ,		// ��Ƽ �ν���Ʈ �� �ʱ�ȭ

} MSG_PARTY_TYPE;

typedef enum _tagMsgPartyErrorType
{
	MSG_PARTY_ERROR_NOTFOUND,			// ����� ����			:
	MSG_PARTY_ERROR_ALREADY_ME,			// ���� �̹� ��Ƽ ��	:
	MSG_PARTY_ERROR_FULL,				// ��Ƽ ������			:
	MSG_PARTY_ERROR_ALREADY_TARGET,		// ����� �̹� ��Ƽ ��	:
	MSG_PARTY_ERROR_ALREADY_REQUEST,	// �̹� ��Ƽ ��û ��	:
	MSG_PARTY_ERROR_DIFF_TYPE,			// ��Ƽ ���°� Ʋ��		:
	MSG_PARTY_ERROR_NOT_BOSS,			// ��Ƽ���� �ƴ϶� ���� �Ұ�
	MSG_PARTY_ERROR_INVALID_LEVEL,      // ������ ���� �ʾ� ��Ƽ �Ұ�
	MSG_PARTY_ERROR_NOT_PARTY,			// ��Ƽ���� �ƴմϴ�
	MSG_PARTY_ERROR_NOT_PARTY_MEMBER,	// ��Ƽ���� �ƴմϴ�.
	MSG_PARTY_ERROR_PVP,				// PVP �߿��� ��Ƽ �Ұ�
} MSG_PARTY_ERROR_TYPE;


typedef enum _tagMsgQuickSlotType
{
	MSG_QUICKSLOT_LIST,			// ������ ����Ʈ		: page(uc) [slottype(c) skilltype(n) or actiontype(n) or  row(c) col(c)] 10ȸ�ݺ�
	MSG_QUICKSLOT_ADD,			// ������ �߰�, ����	: page(uc) slot(uc) slottype(c) skilltype(n) or actiontype(n) or row(c) col(c)
	MSG_QUICKSLOT_SWAP,			// ������ ����			: page(uc) slotNum1(uc) slotNum2(uc)
} MSG_QUICKSLOT_TYPE;

typedef enum _tagMsgConnType
{
	MSG_CONN_LOGIN_REQ,			// �α��� ��û			: id(str) pw(str) server(n) playmode(uc) ip(str)
	MSG_CONN_LOGIN_REP,			// �α��� ����			: id(str) error_code(uc) usertype(uc) timestamp(n) paytype(uc) location(uc) timeremain(n)
	MSG_CONN_LOGOUT_REQ,		// �α׾ƿ� ��û		: id(str)
	MSG_CONN_BLOGIN_REQ,		// ���� �α��� ��û		: id(str) ip(str)
	MSG_CONN_BLOGOUT_REQ,		// ���� �α׾ƿ� ��û	: id(str)
	MSG_CONN_PLAYING,			// ���� ����			: id(str) mode(uc) zone(n)
	MSG_CONN_PLAYER_REQ,		// �������� ������ ��û	: 
	MSG_CONN_PLAYER_REP,		// �������� ������ ����	: serverno(n) count(n) [subno(n) usercount(n) ip(str) port(n)]:count
	MSG_CONN_REBOOT_REQ,		// ������ ���� ����		: 
	MSG_CONN_PREOPEN_GIFT,		// �������� �̺�Ʈ		: GS->CS: userindex(n) charindex(n) cancel(c)
								//						: CS->GS: userindex(n) charindex(n) errorcode(c)
	MSG_CONN_LEVELUP_POINT,		// 10 ������ ����Ʈ		: userindex(n) point(n)
	MSG_CONN_STASH_STATE,		// â�� ���� Ȯ��		: userindex(n) charindex(n) issetpassword(c:cs) issealed(c:cs)
	MSG_CONN_STASH_CHECK_PASSWORD,	// â�� ��ȣ Ȯ��	: userindex(n) charindex(n) password(str) valid(c:cs)
									// valid			: 0: ����, 1: ���� ��ȣ Ʋ��, 2: ���
	MSG_CONN_STASH_CHANGE_PASSWORD,	// â�� ��ȣ ����	: userindex(n) charindex(n) old(str) new(str) error(c:cs)
									// error			: 0: ����, 1: ���� ��ȣ Ʋ��, 2: ���
	MSG_CONN_STASH_SEAL,		// â�� ���			: userindex(n) charindex(n) valid(c:cs)
								// valid				: 0: ����, 1: �̹� ���, 2: �׿� ����
	MSG_CONN_STASH_DELETE_PASSWORD, // â�� ��ȣ ����	: userindex(n) charindex(n) valid(c:cs)
									//					: 0: ����, 1: ������ȣƲ��
	MSG_CONN_STASH_SET_NEW_PASSWORD,// â�� ��ȣ ����	: userindex(n) charindex(n) new(str) error(c:cs)
									// error			: 0: ����, 1: ����, 2: ����

	MSG_CONN_CASHITEM_BALANCE_REQ,	// �� ĳ�� ��û	
	MSG_CONN_CASHITEM_BALANCE_REP,  // ����				: userid(str) errorcode(c) cashBalance(n)
	MSG_CONN_CASHITEM_PURCHASE_REQ,	// ��������� ����	: userid(str) charindex(n) cash(n) count(n) ctid(n)
	MSG_CONN_CASHITEM_PURCHASE_REP,	// 20 ����				: userid(str) errorcode(c) cashBalance(n)
	MSG_CONN_CASHITEM_BRING_REQ,	// ��������� ��������: userindex(n) charindex(n) count(n) idx(n)
	MSG_CONN_CASHITEM_BRING_REP,	// ����				: charindex(n) errorCode(uc) count(n) ctid(n)
	MSG_CONN_CASHITEM_PURCHASELIST_REQ, // ���Ը��     : userindex(n) charindex(n)
	MSG_CONN_CASHITEM_PURCHASELIST_REP, // ����			: charindex(n) errorCode(uc) count(n) idx(n) ctid(n)
	MSG_CONN_CASHITEM_PURCHASEHISTORY_REQ,//���ų���	: userindex(n) charindex(n) y(n) m(c) d(c)
	MSG_CONN_CASHITEM_PURCHASEHISTORY_REP,//����		: charindex(n) errorcode(uc) count(n) ctid(n)

	MSG_CONN_EVENT_2PAN4PAN_LETTER_REQ,				// 2��4�� ������ ���� �̺�Ʈ ��û : userindex(n) charindex(n) MSG_EVENT_2PAN4PAN_WORD_TYPE(n)
	MSG_CONN_EVENT_2PAN4PAN_LETTER_REP,				// 2��4�� ������ ���� �̺�Ʈ ���� : userindex(n) charindex(n) MSG_EVENT_2PAN4PAN_WORD_TYPE(n)
	MSG_CONN_EVENT_2PAN4PAN_LETTER_ROLLBACK_REQ,	// 2��4�� ������ ���� �̺�Ʈ �ѹ� ��û : userindex(n) charindex(n) MSG_EVENT_2PAN4PAN_WORD_TYPE(n)
	MSG_CONN_EVENT_2PAN4PAN_LETTER_ROLLBACK_REP,	// 30 2��4�� ������ ���� �̺�Ʈ �ѹ� ���� : userindex(n) charindex(n) MSG_EVENT_2PAN4PAN_WORD_TYPE(n)

	MSG_CONN_EVENT_2PAN4PAN_GOODS_REQ,				// 2��4�� ������ ������ �̺�Ʈ ���� ��û : userindex(n) charindex(n)
	MSG_CONN_EVENT_2PAN4PAN_GOODS_REP,				// 2��4�� ������ ������ �̺�Ʈ ���� ���� : userindex(n) charindex(n) count(n) [goodindex(n) itemdbindex(n) itemcount(ll)]*count
													// count�� �ִ� 20
	MSG_CONN_EVENT_2PAN4PAN_GOODS_COMMIT,			// 2��4�� ������ ������ �̺�Ʈ ���� Ȯ�� : userindex(n) charindex(n) count(n) [goodindex(n)]*count
													// count�� �ִ� 20

	MSG_CONN_EVENT_2PAN4PAN_BOX_REQ,				// 2��4�� ���� �̺�Ʈ ���� ��û : userindex(n) charindex(n)
	MSG_CONN_EVENT_2PAN4PAN_BOX_REP,				// 2��4�� ���� �̺�Ʈ ���� ���� : userindex(n) charindex(n) count(n) [goodindex(n) itemdbindex(n) itemcount(ll)]*count
													// count�� �ִ� 20
	MSG_CONN_EVENT_2PAN4PAN_BOX_COMMIT,				// 2��4�� ���� �̺�Ʈ ���� Ȯ�� : userindex(n) charindex(n) count(n) [goodindex(n)]*count
													// count�� �ִ� 20

	MSG_CONN_EVENT_2PAN4PAN_MONEY_REQ,				// 2��4�� �Ӵ� �̺�Ʈ ��û		: userindex(n) charindex(n) itemindex(n)
	MSG_CONN_EVENT_2PAN4PAN_MONEY_REP,				// 2��4�� �Ӵ� �̺�Ʈ ����		: userindex(n) charindex(n) itemindex(n)

	MSG_CONN_RANKER_REQ,				// ��Ŀ ���� �о� ���� : username(n) charindex(n)
	MSG_CONN_RANKER_REP,				// 40 ��Ŀ ����		   : errorCode(uc) brank(c)

	MSG_CONN_COUPON_CONFIRM,		// ������ȣ Ȯ��	: charindex(n) coupon(str)
									// CS->GS			: charindex(n) errorCode(c) : eventerror���
	MSG_CONN_COUPON_USE,			// ���� ���		: charindex(n) couponIdx(n)
									// CS->GS			: charindex(n) errorCode(c) : eventerror���
	MSG_CONN_PCBANG_ITEM_GIVE,		// ��ϵ� PC�� ���� �ɸ��Ϳ��� ������ ����
									// CS->GS			: userindex(n) type(c)
	MSG_CONN_LCTIME,				// CS->GS ��ī�� 	: lctime(n) lcstartime(n)

	MSG_CONN_MOVESERVER_OK,			// ���� �̵��� �Ϸ��ϱ� ���� ������->���� �޽��� : userindex(n)
	
	MSG_CONN_LIMIT_CATALOG,			// ����Ʈ�� �ȸ� ��ǰ�� ������ �� ���Ӽ����� ����  CS->GS : count(n) ctid(n) sell(n)
									//							   �� ��ǰ ������ ���� GS->CS : ctid(n) sell(n)
	MSG_CONN_CASHITEM_GIFT,				// ���� ������ ��û	: sendcharName(str) Msg(str) recvuserIndex(n) recvcharName(str) count(n) idx(n) ctid(n)
										//			����	: errcode(uc) 
	MSG_CONN_CASHITEM_GIFT_SENDHISTORY,  // ���� ���� ����Ʈ ��û : y(n) m(c) d(c)
										 // ����				: errorcode(uc) count(n) ctid(n) recvcharName(str)
	MSG_CONN_CASHITEM_GIFT_RECVHISTORY,  // ���� ���� ����Ʈ ��û : y(n) m(c) d(c)
										 // ����				: errorcode(uc) count(n) ctid(n) sendcharName(str)
	MSG_CONN_CASHITEM_GIFT_RECVLIST,     // 50 ���� ���� ����Ʈ ��û
										 // ����				: listflag(c) count(n) idx(n) ctid(n) date(un) sendcharName(str) msg(str)
	MSG_CONN_CASHITEM_GIFT_RECV,		// ���� �ޱ�		: count(n) idx(n) ctid(n)
										// ���� �ޱ�		: errCode(uc)

	MSG_CONN_EVENT_PARTNER_CODENEO_REQ,	// ��Ʈ�� �̺�Ʈ codeNEO �ű� ������ ��� ������

	MSG_CONN_OPEN_BETA_GIFT,		// ���� ��Ÿ �̺�Ʈ		: GS->CS: userindex(n) charindex(n) cancel(c)
								   //						: CS->GS: userindex(n) charindex(n) errorcode(c)

	MSG_CONN_GPARA_PROMOTION,		// �Ϻ� GPARA ���θ�� : subtype(n) userindex(n) charindex(n)

	MSG_CONN_COUPON_CONFIRM_NEW,		// ������ȣ Ȯ��	: charindex(n) coupon(str)
									// CS->GS			: charindex(n) errorCode(c) : eventerror���
	MSG_CONN_COUPON_USE_NEW,			// ���� ���		: charindex(n) couponIdx(n)
									// CS->GS			: charindex(n) errorCode(c) : eventerror���

	MSG_CONN_EVENT_GOMDORI_2007,	// 2007�� 4�� ������ �̺�Ʈ : subtype(uc) ...

	MSG_CONN_EVENT_FLOWERTREE_2007, // 2007�� �ɳ��� �̺�Ʈ :subtype (uc), charIndex(n),

	MSG_CONN_MSN_PROMOTION,		// �Ϻ� MSN ���θ�� : subtype(n) userindex(n) charindex(n)

	MSG_CONN_GMTOOL_GOMMAND,	// 60 gmtool�� ���� ��� ��ɾ� ��� ����

	MSG_CONN_GMTOOL_CHATTING,	// gmtool�� �������� ��ȭ ���� ��� ����

	MSG_CONN_GMTOOL_CHATMONITOR,	//  gmtool�� �����ϴ� ������ ��ȭ���� ��� ����
	MSG_CONN_GUILD_POINT_RANKER_REQ,	// ��Ŀ ���� �о� ���� : guildindex(n) charindex(n)
	MSG_CONN_GUILD_POINT_RANKER_REP,	// ��Ŀ ����		   : errorCode(uc) brank(c)	

	MSG_CONN_CREATEEVENT,			// �ű� ���� �̺�Ʈ : subtype(n) userindex(n) charindex(n) stime(n) etime(n) tableid(n)

	MSG_CONN_EVENT_GIFT_2007,		// ������ ���� �̺�Ʈ gs->cs userindex(n), charindex(n)

	MSG_CONN_EVENT_BJMONO_2007,		// SK BJ Mono Event : REQ : userindex(n) charIndex(n), REP : count(n) ����� ����
	
	MSG_CONN_EVENT_SSHOT_2007,		// Screen Shot Event : REQ : userindex(n) charIndex(n), REP : error(n) ���� ����

	MSG_CONN_EVENT_XMAS_2007,				// 2007�� ũ��������  �̺�Ʈ

	MSG_CONN_CASHITEM_COUPON,		// 70

	MSG_CONN_CASHITEM_PURCHASE_WITH_COUPON,

	MSG_CONN_CLIENT_RESTART,		// userid(str) masterdb �� �ӽ� �н����� ����ð� ����
	
	MSG_CONN_ATTENDANCE_COUNT,		// REQ: subtype
	
	MSG_CONN_ADD_IPOINT,			// REQ : (n)userIndex, (n)charIndex (n)type (i)fIpoint REP: (n)charIndex, (i)fIpoint
	
	MSG_CONN_EVENT_NOM,				// REQ : userIndex(n), charindex(n), REP : error(no) ���� ����

	MSG_CONN_OCN_GOO_PROMOTION,		// �Ϻ� OCN, GOO ���θ�� : subtype(n) userindex(n) charindex(n)

	MSG_CONN_CHAR_LOG,				//  ���� ĳ���� �α�

	MSG_CONN_EVENT_REQUITAL,		//  ���� �̺�Ʈ ����

	MSG_CONN_END_MSG,				// 79 � CONNECTOR �޽����� �̰� ���Ŀ� ���� �ȵȴ�
} MSG_CONN_TYPE;

typedef enum _tagMSgConnIPointType
{
	MSG_IPOINT_TYPE_TEACHER = 0,			// �İ���
	MSG_IPOINT_TYPE_LEVELUP,				// ������
	MSG_IPOINT_TYPE_PD4,					// �۽��� ����
	MSG_IPOINT_TYPE_WARCASTLE,				// ����
	MSG_IPOINT_TYPE_ATTENDANCE,				// �⼮
	MSG_IPOINT_TYPE_PLAYTIME,	// �÷��� �ð�
	MSG_IPOINT_TYPE_ACC_ATTENDANCE,			// ���� �⼮
	MSG_IPOINT_TYPE_ETC,
	MSG_IPOINT_TYPE_DELETE_CHAR,			// ĳ���� ����
	MSG_IPOINT_TYPE_CANCEL_DELETE_CHAR,		// ĳ���� ���� ���
	MSG_IPOINT_TYPE_USEITEM,				// ������ ���
} MSG_CONN_IPOINT_TYPE;

typedef enum _tagMSgConnEventAttendanceRewardType
{
	MSG_ATTENDANCE_COUNT,					// REQ userid(n) charid(n) REP : charid(n) count(n)
	MSG_ATTENDANCE_UPDATE,					// REQ userid(n) charid(n) REP : NONE
} MSG_CONN_EVENT_ATTENDANCE_EVENT_TYPE;

typedef enum _tagMSgConnEventXMas2007Type
{
	MSG_CONN_EVENT_XMASTREE_ADDPOINT,		// REQ : (un)point, 
	MSG_CONN_EVENT_XMASTREE_POINT,			// REQ : NOT , REP : (un) Point
	MSG_CONN_EVENT_XMASTREE_ITEMDROP,		// REQ:NONE , REP: (n)remainTime ���� �ð�
} MSG_CONN_EVENT_XMAS_2007_TYPE;

typedef enum _tagMSgConnEventSshot2007Type
{
	MSG_CONN_EVENT_SSHOT_CHECK,			// REQ : userindex(n), charindex(n), REP charindex(n), error(n)
	MSG_CONN_EVENT_SSHOT_UPDATE,		
} MSG_CONN_EVENT_SSHOT_2007_TYPE;

typedef enum _tagMSgConnEventBjMono2007Type
{
	MSG_CONN_EVENT_BJMONO_TICKET_CHECK,			// REQ : userindex(n), charindex(n), REP charindex(n), giveTicketCount(n)
	MSG_CONN_EVENT_BJMONO_TICKET_UPDATE,	
} MSG_CONN_EVENT_BJMONO_2007_TYPE;

typedef enum _tagMSgConnEventGift2007Type
{
	MSG_CONN_EVENT_GIFT_2007_CHECK,
	MSG_CONN_EVENT_GIFT_2007_GIVE,
	MSG_CONN_EVENT_GIFT_2007_CHECK_ALLOW,
	MSG_CONN_EVENT_GIFT_2007_CHECK_DBERROR,
	MSG_CONN_EVENT_GIFT_2007_CHECK_DENY,
	MSG_CONN_EVENT_GIFT_2007_GIVE_DBERROR,
	MSG_CONN_EVENT_GIFT_2007_GIVE_FULL,
} MSG_CONN_EVENT_GIFT_2007_TYPE;

typedef enum _tagMsgConnEventFlowerTree2007Type
{
	MSG_CONN_EVENT_FLOWERTREE_2007_ADDPOINT,		// ����Ʈ ���� REQ : point(un) 
	MSG_CONN_EVENT_FLOWERTREE_2007_TREE_POINT,		// ����Ʈ ���� REQ: not REP : point0 (un) 
	MSG_CONN_EVENT_FLOWERTREE_2007_TREE_POINT_RANK,	// ��ü ����Ʈ ��û REQ: not REP: servercnt(n) point0 (un) point1(un)...
}MSG_CONN_EVENT_FLOWERTREE_2007_TYPE;

typedef enum _tagMsgConnEventGomdori2007Type
{
	MSG_CONN_EVENT_GOMDORI_2007_COUNT,		// ī��Ʈ ����(���� ����)
	MSG_CONN_EVENT_GOMDORI_2007_STATUS,		// ��Ȳ ���� : charindex(n) count(n) [status(n)]:count
} MSG_CONN_EVENT_GOMDORI_2007_TYPE;

typedef enum _tagMsgConnEventNomType
{
	MSG_CONN_EVENT_NOM_REQ,							// ���� ��û
	MSG_CONN_EVENT_NOM_OK,							// ���� ����
	MSG_CONN_EVENT_ERROR_ALREADY_APPLY,				// �̹� ���� ��..
	MSG_CONN_EVENT_NOM_LOTTERY_NO_GIVE,				// ���� ������
	MSG_CONN_EVENT_NOM_MOVIE_TICKET_REQ,			// ��ȭ Ƽ�� ��� ��û
	MSG_CONN_EVENT_NOM_MOVIE_TICKET_OK,				// ��ȭ Ƽ�� ��� ����
} MSG_CONN_EVENT_NOM_TYPE;

typedef enum _tagMsgConnEventRequitalType
{
	MSG_CONN_EVENT_REQUITAL_REQ,					// ���� ��û
	MSG_CONN_EVENT_REQUITAL_OK,						// ���� ����
	MSG_CONN_EVENT_REQUITAL_FAIL,					// ���� ����
	MSG_CONN_EVENT_REQUITAL_FAIL_TIME,				// �ش� ��¥�� ������ ���� �ʾƼ� ����
	MSG_CONN_EVENT_REQUITAL_FAIL_CREATE_TIME,		// ������ ������ ������ ��¥�� �ʹ� �̸�
	MSG_CONN_EVENT_REQUITAL_ALREADY_APPLY,			// �̹� ���� �޾���..
} MSG_CONN_EVENT_REQUITAL_TYPE;

typedef enum _tagMsgConnGparaPromotionType
{
	MSG_CONN_GPARA_PROMOTION_QUERY,		// GS->CS, �ش� ĳ���Ϳ��� �������� ���� ����
	MSG_CONN_GPARA_PROMOTION_ALLOW,		// CS->GS, �ش� ĳ���Ϳ��� ���� ���
	MSG_CONN_GPARA_PROMOTION_DENY,		// CS->GS, �ش� ĳ���Ϳ��� ���� �Ұ�
	MSG_CONN_GPARA_PROMOTION_COMMIT,	// GS->CS, �ش� ĳ���Ϳ��� ���޵Ǿ����� ���� ��û
} MSG_CONN_GPARA_PROMOTION_TYPE;

typedef enum _tagMsgConnOcnGooPromotionType
{
	MSG_CONN_OCN_GOO_PROMOTION_QUERY,		// GS->CS, �ش� ĳ���Ϳ��� �������� ���� ����
	MSG_CONN_OCN_GOO_PROMOTION_ALLOW,		// CS->GS, �ش� ĳ���Ϳ��� ���� ���
	MSG_CONN_OCN_GOO_PROMOTION_DENY,		// CS->GS, �ش� ĳ���Ϳ��� ���� �Ұ�
	MSG_CONN_OCN_GOO_PROMOTION_COMMIT,	// GS->CS, �ش� ĳ���Ϳ��� ���޵Ǿ����� ���� ��û
} MSG_CONN_OCN_GOO_PROMOTION_TYPE;

typedef enum _tagMsgConnMSNPromotionType
{
	MSG_CONN_MSN_PROMOTION_QUERY,		// GS->CS, �ش� ĳ���Ϳ��� �������� ���� ����
	MSG_CONN_MSN_PROMOTION_ALLOW,		// CS->GS, �ش� ĳ���Ϳ��� ���� ���
	MSG_CONN_MSN_PROMOTION_DENY,		// CS->GS, �ش� ĳ���Ϳ��� ���� �Ұ�
	MSG_CONN_MSN_PROMOTION_COMMIT,	// GS->CS, �ش� ĳ���Ϳ��� ���޵Ǿ����� ���� ��û
} MSG_CONN_MSN_PROMOTION_TYPE;

typedef enum _tagMsgConnCreateEventType
{
	MSG_CONN_CREATEEVENT_CREATETABLE,	// GS->CS, �ű� ���� �̺�Ʈ �� ���̺� ���� ��û												// gs->cs : idx(n)
	MSG_CONN_CREATEEVENT_QUERY,		// GS->CS, �ش� ĳ���Ϳ��� �������� ���� ����
	MSG_CONN_CREATEEVENT_ALLOW,		// CS->GS, �ش� ĳ���Ϳ��� ���� ���
	MSG_CONN_CREATEEVENT_DENY,		// CS->GS, �ش� ĳ���Ϳ��� ���� �Ұ�
	MSG_CONN_CREATEEVENT_COMMIT,	// GS->CS, �ش� ĳ���Ϳ��� ���޵Ǿ����� ���� ��û
} MSG_CONN_CREATEEVENT_TYPE;

typedef enum _tagMsgConnErrorCode
{
	MSG_CONN_ERROR_SUCCESS,							// ����
	MSG_CONN_ERROR_SYSTEM,							// �ý��� ����
	MSG_CONN_ERROR_NOMATCH,							// ���̵�/�н����� ����
	MSG_CONN_ERROR_ALREADY,							// �̹� ���� ��
	MSG_CONN_ERROR_FULLUSER,						// ����� ����
	MSG_CONN_ERROR_BLOCKEDUSER,						// ���� ��
	MSG_CONN_ERROR_PREOPEN_GIFT_INSUFF_CONDITION,	// �������� ���� ���� : ���� �Ҹ���
	MSG_CONN_ERROR_PREOPEN_GIFT_ALREADY_GIVE,		// �������� ���� ���� : ���� �Ϸ�
	MSG_CONN_ERROR_BILLING,							// ERROR BILLING SERVER
	MSG_CONN_ERROR_OPEN_BETA_GIFT_INSUFF_CONDITION,	// ���� ��Ÿ ���� ���� : ���� �Ҹ���
	MSG_CONN_ERROR_OPEN_BETA_GIFT_ALREADY_GIVE,		// ���� ��Ÿ ���� ���� : ���� �Ϸ�
} MSG_CONN_ERRORCODE;

typedef enum _tagMsgSkillType
{
	MSG_SKILL_LIST,				// ��ų ����Ʈ			: count(n) [skill_index(n) skill_level(c)] * count
	MSG_SKILL_LEARN,			// ��ų ����			: skill_index(n) is_new(uc) skill_level(c)
	MSG_SKILL_READY,			// ��ų ����			: char_type(c) char_index(n) skill_index(n) target_type(c) target_index(n) skillspeed(n)
	MSG_SKILL_FIRE,				// ��ų �ߵ�			: char_type(c) char_index(n) skill_index(n) target_type(c) target_index(n) count(n) [target_type(c) target_index(n)] * count skillspeed(n) movechar(c) x(z) z(f) h(f) r(f) y(c)
	MSG_SKILL_CANCEL,			// ��ų ���			: char_type(c) char_index(n)
	MSG_SKILL_LEARN_ERROR,		// ���� ���� �߻�		: errorcode(uc)
	MSG_SKILL_ERROR,			// ��ų ���� ����		: errorcode(c) skillindex(n) extraInfo(n)
	MSG_SKILL_AUTO_USE,			// ��ų �ڵ� ����û C->S: skillindex(n)
	MSG_SKILL_NEWYEAR_2008,		// 2008�� �ų� �̺�Ʈ ��ų : charindex1(n), charindex2(n)
	MSG_SKILL_HANARO_EVENT,		// �ϳ��� ���� �̺�Ʈ
	MSG_SKILL_LEARN_SEAL,		// ���� ��ų ����(seal): skill_index(n) is_new(uc) skill_exp(ll)
} MSG_SKILL_TYPE;

typedef enum _tagMsgSkillErrorType
{
// 050401 : bs : ��ų ��� �Ұ� ����
	MSG_SKILL_ERROR_ALREADY_USE,			// �ٸ� ��ų �����
	MSG_SKILL_ERROR_NOTFOUND,				// �׷� ��ų �����
	MSG_SKILL_ERROR_NOTREADY,				// ��ų �غ� ��... ��, ���� ��ų ������ ���� ��ų ���� �ð��� �ȵǾ�����
	MSG_SKILL_ERROR_INVAL_TARGET,			// Ÿ���� �߸��Ǿ���
	MSG_SKILL_ERROR_INSUFF_HP,				// ������ ������ HP
	MSG_SKILL_ERROR_INSUFF_MP,				// ������ ������ MP
	MSG_SKILL_ERROR_INSUFF_ITEM,			// ������ ������ Item
	MSG_SKILL_ERROR_LONG,					// �־ �ȵ�
	MSG_SKILL_ERROR_INVAL_STATE_DEATH,		// ���� �Ҹ��� : �׾�� ����
	MSG_SKILL_ERROR_INVAL_STATE_WEAPON,		// ���� �Ҹ��� : ���� ���ø� ����
	MSG_SKILL_ERROR_INVAL_STATE_SITDOWN,	// ���� �Ҹ��� : �ɾƼ��� ����
	MSG_SKILL_ERROR_INVAL_STATE_PEACEZONE,	// ���� �Ҹ��� : �ǽ��� �Ұ���
	MSG_SKILL_ERROR_INVAL_STATE_STAND,		// ���� �Ҹ��� : ������ ����
	MSG_SKILL_ERROR_INVAL_STATE_SHIELD,		// ���� �Ҹ��� : ���� ������
	MSG_SKILL_ERROR_INVAL_STATE_MAGIC,		// ���� �Ҹ��� : �ʿ� ���� �����
	MSG_SKILL_ERROR_STATPOINT_STR,			// �� ����
	MSG_SKILL_ERROR_STATPOINT_DEX,			// ��ø ����
	MSG_SKILL_ERROR_STATPOINT_INT,			// ���� ����
	MSG_SKILL_ERROR_STATPOINT_CON,			// ü�� ����
	MSG_SKILL_ERROR_CANNOT_SPELL,			// ��ų ��� �Ұ��� ����
	MSG_SKILL_ERROR_TARGET_PKLIMITLEVEL,			// Ÿ�� PK���� �̴�
	MSG_SKILL_ERROR_ELEMENTAL_TIME,			// ��ȯ �Ұ��� : ��ȯ�� ����� 5�е��� ��ȯ �Ұ�
	MSG_SKILL_ERROR_ELEMENTAL_FIRE,			// ��ȯ �Ұ��� : �������ɰ� �ߺ� �Ұ�
	MSG_SKILL_ERROR_ELEMENTAL_WIND,			// ��ȯ �Ұ��� : �ٶ������ɰ� �ߺ� �Ұ�
	MSG_SKILL_ERROR_ELEMENTAL_EARTH,		// ��ȯ �Ұ��� : ���������ɰ� �ߺ� �Ұ�
	MSG_SKILL_ERROR_ELEMENTAL_WATER,		// ��ȯ �Ұ��� : �������ɰ� �ߺ� �Ұ�
	MSG_SKILL_ERROR_EVOCATION_ALREADY,		// ���� �Ұ��� : �̹� ���Ż���
	MSG_SKILL_ERROR_EVOCATION_TIME,			// ���� �Ұ��� : ���� ������ 5�е��� �Ұ�

	MSG_SKILL_ERROR_CANNOT_INVISIBLE,		// ������ Ÿ���� �Ǿ� �κ�������Ƽ �Ұ���
	MSG_SKILL_ERROR_CANNOT_DEATHMOTION_ANOTHER_PC,	// 15���� �̳��� �ٸ� ������ �־� ������� �Ұ���
	MSG_SKILL_ERROR_MISS_ROGUE_SKILL,		// ���ϵ� ��� ��ų(index 125) ����
	MSG_SKILL_ERROR_COMPETITION,			// ������ ������ ��� �ð��� �ȵǾ���
// --- 050401 : bs : ��ų ��� �Ұ� ����
} MSG_SKILL_ERROR_TYPE;

typedef enum _tagMsgAssistType
{
	MSG_ASSIST_ADD,				// ���� ��ȭ �߰�		: chartype(c) charidx(n) itemidx(n) index(n) level(c) time(n)
	MSG_ASSIST_DEL,				// ���� ��ȭ ����		: chartype(c) charidx(n) itemidx(n) index(n)
	MSG_ASSIST_LIST,			// ����Ʈ ����(�ڽſ���): state(n) count(c) [itemidx(n) index(n) level(c) time(n)]:count
} MSG_ASSIST_TYPE;

typedef enum _tagMsgEffectType
{
	MSG_EFFECT_SKILL,			// ��ų ����Ʈ			: skill_index(n) targettype(c) target_index(n)
	MSG_EFFECT_ETC,				// ��Ÿ ����Ʈ			: type(c) chartype(c) char_index(n) effect_type(uc)
	MSG_EFFECT_PRODUCE,			// ���� ����Ʈ			: type(c) chartype(c) char_index(n) target_chartype(c) target_index(n) target_hp(n)
	MSG_EFFECT_ITEM,			// ������ ��� ����Ʈ	: type(c) chartype(c) char_index(n) item_db_idx(n)
	MSG_EFFECT_FIRE,			// �ұ�� ����Ʈ		: type(c) 
} MSG_EFFECT_TYPE;

typedef enum _tagMsgEffectEtcType
{
	MSG_EFFECT_ETC_LEVELUP,				// ������ ����Ʈ
	MSG_EFFECT_ETC_GOZONE,				// Gozone ����Ʈ
	MSG_EFFECT_ETC_PRODUCE_MINING,		// ���� ���� ����Ʈ
	MSG_EFFECT_ETC_PRODUCE_GATHERING,	// �Ĺ� ���� ����Ʈ
	MSG_EFFECT_ETC_PRODUCE_CHARGE,		// ���� ���� ����Ʈ
	MSG_EFFECT_ETC_ITEM_PROCESS,		// ���� ���� ����Ʈ
	MSG_EFFECT_ETC_ITEM_MAKE,			// ���� ���� ����Ʈ
	MSG_EFFECT_ETC_MP_STEEL,			// MP ��ƿ ���� ����Ʈ
	MSG_EFFECT_ETC_HP_STEEL,			// HP ��ƿ ���� ����Ʈ
	MSG_EFFECT_ETC_FIRECRACKER,			// ���� ������ 
	MGS_EFFECT_ETC_COMPETITION,			// ������ ������ ����Ʈ
} MSG_EFFECT_ETC_TYPE;

typedef enum _tagQuestType
{
	MSG_QUEST_PC_LIST,			// ����Ʈ ����Ʈ(PC)	: quest_count(n) [quest_index(n) current_count0-2(n)] quest_count ��ŭ �ݺ�
	MSG_QUEST_REQUEST,			// ����Ʈ ��û			: npc_index(n)
	MSG_QUEST_NPC_LIST,			// ����Ʈ ����Ʈ(NPC)	: quest_count(n) [quest_index(n) flag(c)]
	MSG_QUEST_CREATE_LIST,		// ����Ʈ ����Ʈ(����)	: quest_count(n) [quest_index(n)]
	MSG_QUEST_START,			// ����Ʈ ����			: quest_index(n)
	MSG_QUEST_COMPLETE,			// ����Ʈ �Ϸ�			: quest_index(n)
	MSG_QUEST_STATUS,			// ����Ʈ ��Ȳ			: quest_index(n) current_count0-2(n)
	MSG_QUEST_PRIZE,			// ����Ʈ ����			: quest_index(n)
	MSG_QUEST_GIVEUP,			// ����Ʈ ����			: quest_index(n)
	MSG_QUEST_FAIL,				// ����Ʈ ����			: quest_index(n)
	MSG_QUEST_ERROR,			// ����Ʈ ����			: error_type(c)

	MSG_QUEST_DONE_LIST,		// ����Ϸ��� ����Ʈ ����Ʈ  : quest_count(n) [quest_index(n)]
	MSG_QUEST_ABANDON_LIST,		// ���� ������ ����Ʈ ����Ʈ : quest_count(n) [quest_index(n)]
	MSG_QUEST_FORCE_GIVEUP,		// ����Ʈ ���� ����(�������� ����..) : quest_index(n)
	MSG_QUEST_UNCOMPLETE,			// ����Ʈ �̿Ϸ�.(�Ϸ�->�̿Ϸ� ���º�ȯ��)

	// �۽��� ���� 4�� �޼���
	MSG_QUEST_PD4_RANK_VIEW_REQ,			// ��ũ ���û	: charjob(c)
	MSG_QUEST_PD4_RANK_VIEW_REP,			// ��ũ ������	: multicount(c) charname(str) bclear(c) deadmon(n) time(ll)   
	MSG_QUEST_PD4_RANK_REWARD_RANK_REQ,	// ���� ���û
	MSG_QUEST_PD4_RANK_REWARD_RANK_REP,	// ���� ������	: multicount(c) charname(str) itemindex(n) itemnum(c) breward(c)
	MSG_QUEST_PD4_REWARD,					// ���� ��û

	MSG_QUEST_PD4_ERROR,		// ����Ʈpd4����		: error_type(c)

	MSG_QUEST_COLLECT,			// ���� ����Ʈ			: npcserverindex(n) charindex(n:s) itemdbindex(n:s)
								// C->S�� MSG_QUEST_COLLECT�� 8�ʿ� ���� 4ȸ���� ����Ʈ �������� ������
								// itemdbindex > 0  : NPC�� ����ϰ� itemdbindex�� ������
								// itemdbindex == 0 : NPC�� ����ϰ� ������ ���� ����
								// itemdbindex < 0  : NPC�� �״�� �ְ� ������ ���� ����

} MSG_QUEST_TYPE;

typedef enum _tagQuestListFlag
{
	MSG_QUEST_FLAG_NOT_LEVEL,		// ���� �Ұ��� : ����
	MSG_QUEST_FLAG_NOT_JOB,			// ���� �Ұ��� : ����
	MSG_QUEST_FLAG_NOT_ITEM,		// ���� �Ұ��� : ������
	MSG_QUEST_FLAG_CAN,				// ���� ����
	MSG_QUEST_FLAG_ING,				// ���� ��
	MSG_QUEST_FLAG_COMPLETE,		// ���� �Ϸ�
	MSG_QUEST_FLAG_NOT_EXP,			// ���� �Ұ��� : ����ġ ����.
	MSG_QUEST_FLAG_NOT_PREQUEST,	// ���� �Ұ��� : ���� ����Ʈ �̿Ϸ�.
	MSG_QUEST_FLAG_NOTENOUGH_AREA,	// ���� �Ұ��� : �۽��� ���� ������ ����
	MSG_QUEST_FLAG_OVERCOUNT,		// ���� �Ұ��� : �۽��� ���� ���� ���� �ʰ�
	MSG_QUEST_FLAG_NOT_PENALTY	,	// ���� �Ұ��� : ����ġ ����
} MSG_QUEST_LIST_FLAG;

typedef enum _tagMsgQuestErrorType
{
	MSG_QUEST_ERR_START_ONCE,		// ����Ʈ ���۽� ���� : �̹� ������ 1ȸ�� ����Ʈ
	MSG_QUEST_ERR_START_ALREADY,	// ����Ʈ ���۽� ���� : �̹� ��������
	MSG_QUEST_ERR_START_LEVEL,		// ����Ʈ ���۽� ���� : ���� ���� �ȸ���
	MSG_QUEST_ERR_START_JOB,		// ����Ʈ ���۽� ���� : ���� ���� �ȸ���
	MSG_QUEST_ERR_START_ITEM,		// ����Ʈ ���۽� ���� : ������ ���� �ȸ���
	MSG_QUEST_ERR_START_MAX,		// ����Ʈ ���۽� ���� : �ִ� ���� ���� �� �ʰ�
	MSG_QUEST_ERR_START_FULL,		// ����Ʈ ���۽� ���� : �̱۴����� ��� �̱۴��� ����

	MSG_QUEST_ERR_DELIVERY_FULL,	// ���� ����Ʈ �� : �κ��丮�� ������ ������ ����Ʈ ����
	MSG_QUEST_ERR_PRIZE_FULL,		// ���� ������ �κ� �� ���� ���� ����
	MSG_QUEST_ERR_PRZIE_ITEM,		// ���� ������ ������ ������ ����
	MSG_QUEST_ERR_PET_NOT_HAVE_ONEMORE,		// �� �ϳ� �̻� ���� ����
	MSG_QUEST_ERR_START_PENALTY	,	// ����Ʈ ���۽� ���� : ���Ƽ ���� �ȸ���

} MSG_QUEST_ERROR_TYPE;

typedef enum _tagMsgQuestPD4ErrorType
{

	MSG_QUEST_ERR_REWARD_NOT_RANK,	// ����� ��Ŀ�� �ƴ�
	MSG_QUEST_ERR_BREWARD,			// �̹� ���� �޾���

} MSG_QUEST_PD4_ERROR_TYPE;


typedef enum _tagStatPointType
{
	MSG_STATPOINT_REMAIN,			// ���� ���� ����Ʈ : statpoint_remain(n)
	MSG_STATPOINT_USE,				// ���� ����Ʈ ��� : dest_stat(uc:client,server) change_value1(int:server:�ɷ�ġ��ȭ��) change_value2(int:server:�ɷ�ġ��ȭ��) statpoint_remain(uc:server:������)
	MSG_STATPOINT_ERROR,			// ����				: errorcode(c)
	MSG_STATPOINT_RESET,			// ����Ʈ �ʱ�ȭ	: reset_str(n) reset_dex(n) reset_int(n) reset_con(n)
} MSG_STATPOINT_TYPE;


typedef enum _tagStatPointUseType
{
	MSG_STATPOINT_USE_STR,
	MSG_STATPOINT_USE_DEX,
	MSG_STATPOINT_USE_INT,
	MSG_STATPOINT_USE_CON,
} MSG_STATPOINT_USE_TYPE;


typedef enum _tagStatPointErrorType
{
	MSG_STATPOINT_ERROR_NOTENOUGH,		// ���� ����Ʈ ����
	MSG_STATPOINT_ERROR_CANTUSE,		// ���� ����Ʈ ��� �Ұ�
	MSG_STATPOINT_ERROR_WRONGPACKET,	// Ŭ���̾�Ʈ���� �̻��� ��Ŷ�� �Դ�
	MSG_STATPOINT_ERROR_NOMONEY,		// ���� ���� �ʱ�ȭ ��û
} MSG_STATPOINT_ERROR_TYPE;


typedef enum _tagSkillLearnErrorType
{
	MSG_SKILL_LEARN_ERROR_LEVEL,		// ���� ����
	MSG_SKILL_LEARN_ERROR_SP,			// ����Ʈ ����
	MSG_SKILL_LEARN_ERROR_ITEM,			// ������ ����
	MSG_SKILL_LEARN_ERROR_SKILL,		// ��ų ����
	MSG_SKILL_LEARN_ERROR_SYSTEM,		// �׿� �ý��� ����(��ų �ִ� ��ġ�� ���� ���� ���, ������ �߻��ϸ� �ȵǴ� ���!)
	MSG_SKILL_LEARN_ERROR_STR,			// �� ����
	MSG_SKILL_LEARN_ERROR_DEX,			// ���� ����
	MSG_SKILL_LEARN_ERROR_INT,			// ���� ����
	MSG_SKILL_LEARN_ERROR_CON,			// ü�� ����
} MSG_SKILL_LEARN_ERROR_TYPE;


typedef enum _tagDamageType
{
	MSG_DAMAGE_UNKNOWN = -1,			// �˼����� ����!
	MSG_DAMAGE_MELEE = 0,				// �ٰŸ� ���� ����
	MSG_DAMAGE_RANGE,					// ���Ÿ� ���� ����
	MSG_DAMAGE_MAGIC,					// ��ų ����
	MSG_DAMAGE_REFLEX,					// �ݻ� ����
	MSG_DAMAGE_LINK,					// ������ ��ũ�� ���� ����
	MSG_DAMAGE_COMBO,					// ���� �޺� ����Ʈ ������ ����
} MSG_DAMAGE_TYPE;


typedef enum _tagWarpType
{
	MSG_WARP_START,						// �̵���ġ ��� ����
	MSG_WARP_CANCEL,					// �̵���ġ ��� ����
	MSG_WARP_END,						// �̵���ġ ��� ��(10�� ������ ��)
	MSG_WARP_TELEPORT,					// ���� �̵�				: pos(n) x(f:s) z(f:s) h(f:s) r(f:s) ylayer(c:s)
	MSG_WARP_PROMPT,					// �̵� Ȯ��				: zone(n) pos(n)
	MSG_WARP_TO_REQING,					// gs->c :�����̵� ���θ� ���� ����
	MSG_WARP_TO_REQ,					// PC�� �����̵���û : charname(str)
										// gs-> c charname���� ����? : charname(str)
	MSG_WARP_TO,						// C->GS charname���� ���ο��ο� ���� ���� : charname(str) ballow(c)
	MSG_WARP_TAKE_REQ,					// pc�� ��ȯ ��û	 : charname(str)
										// gs-> c charname���� ����? : charname(str)
	MSG_WARP_TAKE_REQING,				// gs->c ��ȯ ���� 
	MSG_WARP_TAKE,						// C->GS charname���� ���ο��ο� ���� ��ȯ : charname(str) ballow(c)
	MSG_WARP_ERROR,						// errorcode(c)
} MSG_WARP_TYPE;

typedef enum _tagWarpErrorType
{
	MSG_WARP_ERROR_NOTCHAR,				// �������� �ƴϰų� �������� ����
	MSG_WARP_ERROR_NOTALLOW,			// �̵��� �������� ����
	MSG_WARP_ERROR_NOTALLOWZONE,		// �̵��Ҽ� ���� ���� �ֽ��ϴ�
	MSG_WARP_ERROR_CANCEL,				// ��û�ڰ� ���
} MSG_WARP_ERROR_TYPE;



typedef enum _tagProduceKind
{
	MSG_PRODUCE_MINING,					// ä��
	MSG_PRODUCE_GATHERING,				// ä��
	MSG_PRODUCE_CHARGE,					// ����
} MSG_PRODUCE_KIND;

typedef enum _tagProcessKind
{
	MSG_PROCESS_STONE,					// ���� ����
	MSG_PROCESS_PLANT,					// �Ĺ� ����
	MSG_PROCESS_ELEMENT,				// ���� ����
} MSG_PROCESS_KIND;

typedef enum _tagMsgSSkillType
{
	MSG_SSKILL_LIST,					// Ư�� ��ų ����Ʈ			: count(n) [sskill_index(n) sskill_level(c)] * count
	MSG_SSKILL_LEARN,					// Ư�� ��ų ����			: sskill_index(n) is_new(uc) sskill_level(c)
	MSG_SSKILL_REMOVE,					// Ư�� ��ų ����			: sskill_index(n)
	MSG_SSKILL_LEARN_ERROR,				// ���� ���� �߻�			: errorcode(uc)
} MSG_SSKILL_TYPE;

typedef enum _tagSSkillLearnErrorType
{
	MSG_SSKILL_LEARN_ERROR_LEVEL,		// ���� ����
	MSG_SSKILL_LEARN_ERROR_SP,			// SP ����Ʈ ����
	MSG_SSKILL_LEARN_ERROR_SSKILL,		// SSkill �ƿ� ����
	MSG_SSKILL_LEARN_ERROR_SSKILL_LEVEL,// SSkill Level�� �ȵ�
	MSG_SSKILL_LEARN_ERROR_SYSTEM,		// �׿� �ý��� ����(��ų �ִ� ��ġ�� ���� ���� ���, ������ �߻��ϸ� �ȵǴ� ���!)
} MSG_SSKILL_LEARN_ERROR_TYPE;

typedef enum _tagPKType
{
	MSG_PK_PENALTY_HPMP,				// hp, mp �г�Ƽ ī��Ʈ ���� : hp_count(n) mp_count(n)
	MSG_PK_ITEMSEAL,					// item ���� ��				 : tab(c) row(c) col(c) itemindex(n) flag(n)
	MSG_PK_RECOVER_HPMP,				// hp, mp ���� ��û/����	 : hp_request(c) mp_request(c)
	MSG_PK_RECOVER_ITEMSEAL,			// item ���� ���� ��û/����	 : tab(c) row(c) col(c) itemindex(n) flag(n:s)
	MSG_PK_ERROR,						// ���� ����				 : errorcode(c)
										//							 : 0 - �� ����, 1 - hp ����, 2 - mp ����, 3 - ������ ����
	MSG_PK_FREE,						// Free PK SYSTEM
	MSG_PK_CHANGE_KING,					// ī��ŷ ���� �޼��� : bChao(c) 0-���� 1-ī��, CharIndex(n) ĳ���� �ε��� 
	MSG_PK_MYZONE_ATT,					// REQ : NONE, REP : ZoneAtt(c) ( 0-Normal, 1-���� , 2-ī�� )
	MSG_PK_REMOVE_PENALTY,				// REQ : type(c) 0-����, 1-1�ܰ� , REP : succecc(c) : 0-����, 1-���� 
	MSG_PK_OTHERZONE_ALRAM,				// REQ : NONE , REP : bAram(c) 0-OFF 1-ON, charIndex(n) ĳ���� ���ؽ� 
	MSG_PK_TARGET_SHOWHP,				// REQ : On(c) 0-OFF 1-ON REP : NONE
} MSG_PK_TYPE;

typedef enum _tagEventType
{
	MSG_EVENT_ERROR,							// �����ڵ�					: errcode(uc)
	MSG_EVENT_PREOPEN_GIFT,						// �������� ���� ���� �ֱ�	: itemdbindex(n:s)
	MSG_EVENT_LATTO,							// ��� �̺�Ʈ ����			: subtype(uc)
	MSG_EVENT_LETTER,							// ���� ���߱� �̺�Ʈ		: subtype(uc)
	MSG_EVENT_CHANGEWEAPON,						// ���� ��ȯ �̺�Ʈ			: olddbindex(n:s) newdbindex(n:s)
	MSG_EVENT_MOONSTONE,						// ������ �̺�Ʈ.
	MSG_EVENT_TREASUREBOX,						// �������� �̺�Ʈ.
	MSG_EVENT_SUPERSTONE,						// ���۰��� �̺�Ʈ.//0627
	MSG_EVENT_CHUSEOK_UPGRADE,					// �߼� �̺�Ʈ ���׷��̵�	: 
	MSG_EVENT_CHUSEOK_EXCHANGE,					// �߼� �̺�Ʈ ��ȯ			: 
	MSG_EVENT_CHANGE_WITHOUT_OPTION,			// 10 2��4�� ������ ���� ��ü �̺�Ʈ : old_itemindex(n) new_subtype(n)
	MSG_EVENT_2PAN4PAN_LETTER,					// 2��4�� ������ ���� �̺�Ʈ : MSG_EVENT_2PAN4PAN_WORD_TYPE(n)

	MSG_EVENT_2PAN4PAN_GOODS_CHECK,				// 2��4�� ������ ������ ����Ʈ ��û : count(n:server)
	MSG_EVENT_2PAN4PAN_GOODS_REQ,				// 2��4�� ������ ������ �ޱ� ��û :
	MSG_EVENT_2PAN4PAN_GOODS_REP,				// 2��4�� ������ ������ �ޱ� ���� : MSG_EVENT_2PAN4PAN_GOODS_ERROR_TYPE(n) count(n) [itemdbindex(n) itemcount(ll)]*count

	MSG_EVENT_2PAN4PAN_MONEY_REQ,				// 2��4�� �Ӵ� ī�� ��ȯ ��û : type(n)
												// type : 1 - �°�, 2 - ��Ŀ
	MSG_EVENT_2PAN4PAN_MONEY_REP,				// 2��4�� �Ӵ� ī�� ��ȯ ���� : success(n)
												// success : 0 - ����, 1 - �°� ����, 2 - ��Ŀ����

	MSG_EVENT_2PAN4PAN_BOX_CHECK,				// 2��4�� ���� ��ȯ �˻�	: count(n:server)
	MSG_EVENT_2PAN4PAN_BOX_REQ,					// 2��4�� ���� ��ȯ ��û	: 
	MSG_EVENT_2PAN4PAN_BOX_REP,					// 2��4�� ���� ��ȯ ����	: MSG_EVENT_2PAN4PAN_BOX_ERROR_TYPE(n) count(n)  [itemdbindex(n) itemcount(ll)]*count

	MSG_EVENT_XMAS_2005,						// 20 2005 ũ�������� �̺�Ʈ : MSG_EVENT_XMAS_2005_ERROR_TYPE(n:server)
	MSG_EVENT_NEWYEAR_2006_CHECK,				// 2006 �ų� �̺�Ʈ �ð� ��û : time_sec(n:server)
	MSG_EVENT_NEWYEAR_2006_GOODS,				// 2006 �ų� �̺�Ʈ ����  : MSG_EVENT_NEWYEAR_2006_GOODS_ERROR_TYPE(n:server)

	MSG_EVENT_SEARCHFRIEND_ADD_CHECK,			// �޸��ɸ� ��� üũ : MSG_EVENT_SEARCHFRIEND_ERROR_TYPE(n)
	MSG_EVENT_SEARCHFRIEND_ADDSELECT_LIST,		// ����� ����Ʈ �κ� : listCount(n), startindex(n), nTotal(n), [requestindex(n), reqnick(char)]*listCount 
	MSG_EVENT_SEARCHFRIEND_ADDSELECT_CHECK,		// ����� ����Ʈ�� �����ϴ� �κ� :  requestindex(n), MSG_EVENT_SEARCHFRIEND_ERROR_TYPE(n)
	MSG_EVENT_SEARCHFRIEND_TIME_CHECK,			// ��ɽð� üũ : time_sec(n:server)
	MSG_EVENT_SEARCHFRIEND_ONETIME_CHECK,		// ��ɽð� �ѽð� ���� üũ : time_sec(n:server)
	MSG_EVENT_SEARCHFRIEND_LIST_GOODS,			// ��ϵ� ģ�� ���󰡴ɿ��� : request_listmember(n), startindex(n), nTotal(n), (MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_TYPE)errcode, [reqnick[n], request_index[n], request_time[n], item_good[n]]
	MSG_EVENT_SEARCHFRIEND_GOODS_CHECK,			// ������ ���� ���� :MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_TYPE(n)

	MSG_EVENT_PACKAGE_ITEM_GIVE,				// 30 ��Ű�� ������ ���� ��û  : couponNo(str)
												// gs->client				: errorcode(c)
	MSG_EVENT_OPENBETA_CONN,					// ���º�Ÿ ������ ���� ��û: 
												// gs->client				: errorcode(c)
	MSG_EVENT_SAKURABUD,						// �ɺ����� ������ ���� ��û : cmd(c) : 0-��������,1-�尩�Ź�,2-���� 

	MSG_EVENT_OXQUIZ,							// OX ���� �̺�Ʈ			: subtype(n) ...

	MSG_EVENT_RECOMMEND,						// ��õ����					: subtype(n) ...
	MSG_EVENT_PCBANG,							// �Ǿ��� (�ݱ��� ķ����)	: ���� ����Ȥ�� ��ȯ ����  GS->C : itemindex(n)    -1�̸� ����(���ڰ� ����)
												//							: ��ȯ ��û�� C->GS :

	MSG_EVENT_WORLDCUP,							// ������ �̺�Ʈ			: subtype(n) ...
	MSG_EVENT_GOLDENBALL,						// ��纼 �̺�Ʈ			: subtype(n) ...

	MSG_EVENT_RAIN_2006,						// �帶 �̺�Ʈ				: errorcode(n:s)

	MSG_EVENT_TLD_BUDDHIST,						// �ұ� �к� �̺�Ʈ			: requesttype(c) errorcode(n:s)
												// requesttype				: 0 - ����, 1 - ������

	MSG_EVENT_COLLECT_BUG,						// 40 ���� ä��				: subtype(n) ...

	MSG_EVENT_CHUSEOK_2006,						// 2006�� �߼� �̺�Ʈ		: subtype(n) ...

	MSG_EVENT_OPEN_BETA_GIFT,					// ���� ��Ÿ ����ǰ �ֱ�	: itemdbindex(n:s)

	MSG_EVENT_XMAS_2006,						// 2006 ũ�������� �̺�Ʈ ��ȯ : cakecount(n) errcode(n:s)

	MSG_EVENT_VALENTINE_2007,					// 2007 �߷�Ÿ�ε��� �̺�Ʈ

	MSG_EVENT_WHITEDAY_2007,					// 2007 ȭ��Ʈ���� �̺�Ʈ

	MSG_EVENT_SONGKRAN_2007,					// 2007 �±� ��ũ�� �̺�Ʈ 

	MSG_EVENT_EGGS_HUNT_2007,					// 2007 �̱� ��Ȱ�� �̺�Ʈ

	MSG_NEW_EVENT_PACKAGE_ITEM_GIVE,			// NEW ��Ű�� ������ ���� ��û  : couponNo(str)
												// gs->client				: errorcode(c)

	MSG_EVENT_PARENTSDAY_2007,					// 2007 ����̳� �̺�Ʈ

	MSG_EVENT_TEACH_2007,						// 50 2007�� �����ǳ� �̺�Ʈ

	MSG_EVENT_GOMDORI_2007,						// 2007�� ������ �̺�Ʈ		: subtype(uc) ...
	
	MSG_EVENT_CHILDRENSDAY_2007,				// 2007�� ��̳� �̺�Ʈ : subtype(uc)..

	MSG_EVENT_FLOWERTREE_2007,					// 2007�� �ɳ��� �̺�Ʈ : subtype(uc)..

	MSG_EVENT_SUMMER_VACATION_2007,				// 2007�� ���� ���� �̺�Ʈ : subtype(uc)....

	MSG_EVENT_TLD_MOTHERDAY_2007,				// ��Ӵϳ� �̺�Ʈ			: requesttype(c) errorcode(n:s)
												// requesttype				: 1 - ��� ���ü� ��ȯ , 2 - Poem Book ��ȯ ,3Blessing of mother(red),
												//							: 4.Blessing of mother(yellow),5.Blessing of mother(blue)

	MSG_EVENT_OPEN_ADULT_SERVER,				// ���μ��� ����ī���̺�Ʈ

	MSG_EVENT_GIFT_2007,						// 2007�� �̺�Ʈ �Ⱓ ���� �����鿡�� ������ ��������
	
	MSG_EVENT_BJMONO_2007,						// SK bj mono �̺�Ʈ : subtype(uc)

	MSG_EVENT_SSHOT_2007,						// Screen Shot Event : Subtype(uc)

	MSG_EVENT_RICHYEAR,							// 60 ǳ�� �̺�Ʈ

	MSG_EVENT_LC_1000DAY,						// ��Ʈī���� 1000�� �̺�Ʈ 
	
	MSG_EVENT_HALLOWEEN_2007,					// 2007�� �ҷ��� �̺�Ʈ 

	MSG_EVENT_NEW_MOONSTONE,					// ������ ����

	MSG_EVENT_XMAS_2007,						// 2007�� ũ�������� �̺�Ʈ
	
	MSG_EVENT_NEWYEAR_2008,						// 2008�� �ų� �̺�Ʈ	gs->cl, cl->gs   charindex(n), charname(s)
	
	MSG_EVENT_TREASUREBOX_RED,					// ���� ���� ���� �̺�Ʈ
	
	MSG_EVENT_SAKURA_2008,						// 2008�� ���� �̺�Ʈ

	MSG_EVENT_NOM,								// ���� ��ȭ �̺�Ʈ

	MSG_EVENT_PHOENIX,							// �Ǵн� �̺�Ʈ // yhj   081105  �Ǵн�

	MSG_EVENT_PHOENIX_SUCCESS,					// �Ǵн� �̺�Ʈ �¶�// yhj   081105  �Ǵн�

	MSG_EVENT_REQUITAL,							// ���� �̺�Ʈ 
	
	MSG_EVENT_END_MSG,							// ��� �̺�Ʈ ���� �޽����� �̺��� �տ�
	
} MSG_EVENT_TYPE;

typedef enum _tagEventNomErrorType
{
	MSG_EVENT_NOM_OK,						// ���� ����
	MSG_EVENT_NOM_ERROR_ALREADY_APPLY,		// �̹� ���� ��
	MSG_EVENT_NOM_ERROR_FULL_INVEN,			// �κ��丮�� ����
	MSG_EVENT_NOM_ERROR_ITEM_FAIL,			// ������ ����
	MSG_EVENT_NOM_LOTTERY_USE_OK,			// ���� ��� ����
	MSG_EVENT_NOM_MOVIE_TICKET_OK			// Ƽ�� ��� ����	
} MSG_EVENT_NOM_ERROR_TYPE;

typedef enum _tagEventRequitalErrorType
{
	MSG_EVENT_REQUITALM_OK,						// ���� ����
	MSG_EVENT_REQUITAL_FAIL,					// ���� ����
	MSG_EVENT_REQUITAL_ERROR_ALREADY_APPLY,		// �̹� ���� ��
	MSG_EVENT_REQUITAL_FAIL_TIME,				// ���� �ð��� ������
	MSG_EVENT_REQUITAL_ERROR_FULL_INVEN,		// �κ��丮�� ����
	MSG_EVENT_REQUITAL_ERROR_TOO_HEAVY_INVEN,	// �κ��丮�� �ʹ� ���ſ�
	MSG_EVENT_REQUITAL_FAIL_TIME_NOPLAY,		// �ش� ��¥�� ������ ���� �ʾƼ� ����
	MSG_EVENT_REQUITAL_FAIL_CREATE_TIME,		// ������ ������ ������ ��¥�� �ʹ� �̸�
} MSG_EVENT_REQUITAL_ERROR_TYPE;

typedef enum _tagEventSakura2008Type
{
	MSG_EVNET_SAKURAEVENT_2008,					// non parm
	MSG_EVENT_SAKURAEVENT_2008_ERROR,			// (n) error code 0 - SUCCESS, 1-FAILED
	MSG_EVNET_SAKURAEVENT_2008_ITEMCHANGE,		//  (str) charName (n) itemIndex
} MSG_EVNET_SAKURA_2008_TYPE;

typedef enum _tagEventNewMoonStoneType
{
	MSG_EVENT_NEW_MOONSTONE_START_REQ,		// ������ ���ۿ�û
	MSG_EVENT_NEW_MOONSTONE_START_REP,		// ������ ��������		nas(n)

	MSG_EVENT_NEW_MOONSTONE_TRY_REQ,		// ������ ���� ��û		moonstone_idx(n)
	MSG_EVENT_NEW_MOONSTONE_TRY_REP,		// ������ ���� ����		giftitemindex(n) , nas(n)

	MSG_EVENT_NEW_MOONSTONE_RESULT_REQ,		// ������ ���� ��� ��û
	MSG_EVENT_NEW_MOONSTONE_RESULT_REP,		// ������ ���� ��� ����	giftitemidx(n), giftitemcount(n)
	MSG_EVENT_NEW_MOONSTONE_JACK_POT,		// ����	

	MSG_EVENT_NEW_MOONSTON_OK,				// ���������		moonstone idx(n)

	MSG_EVENT_NEW_MOONSTONE_NO_MOONSTONE,	// ������ ����		itemindex(���¹�����index)
	MSG_EVENT_NEW_MOONSTONE_FULLINVEN,		// �κ�������	

	MSG_EVENT_NEW_MOONSTONE_MIX_REQ,		// ������ ���� ��û	moonstone_idx(n) ���������չڽ�(n)
	MSG_EVENT_NEW_MOONSTONE_MIX_SUCCESS,	// ������ ���� ����	new_moonstone_idx(n),
	MSG_EVENT_NEW_MOONSTONE_MIX_FAILED,		// ������ ���� ����
	MSG_EVENT_NEW_MOONSTONE_MIX_MISS		// ������ ���� ���Ŀ� ��߳�
} MSG_EVENT_NEW_MOONSTONE_TYPE;

typedef enum _tagEventXMas2007Type
{
	MSG_EVENT_XMASTREE_ADD_POINT,		// REQ: NOT , REP (c)error 0:����, 1:������ ����
	MSG_EVENT_XMASTREE_GET_BLESS,		// REQ: NOT , REP (c)error 0:����, 1:������ ����
	MSG_EVENT_XMASTREE_DROP_ITEM,		// REQ: NONE, REP (n)remainTime ���� �ð�(��)
} MSG_EVENT_XMAS_2007_TYPE;

typedef enum _tagMsgEventHallowWeen2007
{
	MSG_EVENT_TAKE_DEVILHEAIR,						// �Ǹ����� �Ӹ��� �ޱ� REQ: , REP: 0(SUCCESS), 1(����������)
	MSG_EVENT_CHANGE_CANDYBASKET,					// �����ٱ��Ͽ� ���� �ޱ� REQ: , REP: 0(SUCCESS), 1(�ٱ��� ����)
	MSG_EVENT_CHANGE_PUMKINHEAD,					// ȣ�ڸӸ� Ż ��ȯ�ޱ� REQ: , REP: 0(SUCCESS) , 1(�������ڶ�)
	MSG_EVENT_CHANGE_WITCHHAT,						// ������� ��ȯ�ޱ� REQ: , REP: 0(SUCCESS), 1(��ǥ����)
	MSG_EVENT_CHANGE_PUMKIN,						// ȣ�� ��ȯ �ޱ� REQ: , REP: 0(SUCCESS), 1(ȣ�ھ���)
	MSG_EVENT_TASTE_CANDY,							// ���� �� REQ:NONE , REP : 0(�������θ�),1(�䳪���¸�),2(�׷�����),3(��������),4(õ���Ǹ�)
	MSG_EVENT_FULL_INVEN,							// �κ� ������ REQ:NONE , REP : NOT
} MSG_EVENT_HALLOWEEN_2007_TYPE;

typedef enum _tagMsgEventLC1000Day
{
	MSG_EVENT_LC_1000DAY_HAT,						// 1000�� �̺�Ʈ ���� ��û 
	MSG_EVENT_LC_1000DAY_HAT_UPDATE,				// ���� �ɼ� ������Ʈ ��û 
	MSG_EVENT_LC_1000DAY_FIRECRACKER,				// ���� ��û
	MSG_EVENT_LC_1000DAY_FULLINVEN,					// �κ��� ���� ��
	MSG_EVENT_LC_1000DAY_HAT_UPDATE_SUCCESS,		// ���� �ɼ� ������Ʈ ����
	MSG_EVENT_LC_1000DAY_HAT_UPDATE_FAIL,			// ���� �ɼ� ������Ʈ ����
	MSG_EVENT_LC_1000DAY_FIRECRACKER_DUPLICATION,	// ���� �������� �κ��� ����
	MSG_EVENT_LC_1000DAY_NOITEM,					// ������ ����
} MSG_EVENT_LC_1000DAY_TYPE;

typedef enum _tagMsgEventRichYear
{
	MSG_EVENT_RICHYEAR_UPGRADE,					// ������ ���׷��̵� ��û
	MSG_EVENT_RICHYEAR_EXCHANGE,				// ����ǰ ��ȯ
	MSG_EVENT_RICHYEAR_ERROR_UPGRADE_NOITEM,	// ���׷��̵��� ��� ����
	MSG_EVENT_RICHYEAR_ERROR_UPGRADE_FAILED,	// ���׷��̵� ����
	MSG_EVENT_RICHYEAR_ERROR_NOCROP,			// �۹��� ���� ���
	MSG_EVENT_RICHYEAR_ERROR_ALREADY_UPGRADE,	// ���̻� ���׷��̵� �Ұ���
	MSG_EVENT_RICHYEAR_ERROR_FULLINVEN,			// �κ�����
	MSG_EVENT_RICHYEAR_UPGRADE_OK,				// ���׷��̵� ����
	MSG_EVENT_RICHYEAR_EXCHAGE_OK,				// ���� ����
}MSG_EVENT_RICHYEAR_TYPE;


typedef enum _tagMsgEventSshot
{
	MSG_EVENT_SSHOT_2007_RECIVE,			// ���� �ޱ� REQ : ��û - REP : ����
	MSG_EVENT_SSHOT_2007_ALREADY,			// ������ �������� �ִ�.
	MSG_EVENT_SSHOT_2007_NOSSHOT,			// �������� ����
	MSG_EVENT_SSHOT_2007_FULLINVEN			// �κ��� ���� ��
} MSG_EVENT_SSHOT_2007_TYPE;

typedef enum _tagMsgEventBjMono
{
	MSG_EVENT_BJMONO_2007_TICKET_REQ,			// ����� �ޱ� REQ : ��û - REP : ���� count 
	MSG_EVENT_BJMONO_2007_CHANGE_TICKET_REQ,	// ����� ��ȯ REQ : ��û - REP : ���� itemIndex(n)
	MSG_EVENT_BJMONO_2007_NO_TICKET,			// ����� ����
	MSG_EVENT_BJMONO_2007_DONT_CHANGE_TICKET,	// ��ȯ�� ����� ����
	MSG_EVENT_BJMONO_2007_PRICE_FULLINVEN		// �κ��� ���� ��
} MSG_EVENT_BJMONO_2007_TYPE;

typedef enum _tagMsgEventOpenAdultServer
{
	// ����ī�����
	MSG_EVENT_OPEN_ADULT_SERVER_MAGIC_REQ,		// ����ī�庸��ޱ�
	MSG_EVENT_OPEN_ADULT_SERVER_MAGIC_OK,		// ��ų���󼺰�			exchangeType(b) 
											// exchangeType			0 : �ٶ��� �������
											//						1 : ���� �������
											//						2 : ��ø�� �������
											//						3 : ������ �������
											//						4 : ü���� �������
											//						5 : �η����� �������

	MSG_EVENT_OPEN_ADULT_SERVER_MAGIC_FAILED,	// ��ȯ ���� ( ��ų���� �������� ��)
	MSG_EVENT_OPEN_ADULT_SERVER_MAGIC_NOITEM,	// ������ ����			

	// ��������
	MSG_EVENT_OPEN_ADULT_SERVER_CHABGEJOB_EXCHANGE,		// ������ �����û
	MSG_EVENT_OPEN_ADULT_SERVER_CHABGEJOB_EXCHANGE_OK,		// ���󼺰�	: ���(n), �����Ǻ��� ���󰳼�(n)
	
	MSG_EVENT_OPEN_ADULT_SERVER_CHABGEJOB_ERROR_ALREADY,	// ��ǰ�̹� �޾���
	MSG_EVENT_OPEN_ADULT_SERVER_CHABGEJOB_ERROR_FAILED,		// ������ ���ؼ� ����	
	MSG_EVENT_OPEN_ADULT_SERVER_CHABGEJOB_ERROR_FULLINVEN,	// �κ�����

	// ������ ���հ���
	MSG_EVENT_OPEN_ADULT_SERVER_UPGRADE_REQ,			// ������ ���׷��̵� ��û : tab(n), row(n), col(n)
	MSG_EVENT_OPEN_ADULT_SERVER_UPGRADE_OK,

	MSG_EVENT_OPEN_ADULT_SERVER_UPGRADE_ERROR_NOT_FOUND,	// ��� ����
	MSG_EVENT_OPEN_ADULT_SERVER_UPGRADE_ERROR_FAILED,		// ���׷��̵� ����
	MSG_EVENT_OPEN_ADULT_SERVER_UPGRADE_ERROR_FULLINVEN,	// �κ�����
}MSG_EVENT_OPEN_ADULT_SERVER_TYPE;


typedef enum _tagMsgEventSummerVacation_2007
{
	MSG_EVENT_SUMMER_VACATION_2007_PAPER_FIGURES,	// ���� ���� ��û REQ: papaerindex(n) papaerindex(n) papaerindex(n)
													//  REP : errorcode(n) figuretype(n) itemindex(n) itemcount(n)
	MSG_EVENT_SUMMER_VACATION_2007_INCHEN,			// ��þ ��û : count(n) paperindex(uc) 
													// REP : err(n) itemindex(n)
	
	MSG_EVENT_SUMMER_VACATION_2007_ERROR_INCHEN_FALIL,	// ��þ ����
	MSG_EVENT_SUMMER_VACATION_2007_ERROR_INCHEN_OK,
	MSG_EVENT_SUMMER_VACATION_2007_ERROR_NOITEM,		// ������ ����
	MSG_EVENT_SUMMER_VACATION_2007_ERROR_MAKE_FAIL,
	MSG_EVENT_SUMMER_VACATION_2007_ERROR_MAKE_OK,
	MSG_EVENT_SUMMER_VACATION_2007_ERROR_FULLINVENTORY,	// �κ��丮 �������� ������ ���� �Ұ���
	MSG_EVENT_SUMMER_VACATION_2007_ERROR_NOMONEY,			// �� ����
} MSG_EVENT_SUMMER_VACATION_2007_TYPE;

typedef enum _tagMsgEventFlowerTree_2007
{
	MSG_EVENT_FLOWERTREE_2007_POINT, 			// ���� �ɳ��� ���� ����Ʈ   REQ : not REP: point(un)
	MSG_EVENT_FLOWERTREE_2007_POINT_RANK,		// ������ �ɳ��� ���� ����Ʈ REQ : not REP: servercnt(n) point0 (un) point1(un)...
	MSG_EVENT_FLOWERTREE_2007_GROWUP,			// �������� ����Ͽ� ��ȭ ���� REQ : not REP: givePoint(un)	
	MSG_EVENT_FLOWERTREE_2007_MY_POINT,			// ���� �⿩�� ����Ʈ REQ : not REP: point(un)
	MSG_EVENT_FLOWERTREE_2007_RECV_TICKET,		// ��ȯ�� �ޱ� REQ : not REP: count(n) 
	MSG_EVENT_FLOWERTREE_2007_OPEN_TICKET,		// ��ȯ�� Ȯ�� REQ : not REP: error(uc) 0-Ƽ�Ͼ���, 1-Ƽ�ϻ��;
	MSG_EVENT_FLOWERTREE_2007_PRICE_MSG,		// ��÷ �޼��� REP : charIndex(n), itemindex(n)
} MSG_EVENT_FLOWERTREE_2007_TYPE;

typedef enum _tagMsgEventChildrensDay_2007
{
	MSG_EVENT_CHILDRENSDAY_2007_REQ,		// ��ȯ ��û	(n)ItemIndex, (n)������ ����
	MSG_EVENT_CHILDRENSDAY_2007_REP,		// �����ڵ�		(n) 0- ��ȯ ���� + (n)ItemIndex, 1-������ ���� ����, 2-�̹� ���� ��� , 3-Unknown
}MSG_EVENT_CHILDRENSDAY_2007_TYPE;

typedef enum _tagMsgEventGomdori2007
{
	MSG_EVENT_GOMDORI_2007_CHECKITEM,			// ���������� ������ �˻�
	MSG_EVENT_GOMDORI_2007_START,				// ���������� �����ϱ�
	MSG_EVENT_GOMDORI_2007_SELECT,				// ���������� �����ϱ�	: type(c)
												// type					: ����-0, ����-1, ��-2
	MSG_EVENT_GOMDORI_2007_RESULT_WIN,			// ���������� �¸� �˸�	: wincount(c) usersel(c) npcsel(c)
	MSG_EVENT_GOMDORI_2007_RESULT_LOSE,			// ���������� �й� �˸�	: wincount(c) usersel(c) npcsel(c)
	MSG_EVENT_GOMDORI_2007_RESULT_DRAW,			// ���������� ��� �˸�	: wincount(c) usersel(c) npcsel(c)
	MSG_EVENT_GOMDORI_2007_CONTINUE,			// ���������� ��� �ϱ�
	MSG_EVENT_GOMDORI_2007_END,					// ���������� �׸� �ϱ�	: wincount(c:s) prompttype(c:s) extar1(n:s) extar2(n:s)
												// prompttype			: 0 - �Ϲ� ����: extra1(����������ε���) extra2(��������ۼ���)
												//						: 1 - ü�豳�� ����: extra1(������) extra2(������)
												//						: 2 - ���� ���� ���� �ʿ�: extra1(���þ�����1) extra2(���þ�����2)
	MSG_EVENT_GOMDORI_2007_SELECT_GIFT,			// ���⹫�� ����		: itemdbindex(n)
	MSG_EVENT_GOMDORI_2007_VIEW_STATUS,			// ��Ȳ ����			: curserver(n:s) count(n:s) [server(n:s)]:count
	MSG_EVENT_GOMDORI_2007_ERROR_NOITEM,		// ������ ������ ����
	MSG_EVENT_GOMDORI_2007_ERROR_FULLINVENTORY,	// �κ��丮 �������� ������ ���� �Ұ���
} MSG_EVENT_GOMDORI_2007_TYPE;

typedef enum _tagMsgEventParentsDay2007
{
	MSG_EVENT_PARENTSDAY_2007_ACCUMULATEPOINT_RANKING_LIST, // ����̳� ���� ����Ʈ ����Ʈ ���� ��û  c->s��  MessageType��
				  // s->c : error(c) count( n ) rankig( c ) savepoint( n ) gildname(str)
	MSG_EVENT_PARENTSDAY_2007_ADD_POINT,    // ����Ʈ ���
				  // c->s : CharIndex(n) echangeItemIndex(n)
				  // s->c : errorcode(c) point(n) totalpoint(n)
	MSG_EVENT_PARENTSDAY_2007_EXCHANGE_TICKET,   // ���� ����Ʈ�� ���� ��ȯ�� ��û
				  // s->c : errorcode(c) changeTicketCount(n)
	MSG_EVENT_PARENTSDAY_2007_EXCHANGE_ITEM,   // ��ȯ������ ������ ��ȯ ��û
	// s->c: errcode(c)
	MSG_EVENT_PARENTSDAY_2007_NOTICE, // ����	//s-c : guildName(str) itemName(str)

	MSG_EVENT_PARENTSDAY_2007_RESULT, // s->c : ranking(n)

}MSG_EVENT_PARENTSDAY_2007_TYPE;

typedef enum _tagParentsDay2007ErrorType
{
	MSG_ERROR_PARENTSDAY_2007_FULLINVEN,			// �κ� ���� ��
	MSG_ERROR_PARENTSDAY_2007_NO_EXCHAGNE_ITEM,		// ��ȯ�� ����
	MSG_ERROR_PARENTSDAY_2007_NOT_GUILD_OWNER,		// ������� �ƴմϴ�.
	MSG_ERROR_ACCUMULATEPOINT_NOT_RANKING,			// ��ŷ ����Ÿ�� �����ϴ�.
	MSG_ERROR_ADD_POINT,							// ����Ʈ ���� ����
	MSG_ERROR_NOT_ENOUGH_POINT,						// ����Ʈ ����
	MSG_ERROR_NOT_FOUND_ACCUMULATEPOINT_LIST,		// ���� ����Ʈ ������ �����ϴ�.
	MSG_ERROR_PARENTSDAY_2007_ERROR_NOITEM,			// ������ ����
	MSG_PARENTSDAY_2007_SUCCESS,					// ����
}MSG_PARENTSDAY_2007_ERROR_TYPE;


typedef enum _tagMsgEventSongkran2007
{
	MSG_EVENT_SONGKRAN_2007_EXCHANGE_OK,		// ��ȯ ����			exchangeType(b) 0-Silver,1-Gold	
	MSG_EVENT_SONGKRAN_2007_EXCHANGE_NOITEM,	// ������ ����			
	MSG_EVENT_SONGKRAN_2007_EXCHANGE_FULLINVEN,	// �κ� ���� ��
}MSG_EVENT_SONGKRAN_2007_TYPE;
	


typedef enum _tagMsgEventEggsHunt2007Type
{
	MSG_EVENT_EGGS_HUNT_2007_GIFT_REP_OK,					// ������ ���� ����
	MSG_EVENT_EGGS_HUNT_2007_ERROR_ALREADY_EXIST,			// ������ �ߺ� ���� �ȵ�
	MSG_EVENT_EGGS_HUNT_2007_ERROR_GIFT_FULLINVEN,			// �κ��丮 ����
	MSG_EVENT_EGGS_HUNT_2007_ERROR_NOITEM,					// ������ ����
} MSG_EVENT_EGGS_HUNT_2007_TYPE;


typedef enum _tagEventEggsHunt2007ChangeType
{
	MSG_EGGS_HUNT_CHANGE_50_NAS,				// 50���� 
	MSG_EGGS_HUNT_CHANGE_500_NAS,				// 500����
	MSG_EGGS_HUNT_CHANGE_QUALITY_STONE,			// ���� ����		10��
	MSG_EGGS_HUNT_CHANGE_GAMMA_WAVE_ENERGY,		// C��� ����		10��
	MSG_EGGS_HUNT_CHANGE_HERB,					// ũ���� �ٱ�		10��
	MSG_EGGS_HUNT_CHANGE_PORTION_SPEED,			// �ӵ���� ����
	MSG_EGGS_HUNT_CHANGE_BOOSTER,				// �ν���
	MSG_EGGS_HUNT_CHANGE_GREEN_STONE,			// Ǫ����
	MSG_EGGS_HUNT_CHANGE_MAGIC_STONE,			// ������
	MSG_EGGS_HUNT_CHANGE_HEAVEN_STONE,			// ������ü�
	MSG_EGGS_HUNT_CHANGE_EXPERIENCE_SCROLL,		// ������ ��ũ��
	MSG_EGGS_HUNT_CHANGE_PLATINUM_BOOSTER,		// �÷�Ƽ�� �ν���
	MSG_EGGS_HUNT_CHANGE_CAKE,					// ����ũ
	MSG_EGGS_HUNT_CHANGE_CACAO_90,				// īī�� 90
	MSG_EGGS_HUNT_CHANGE_SNOWMAN,				// ����� ����
	MSG_EGGS_HUNT_CHANGE_GREATEST_EXP_PORTION,	// ���������� ����
	MSG_EGGS_HUNT_CHANGE_25000_NAS,				// 25000 ����
}MSG_EVENT_EGGS_HUNT_2007_CHANGE_TYPE;


typedef enum _tagMsgEventWhiteday2007
{
	MSG_EVENT_WHITEDAY_2007_EXCHANGE_REQ,		// ��ȯ ��û			exchangeType(b) 0-Skill,1-SkyLetter,2-PinkLetter 
	MSG_EVENT_WHITEDAY_2007_EXCHANGE_OK,		// ��ȯ ����			exchangeType(b) 0-Skill,1-SkyLetter,2-PinkLetter  if(0) skillIdx(n)-SkillIndex
	MSG_EVENT_WHITEDAY_2007_EXCHANGE_FAILED,	// ��ȯ ���� ( ��ų�� �����ϰų�, ���� ������ ������ ���� �Ҷ�)
	MSG_EVENT_WHITEDAY_2007_EXCHANGE_NOITEM,	// ������ ����			
	MSG_EVENT_WHITEDAY_2007_EXCHANGE_FULLINVEN,	// �κ� ���� ��
	MSG_EVENT_WHITEDAY_2007_EXCHANGE_MAXITEM,	// ������ ���� �ִ밹�� �ʰ�
	MSG_EVENT_WHITEDAY_2007_LETTER_REQ,			// ������ ��� ��û		itemIndex(n), colorIndex(n), msg(str)
	MSG_EVENT_WHITEDAY_2007_LETTER_REP,			// ������ ��� ����		colorIndex(n), msg(str)
} MSG_EVENT_WHITEDAY_2007_TYPE;


typedef enum _tagMsgEventXmas2006
{
	MSG_EVENT_XMAS_2006_ERROR_OK,				// ����
	MSG_EVENT_XMAS_2006_ERROR_FULLINVEN,		// �κ� ���� ��
	MSG_EVENT_XMAS_2006_ERROR_NOITEM,			// ������ ����
} MSG_EVENT_XMAS_2006_ERROR_TYPE;


typedef enum _tagMsgEventValentine2007Type
{
	MSG_EVENT_VALENTINE_2007_PACKAGE_OK,					// ���ڷ� ������ ���� ����			errcode(n)
	MSG_EVENT_VALENTINE_2007_PACKAGE_FULLINVEN,				// �κ�����							errcode(n)

	MSG_EVENT_VALENTINE_2007_BINGO_ITEM_ARRANGE,			// ���ڷ� ���� ��û					itempos(b), itemindex(n), bingoitemindex(n)
	MSG_EVENT_VALENTINE_2007_BINGO_ITEM_ARRANGE_OK,			// ���ڷ� ���� ����					errcode(n) score(n)
	MSG_EVENT_VALENTINE_2007_BINGO_ITEM_ARRANGE_NOTPACKAGE,	// ����� ���ڷ� �������� �ƴ�		errcode(n)
	MSG_EVENT_VALENTINE_2007_BINGO_ITEM_ARRANGE_ALREADY,	// �̹� ����� �ڸ�					errcode(n)

	MSG_EVENT_VALENTINE_2007_BINGO_GIFT,					// �����û							bingoindex(n)
	MSG_EVENT_VALENTINE_2007_BINGO_GIFT_OK,					// ���󼺰�							errcode(n), num(n)
	MSG_EVENT_VALENTINE_2007_BINGO_GIFT_NOITEM,				// ���� �ϳ��� ����				errcode(n)

	MSG_EVENT_VALENTINE_2007_BINGO_ITEM_NOTFOUND,			// ����ڽ� ������ ����				errcode(n)
} MSG_EVENT_VALENTINE_TYPE;


typedef enum _tagMsgEventChuseok2006Type
{
	MSG_EVENT_CHUSEOK_2006_MAKE_RICECAKE,					// ���� ����� ��û
	MSG_EVENT_CHUSEOK_2006_MAKE_RICECAKE_OK,				// ���� ����� ����
	MSG_EVENT_CHUSEOK_2006_MAKE_RICECAKE_FAIL,				// ���� ����� ����
	MSG_EVENT_CHUSEOK_2006_MAKE_RICECAKE_NOITEM,			// ���� ��� ����
	MSG_EVENT_CHUSEOK_2006_MAKE_RICECAKE_FULLINVEN,			// �κ��丮 ����

	MSG_EVENT_CHUSEOK_2006_MAKE_RAINBOW_CAKE,				// ���� ���� ����� ��û
	MSG_EVENT_CHUSEOK_2006_MAKE_RAINBOW_CAKE_OK,			// ���� ���� ����� ����
	MSG_EVENT_CHUSEOK_2006_MAKE_RAINBOW_CAKE_FAIL,			// ���� ���� ����� ����
	MSG_EVENT_CHUSEOK_2006_MAKE_RAINBOW_CAKE_NOITEM,		// ���� ���� ��� ����
	MSG_EVENT_CHUSEOK_2006_MAKE_RAINBOW_CAKE_FULLINVEN,		// �κ��丮 ����

	MSG_EVENT_CHUSEOK_2006_GIFT,							// ���� ���� ��ȯ ��û
	MSG_EVENT_CHUSEOK_2006_GIFT_OK,							// ���� ���� ��ȯ ����
	MSG_EVENT_CHUSEOK_2006_GIFT_OK_NOITEM,					// ���� ���� ����
	MSG_EVENT_CHUSEOK_2006_GIFT_OK_FULLINVEN,				// �κ��丮 ����

} MSG_EVENT_CHUSEOK_2006_TYPE;

typedef enum _tagMsgEventCollectBugType
{
	MSG_EVENT_COLLECT_BUG_BUY_BOX_REQ,					// [C]���� ���� ��û
	MSG_EVENT_COLLECT_BUG_BUY_BOX_REP_OK,				// [S]���� ���� ���� 1�̸� ���: isgoldenbox(n)
	MSG_EVENT_COLLECT_BUG_BUY_BOX_REP_ERROR_DUPLICATE,	// [S]�̹� ������ ����
	MSG_EVENT_COLLECT_BUG_BUY_BOX_REP_ERROR_FULLINVEN,	// [S]�κ� ���� ����
	MSG_EVENT_COLLECT_BUG_BUY_BOX_REP_ERROR_MONEY,		// [S]�� ����

	MSG_EVENT_COLLECT_BUG_GIFT_REQ,						// [C]���� ��û
	MSG_EVENT_COLLECT_BUG_GIFT_REP_OK,					// [S]���� 0���� 11����: gifttype(n)
	MSG_EVENT_COLLECT_BUG_GIFT_REP_ERROR_FULLINVEN,		// [S]�κ� ���� ����
	MSG_EVENT_COLLECT_BUG_GIFT_REP_ERROR_NOITEM,		// [S]���� ���� ���� ����
	MSG_EVENT_COLLECT_BUG_GIFT_REP_ERROR_NOTFULL,		// [S]���ڿ� ������ ����

	MSG_EVENT_COLLECT_BUG_PICK_OK,						// [S]���� ���� : bugitemdbindex(n)
	MSG_EVENT_COLLECT_BUG_PICK_NOITEM,					// [S]ä�� ���� ����
	MSG_EVENT_COLLECT_BUG_PICK_FULL,					// [S]ä�� ���� ���� ��

	MSG_EVENT_COLLECT_BUG_DROP,							// [C,S]���� ���ڿ��� n�� ���� ���� : position(n)
														// plus -> 0 ~ 7, used 8 ~ 15
} MSG_EVENT_COLLECT_BUG_TYPE;

typedef enum _tagMsgEventTldMotherday2007ErrorType
{
	MSG_EVENT_TLD_MOTHERDAY_2007_ERROR_OK,			// ��ȯ ����
	MSG_EVENT_TLD_MOTHERDAY_2007_ERROR_FULLINVEN,	// inven full
	MSG_EVENT_TLD_MOTHERDAY_2007_ERROR_NOITEM,		// itemd not exist
}MSG_EVENT_TLD_MOTHERDAY_2007_ERROR_TYPE;

typedef enum _tagMsgEventTldBuddhistErrorType
{
	MSG_EVENT_TLD_BUDDHIST_ERROR_OK,
	MSG_EVENT_TLD_BUDDHIST_ERROR_FULLINVEN,
	MSG_EVENT_TLD_BUDDHIST_ERROR_NOITEM,
} MSG_EVENT_TLD_BUDDHIST_ERROR_TYPE;

typedef enum _tagMsgEventRain2006ErrorType
{
	MSG_EVENT_RAIN_2006_ERROR_OK,				// ���� ����
	MSG_EVENT_RAIN_2006_ERROR_NOITEM,			// �����/������ ����
	MSG_EVENT_RAIN_2006_ERROR_FULLINVEN,		// �κ��丮 ������
} MSG_EVENT_RAIN_2006_ERROR_TYPE;

typedef enum _tagMsgEventGoldenballType
{
	MSG_EVENT_GOLDENBALL_VOTE_START,			// ���� ����(���̵��õ� ����)	: team1(str) team2(str) yyyy(n) mm(n) dd(n) hh(n) min(n)
	MSG_EVENT_GOLDENBALL_VOTE_END,				// ���� ����					: team1(str) team2(str)
	MSG_EVENT_GOLDENBALL_GIFT_START,			// ���� ����(���̵��õ� ����)	: team1(str) team1score(n) team2(str) team2score(n) yyyy(n) mm(n) dd(n) hh(n) min(n)
	MSG_EVENT_GOLDENBALL_GIFT_END,				// ���� ����					: team1(str) team2(str)

	MSG_EVENT_GOLDENBALL_VOTE,					// ����							: team1score(n) team2score(n) errorcode(n:s)
	MSG_EVENT_GOLDENBALL_GIFT,					// ����							: errorcode(n:s)
} MSG_EVENT_GOLDENBALL_TYPE;

typedef enum _tagMsgEventGoldenballErrorType
{
	MSG_EVENT_GOLDENBALL_ERROR_VOTE_OK,			// ��纼 ���� - ����
	MSG_EVENT_GOLDENBALL_ERROR_VOTE_ALREADY,	// ��纼 ���� - �̹� ������
	MSG_EVENT_GOLDENBALL_ERROR_VOTE_NOITEM,		// ��纼 ���� - �౸�� ����
	MSG_EVENT_GOLDENBALL_ERROR_VOTE_FULLINVEN,	// ��纼 ���� - �κ� ���� ��
	MSG_EVENT_GOLDENBALL_ERROR_VOTE_TIME,		// ��纼 ���� - ���� �Ⱓ �ƴ�

	MSG_EVENT_GOLDENBALL_ERROR_GIFT_OK_EXACT,	// ��纼 ���� - �¸���/���� ���� ���� ����
	MSG_EVENT_GOLDENBALL_ERROR_GIFT_OK_WINNER,	// ��纼 ���� - �¸��� ���� ���� ����
	MSG_EVENT_GOLDENBALL_ERROR_GIFT_OK_NONE,	// ��纼 ���� - ������ ���� ����
	MSG_EVENT_GOLDENBALL_ERROR_GIFT_FULLINVEN,	// ��纼 ���� - �κ� ���� ��
	MSG_EVENT_GOLDENBALL_ERROR_GIFT_NOITEM,		// ��纼 ���� - ���� ī�� ����
	MSG_EVENT_GOLDENBALL_ERROR_GIFT_TIME,		// ��纼 ���� - ���� �Ⱓ �ƴ�
} MSG_EVENT_GOLDENBALL_ERROR_TYPE;

typedef enum _tagMsgEventWorldcupType
{
	MSG_EVENT_WORLDCUP_VOTE,					// �¸����� ����			: country(n) errorcode(n:s)
	MSG_EVENT_WORLDCUP_GIFT,					// ��÷ ���� �ޱ�			: rank(n) errorcode(n:s)
												// rank : 1, 2, 3 - �� ���� �� ����, 4 - �׿�
} MSG_EVENT_WORLDCUP_TYPE;

typedef enum _tagMsgEventWorldcupErrorType
{
	MSG_EVENT_WORLDCUP_ERROR_VOTE_OK,			// �¸� ���� ���� : ����
	MSG_EVENT_WORLDCUP_ERROR_VOTE_NOITEM,		// �¸� ���� ���� : FIFA �� ����
	MSG_EVENT_WORLDCUP_ERROR_VOTE_NOTCHANGE,	// �¸� ���� ���� : ���� �Ⱓ �ƴ�
	MSG_EVENT_WORLDCUP_ERROR_VOTE_FULLINVEN,	// �¸� ���� ���� : �κ� ���� ����
	MSG_EVENT_WORLDCUP_ERROR_VOTE_ALREADY,		// �¸� ���� ���� : �̹� ������ ����

	MSG_EVENT_WORLDCUP_ERROR_GIFT_OK,			// �¸� ���� ���� ��÷ Ȯ�� : ���� ����
	MSG_EVENT_WORLDCUP_ERROR_GIFT_NOTCHANGE,	// �¸� ���� ���� ��÷ Ȯ�� : ��ȯ �Ⱓ �ƴ�
	MSG_EVENT_WORLDCUP_ERROR_GIFT_NOITEM,		// �¸� ���� ���� ��÷ Ȯ�� : ���� ������ ����
	MSG_EVENT_WORLDCUP_ERROR_GIFT_FULLINVEN,	// �¸� ���� ���� ��÷ Ȯ�� : �κ� ���� ����
} MSG_EVENT_WORLDCUP_ERROR_TYPE;

typedef enum _tagMsgEventRecommendType
{
	MSG_EVENT_RECOMMEND_SET,					// ��õ ���� ����			: flag(c)
	MSG_EVENT_RECOMMEND_POTION,					// ���� ���
	MSG_EVENT_RECOMMEND_MOONSTONE,				// ������ ��÷				: charindex(n) charname(str)
} MSG_EVENT_RECOMMEND_TYPE;

typedef enum _tagMsgEventOXQuizType
{
	MSG_EVENT_OXQUIZ_INVALID_TIME,				// ���� ���� �ð��� �ƴѵ� ������ �� ���
	MSG_EVENT_OXQUIZ_START,						// OX ���� ����
	MSG_EVENT_OXQUIZ_QUIZ,						// ���� ����				: quizno(n) limitsec(n) quiz(str)
	MSG_EVENT_OXQUIZ_ANSWER,					// ���� �˸�				: quizno(n) isAnswerO(c)
} MSG_EVENT_OXQUIZ_TYPE;

typedef enum _tagEventSearchFriendErrorType
{
	MSG_EVENT_SEARCHFRIEND_ERROR_OK,				 //����.(ģ�����OK, ���� OK)
	MSG_EVENT_SEARCHFRIEND_ERROR_PACKET,			 //��Ŷ����
	MSG_EVENT_SEARCHFRIEND_ERROR_NOT_EXIST,			 //�������� �ʴ´�.
	MSG_EVENT_SEARCHFRIEND_ERROR_FULLMEMBER,		 //ģ�� ���� �ʰ�.
	MSG_EVENT_SEARCHFRIEND_ERROR_ALREADY_EXIST,		 //�̹� ģ������Ʈ�� ����.
	MSG_EVENT_SEARCHFRIEND_ERROR_NOT_MATCH_INDEX,	 //���ΰ�  ��û,���� ���̵� ��ġ�ϸ� �ȵ�.
	MSG_EVENT_SEARCHFRIEND_ERROR_HELPER_SERVER,		 //���ۼ������� ���ӿ���.
	MSG_EVENT_SEARCHFRIEND_ERROR_GAMESERVER,		 //�Ⱓ�� ������.
	MSG_EVENT_SEARCHFRIEND_ERROR_FRIENDNAME,		 //�̸��� �߸��Ǿ���.
} MSG_EVENT_SEARCHFRIEND_ERROR_TYPE;

typedef enum _tagEventSearchFriendGoodsErrorType
{
	MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_OK,				// ���� ����
	MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_TIME,			// ���� ���� : �ð� ����
	MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_END,				// ���� ���� : �Ⱓ �ƴ�
	MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_SOMEREMAIN,		// ���� ����, �Ϻ� ������ ������
	MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_NOGOODS,			// ���� ����, ���� ������ ����
	MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_NOSPACE,			// ���� ���� : ������ ĭ�� ���ڸ�.
	MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_HELPER,			// ���� ���� ����.
} MSG_EVENT_SEARCHFRIEND_GOODS_ERROR_TYPE;

typedef enum _tagEventNewYear2006ErrorType
{
	MSG_EVENT_NEWYEAR_2006_GOODS_ERROR_OK,				// ���� ����
	MSG_EVENT_NEWYEAR_2006_GOODS_ERROR_TIME,			// ���� ���� : �ð� ����
	MSG_EVENT_NEWYEAR_2006_GOODS_ERROR_END,				// ���� ���� : �Ⱓ �ƴ�
	MSG_EVENT_NEWYEAR_2006_GOODS_ERROR_ALREADY,			// ���� ���� : �̹� ����
} MSG_EVENT_NEWYEAR_2006_GOODS_ERROR_TYPE;

typedef enum _tagEventXMas2005ErrorType
{
	MSG_EVENT_XMAS_2005_ERROR_OK,				// ���� ����
	MSG_EVENT_XMAS_2005_ERROR_NO_ITEM,			// ���� ����
} MSG_EVENT_XMAS_2005_ERROR_TYPE;

typedef enum _tagEvent2pan4panGoodsErrorType
{
	MSG_EVENT_2PAN4PAN_GOODS_ERROR_OK,			// ���� ����
	MSG_EVENT_2PAN4PAN_GOODS_ERROR_SOMEREMAIN,	// ���� ����, �Ϻ� ������ ������
	MSG_EVENT_2PAN4PAN_GOODS_ERROR_NOGOODS,		// ���� ����, ���� ������ ����
	MSG_EVENT_2PAN4PAN_GOODS_ERROR_NOSPACE,		// ���� ����
} MSG_EVENT_2PAN4PAN_GOODS_ERROR_TYPE;

typedef enum _tagEvent2pan4panBoxErrorType
{
	MSG_EVENT_2PAN4PAN_BOX_ERROR_OK,			// ���� ����
	MSG_EVENT_2PAN4PAN_BOX_ERROR_SOMEREMAIN,	// ���� ����, �Ϻ� ������ ������
	MSG_EVENT_2PAN4PAN_BOX_ERROR_NOBOX,			// ���� ����, ���� ������ ����
	MSG_EVENT_2PAN4PAN_BOX_ERROR_NOSPACE,		// ���� ����
} MSG_EVENT_2PAN4PAN_BOX_ERROR_TYPE;

typedef enum _tagEvent2pan4panWordType
{
	MSG_EVENT_2PAN4PAN_WORD_SSAWAR,				// �ڹ;׼ǽο�
	MSG_EVENT_2PAN4PAN_WORD_2PAN4PAN,			// ���ǻ���
	MSG_EVENT_2PAN4PAN_WORD_LASTCHAOS,			// ��Ʈī����
	MSG_EVENT_2PAN4PAN_WORD_LAGHAIM,			// �������
	MSG_EVENT_2PAN4PAN_WORD_NORABA,				// ����

	// ������ʹ� ���� �ڵ�
	MSG_EVENT_2PAN4PAN_WORD_OK,					// ���޼���
	MSG_EVENT_2PAN4PAN_WORD_NOITEM,				// �����ۺ���
	MSG_EVENT_2PAN4PAN_WORD_ALREADY,			// �̹� ����
} MSG_EVENT_2PAN4PAN_WORD_TYPE;

typedef enum _tagEventErrorType
{
	MSG_EVENT_ERROR_ALREADY_GIVE,				// �̹� ���޵Ǿ���
	MSG_EVENT_ERROR_INSUFF_CONDITION,			// ���� ����� : ��������(��������) : ���� ��Ÿ ( �������� )
	MSG_EVENT_ERROR_FULLINVENTORY,				// �κ��丮 ������
	MSG_EVENT_ERROR_WRONG_PACKET,				// ���ⱳȯ : ��Ŷ ����
	MSG_EVENT_ERROR_NO_MATCH,					// ���ⱳȯ : ������ ��ȯ ��� ������ ����
	MSG_EVENT_ERROR_CANT_OPTION,				// ���ⱳȯ : �ɼ� �̵� �Ҵ�
	MSG_EVENT_ERROR_CHUSEOK_NO_CROP,			// �߼� �̺�Ʈ, �۹� ����
	MSG_EVENT_ERROR_CHUSEOK_NO_SOIL,			// �߼� �̺�Ʈ, ����� ����
	MSG_EVENT_ERROR_CHUSEOK_ALREADY_UPGRADE,	// �߼� �̺�Ʈ, ���̻� ���׷��̵� �Ұ���
	MSG_EVENT_ERROR_CHUSEOK_UPGRADE_OK,			// �߼� �̺�Ʈ, ���׷��̵� ����
	MSG_EVENT_ERROR_CHUSEOK_UPGRADE_FAIL,		// �߼� �̺�Ʈ, ���׷��̵� ����
	MSG_EVENT_ERROR_CHUSEOK_EXCHANGE_OK,		// �߼� �̺�Ʈ, ��ȯ ����
	MSG_EVENT_ERROR_SEPTEMBER_NAS,				// 9�� �̺�Ʈ, ���� ��÷
	MSG_EVENT_ERROR_SEPTEMBER_DROP,				// 9�� �̺�Ʈ, ����� ��÷
	MSG_EVENT_ERROR_SEPTEMBER_EXP,				// 9�� �̺�Ʈ, ����ġ ��÷
	MSG_EVENT_ERROR_SEPTEMBER_SP,				// 9�� �̺�Ʈ, ���õ� ��÷
	MSG_EVENT_GUILD_REWARD,						// �±� ��� ���� ������ ���� : nas(ll) sp(ll) 
	MSG_EVENT_ERROR_NOT_COUPON,					// ��Ű�� ������ ����, ���� �ø���
	MSG_EVENT_ERROR_ALREADY_USE_COUNPON,		// ��Ű�� ������ ����, �̹� ���� ���� ����
	MSG_EVENT_ERROR_COUPON_SUCCESS,				// ��Ű�� ������ ����, ���� ����
	MSG_EVENT_ERROR_OPENBETA_SUCCESS,			// ���º�Ÿ ������ ���� ���� : �Ϻ�  : �̱�
	MSG_EVENT_ERROR_SAKURABUD_SUCCESS,			// �ɺ����� ������ ���� ���� : cmd(c)
	MSG_EVENT_ERROR_SAKURABUD_LEAKITEM,			// �ɺ����� ������ ���� ���� �ɺ����� ���� : �Ϻ�
//	MSG_EVENT_ERROR_NOT_PROMOTION_ITEM,			// ��Ű�� ������ ����, ���� ������
} MSG_EVENT_ERROR_TYPE;

typedef enum _tagEventLetterType
{
	MSG_EVENT_LETTER_REQ,						// ��ȯ ��û	: count(n) itemdbindex(n):count		: C -> S
	MSG_EVENT_LETTER_LASTCHAOS,					// ��Ʈī���� ��÷								: S -> C
	MSG_EVENT_LETTER_NAKO,						// ���� ��÷										: S -> C
	MSG_EVENT_LETTER_KNIGHT,					// ����Ʈ ��÷										: S -> C
	MSG_EVENT_LETTER_MERAC,						// �޶�ũ ��÷										: S -> C
	MSG_EVENT_LETTER_CRIS,						// ũ���� ��÷										: S -> C
	MSG_EVENT_LETTER_LAMIAN,					// ��̾� ��÷										: S -> C
	MSG_EVENT_LETTER_ARCHWAND,					// ��ũ�ϵ� ��÷									: S -> C
	MSG_EVENT_LETTER_NOMATCH,					// ���� ���߱� ����									: S -> C
	MSG_EVENT_LETTER_WRONGPACKET,				// �̻��� ��Ŷ ����
} MSG_EVENT_LETTER_TYPE;

typedef enum _tagEventLattoType
{
	MSG_EVENT_LATTO_UPGRADE_SUCCESS,			// "��þƮ ���� ��� ������ +2�� ��÷ �Ǿ����ϴ�"
	MSG_EVENT_LATTO_BLOOD_SUCCESS,				// "���� ���� ��� ������ �ɼǿ� ��÷ �Ǿ����ϴ�"
	MSG_EVENT_LATTO_PROCESS_SUCCESS,			// "���� ���� ��� �����ۿ� ��÷ �Ǿ����ϴ�"
	MSG_EVENT_LATTO_EXPSP_SUCCESS,				// "���� ���� ��� (����ġ *%, ���õ� *)�� ��÷ �Ǿ����ϴ�" : exp(n) sp(n)
	MSG_EVENT_LATTO_PARTY_SUCCESS,				// "��Ƽ ���� ��� ������ ���ָӴϿ� ��÷ �Ǿ����ϴ�" : �ý��� â���� msg ó��
	MSG_EVENT_LATTO_CHANGE_LUCKYBAG_REQ,		// ���ָӴ� ��ȯ ��û
	MSG_EVENT_LATTO_CHANGE_LUCKYBAG_REP,		// ���ָӴ� ��ȯ ����		: type (c)
} MSG_EVENT_LATTO_TYPE;

typedef enum _tagEventLattoChangeLuckyBagType
{
	MSG_CHANGE_26LEVEL_GENERAL_STONE,			// 26���� �Ϲ� ���ü�
	MSG_CHANGE_SPECIAL_STONE,					// ������ü�
	MSG_CHANGE_22LEVEL_EVENT_WEAPON,			// 22���� �̺�Ʈ ���� (������)
	MSG_CHANGE_31LEVEL_ARMOR,					// 31���� �� ���� (������)
	MSG_CHANGE_ATTACK_UP,						// ���ݷ� �����
	MSG_CHANGE_DEFENSE_UP,						// ���� �����
	MSG_CHANGE_50000NAS,						// 5�� ����
	MSG_CHANGE_NO_LUCKYBAG,						// ��ȯ�� ���ָӴϰ� ����
} MSG_EVENT_LATTO_CHANGE_LUCKYBAG_TYPE;

typedef enum _tagPersonalShopType
{
	MSG_PERSONALSHOP_ERROR,						// ���λ��� ���� ����		: errorcode(uc)
	MSG_PERSONALSHOP_CHANGE,					// ���� ���� ��ȭ(����)		: charindex(n) shoptype(c)
	MSG_PERSONALSHOP_SELL_START,				// �ǸŽ���					: charindex(n) shoptype(c) shopname(str) [normal_count(c) normal_item(v:normal_count) pack_price(ll) pack_count(c) pack_item(v:pack_count)]:client
												// normal_item				: row(c) col(c) item_idx(n) item_db_idx(n) count(ll) price(ll)
												// pack_item				: row(c) col(c) item_idx(n) item_db_idx(n) count(ll)
	MSG_PERSONALSHOP_SELL_LIST,					// �ǸŸ���Ʈ ��û			: charindex(n) [ shoptype(c) normal_count(c) normal_item(v:normal_count) pack_price(ll) pack_count(c) pack_item(v:pack_count)]:server
												// normal_item				: item_idx(n) item_db_idx(n) plus(n) flag(n) option_count(c) ([option_type(c) option_level(c)]:option_count) count(ll) price(ll)
												// pack_item				: item_idx(n) item_db_idx(n) plus(n) flag(n) option_count(c) ([option_type(c) option_level(c)]:option_count) count(ll)
	MSG_PERSONALSHOP_BUY,						// ���ſ�û					: charindex(n) pack_buy(c) normal_count(c) ([normal_item_index(n) normal_item_count(ll)]:normal_count)	
} MSG_PERSONALSHOP_TYPE;

typedef enum _tagPersonalShopErrorType
{
	MSG_PERSONALSHOP_ERROR_OK,					// ����
	MSG_PERSONALSHOP_ERROR_INSUFF_SKILL,		// ��û ĳ���Ͱ� ��ų ��� ���϶�
	MSG_PERSONALSHOP_ERROR_INSUFF_WARP,			// ��û ĳ���Ͱ� ����(�̵���ġ) ���϶�
	MSG_PERSONALSHOP_ERROR_INSUFF_EXCHANGE,		// ��û ĳ���Ͱ� ��ȯ ���϶�
	MSG_PERSONALSHOP_ERROR_INSUFF_ALREADY,		// ��û ĳ���Ͱ� �̹� ���λ��� ���϶�
	MSG_PERSONALSHOP_ERROR_INSUFF_MONEY,		// ������ ���λ������� �ŷ��ϰ��� �Ҷ�
	MSG_PERSONALSHOP_ERROR_INSUFF_ETC,			// �׿� ������ ���� ���� ����(��Ŷ������� ��)
	MSG_PERSONALSHOP_ERROR_AREA,				// ���� ���� �Ұ��� �����϶�
	MSG_PERSONALSHOP_ERROR_DUPLICATION,			// �ϳ��� �������� ���� �� ����Ϸ� �� ��
	MSG_PERSONALSHOP_ERROR_NOTFOUND,			// ��� ĳ���Ͱ� ���� ��
	MSG_PERSONALSHOP_ERROR_NOTSELL,				// ��� ĳ���Ͱ� �Ǹ� ������ �ƴ� ��
	MSG_PERSONALSHOP_ERROR_NOTPACKAGE,			// ��� ĳ���Ͱ� ��Ű�� �ǸŰ� �ƴ� ��
	MSG_PERSONALSHOP_ERROR_MONEY,				// ������ ����
	MSG_PERSONALSHOP_ERROR_COUNT,				// ��� ���λ������� ��û �Ǹ�/���� ī��Ʈ�� Ŭ��
	MSG_PERSONALSHOP_ERROR_CANTPREMIUM,			// ������ �������� ��Ű�� ���� ���� �Ұ�
	MSG_PERSONALSHOP_ERROR_BUY_FULLINVENTORY,	// �κ��丮 �������� �� ��
	MSG_PERSONALSHOP_ERROR_ANYMORE_PET,			// �� ���� ������ �Ѿ ���
	MSG_PERSONALSHOP_ERROR_NOSPACE,				// �κ��� �������� �Ǹ� �Ұ� : �� ���� ���� ������ ����
} MSG_PERSONALSHOP_ERROR_TYPE;



typedef enum _tagRightAttackType
{
	MSG_RIGHT_ATTACK_ADD,						// ������� ����Ʈ �߰�
	MSG_RIGHT_ATTACK_DELAY,						// ������� ����Ʈ ���� ���� : 5s
	MSG_RIGHT_ATTACK_DEL,						// ������� ����Ʈ ����
} MSG_RIGHT_ATTACK_TYPE;

typedef enum _tagStashType
{
	MSG_STASH_ERROR,							// â�� ���� ����			: errorcode(uc)
	MSG_STASH_ISSETPASSWORD,					// â�� ��ȣ ���� ���� �˻�	: isset(c:s)
	MSG_STASH_LIST_REQ,							// â�� ������ ����Ʈ ��û	: password(str)
	MSG_STASH_LIST_REP, 						// â�� ������ ����Ʈ		: listflag(c) item_idx(n) plus(n) flag(n) used(n), used_2(n) option_count(c) ([option_type(c) option_level(c)]:option_count) count(ll) remain(n)
												// listflag					: (1 << 0): start, (1 << 1): end, (1 << 2): empty
												// COMPOSITE_TIME ���� used_2(n) �߰�
	MSG_STASH_KEEP_REQ,							// â�� ���� �ñ��		: password(str) keepcount(n) [row(c) col(c) item_idx(n) count(ll)]:keepcount
												// keepcount				: 1 ~ 10
	MSG_STASH_KEEP_REP,							// �ñ�� ���				: keepcount(n) [itemdbindex(n) count(ll)]:keepcount
	MSG_STASH_TAKE_REQ,							// ã�� ��û				: password(str) takecount(n) [item_idx(n) count(ll)]:takecount
												// takecount				: 1 ~ 10
	MSG_STASH_TAKE_REP,							// ã�� ���				: takecount(n) [itemdbindex(n) count(ll)]:keepcount
	MSG_STASH_CHANGE_PASSWORD_REQ,				// �н����� ���� ��û		: old(str) new(str)
	MSG_STASH_CHANGE_PASSWORD_REP,				// �н����� ���� ���		: isset(c:s)
	MSG_STASH_SEAL,								// ��� ��û/���

	MSG_STASH_DELETE_PASSWORD_REQ,				// ��ȣ�нǽ� ���� ��û		: idnum(str)
	MSG_STASH_DELETE_PASSWORD_REP,				// ��ȣ�н� ���			: success(c:s)

	MSG_STASH_CHECK_PASSWORD_REQ,				// ��ȣ Ȯ��				: pass(str)
	MSG_STASH_CHECK_PASSWORD_REP,				// ���						
	MSG_STASH_SETTING_NEWPASSWORD_REQ,			// ��ȣ ����				: pass(str)	
	MSG_STASH_SETTING_NEWPASSWORD_REP,			// ���						: bsuccess(c)
												//	bsuccess 0: ���� 1: ���� 2: ��ȣ�� ����
} MSG_STASH_TYPE;

typedef enum _tagStashErrorType
{
	MSG_STASH_ERROR_OK,							// ����
	MSG_STASH_ERROR_CANNOT_STATE,				// â�� �̿��� �Ҽ� ���� ����: ���� ����, ������, ��ų ������, ������, ���λ���, ��ȯ�߿����� �Ұ���
	MSG_STASH_ERROR_NOTCOMPLETE,				// ���� â�� ��û�� ������ ���� �ʾ���
	MSG_STASH_ERROR_SEALED,						// â�� ��� ��� ����
	MSG_STASH_ERROR_WRONG_PASSWORD,				// ��ȣ Ʋ��
	MSG_STASH_ERROR_WRONG_PACKET,				// ��Ŷ ���� ����
	MSG_STASH_ERROR_MONEY,						// �� ����
	MSG_STASH_ERROR_STASH_FULL,					// â�� ���� ��
	MSG_STASH_ERROR_WEIGHT_OVER,				// ���� �ʰ��� ã�� �� ����
	MSG_STASH_ERROR_INVENTORY_FULL,				// �κ��丮 ���� �ʰ��� ã�� �� ����
	MSG_STASH_ERROR_WRONG_CHAR,					// ��ȣ�� �߸��� ���ڰ� ��
	MSG_STASH_ERROR_CANNOT_SEAL,				// ��ۼ� ����
	MSG_STASH_ERROR_ALREADY_SEAL,				// �̹� ���
} MSG_STASH_ERROR_TYPE;

typedef enum _tagGuildType {MSG_GUILD_ERROR, MSG_GUILD_CREATE, MSG_GUILD_INFO, MSG_GUILD_MEMBERLIST, MSG_GUILD_ONLINE, MSG_GUILD_LEVELUP, MSG_GUILD_LEVELINFO, MSG_GUILD_BREAKUP, MSG_GUILD_BREAKUP_NOTIFY, MSG_GUILD_REGIST_REQ, MSG_GUILD_REGIST_ALLOW, MSG_GUILD_REGIST_CANCEL, MSG_GUILD_OUT_REQ, MSG_GUILD_CHANGE_BOSS, MSG_GUILD_APPOINT_OFFICER, MSG_GUILD_FIRE_OFFICER, MSG_GUILD_KICK, MSG_GUILD_MEMBER_ADD, MSG_GUILD_MEMBER_OUT, MSG_GUILD_MEMBER_KICK, MSG_GUILD_INFO_CHANGE, MSG_GUILD_BATTLE_REQ_REQ, MSG_GUILD_BATTLE_REQ_REJECT, MSG_GUILD_BATTLE_REQ_ACCEPT, MSG_GUILD_BATTLE_STOP_REQ, MSG_GUILD_BATTLE_STOP_REJECT, MSG_GUILD_BATTLE_STOP_ACCEPT, MSG_GUILD_BATTLE_START, MSG_GUILD_BATTLE_STATUS, MSG_GUILD_BATTLE_END, MSG_GUILD_WAR_SET_TIME_REQ, MSG_GUILD_WAR_GET_TIME, MSG_GUILD_WAR_NOTICE_TIME, MSG_GUILD_WAR_NOTICE_TIME_REMAIN, MSG_GUILD_WAR_START, MSG_GUILD_WAR_JOIN_ATTACK_GUILD, MSG_GUILD_WAR_JOIN_DEFENSE_GUILD, MSG_GUILD_WAR_JOIN_ATTACK_CHAR, MSG_GUILD_WAR_JOIN_DEFENSE_CHAR, MSG_GUILD_WAR_POINT, MSG_GUILD_WAR_NOTICE_START_CASTLE, MSG_GUILD_WAR_NOTICE_REMAIN_FIELD_TIME, MSG_GUILD_WAR_CASTLE_STATE, MSG_GUILD_WAR_GATE_STATE, MSG_GUILD_WAR_ATTACK_SYMBOL, MSG_GUILD_WAR_END, MSG_GUILD_WAR_SET_TIME_REP, MSG_GUILD_WAR_INVALID_COMMAND, MSG_GUILD_STASH_HISTORY_REQ, MSG_GUILD_STASH_HISTORY_REP, MSG_GUILD_STASH_VIEW_REQ, MSG_GUILD_STASH_VIEW_REP, MSG_GUILD_STASH_TAKE_REQ, MSG_GUILD_STASH_TAKE_REP, MSG_NEW_GUILD_INCLINE_ESTABLISH, MSG_NEW_GUILD_MEMBER_ADJUST, MSG_NEW_GUILD_INFO, MSG_NEW_GUILD_MEMBERLIST, MSG_NEW_GUILD_SKILL, MSG_NEW_GUILD_NOTICE, MSG_NEW_GUILD_NOTICE_UPDATE, MSG_NEW_GUILD_NOTICE_REQUEST, MSG_NEW_GUILD_NOTICE_TRANSMISSION, MSG_NEW_GUILD_MANAGE, MSG_NEW_GUILD_SKILL_LEARN, MSG_NEW_GUILD_POINT_RANKING, MSG_GUILD_BATTLE_COMMAND_REQ, MSG_GUILD_BATTLE_COMMAND_START, MSG_GUILD_BATTLE_COMMAND_STOP, MSG_GUILD_BATTLE_COMMAND_END, MSG_GUILD_BATTLE_KILL_MASTER, MSG_GUILD_BATTLE_NOW_SCORE, MSG_GUILD_BATTLE_BEFORE, MSG_GUILD_BATTLE_END_NOTICE_SAME_ZONE, MSG_GUILD_BATTLE_START_NOTICE_SAME_ZONE, MSG_GUILD_GP_INFO, MSG_CASTLE_BUFF, MSG_GUILD_WAR_SET_TIME_MENU, MSG_GUILD_WAR_GET_TIME_UNI_REQ, MSG_GUILD_WAR_GET_TIME_UNI_REP, MSG_NEW_GUILD_MARK_EDIT_WND, MSG_NEW_GUILD_MARK_EDIT_FIN, MSG_NEW_GUILD_MARK_EXPIRE, MSG_NEW_GUILD_STASH_LIST, MSG_NEW_GUILD_STASH_KEEP, MSG_NEW_GUILD_STASH_TAKE, MSG_NEW_GUILD_STASH_LOG, MSG_NEW_GUILD_STASH_ERROR, MSG_GUILD_MASTER_KICK_REQ, MSG_GUILD_MASTER_KICK_REP, MSG_GUILD_MASTER_KICK_CANCEL_REQ, MSG_GUILD_MASTER_KICK_CANCEL_REP, MSG_GUILD_MASTER_KICK_STATUS, MSG_GUILD_REMOTE_JOIN_REQ, MSG_GUILD_REMOTE_JOIN_OK, MSG_GUILD_REMOTE_JOIN_NO};


//typedef enum _tagGuildType
//{
//	MSG_GUILD_ERROR,						// ��� ���� ����		: errorcode(c)
//	MSG_GUILD_CREATE,						// ��� ����			: name(str)
//	MSG_GUILD_INFO,							// �� ��� ���� ������	: guildindex(n) guildname(str) guildlevel(n) mypos(n) battle_guildindex(n) battle_killcount(n) battle_prize(n) battle_zone(n) battle_time(n)
//											// ��� ������ guildindex == -1, ���� �׸� ����
//	MSG_GUILD_MEMBERLIST,					// ��� ����Ʈ			: guildindex(n) count(n) [index(n) name(str) position(n) online(c)]:count
//	MSG_GUILD_ONLINE,						// ���� �¶��� ����	: guildindex(n) charindex(n) charname(str) online(c)
//	MSG_GUILD_LEVELUP,						// ��� �±�			: 
//	MSG_GUILD_LEVELINFO,					// ��� ���� ����		: guildindex(n) guildlevel(n)
//	MSG_GUILD_BREAKUP,						// �ػ� ��û			: 
//	MSG_GUILD_BREAKUP_NOTIFY,				// ��� �ػ��� �˸�		: guildindex(n) guildname(str)
//	MSG_GUILD_REGIST_REQ,					// ���� ��û ��û		: guildindex(n) bossindex(n) requesterindex(n)
//	MSG_GUILD_REGIST_ALLOW,					// 10 ���� ��û ���		: guildindex(n) requesterindex(n)
//	MSG_GUILD_REGIST_CANCEL,				// ���� ��û ���		: bCancelTarget(c)
//	MSG_GUILD_OUT_REQ,						// Ż��					: guildindex(n)
//	MSG_GUILD_CHANGE_BOSS,					// ���� ����			: guildindex(n) current(n) newboss(n)
//	MSG_GUILD_APPOINT_OFFICER,				// �δ��� �Ӹ�			: guildindex(n) charindex(n)
//	MSG_GUILD_FIRE_OFFICER,					// �δ��� ����			: guildindex(n) charindex(n)
//	MSG_GUILD_KICK,							// ����	��û			: guildindex(n) charindex(n)
//	MSG_GUILD_MEMBER_ADD,					// ��� �߰� �˸�		: guildindex(n) charindex(n) charname(str)
//	MSG_GUILD_MEMBER_OUT,					// ��� Ż�� �˸�		: guildindex(n) charindex(n) charname(str)
//	MSG_GUILD_MEMBER_KICK,					// ��� ���� �˸�		: guildindex(n) bossindex(n) charindex(n) charname(str)
//	MSG_GUILD_INFO_CHANGE,					// 20 ��� ���� ����		: charindex(n) guildindex(n) guildname(str) pos(n)
//
//	MSG_GUILD_BATTLE_REQ_REQ,				// ����� ��û ��û		: charindex(n) or guildindex(n) guildname(n) prize(n) time(n)
//	MSG_GUILD_BATTLE_REQ_REJECT,			// ����� ��û ����		: reject_charindex(n)
//	MSG_GUILD_BATTLE_REQ_ACCEPT,			// ����� ��û ���		: guildindex1(n) guildname1(n) guildindex2(n) guildname2(n) prize(n) zone(n) time(n)
//	MSG_GUILD_BATTLE_STOP_REQ,				// ����� �ߴ� ��û		: charindex(n) or guildindex(n) guildname(n) 
//	MSG_GUILD_BATTLE_STOP_REJECT,			// ����� �ߴ� ����		: reject_charindex(n)
//	MSG_GUILD_BATTLE_STOP_ACCEPT,			// ����� �ߴ� ���		:
//	MSG_GUILD_BATTLE_START,					// ����� ���� �˸�		: guildindex1(n) guildname1(n) guildindex2(n) guildname2(n) prize(n) zone(n) time(n)
//	MSG_GUILD_BATTLE_STATUS,				// ����� ��Ȳ			: guildindex1(n) guildname1(str) killcount1(n)guildindex2(n) guildname2(str) killcount2(n) battletime(n)
//	MSG_GUILD_BATTLE_END,					// ����� ����			: winner_guildindex(n) guildindex1(n) guildname1(n) guildindex2(n) guildname2(n) prize(n)
//
//	MSG_GUILD_WAR_SET_TIME_REQ,				// 30 ���� �ð� ���� ��û	: wday(n) hour(n)
//	MSG_GUILD_WAR_GET_TIME,					// ���� �ð� Ȯ��		: warerrorcode(n:s) guildindex(n:s) guildname(n:s) month(c:s) day(c:s) hour(c:s) min(c:s)
//	MSG_GUILD_WAR_NOTICE_TIME,				// ���� �ð� Ȯ�� �˸�	: zoneindex(n) month(c) day(c) hour(c) min(c)
//	MSG_GUILD_WAR_NOTICE_TIME_REMAIN,		// ���� ���� ���� �ð� �˸�	: zoneindex(n) min(c)
//	MSG_GUILD_WAR_START,					// ���� ���� �˸�		: zoneindex(n) remainSec(n)
//	MSG_GUILD_WAR_JOIN_ATTACK_GUILD,		// ���� ��� ��û ��û	: warerrorcode(n:s) month(c:s) day(c:s) hour(c:s) min(c:s)
//	MSG_GUILD_WAR_JOIN_DEFENSE_GUILD,		// ���� ��� ��û ��û	: warerrorcode(n:s) month(c:s) day(c:s) hour(c:s) min(c:s)
//	MSG_GUILD_WAR_JOIN_ATTACK_CHAR,			// ���� �뺴 ��û ��û	: warerrorcode(n:s) month(c:s) day(c:s) hour(c:s) min(c:s)
//	MSG_GUILD_WAR_JOIN_DEFENSE_CHAR,		// ���� �뺴 ��û ��û	: warerrorcode(n:s) month(c:s) day(c:s) hour(c:s) min(c:s)
//	MSG_GUILD_WAR_POINT,					// ���� ��� ����Ʈ �˸�: remain_sec(n) guild1_index(n) guild1_name(str) guild1_point(n) guild2_index(n) guild2_name(str) guild2_point(n) guild3_index(n) guild3_name(str) guild3_point(n) my_guild_point(n) defense_point(n)
//	MSG_GUILD_WAR_NOTICE_START_CASTLE,		// 40 ������ ���� ���� �˸�: zoneindex(n) remain_sec(n) guildindex1(n) guildname1(str) guildindex2(n) guildname2(str) guildindex3(n) guildname3(str)
//	MSG_GUILD_WAR_NOTICE_REMAIN_FIELD_TIME,	// ���� ���� �ð� �˸�	: zoneindex(n) remainSec(n)
//	MSG_GUILD_WAR_CASTLE_STATE,				// ���� ���� ��Ȳ �˸�	: zoneindex(n) state(n) gatestate(n) remain_sec(n) guild1_index(n) guild1_name(str) guild1_point(n) guild2_index(n) guild2_name(str) guild2_point(n) guild3_index(n) guild3_name(str) guild3_point(n) my_guild_point(n) defense_point(n)
//											// state				: 0 - �Ϲ�, 1 - ����, 2 - ����
//	MSG_GUILD_WAR_GATE_STATE,				// ���� ���� ������ �˸�: old_gate_state(n) new_gate_state(n)
//	MSG_GUILD_WAR_ATTACK_SYMBOL,			// ���� ���� ��û		: 
//	MSG_GUILD_WAR_END,						// ���� ����			: zoneindex(n) bWinDefense(c) owner_index(n) owner_name(str) char_index(n) char_name(str) nextMonth(n) nextDay(n) nextHour(n) wDay(n)
//	MSG_GUILD_WAR_SET_TIME_REP,				// ���� �ð� ���� ����	: warerrorcode(n) month(c:s) day(c:s) hour(c:s) min(c:s)
//	MSG_GUILD_WAR_INVALID_COMMAND,			// ������ �Ұ����� ��� ����� ��û : req_msg_type(uc)
//											// req_msg_type : MSG_GUILD_TYPE
//
//	MSG_GUILD_STASH_HISTORY_REQ,			// �Աݳ��� ��û		: 
//	MSG_GUILD_STASH_HISTORY_REP,			// �Աݳ��� ����		: errcode(n) [month(n) day(n) money(ll)]:7
//	MSG_GUILD_STASH_VIEW_REQ,				// 50 ����� �ܾ� ��û		: 
//	MSG_GUILD_STASH_VIEW_REP,				// �ܾ� ����			: errcode(n) money(ll)
//	MSG_GUILD_STASH_TAKE_REQ,				// ��� ��û			: money(ll)
//	MSG_GUILD_STASH_TAKE_REP,				// ��� ����			: errcode(n)
//
//	MSG_NEW_GUILD_INCLINE_ESTABLISH,			// ��� ���� ����		: guildindex(n:s) charindex(n:s)  guildincline(c)
//	MSG_NEW_GUILD_MEMBER_ADJUST,				// ���� ���� ����	:charIndex(n) name(s) exp(n) fame(n)
//
//	MSG_NEW_GUILD_INFO,		// ����� ���ο� ���� : guildname(str) guildlevel(n) bossname(str) membercount(n) maxmembercount(n) avelevel(n) guildpoint(n) contributepoint(n)
//	MSG_NEW_GUILD_MEMBERLIST,					// ���ο� ����� ��� ����Ʈ : maxmembercount(n) charname(str) positionname(str) charlevel(n) bplaying(b) zoneindex(n) contributepoint(n) job
//	MSG_NEW_GUILD_SKILL,
//	MSG_NEW_GUILD_NOTICE,				// ����� ���� ���� ��û 
//	MSG_NEW_GUILD_NOTICE_UPDATE,		// 60 ��� ���� ���� ������Ʈ 
//	MSG_NEW_GUILD_NOTICE_REQUEST,	// ��� ���� �ϱ�
//	MSG_NEW_GUILD_NOTICE_TRANSMISSION,	// ��� ���� �ϱ�	
//	MSG_NEW_GUILD_MANAGE,				// ����� ���ο� �Ŵ��� : errorcode(n), membercount(n), guildpos(n), membername(str) positionname(str) charlevel(n) bplaying(b) contributeExp(n) contributeFame(n)
//
//	MSG_NEW_GUILD_SKILL_LEARN,		// ��� ��ų ���� c->s: skillindex(n)
//									// s->c: skill_index(n) is_new(uc) skill_level(c)
//	MSG_NEW_GUILD_POINT_RANKING,	// ��� ��ŷ ���� charindex(n) guildindex(n) ranking(n)	
//} MSG_GUILD_TYPE;

typedef enum _tagGuildStashErrorType
{
	MSG_GUILD_STASH_ERROR_OK,				// ����
	MSG_GUILD_STASH_ERROR_NOHISTORY,		// �����丮 ����
	MSG_GUILD_STASH_ERROR_NOTBOSS,			// �����/�ΰ� �ƴ�
	MSG_GUILD_STASH_ERROR_NOTENOUGH,		// �ܾ� ����
	MSG_GUILD_STASH_ERROR_FAIL_DB,			// �ý��� ����

	// ���� �޽����� ������ ��� â�� ������ �����ؾ���
	MSG_GUILD_STASH_ERROR_NOSPACE,			// �κ��丮 ���� �������� ���� �Ұ�
} MSG_GUILD_STASH_ERROR_TYPE;

typedef enum _tagGuildErrorType
{
	MSG_GUILD_ERROR_OK,							// ����
	MSG_GUILD_ERROR_PACKET,						// ��Ŷ ���� ����
	MSG_GUILD_ERROR_GUILDNAME,					// �̸� ����(2~16)�� �߸��Ǿ��ų�, ��� �̸��� �߸��� ����(\'"%_) ����
	MSG_GUILD_ERROR_ALREADYBOSS,				// ������̳� ������ ��� â�� �Ұ���
	MSG_GUILD_ERROR_CHARLEVEL,					// ĳ���� ���� ����
	MSG_GUILD_ERRRO_SKILLPOINT,					// ��ų ����Ʈ ����
	MSG_GUILD_ERROR_MONEY,						// ���� ����
	MSG_GUILD_ERROR_GAMESERVER,					// ���Ӽ��� ������ ���ؼ� ���� �Ұ�
	MSG_GUILD_ERROR_DUPNAME,					// �̸� �ߺ�
	MSG_GUILD_ERROR_NOGUILD,					// ��� ���µ� ��� ���� �޽����� ��û�� ��
	MSG_GUILD_ERROR_NOTBOSS,					// ������� �ƴѵ� ���� �޽����� ��û�� ��
	MSG_GUILD_ERROR_MAXLEVEL,					// �̹� �ְ��� ����ε� �±� ��û�� ��
	MSG_GUILD_ERROR_CREATE_OK,					// ����� ����
	MSG_GUILD_ERROR_LEVELUP_OK,					// ������ ����
	MSG_GUILD_ERROR_BREAKUP_OK,					// �ػ� ����
	MSG_GUILD_ERROR_TARGET_NOBOSS,				// ����� ������� �ƴϾ ���� ��û�� �� �� ����
	MSG_GUILD_ERROR_TARGET_BUSY,				// ����� �ٸ� ������� ��û�� ����
	MSG_GUILD_ERROR_SOURCE_BUSY,				// ���� �ٸ� ������� ��û�� �� ���� �ȵ� ���¿��� �ٽ� ��3�ڿ��� ��û
	MSG_GUILD_ERROR_FULLMEMBER,					// ��� ������ �ʰ�
	MSG_GUILD_ERROR_REGIST_OK,					// ���� ���� �Ϸ�
	MSG_GUILD_ERROR_OUTBOSS,					// ������� Ż���Ϸ��� ����
	MSG_GUILD_ERROR_OUT_OK,						// Ż�� ����
	MSG_GUILD_ERROR_NOTFOUNDMEMBER,				// ����, �Ӹ�, ���ӵ�� ��� ����� ������
	MSG_GUILD_ERROR_CANTKICKBOSS,				// ������ ���� �Ҵ�
	MSG_GUILD_ERROR_KICK_OK,					// ���� ����
	MSG_GUILD_ERROR_CHANGE_BOSS_OK,				// ���� ���� ����
	MSG_GUILD_ERROR_CANTOFFICER,				// ������̳� �ΰ��� �ٽ� �ΰ����� �Ӹ��
	MSG_GUILD_ERROR_APPOINT_OFFICER_OK,			// �ΰ� �Ӹ� ����
	MSG_GUILD_ERROR_FULLOFFICER,				// �ΰ� ���� ��
	MSG_GUILD_ERROR_NOTOFFICER,					// �ΰ��� �ƴ϶� ���� �Ұ�
	MSG_GUILD_ERROR_FIRE_OFFICER_OK,			// ���� ����S
	MSG_GUILD_ERROR_REGDELAY,					// Ż���� 7���� ������ �ʾ� ���� �Ҵ�
	MSG_GUILD_ERROR_CANTKICK,					// ���� �Ұ���(�δ����� �δ��� �����)
	MSG_GUILD_ERROR_CANNOT_REGIST_REQ_BATTLE,	// ����� �߿��� ���Խ�û �Ұ�
	MSG_GUILD_ERROR_CANNOT_BREAK_BATTLE,		// ������ - ����� �� ��� ��ü �Ұ�
	MSG_GUILD_ERROR_CANNOT_KICK_BATTLE,			// ������ - ����� �� ���� �Ұ�
	MSG_GUILD_ERROR_CANNOT_OUT_BATTLE,			// ������ - ����� �� Ż�� �Ұ�

	MSG_GUILD_ERROR_BATTLE,						// ����� ����		: errtype(uc)
	MSG_GUILD_ERROR_CANNOT_BREAK_WAR,			// ����� ���� ��� ��ü�� �Ұ���

	MSG_NEW_GUILD_ERRROR_GUILDPOINT,				// ��� �������� ��� ����Ʈ ���� 
	MSG_NEW_GUILD_ERROR_SAME_INCLNE,				// ��� ������ ����
	MSG_NEW_GUILD_ERROR_CHANG_INCLINE,				// ��� ���� ���� ����
	MSG_NEW_GUILD_ERROR_INCLINE_OK,					// ��� ���� ���� ����
	MSG_NEW_GUILD_ERROR_ADJUST_FAIL,				// ��� �������  ���� ���� ����
	MSG_NEW_GUILD_ERROR_ADJUST_OK,	

	MSG_NEW_GUILD_INFO_ERROR_OK,				// ���ο� ��� ���� ��û ����
	MSG_NEW_GUILD_MEMBERLIST_ERROR_OK,			// ���ο� ��� ��� ����Ʈ ��û ����
	MSG_NEW_GUILD_MANAGE_ERROR_OK,				// ���ο� ��� �Ŵ��� ��û ����
	MSG_NEW_GUILD_NOTICE_ERROR_OK,				// ���ο� ��� ���� ��û ����
	MSG_NEW_GUILD_NOTICE_UPDATE_ERROR_OK,		// ���ο� ��� ���� ������Ʈ ����
	MSG_NEW_GUILD_NOTICE_UPDATE_ERROR_FAIL,		// ���ο� ��� ���� ������Ʈ ����
	MSS_NEW_GUILD_NOTICE_TRANSMISSION_ERROR_OK,
	MSS_NEW_GUILD_NOTICE_TRANSMISSION_ERROR_FAIL,
	MSG_NEW_GUILD_SKILL_ERROR_OK,				// ��� ��ų ����
	MSG_NEW_GUILD_SKILL_ERROR_NOTEXIST,			// ��� ��ų�� ����
	MSG_NEW_GUILD_NOTICE_ERROR_NOT_MESSAGE,		// �޼����� ����.
	MSG_NEW_GUILD_SKILL_LEARN_ERROR_OK,
	MSG_NEW_GUILD_SKILL_LEARN_ERROR_LEVEL,		// ���� ����
	MSG_NEW_GUILD_SKILL_ALEADY_LEARN,			//  �̹� ��� ��ų 
} MSG_GUILD_ERROR_TYPE;

typedef enum _tagGuildErrorBattleType
{
	MSG_GUILD_ERROR_BATTLE_NOGUILD,				// ����� - ���� ��尡 ����
	MSG_GUILD_ERROR_BATTLE_NOTBOSS,				// ����� - ������� ����
	MSG_GUILD_ERROR_BATTLE_MEMBERCOUNT,			// ����� - �ο� �� ����
	MSG_GUILD_ERROR_BATTLE_ZONE,				// ����� - ���� ���� �ƴ�
	MSG_GUILD_ERROR_ALREADY_BATTLE,				// ����� - �̹� ����� ��
	MSG_GUILD_ERROR_BATTLE_PRIZE,				// ����� - ���ñݾ� ��ü ���� (����� ���� ���ݾ��� �ƴ�)
	MSG_GUILD_ERROR_BATTLE_NOT_REQ,				// ����� - ��û���� ����
	MSG_GUILD_ERROR_BATTLE_SHORT_PRIZE,			// ����� - ���ñݾ� ������
	MSG_GUILD_ERROR_BATTLE_NOT_BATTLE,			// ����� = ����� ���� �ƴ�

	MSG_GUILD_ERROR_BATTLE_TIME,				// ����� - �ð��� �߸� ��

} MSG_GUILD_EROOR_BATTLE_TYPE;

typedef enum _tagGuildPositionType
{
	MSG_GUILD_POSITION_BOSS,					// ��� ������
	MSG_GUILD_POSITION_OFFICER,					// ��� �ΰ�
	MSG_GUILD_POSITION_MEMBER,					// ����
	MSG_GUILD_POSITION_UNKNOWN = 99,			// 
} MSG_GUILD_POSITION_TYPE;

typedef enum _tagGuildWarErrorType
{
	MSG_GUILD_WAR_ERROR_OK,						// ����
	MSG_GUILD_WAR_ERROR_PROGRESS_WAR,			// ���� ���� ��
	MSG_GUILD_WAR_ERROR_JOIN_OWNER_GUILD,		// �������� �����ϰڴٰ� ��� ��
	MSG_GUILD_WAR_ERROR_JOIN_NOT_GUILD,			// ��� ���� ���� ���� ��û�ϰڴٰ� ��� ��
	MSG_GUILD_WAR_ERROR_JOIN_ALREADY,			// �̹� ��û�� ���� �ڲ� �ϰڴٰ� �� ��
	MSG_GUILD_WAR_ERROR_JOIN_TIME,				// ��û ���� �ð��� �ƴ� ��
	MSG_GUILD_WAR_ERROR_JOIN_GUILDLEVEL,		// ��� ���� �����ؼ� ���� ��û �Ұ�
	MSG_GUILD_WAR_ERROR_JOIN_GUILDMEMBER,		// ���� �����ؼ� ���� ��û �Ұ�
	MSG_GUILD_WAR_ERROR_JOIN_ITEM,				// ������ ��ǥ ����
	MSG_GUILD_WAR_ERROR_JOIN_MONEY,				// �� ���� ���� ��û
	MSG_GUILD_WAR_ERROR_JOIN_NO_OWNER,			// ���� ���� ������ �����뺴 �Ұ�
	MSG_GUILD_WAR_ERROR_JOIN_ALREADY_GUILD,		// ����� ��ħ�� ���� ���� �뺴 ��û �Ұ�
	MSG_GUILD_WAR_ERROR_JOIN_CHARLEVEL,			// ĳ������ ����
	MSG_GUILD_WAR_ERROR_NOT_OWNER,				// ���ֵ� �ƴϸ鼭 ������ �ٲٷ� �Ҷ�
	MSG_GUILD_WAR_ERROR_NOT_SETTIME,			// ���� ���� �ð��� �ƴ�
	MSG_GUILD_WAR_ERROR_INVALID_TIME,			// ���� �Ұ��� �ð���
	MSG_GUILD_WAR_ERROR_JOIN_NOT_GUILD_BOSS,	// �Ϲ� ������ ���� ��û �Ұ�
} MSG_GUILD_WAR_ERROR_TYPE;

typedef enum _tagMsgHelperType
{
	MSG_HELPER_WHISPER_REQ,				// �Ӹ� ��û		: sender_index(n) sender_name(str) receiver_index(n) receiver_name(str) chat(str)
	MSG_HELPER_WHISPER_REP,				// �Ӹ� ����		: sender_index(n) sender_name(str) receiver_index(n) receiver_name(str) chat(str)
	MSG_HELPER_WHISPER_TIMEOUT,			// �Ӹ� Ÿ�Ӿƿ�	: sender_index(n) sender_name(str)
	MSG_HELPER_WHISPER_NOTFOUND,		// ��� ����		: sender_index(n) sender_name(str)
	MSG_HELPER_WAR_NOTICE_TIME,			// ������ �ð� �˸�	: zoneindex(n) month(c) day(c) hour(c) min(c)
	MSG_HELPER_WAR_NOTICE_TIME_REMAIN,	// ���� ���� �ð� �˸�	: zoneindex(n) min(c)
	MSG_HELPER_WAR_NOTICE_START,		// ������ ���� �˸�	: zoneindex(n) remainSec(n)
	MSG_HELPER_WAR_JOIN_ATTACK_GUILD,	// ���� ��� �߰�	: zoneindex(n) guildindex(n)
	MSG_HELPER_WAR_JOIN_DEFENSE_GUILD,	// ���� ��� �߰�	: zoneindex(n) guildindex(n)
	MSG_HELPER_WAR_NOTICE_START_ATTACK_CASTLE,	// ���� ���� : zoneindex(n) remainSec(n) guildindex1(n) guildname1(str) guildindex2(n) guildname2(str) guildindex3(n) guildname3(str)
	MSG_HELPER_WAR_NOTICE_REMAIN_FIELD_TIME,	// ���� ���� �ð� �˸�	: zoneindex(n) remainSec(n)
	MSG_HELPER_WAR_NOTICE_END,			// ���� ����		: zoneindex(n) bWinDefense(c) owner_index(n) owner_name(str) char_index(n) char_name(str) nextMonth(n) nextDay(n) nextHour(n) wDay(n)

	MSG_HELPER_PARTY_MEMBER_CHANGE_JOB,	// ��Ƽ�� ���� ���� �˸� : bossindex(n) charindex(n) job1(c) job2(c)
	MSG_HELPER_PARTY_CHAT,				// ��Ƽ ä��		: bossindex(n) charindex(n) charname(str) chat(str)
	MSG_HELPER_PARTY_RECALL_PROMPT,		// ��Ƽ ���� ��û	: bossindex(n) charindex(n) charname(str) isincastle(c) guildindex(n)
	MSG_HELPER_PARTY_RECALL_CONFIRM,	// ��Ƽ���� Ȯ��	: bossindex(n) reqcharindex(n) reqcharname(str) repcharindex(n) repcharname(str) yesno(c)
	MSG_HELPER_PARTY_RECALL_PROC,		// ��Ƽ���� ����	: bossindex(n) repcharindex(n) zone(n) x(f) z(f) y(c) isincastle(c) guildindex(n)

	MSG_HELPER_COMBO_GOTO_COMBO_PROMPT, // �޺� ��Ƽ����
	MSG_HELPER_COMBO_RECALL_TO_COMBO_PROMPT, //  �޺���Ƽ���� npc

	MSG_HELPER_END_MSG,					// ���� REQ, REP �޽����� �� �޽������� �ڿ� ���� �ȵ�
} MSG_HELPER_TYPE;

typedef enum _tagMsgHelperCommandType
{
	MSG_HELPER_SHUTDOWN,				// 0 ���۸� �ٿ�

	MSG_HELPER_GUILD_CREATE_REQ,		// ��� ���� ��û	: charindex(n) charname(str) guildname(str)
	MSG_HELPER_GUILD_CREATE_REP,		// ��� ���� ����	: charindex(n) errorcode(uc)
	MSG_HELPER_GUILD_CREATE_NTF,		// ��� �߰� �˸�	: guildindex(n) guildlevel(n) guildname(str) bossindex(n) bossname(str)
	MSG_HELPER_GUILD_ONLINE_NTF,		// ���� �¶���	: guildindex(n) charindex(n) online(c)
	MSG_HELPER_GUILD_MEMBER_LIST,		// ���� ����Ʈ	: guildindex(n) count(n) [charindex(n) charname(str) pos(n) online(c)]
	MSG_HELPER_GUILD_ONLINE,			// �¶��� ����		: guildindex(n) charindex(n) online(c)
	MSG_HELPER_GUILD_LOAD_REQ,			// ������� ��û	: idname(str) charindex(n)
	MSG_HELPER_GUILD_LOAD_REP,			// ������� ����	: idname(str) charindex(n) errorcode(uc)
	MSG_HELPER_GUILD_LEVELUP_REQ,		// ��� ��� ��û	: guildindex(n) charindex(n)
	MSG_HELPER_GUILD_LEVELUP_REP,		// 10 ��� ��� ����	: guildindex(n) charindex(n) errorcode(uc)
	MSG_HELPER_GUILD_LEVELUP_NTF,		// ��� ��� �˸�	: guildindex(n) guildlevel(n)
	MSG_HELPER_GUILD_BREAKUP_REQ,		// ��� �ػ� ��û	: bossindex(n) guildindex(n)
	MSG_HELPER_GUILD_BREAKUP_REP,		// ��� �ػ� ����	: charindex(n) errcode(uc)
	MSG_HELPER_GUILD_BREAKUP_NTF,		// ��� �ػ� �˸�	: guildindex(n)
	MSG_HELPER_GUILD_MEMBER_ADD_REQ,	// ��� �߰� ��û	: guildindex(n) boss(n) requester(n)
	MSG_HELPER_GUILD_MEMBER_ADD_NTF,	// �߰� �˸�		: guildindex(n) index(n) name(str) position(n)
	MSG_HELPER_GUILD_MEMBER_ADD_REP,	// �߰� ����		: guildindex(n) boss(n) requester(n) errcode(n)
	MSG_HELPER_GUILD_MEMBER_OUT_REQ,	// Ż�� ��û		: guildindex(n) charindex(n)
	MSG_HELPER_GUILD_MEMBER_OUT_NTF,	// Ż�� �˸�		: guildindex(n) charindex(n) charname(str)
	MSG_HELPER_GUILD_MEMBER_OUT_REP,	// 20 Ż�� ����		: guildindex(n) charindex(n) errcode(uc)
	MSG_HELPER_GUILD_MEMBER_KICK_REQ,	// ���� ��û		: guildindex(n) bossindex(n) charindex(n)
	MSG_HELPER_GUILD_MEMBER_KICK_REP,	// ���� ����		: guildindex(n) bossindex(n) charindex(n) errcode(uc)
	MSG_HELPER_GUILD_MEMBER_KICK_NTF,	// ���� ���� �˸�	: guildindex(n) bossindex(n) charindex(n)
	MSG_HELPER_GUILD_CHANGE_BOSS_REQ,	// ���� ���� ��û	: guildindex(n) current(n) change(n)
	MSG_HELPER_GUILD_CHANGE_BOSS_NTF,	// ���� ���� �˸�	: guildindex(n) current(n) change(n)
	MSG_HELPER_GUILD_CHANGE_BOSS_REP,	// ���� ���� ����	: guildindex(n) current(n) change(n) errcode(uc)
	MSG_HELPER_GUILD_APPOINT_OFFICER_REQ, // �ΰ� ���� ��û : guildindex(n) boss(n) officer(n)
	MSG_HELPER_GUILD_APPOINT_OFFICER_REP, // �ΰ� ���� ���� : guildindex(n) boss(n) officer(n) errcode(uc)
	MSG_HELPER_GUILD_APPOINT_OFFICER_NTF, // �ΰ� ���� �˸� : guildindex(n) boss(n) officer(n)
	MSG_HELPER_GUILD_CHAT,				// 30 ��� ä��		: guildindex(n) charindex(n) charname(str) chat(str)
	MSG_HELPER_GUILD_FIRE_OFFICER_REQ,	// �ΰ� ���� ��û	: guildindex(n) boss(n) officer(n)
	MSG_HELPER_GUILD_FIRE_OFFICER_REP,	// �ΰ� ���� ����	: guildindex(n) boss(n) officer(n) errcode(uc)
	MSG_HELPER_GUILD_FIRE_OFFICER_NTF,	// �ΰ� ���� �˸�	: guildindex(n) boss(n) officer(n)
	MSG_HELPER_GUILD_LOAD_NTF,			// ��� �б� ����	: guildindex(n) guildlevel(n) guildname(str) bossindex(n) bossname(str) battle_guildindex(n) battle_name(str) battle_prize(n) battle_time(n) battle_zone(n) battle_killcount(n) battle_state(c)

	MSG_HELPER_CHAR_DEL,				// ĳ���� ����		: charindex(n)

	MSG_HELPER_GUILD_BATTLE_REQ,		// ����� ��û		: guildindex1(n) guildindex2(n) prize(n) zone(n) time(n)
	MSG_HELPER_GUILD_BATTLE_REP,		// ����� ����		: guildindex1(n) guildname1(str) guildindex2(n) guildname2(str) prize(n) zone(n) time(n)
	MSG_HELPER_GUILD_BATTLE_START,		// ����� ����		: guildindex1(n) guildindex2(n)
	MSG_HELPER_GUILD_BATTLE_STATUS,		// ����� ��Ȳ		: guildindex1(n) guildname1(str) killcount1(n) guildindex2(n) guildname2(str) killcount2(n) battletime(n) battlezone(n)
	MSG_HELPER_GUILD_BATTLE_STOP_REQ,	// 40 ����� ���� ��û	: guildindex1(n) guildindex2(n)
	MSG_HELPER_GUILD_BATTLE_STOP_REP,	// ����� ���� ����	: winner_index(n) guildindex1(n) guildname1(str) guildindex2(n) guildname2(str) prize(n) zone(n)
	MSG_HELPER_GUILD_BATTLE_PEACE_REQ,	// ����� ��ȭ ��û	: guildindex(n)
	MSG_HELPER_GUILD_BATTLE_PEACE_REP,	// ����� ��ȭ ����	: guildindex(n)
	MSG_HELPER_GUILD_BATTLE_KILL_REQ,	// ����� ų ����	: of_guildindex(n) df_guildindex(n)

	MSG_HELPER_EVENT_MOONSTONE_LOAD,
	MSG_HELPER_EVENT_MOONSTONE_UPDATE_REQ,
	MSG_HELPER_EVENT_MOONSTONE_UPDATE_REP,
	MSG_HELPER_EVENT_MOONSTONE_JACKPOT_REQ,
	MSG_HELPER_EVENT_MOONSTONE_JACKPOT_REP,

	MSG_HELPER_FRIEND_MEMBER_ADD_REQ,		// 50 ģ�� �߰� ��û.
	MSG_HELPER_FRIEND_MEMBER_ADD_REP,		//ģ�� �߰� ����.
	MSG_HELPER_FRIEND_MEMBER_DEL_REQ,		//ģ�� ���� ��û.
	MSG_HELPER_FRIEND_MEMBER_DEL_REP,		//ģ�� ���� ��û.
	MSG_HELPER_FRIEND_SET_CONDITION_REQ,	//���º����û.
	MSG_HELPER_FRIEND_SET_CONDITION_NOTIFY, //���º�������

	MSG_HELPER_PD4_RANK_INIT,			// pd4 rank DB init 
	MSG_HELPER_PD4_RANK_ADD,			// pd4 rank ����	 : charIndex(n) 
	MSG_HELPER_PD4_RANK_END,			// pd4 ����			 : charIndex(n) deadmonNum(n) bclear(c)
	MSG_HELPER_PD4_RANK_VIEW_REQ,		// : charindex(n) charjob(c)
	MSG_HELPER_PD4_RANK_VIEW_REP,		// 60 : charindex(n) multicount(c), charname(str), bclear(c), deadmon(n), ctime(ll);
	MSG_HELPER_PD4_REWARD_VIEW_REQ,		// : charindex(n) charjob(c)
	MSG_HELPER_PD4_REWARD_VIEW_REP, 	// : charindex(n) multicount(c), charname(str) breward(c)
	MSG_HELPER_PD4_REWARD_REQ,			// : charindex(n)
	MSG_HELPER_PD4_REWARD_REP,			// : charindex(n) charrank(c) breward(c)
	MSG_HELPER_PD4_REWARD_INIT,			// pd4 reward�� 0�� ����
	MSG_HELPER_PD4_REWARD_END,			// pd4 reward�� 1�� ���� 

	MSG_HELPER_PET_CREATE_REQ,			// �� ���� ��û		: owner(n) type_grade(c)
	MSG_HELPER_PET_CREATE_REP,			// �� ���� ����		: index(n) owner(n) type_grade(c)
	MSG_HELPER_PET_DELETE_REQ_RESERVE,	// �̻�� : �� ���� ��û		: index(n) owner(n)
	MSG_HELPER_PET_DELETE_REP_RESERVE,	// 70 �̻�� : �� ���� ����	: index(n) owner(n)

	MSG_HELPER_GUILD_STASH_HISTORY_REQ,	// �Աݳ��� ��û	: guildindex(n) charindex(n)
	MSG_HELPER_GUILD_STASH_HISTORY_REP,	// �Աݳ��� ����	: charindex(n) errcode(n) [month(n) day(n) money(ll)]:7
	MSG_HELPER_GUILD_STASH_VIEW_REQ,	// �ܾ� ��û		: guildindex(n) charindex(n)
	MSG_HELPER_GUILD_STASH_VIEW_REP,	// �ܾ� ����		: charindex(n) errcode(n) money(ll)
	MSG_HELPER_GUILD_STASH_TAKE_REQ,	// ��� ��û		: guildindex(n) charindex(n) money(ll)
	MSG_HELPER_GUILD_STASH_TAKE_REP,	// ��� ����		: guildindex(n) charindex(n) errcode(n) money(ll) balance(ll)
	MSG_HELPER_GUILD_STASH_ROLLBACK,	// ��� ���		: guildindex(n) money(ll)
	MSG_HELPER_GUILD_STASH_SAVE_TAX_REQ,// ���� �Ա�		: guildindex(n) taxItem(ll) taxProduct(ll)
	MSG_HELPER_GUILD_STASH_SAVE_TAX_REP,// ���� �Ա� ����	: errcode(n) guildindex(n) taxItem(ll) taxProduct(ll)
	
	MSG_HELPER_NAME_CHANGE_REQ,			// �̸� ����ī�� ��� : gs -> hs: bguild(c) charindex(n) nickname(str) 
	MSG_HELPER_NAME_CHANGE_REP,			// bguild : 0 �ɸ��� 1 ������ hs->gs : bguild(c) charindex(n) error(c)

	MSG_HELPER_TEACHER_FAMEUP_REQ,			// ���� ��ġ ��(����, �л�): charindex(n) charindex(n) fame(n)
	MSG_HELPER_TEACHER_FAMEUP_REP,			

	MSG_HELPER_TEACHER_REGISTER_REQ,	// ���� ��� ��û	: teacheridx(n) bteacher(c) studentidx(n)
	MSG_HELPER_TEACHER_GIVEUP_REQ,		// ���� ��û		: teacheridx(n) studentidx(n)
	MSG_HELPER_TEACHER_REQ,				// ��������Ʈ		: charindex(n) bteacher(c)

	MSG_HELPER_TEACHER_TIMEOVER_REQ,	// �ð� ���� ����	: bteacher(c) teacheridx(n) studentidx(n)
	MSG_HELPER_TEACHER_SUPERSTONERECIEVE,// �ʰ��� �ޱ�		: charindex(c)

	MSG_HELPER_TEACHER_LOAD_REQ,		// ���� �ý��� �б� : idname(str) charindex(n)
	MSG_HELPER_TEACHER_LOAD_REP,		// ���� �ʿ�����

	MSG_HELPER_MARGADUM_PVP_RANK,		// �������� ��ŷ : count(n) charindex(n) damage(ll)

	MSG_HELPER_SEARCHFRIEND_ADD_REQ,	// �޸� �߰���û	: approvalindex(n) appnick(str) appjob(n) appuserindex(n) appserverold(n) reqnick(str)  			
	MSG_HELPER_SEARCHFRIEND_ADD_REP,	// �޸� �߰�����	: approvalindex(n) appnick(str) appjob(n) requestindex(n) reqnick(str) reqjob(n) errcode(uc)
	MSG_HELPER_SEARCHFRIEND_SELECT_ADD_REQ,	// �޸� ���� ��� ��û		: approvalindex(n) requestindex(n)
	MSG_HELPER_SEARCHFRIEND_SELECT_ADD_REP,	// �޸� ���� ��� ����		: approvalindex(n) requestindex(n) errcode(uc)
	MSG_HELPER_SEARCHFRIEND_ONETIME_ADD_REQ,	// �ѽð� ���������û		: timesec(n) appDormantindex(n) appDormantgood(n)
	MSG_HELPER_SEARCHFRIEND_ONETIME_ADD_REP,	// �ѽð� ������������		: timesec(n) appDormantindex(n) appDormantgood(n) errcode(uc)
	MSG_HELPER_SEARCHFRIEND_LISTGOOD_REQ,	// ���� ���󰡴ɿ��� ��û	: approvalindex(n)
	MSG_HELPER_SEARCHFRIEND_LISTGOOD_REP,	// ���� ���󰡴ɿ��� ����	: approvalindex(n) request_listmember(n) startIndex(n) nTotal(n) requestnick(char)[] requestindex(n)[] approvalgood(n)[] 
	MSG_HELPER_SEARCHFRIEND_GOOD_REQ,		// ���� ������ ��û : approvalindex(n) ndormantindex(n) itemgood(n)
	MSG_HELPER_SEARCHFRIEND_GOOD_REP,		// ���� ������ ���� : approvalindex(n) errcode(uc)

	MSG_HELPER_PARTY_INVITE_REQ,		// ��Ƽ �ʴ� ��û	: bossindex(n) bossname(str) bosslevel(n) targetindex(n) partytype(c)
	MSG_HELPER_PARTY_INVITE_REP,		// ��Ƽ �ʴ� ����	: bossindex(n) bossname(str) targetindex(n) targetname(str) partytype(c) errorcode(n)
	MSG_HELPER_PARTY_ALLOW_REQ,			// ��Ƽ ���� ��û	: bossindex(n) targetindex(n) targetname(str)
	MSG_HELPER_PARTY_ALLOW_REP,			// ��Ƽ ���� ����	: bossindex(n) targetindex(n) targetname(str) errcode(n)
	MSG_HELPER_PARTY_REJECT_REQ,		// ��Ƽ �ź� ��û	: bossindex(n) targetindex(n)
	MSG_HELPER_PARTY_REJECT_REP,		// ��Ƽ �ź� ����	: bossindex(n) targetindex(n) errcode(n)
	MSG_HELPER_PARTY_QUIT_REQ,			// ��Ƽ Ż�� ��û	: bossindex(n) targetindex(n)
	MSG_HELPER_PARTY_QUIT_REP,			// ��Ƽ Ż�� ����	: bossindex(n) targetindex(n) errcode(n) newbossindex(n) newbossname(str)
	MSG_HELPER_PARTY_KICK_REQ,			// ��Ƽ ���� ��û	: bossindex(n) targetindex(n)
	MSG_HELPER_PARTY_KICK_REP,			// ��Ƽ ���� ����	: bossindex(n) targetindex(n) errcode(n)
	MSG_HELPER_PARTY_CHANGE_BOSS_REQ,	// ��Ƽ�� ���� ��û	: bossindex(n) newbossname(str)
	MSG_HELPER_PARTY_CHANGE_BOSS_REP,	// ��Ƽ�� ���� ����	: bossindex(n) bossname(str) newbossindex(n) newbossname(str)

	MSG_HELPER_PARTY_MATCH_REG_MEMBER_REQ,		// ��Ƽ ��Ī �Ϲ� ��� ��û : charIndex(n) charName(str) level(n) zone(n) job(c) partytype(c)
	MSG_HELPER_PARTY_MATCH_REG_MEMBER_REP,		// ��Ƽ ��Ī �Ϲ� ��� ���� : errorcode(n) charIndex(n) charName(str) level(n) zone(n) job(c) partytype(c)

	MSG_HELPER_PARTY_MATCH_REG_PARTY_REQ,		// ��Ƽ ��Ī ��Ƽ ��� ��û : bossindex(n) bossname(str) bosslevel(n) zone(n) jobflag(n) limitlevel(c) comment(str)
	MSG_HELPER_PARTY_MATCH_REG_PARTY_REP,		// ��Ƽ ��Ī ��Ƽ ��� ���� : errorcode(n) bossindex(n) bossname(str) bosslevel(n) zone(n) jobflag(n) limitlevel(c) partytype(c) comment(str)

	MSG_HELPER_PARTY_MATCH_DEL_REQ,				// ��Ƽ ��Ī ��� ���� ��û : charindex(n)
	MSG_HELPER_PARTY_MATCH_DEL_REP,				// ��Ƽ ��Ī ��� ���� ��û : charindex(n) errorcode(n)

	MSG_HELPER_PARTY_MATCH_INVITE_REQ,			// ��Ƽ ��Ī �Ϲ� �ʴ� ��û : bossindex(n) bossname(str) bosslevel(n) charindex(n) partytype(c)
	MSG_HELPER_PARTY_MATCH_INVITE_REP,			// ��Ƽ ��Ī �Ϲ� �ʴ� ���� : errorcode(n) bossindex(n) bossname(str) charindex(n) charname(str) partytype(c)

	MSG_HELPER_PARTY_MATCH_JOIN_REQ,			// ��Ƽ ��Ī ��Ƽ ���� ��û : bossindex(n) charindex(n) charname(str) charlevel(n) charjob(c)
	MSG_HELPER_PARTY_MATCH_JOIN_REP,			// ��Ƽ ��Ī ��Ƽ ���� ���� : errorcode(n) partytype(c) bossindex(n) bossname(str) charindex(n) charname(str) charjob(c)
	MSG_HELPER_PARTY_MATCH_JOIN_ALLOW_REQ,		// ��Ƽ ��Ī ��Ƽ ���� ���� : bossindex(n) charindex(n)
	MSG_HELPER_PARTY_MATCH_JOIN_ALLOW_REP,		// ��Ƽ ��Ī ��Ƽ ���� ��� : errorcode(n) bossindex(n) targetindex(n) targetname(str)

	MSG_HELPER_PARTY_MATCH_JOIN_REJECT_REQ,		// ��Ƽ ��Ī ��Ƽ ���� ���� : joincharindex(n) rejectcharindex(n)
	MSG_HELPER_PARTY_MATCH_JOIN_REJECT_REP,		// ��Ƽ ��Ī ��Ƽ ���� ��� : errorcode(n) joincharindex(n) rejectcharindex(n)

	MSG_HELPER_PARTY_MATCH_MEMBER_CHANGE_INFO,	// ��Ƽ �Ϲ� ��� ���� ���� : charindex(n) type(n) ...

	MSG_HELPER_PARTY_INFO_PARTY,				// ��Ƽ ���� ����			: partytype(c) requestindex(n) requestname(str) membercount(n) [charindex(n) charname(str)] * membercount
	MSG_HELPER_PARTY_INFO_PARTY_MATCH_MEMBER,	// ��Ƽ ��Ī �Ϲ� ��� ����	: charindex(n) charname(str) level(n) zone(n) job(c) partytype(c)
	MSG_HELPER_PARTY_INFO_PARTY_MATCH_PARTY,	// ��Ƽ ��Ī ��Ƽ ��� ����	: bossindex(n) bossname(str) bosslevel(n) zone(n) jobflag(n) partytype(c) limitlevel(c) comment(str)
	MSG_HELPER_PARTY_INFO_END,					// ��Ƽ ���� ���� �Ϸ�

	MSG_HELPER_BLOCKPC_REQ,						// ����û, �ش��ɸ��͸� ã�Ƽ� ������ ������ : reqIndex(n) blockName(str)
	MSG_HELPER_BLOCKPC_REP,						//							: reqIndex(n) blockIndex(n) blockName(str)

	MSG_HELPER_GIFT_RECVCHARNAME_REQ,			// ���ۿ� �ش� �ɸ��Ͱ� �ִ� : sendCharIndex(n) recvCharName(str) msg(str) count(n) idx(n) ctid(n)
	MSG_HELPER_GIFT_RECVCHARNAME_REP,			//							: sendCharIndex(n) recvUserIdx(n) recvCharIndex(n) revCharName(str) msg(str) count(n) idx(n) ctid(n)

	MSG_HELPER_SAVE_EXP_GUILD,					// ���� ���� ����ġ ����	: guildindex(n) exp(d)

	MSG_HELPER_PARENTSDAY_2007_ACCUMULATEPOINT_RANKING_LIST,	//����̳� ���� ����Ʈ ����Ʈ ���� ��û gs->hs charindex
																// hs->gs :errorcode(n) charindex(n) count( n ) rankig( c ) savepoint( n ) gildname(str)
	MSG_HELPER_PARENTSDAY_2007_ADD_POINT,						// ����Ʈ ��� gc->hs : CharIndex(n) CarnationCount(n)
																// hs->gs : errorcode(c) CharIndex(n) Carnationcount(n) totalpoint(n)
	MSG_HELPER_PARENTSDAY_2007_EXCHANGE_TICKET,					// ���� ����Ʈ�� ���� ��ȯ�� ��û  gs->hs : GuildIndex( n ) CharIndex(n)
																// hs->gs : errorcode(c) CharIndex(n) GiftTicket(n)
	
	MSG_HELPER_CHILDRENSDAY_2007,				// subtype (uc)	
	
	MSG_HELPER_PARENTSDAY_2007_EXCHANGE_ITEM,					// ��ȯ������ ITEM ��ȯ  gs->hs : GuildIndex( n ) CharIndex(n)
																// hs->gs : errorcode(c) CharIndex(n) GiftItemIndex(n)
	MSG_HELPER_TEACH_2007,
	MSG_HELPER_TEACH_2007_ADDFLOWER,							// ��� ī���̼� �����ض� gs->hs : charindex(n)
	MSG_HELPER_PARENTSDAY_2007_EXCHANGE_ITEM_INSERT,			// Item Insert ����  gs->hs : Charindex(n) GiftItemIndex(n)
	MSG_HELPER_PARENTSDAY_2007_NOTICE,
	MSG_HELPER_TEACH_2007_RECEIVE_FLOWER,						// ��� ī���̼� �޾��� gs->hs : charindex(n)

	MSG_HELPER_FLOWERTREE_2007,									// subtype (uc) , Charindex(n)
	MSG_HELPER_UPDATE_CHAOKING,									// ī��ŷ ���� REQ : bChao(c) charindex(n), charpenalty(n) 
																// REP : sucess(c) 0-���� ,1-����, bChao(c), charindex(n), charpenalty(n) //���н� ���� ŷ ����
	MSG_HELPER_ZONE_CHAO_ATTR,									// ī���� �Ӽ� ��û subtype(uc)
	MSG_HELPER_UPDATE_FAMEUP,									// ���ۿ� ĳ���� ��ġ ������Ʈ : REQ : charIndex(n), fameup(n), REP:NONE
	



	MSG_HELPER_GUILD_MARK_TABLE,				// hs->gs : index1(n), index2(n), index3(n)
	MSG_HELPER_LEVELUP_LOG,						// gs->hs : charstr(str), level(n)
	MSG_HELPER_PET_COLOR_CHANGE,				// gs->hs : charindex(n) petindex(n) petcolor(c)
												
	MSG_HELPER_GUILD_INCLINE_ESTABLISH_REQ,			// ��� ���� ����		: guildindex(n) charindex(n) guildincline(c)	
	MSG_HELPER_GUILD_INCLINE_ESTABLISH_REP,			// ��� ���� ����		: guildindex(n) charindex(n) guildincline(c)
	
	MSG_HELPER_GUILD_MEMBER_ADJUST_REQ,				// ��� ������� �⿩�� �� ������ �̸� ���� ��û: guildindex(n) count(n) charindex(n) positionname(str) contributeExp(n) contributeFame(n)
	MSG_HELPER_GUILD_MEMBER_ADJUST_REP,				// ��� ������� �⿩�� �� ������ �̸� ���� ����: guildindex(n) charindex(n) errorcode(n)

	MSG_HELPER_NEW_GUILD_INFO_REQ,					// ���ο� ��� ���� ��û : guildindex(n) charindex(n)
	MSG_HELPER_NEW_GUILD_INFO_REP,					// ���ο� ��� ���� ���� : charindex(n) errorcode(n)
	MSG_HELPER_NEW_GUILD_INFO_NTF,					// ���ο� ��� ���� ����

	MSG_HELPER_NEW_GUILD_MEMBERLIST_REQ,			// ���ο� ���� ���� ��û : guildindx(n) charindex(n)
	MSG_HELPER_NEW_GUILD_MEMBERLIST_REP,			// ���ο� ���� ���� ���� : charindex(n) guildindex(n) errorcode(n) membercount(n) membercharindex(n) cumulatePoint(n)

	MSG_HELPER_NEW_GUILD_MANAGE_REQ,				// ���ο� ��� �Ŵ��� ��û : guildindex(n) charindex(n)
	MSG_HELPER_NEW_GUILD_MANAGE_REP,				// ���ο� ��� �Ŵ��� ���� : 

	MSG_HELPER_NEW_GUILD_NOTICE_REQ,				// ���ο� ��� ���� ��û : guildindex(n) charindex(n)
	MSG_HELPER_NEW_GUILD_NOTICE_REP,				// ���ο� ��� ���� ���� : 

	MSG_HELPER_NEW_GUILD_NOTICE_UPDATE_REQ,			// ��� ���� ������Ʈ ��û :
	MSG_HELPER_NEW_GUILD_NOTICE_UPDATE_REP,			// ��� ���� ������Ʈ ���� :

	MSG_HELPER_NEW_GUILD_NOTICE_TRANSMISSION_REQ,		// �������� ���� ���� ��û :
	MSG_HELPER_NEW_GUILD_NOTICE_TRANSMISSION_NTF,
	MSG_HELPER_NEW_GUILD_NOTICE_TRANSMISSION_REP,

	MSG_HELPER_NEW_GUILD_NOTICE_SKILLLIST_REQ,
	MSG_HELPER_NEW_GUILD_NOTICE_SKILLLIST_REP,

	MSG_HELPER_NEW_GUILD_LOAD_NTF,
	MSG_HELPER_NEW_GUILD_MEMBER_LIST,
	MSG_HELPER_SAVE_GUILD_POINT,
	MSG_HELPER_SAVE_GUILD_MEMBER_POINT,
	MSG_HELPER_SAVE_GUILD_SKILL,
	
	MSG_HELPER_INSERT_GUARD,					// ���� ������ ����� ���� : gs->hs zoneidx(n) x(f) z(f) h(f) itemindex(n)
	MSG_HELPER_CASTLE_TOWER_ADD,				// ��ȣž �߰� : zoneidx(n), ž����  i(n), ž���� j(n), ���� nValue(b)

	MSG_HELPER_OPEN_ADULT_SERVER,
	MSG_HELPER_OPEN_ADULT_SERVER_REP,
	MSG_HELPER_UPDATE_GUILD_POINT,				// ��� ����Ʈ ������Ʈ�� �ϱ� ���� ����
	MSG_HELPER_PET_NAME_CHANGE,					// gs->hs : charindex(n) petindex(n) petname(str)
												// hs->gs : errorcode(c) charindex(n) petindex(n) petname(str)
												
	MSG_HELPER_CASTLE_TOWER_REINFORCE,			// ���� ���� ��ȣž ��ȭ gs->hs zoneidx(n), type(c), step(c)
	MSG_HELPER_CASTLE_QUARTERS_INSTALL,			// ��Ȱ ���� ��ġ qindex(n), gindex(n)
	MSG_HELPER_GUILD_NOTICE,					// ���ӽ� ��� ���� ���� ����
	MSG_HELPER_GUILD_SKILL_LEARN,				// ��� ��ų ����Ʈ DB�� ����

	MSG_HELPER_REWARD_IDC2007_REQ,		// 2007�� IDC�������� ������ ����(��û)
	MSG_HELPER_REWARD_IDC2007_REP,		// 2007�� IDC�������� ������ ����(����)
	MSG_HELPER_HALLOWEEN_2007,			// REQ : (n)user_index	REP : (n)user_index, (c) sucess (0-����, 1-�̹� ������ ����)

	MSG_HELPER_DVD_RATE_CHANGE,			// REQ : (c) nSubtype (n) rate REP : (c) nSubtype (n) rate

	MSG_HELPER_SAVE_MOONSTONE_MIX,		// �ֻ�޹����� ���ռ��� ����
	MSG_HELPER_PET_TURNTO_NPC,			// �� ��� ���� (n)nCharIndex, (n)nPetIndex, (n)toNpc ���� npc�ε���
	MSG_HELPER_ALTERNATEMERCHANT_START,	// �븮 ���� ����
	MSG_HELPER_ALTERNATEMERCHANT_BUY,	// ���� ����
	MSG_HELPER_ALTERNATEMERCHANT_PRODUCT_RECOVERY, // ���� ã�ƿ���
	MSG_HELPER_ALTERNATEMERCHANT_NAS_RECOVERY,	// ���� ã�ƿ���
	MSG_HELPER_ALTERNATEMERCHANT_END,		// �븮 ���� ����
	MSG_HELPER_ALTERNATEMERCHANT,			// �븮 ���� ����  ����

	MSG_HELPER_CREATE_COMBO,
	MSG_HELPER_TO_CONN_ADD_IPOINT,			// ���ۿ��� ���Ӽ����� ���� ���̸��� ����Ʈ ���� : REQ : NONE, REP : (n)UserIndex, (n)Type, (f)fIpoint
	
	MSG_HELPER_APET,						// AttackPet �� ���� Message : REQ:Subtype(c) REP:Subtype(c)

	MSG_HELPER_PARTY_CHANGE_TYPE_REQ,
	MSG_HELPER_PARTY_CHANGE_TYPE_REP,
	MSG_HELPER_PARTY_END_PARTY_REQ,
	MSG_HELPER_PARTY_END_PARTY_REP,
	
	MSG_HELPER_PET_DELETE_REQ,
	MSG_HELPER_PET_DELETE_REP,

	MSG_HELPER_ADDCUBEPOINT_PERSONAL,
	MSG_HELPER_CUBESTATE_REQ,
	MSG_HELPER_CUBESTATE_REP,
	MSG_HELPER_CUBESTATE_PERSONAL_REQ,
	MSG_HELPER_CUBESTATE_PERSONAL_REP,
	MSG_HELPER_GUILDCUBETIME_NOTICE,
	MSG_HELPER_ADDCUBETAX_REQ,
	MSG_HELPER_ADDCUBETAX_REP,
	MSG_HELPER_ADDCUBEPOINT,				// ���ť������Ʈ ȹ��
	MSG_HELPER_GUILDCUBETIME_END,
	MSG_HELPER_GUILDCUBETIME_START,			// 

	MSG_HELPER_EVENT_PHOENIX,				// �Ǵн� �̺�Ʈ // yhj   081105  �Ǵн�

	MSG_HELPER_TRADEAGENT_ERROR,			// �ŷ� ���� 			
	MSG_HELPER_TRADEAGENT_REG_LIST_REQ,		
	MSG_HELPER_TRADEAGENT_REG_LIST_REP,
	MSG_HELPER_TRADEAGENT_REG_REQ,			
	MSG_HELPER_TRADEAGENT_REG_REP,
	MSG_HELPER_TRADEAGENT_REG_CANCEL_REQ,
	MSG_HELPER_TRADEAGENT_REG_CANCEL_REP,
	MSG_HELPER_TRADEAGENT_RETURNED,
	MSG_HELPER_TRADEAGENT_SEARCH_REQ,
	MSG_HELPER_TRADEAGENT_SEARCH_REP,
	MSG_HELPER_TRADEAGENT_BUY_REQ,
	MSG_HELPER_TRADEAGENT_BUY_REP,
	MSG_HELPER_TRADEAGENT_CALCLIST_REQ,
	MSG_HELPER_TRADEAGENT_CALCLIST_REP,	
	MSG_HELPER_TRADEAGENT_CALCULATE_REQ,
	MSG_HELPER_TRADEAGENT_CALCULATE_REP,
	MSG_HELPER_TRADEAGENT_CALCRESULT,
	MSG_HELPER_TRADEAGENT_CHECKCALC_REQ,	//���� �ʿ� üũ(�α��ν�)
	MSG_HELPER_TRADEAGENT_CHECKCALC_REP,
	MSG_HELPER_TRADEAGENT_REGRESULT,		//��� ���	

	MSG_HELPER_DISCONNECT_HACK_CHARACTER,	// �� ĳ���� ���α� �����

	MSG_HELPER_EXPED_ERROR,					// ������ -->
	MSG_HELPER_EXPED_CREATE_REQ,			
	MSG_HELPER_EXPED_CREATE_REP,			
	MSG_HELPER_EXPED_CREATE_RESULT,			
	MSG_HELPER_EXPED_INVITE_REQ,				
	MSG_HELPER_EXPED_INVITE_REP,			
	MSG_HELPER_EXPED_INVITE_RESULT,			
	MSG_HELPER_EXPED_ALLOW_REQ,			
	MSG_HELPER_EXPED_ALLOW_REP,
	MSG_HELPER_EXPED_ALLOW_RESULT,
	MSG_HELPER_EXPED_REJECT_REQ,			
	MSG_HELPER_EXPED_REJECT_REP,
	MSG_HELPER_EXPED_REJECT_RESULT,
	MSG_HELPER_EXPED_QUIT_REQ,				
	MSG_HELPER_EXPED_QUIT_REP,
	MSG_HELPER_EXPED_QUIT_RESULT,
	MSG_HELPER_EXPED_KICK_REQ,				
	MSG_HELPER_EXPED_KICK_REP,
	MSG_HELPER_EXPED_KICK_RESULT,
	MSG_HELPER_EXPED_MEMBERINFO_REQ,		
	MSG_HELPER_EXPED_MEMBERINFO_REP,
	MSG_HELPER_EXPED_ADMIN_REQ,				
	MSG_HELPER_EXPED_ADMIN_REP,
	MSG_HELPER_EXPED_ADMIN_RESULT,		
	MSG_HELPER_EXPED_CHANGETYPE_REQ,		
	MSG_HELPER_EXPED_CHANGETYPE_REP,
	MSG_HELPER_EXPED_CHANGETYPE_RESULT,	
	MSG_HELPER_EXPED_CHANGEBOSS_REQ,		
	MSG_HELPER_EXPED_CHANGEBOSS_REP,
	MSG_HELPER_EXPED_CHANGEBOSS_RESULT,	
	MSG_HELPER_EXPED_SETMBOSS_REQ,		
	MSG_HELPER_EXPED_SETMBOSS_REP,
	MSG_HELPER_EXPED_SETMBOSS_RESULT,  
	MSG_HELPER_EXPED_RESETMBOSS_REQ,		
	MSG_HELPER_EXPED_RESETMBOSS_REP,
	MSG_HELPER_EXPED_RESETMBOSS_RESULT,  
	MSG_HELPER_EXPED_VIEWDETAIL_REQ,		
	MSG_HELPER_EXPED_VIEWDETAIL_REP,	 	
	MSG_HELPER_EXPED_ENDEXPED_REQ,			
	MSG_HELPER_EXPED_ENDEXPED_REP,
	MSG_HELPER_EXPED_ENDEXPED_RESULT,  
	MSG_HELPER_EXPED_MOVEGROUP_REQ,			
	MSG_HELPER_EXPED_MOVEGROUP_REP,
	MSG_HELPER_EXPED_MOVEGROUP_RESULT,  
	MSG_HELPER_EXPED_ADDMEMBER_REQ,			
	MSG_HELPER_EXPED_ADDMEMBER_REP,
	MSG_HELPER_EXPED_ADDMEMBER_RESULT, 
	MSG_HELPER_EXPED_SET_LABEL_REQ,				
	MSG_HELPER_EXPED_SET_LABEL_REP,	
	MSG_HELPER_EXPED_SET_LABEL_RESULT,		// ������ <--	
	MSG_HELPER_EXPED_REJOIN_REQ,
	MSG_HELPER_EXPED_REJOIN_REP,
	MSG_HELPER_EXPED_CHAT_REQ,	
	MSG_HELPER_EXPED_CHAT_REP,	
} MSG_HELPER_COMMAND_TYPE;

typedef enum _tagHelperApetType
{
	MSG_HELPER_APET_CREATE_REQ,				// APET ���� ��û (n) owner_indx, (n)proto_index
	MSG_HELPER_APET_CREATE_OK,				// �� ���� ��û ����
	MSG_HELPER_APET_CREATE_FAILED,			// �� ���� ��û ����
	MSG_HELPER_APET_ACCENPT_REQ,			// APET �Ÿ� �����Ϸ� (n)owner_index, (n) pet_index
	MSG_HELPER_APET_ACCENPT_OK,
	MSG_HELPER_APET_ACCENPT_FAILED,
	MSG_HELPER_APET_DELETE_REQ,				// �޸𸮿��� ���� �ϰ� DB�� ���� ��û
	MSG_HELPER_APET_CHANGE_OWNER_REQ,		// DB�� ���� ���� ��û
	MSG_HELPER_APET_CHANGE_OWNER_OK,
	MSG_HELPER_APET_CHANGE_OWNER_FAILED,
} MSG_HELPER_APET_TYPE;

typedef enum _tagHelperZoneChaoAttType
{
	MSG_HELPER_ZONE_CHAO_ATT_REQ,								// ���� ��ü �� �Ӽ��� ���ۿ� ��û 
	MSG_HELPER_ZONE_CHAO_ATT_CHANGE,							// ��ȭ�� �� �Ӽ� ���� ��û count(n), zoneidx(n), extra(n), attribute(c), ( extra1, attribute1,) ...
	MSG_HELPER_ZONE_CHAO_ATT_REP,								// ���� �Ǵ� ����� �Ӽ� count(n), ( zoneindex(n), attcount(n), attribute(c)... )....
} MSG_HELPER_ZONE_CHAO_ATT_TYPE;

typedef enum _tagHelperChildrensDay2007Type
{
	MSG_HELPER_CHILDRENSDAY_2007_CHECK,			// ������ ���� �ߺ��˻� : charindex(n), itemindex(n) ,needFlower(n) : �ʿ��� ���� ����, columnindex(c)
												//						: charindex(n), itemindex(n), needFlower(n), request(c) : 0-����, 1-���  
	MSG_HELPER_CHILDRENSDAY_2007_UPDATE,		// ������ ���� ������Ʈ : charindex(n), itemindex(n) 
} MSG_HELPER_CHILDRENSDAY_2007_TYPE;

typedef enum _tagHelperFlowerTree2007Type
{
	MSG_HELPER_FLOWERTREE_2007_MYPOINT,				// REQ : not / REP: point(un)....
	MSG_HELPER_FLOWERTREE_2007_ADDMYPOINT,			// REQ : point(un)
	MSG_HELPER_FLOWERTREE_2007_RECV_TICKET,			// REQ : not / rep : count(n)
	MSG_HELPER_FLOWERTREE_2007_TICKET_UPDATE,		// REQ : count(n) 
	MSG_HELPER_FLOWERTREE_2007_PRICEITEM,			// REQ : not / REP : itemindex(n), count(n)
	MSG_HELPER_FLOWERTREE_2007_PRICEITEM_INSERT,	// REQ : isGM(uc) itemindex(n)
	MSG_HELPER_FLOWERTREE_2007_PRICEMSG,			// REP : itemindex(n)
}MSG_HELPER_FLOWERTREE_2007_TYPE;

typedef enum _tagHelperPartyMatchMemberChangeInfoType
{
	MSG_HELPER_PARTY_MATCH_MEMBER_CHANGE_INFO_NAME,				// �̸� ����	: charname(str)
	MSG_HELPER_PARTY_MATCH_MEMBER_CHANGE_INFO_LEVEL,			// ���� ����	: level(n)
	MSG_HELPER_PARTY_MATCH_MEMBER_CHANGE_INFO_ZONE,				// ���̵�		: level(n) zone(n)
} MSG_HELPER_PARTY_MATCH_MEMBER_CHANGE_INFO_TYPE;

typedef enum _tagHelperPartyMatchErrorType
{
	MSG_HELPER_PARTY_MATCH_ERROR_REG_MEMBER_OK,					// 0 ��� ����
	MSG_HELPER_PARTY_MATCH_ERROR_REG_MEMBER_ALREADY_PARTY,		// 1 ��Ƽ ��
	MSG_HELPER_PARTY_MATCH_ERROR_REG_MEMBER_ALREADY_REG,		// 2 ���� �����

	MSG_HELPER_PARTY_MATCH_ERROR_REG_PARTY_OK,					// 3 ��Ƽ ��Ī ��Ƽ ��� ����
	MSG_HELPER_PARTY_MATCH_ERROR_REG_PARTY_NO_BOSS,				// 4 ��Ƽ���� �ƴ� ����� ��û��
	MSG_HELPER_PARTY_MATCH_ERROR_REG_PARTY_FULL,				// 5 ��Ƽ�ο� ������
	MSG_HELPER_PARTY_MATCH_ERROR_REG_PARTY_ALREADY_REG,			// 6 �̹� ��ϵ� ��Ƽ

	MSG_HELPER_PARTY_MATCH_ERROR_DEL_MEMBER,					// 7 �Ϲ� ��Ͽ��� ������
	MSG_HELPER_PARTY_MATCH_ERROR_DEL_PARTY,						// 8 ��Ƽ ��Ͽ��� ������

	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_OK,						// 9 ����
	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_NOT_FOUND,				// 10 ��Ƽ ��Ī�� ���� ����� �ʴ�
	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_LEVEL,					// 11 ��Ƽ Ÿ���� PARTY_TYPE_BATTLE �϶� ���� �˻翡 ��������
	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_NOBOSS,					// 12 ��Ƽ���� �ƴ� ����� ��û��
	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_DIFF_TYPE,				// 13 ��Ƽ Ÿ���� ���� ����
	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_ALREADY_TARGET,			// 14 ����� �̹� ��Ƽ ��
	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_FULL,					// 15 ��Ƽ �ο��� �ʰ�
	MSG_HELPER_PARTY_MATCH_ERROR_INVITE_ALREADY_REQUEST,		// 16 �ٸ� ������� ��û ���϶�

	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_OK,						// 17 ���� ����
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_ALREADY_TARGET,			// 18 ������ ��û�� ���� �̹� �ٸ� ��Ƽ�� ���� ��
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_NOT_FOUND,				// 19 ���� �Ϸ��� �ϴ� ��Ƽ�� ��Ī ���̺� ����
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_LEVEL,					// 20 ��Ƽ Ÿ���� PARTY_TYPE_BATTLE�̰� ���� �˻翡 ������
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_LIMIT_LEVEL,				// 21 ���� ���� ���ǿ� ������
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_JOB,						// 22 ���� ������
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_FULL,						// 23 �ο� ������
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_ALREADY_REQUEST,			// 24 ���� �ʴ� ��û�ڰ� �־ �Ұ���

	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_ALLOW_OK,					// 25 ��Ƽ ���� ����
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_ALLOW_NOT_PARTY,			// 26 ��Ƽ�� ����

	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_REJECT_OK,				// 27 ��Ƽ ���� ���� ����
	MSG_HELPER_PARTY_MATCH_ERROR_JOIN_REJECT_FAIL,				// 28 ��Ƽ ���� ���� ����

} MSG_HELPER_PARTY_MATCH_ERROR_TYPE;

typedef enum _tagHelperPartyErrorType
{
	MSG_HELPER_PARTY_ERROR_INVITE_OK,				// 0 ����
	MSG_HELPER_PARTY_ERROR_INVITE_ALREADY_ME,		// 1 ��û�ڰ� ��Ƽ ��
	MSG_HELPER_PARTY_ERROR_INVITE_DIFF_TYPE,		// 2 ��Ƽ Ÿ���� ������ �ٸ�
	MSG_HELPER_PARTY_ERROR_INVITE_LEVEL,			// 3 ����� ���� ���� �ȵ�
	MSG_HELPER_PARTY_ERROR_INVITE_ALREADY_TARGET,	// 4 ����ڰ� ��Ƽ ��
	MSG_HELPER_PARTY_ERROR_INVITE_FULL,				// 5 ��Ƽ �ο� �ʰ�
	MSG_HELPER_PARTY_ERROR_INVITE_ALREADY_REQUEST,	// 6 �ٸ� ������� �̹� ��û ��

	MSG_HELPER_PARTY_ERROR_ALLOW_OK,				// 7 ����
	MSG_HELPER_PARTY_ERROR_ALLOW_NOT_PARTY,			// 8 ��Ƽ ���� �ƴҶ�

	MSG_HELPER_PARTY_ERROR_REJECT_OK,				// 9 ����
	MSG_HELPER_PARTY_ERROR_REJECT_FAIL,				// 10 ����

	MSG_HELPER_PARTY_ERROR_QUIT_OK,					// 11 ����
	MSG_HELPER_PARTY_ERROR_QUIT_END,				// 12 ����, ��Ƽ ��ü

	MSG_HELPER_PARTY_ERROR_KICK_OK,					// 13 ����
	MSG_HELPER_PARTY_ERROR_KICK_END,				// 14 ����, ��Ƽ ��ü

	MSG_HELPER_PARTY_ERROR_INVITE_PVP,				// 15 ��û�ڳ� ����ڰ� PVP ��

} MSG_HELPER_PARTY_ERROR_TYPE;

typedef enum _tagHelperGuildStashErrorType
{
	MSG_HELPER_GUILD_STASH_ERROR_OK,			// ����
	MSG_HELPER_GUILD_STASH_ERROR_NOHISTORY,		// �����丮 ����
	MSG_HELPER_GUILD_STASH_ERROR_NOTBOSS,		// �����/�ΰ� �ƴ�
	MSG_HELPER_GUILD_STASH_ERROR_NOTENOUGH,		// �ܾ� ����
	MSG_HELPER_GUILD_STASH_ERROR_FAIL_DB,		// �ý��� ����
} MSG_HELPER_GUILD_STASH_ERROR_TYPE;

typedef enum _tagHelperOpenAdultServerErrorType
{
	MSG_HELPER_OPEN_ADULT_SERVER_CHANGEJOB,			// �����û
	MSG_HELPER_OPEN_ADULT_SERVER_CHANGEJOB_OK,		// ���󼺰� ���(n)
	MSG_HELPER_OPEN_ADULT_SERVER_CHANGEJOB_ALREADY, // �̹� ��ȯ����

	MSG_HELPER_OPEN_ADULT_SERVER_CHANGEJOB_FAILED,  // �������

}MSG_HELPER_OPEN_ADULT_SERVER_ERROR_TYPE;

//typedef enum _tagHelperParentsDay2007Type
//{
//	MSG_HELPER_PARENTSDAY_2007_ACCUMULATEPOINT_RANKING_LIST,	//����̳� ���� ����Ʈ ����Ʈ ���� ��û gs->hs
//																// hs->gs :count( n ) rankig( c ) savepoint( n ) gildname(str) gildmaster(str)
//	MSG_HELPER_PARENTSDAY_2007_ADD_POINT,						// ����Ʈ ��� gc->hs : CharIndex(n) echangeItemIndex(n)
//																// hs->gs : errorcode(c) point(n) totalpoint(n)
//	MSG_HELPER_PARENTSDAY_2007_EXCHANGE_TICKET,					// ���� ����Ʈ�� ���� ��ȯ�� ��û  s->c : errorcode(c) changeTicketCount(n)
//}MSG_HELPER_PARENTSDAY_2007_TYPE;




typedef enum _tagMsgChangeType
{
	MSG_CHANGE_START,					// ���ż��� ����	: charindex(n) mobindex(n)
	MSG_CHANGE_STOP,					// ���� ����		: charindex(n)
	MSG_CHANGE_CANCEL,					// ���� ��� ��û	: 
	MSG_CHANGE_ERR,						// ���� ��û�� ����	: errtype(uc)
} MSG_CHANGE_TYPE;

typedef enum _tagMsgChangeErrType
{
	MSG_CHANGE_ERR_DEAD,				// ���ſ���			: �׾����� ���� �Ұ�
	MSG_CHANGE_ERR_SITDOWN,				// ���ſ���			: �ɾ������� ���� �Ұ�
	MSG_CHANGE_ERR_WRAP,				// ���ſ���			: �̵���ġ ����� �϶� ���� �Ұ�
	MSG_CHANGE_ERR_SKILL,				// ���ſ���			: ��ų ����� �϶� ���� �Ұ�
	MSG_CHANGE_ERR_EXCHANGE,			// ���ſ���			: ��ȯ���϶� ���� �Ұ�
	MSG_CHANGE_ERR_PARTY,				// ���ſ���			: ��Ƽ ��û ���϶� ���� �Ұ�
	MSG_CHANGE_ERR_PK,					// ���ſ���			: PK ���϶� ���� �Ұ�
	MSG_CHANGE_ERR_LEVEL,				// ���ſ���			: ������ ������ ���� �Ұ�
	MSG_CHANGE_ERR_ZONE,				// ���ſ���			: ���� Ʋ�� ���� �Ұ�
	MSG_CHANGE_ERR_BATTLE,				// ���ſ���			: ������ ���� �Ұ�
	MSG_CHANGE_ERR_PERSONAL_SHOP,		// ���ſ���			: ���λ����� ���� �Ұ�
} MSG_CHANGE_ERR_TYPE;

typedef enum _tagMsgUIType
{
	MSG_UI_PLUS_EFFECT_REQ,				// �÷�������Ʈ��û	: pluseffect(c)
	MSG_UI_PLUS_EFFECT_REP,				// �÷�������Ʈ����	: pluseffect(c) charindex(n)
} MSG_UI_TYPE;

typedef enum _tagMsgTeachType
{
	MSG_TEACH_TEACHER_LIST,				// ���� ����Ʈ		: subtype(uc)
	MSG_TEACH_TEACHER_REQ,				// ���� ��û ����	: subtype(uc)
	MSG_TEACH_END,						// ����				: teacher_index(n) teacher_name(str) student_index(n) student_name(str) end_type(uc)
	MSG_TEACH_INFO,						// ���� ����		: bteacher_list(c) char_type(c) teacher_index(n) teach_level(n) teacher_name(str) teacher_job(c) teacher_job2(c) or [student_index(n) student_level(n) student_name(str) student_job(c) student_job2(c)] * 8
	MSG_TEACH_STUDENT_LEVELUP,			// �л� ������		: student_index(n) student_level(n) student_name(str) student_job(c) student_job2(c)

	MSG_TEACH_ERR,						// ����				: errtype(uc)

} MSG_TEACH_TYPE;

typedef enum _tagMsgTeachTeacherListType
{
	MSG_TEACH_TEACHER_LIST_UP,			// ����Ʈ ���
	MSG_TEACH_TEACHER_LIST_DN,			// ����Ʈ ��� ���
	MSG_TEACH_TEACHER_LIST_SHOW,		// ����Ʈ ���		: [char_index(n) char_name(str) char_job(c) char_job2(c)] * 20

} MSG_TEACH_TEACHER_LIST_TYPE;

typedef enum _tagMsgTeachTeacherReqType
{
	MSG_TEACH_TEACHER_REQ_REQ,			// ���� ��û		: charindex(n) char_name(str)
	MSG_TEACH_TEACHER_REQ_REJECT,		// ���� ��û ����	: reject_charindex(n) reject_charname(str)
	MSG_TEACH_TEACHER_REQ_ACCEPT,		// ���� ���		: teacher_index(n) teacher_name(str) student_index(n) student_name(str)
	MSG_TEACH_TEACHER_GIVEUP,			// �л� ���� ��û	: teacher_index(n) teacher_name(str) student_index(n) student_name(str)

} MSG_TEACH_TEACHER_REQ_TYPE;

typedef enum _tagMsgTeachCharType
{
	MSG_TEACH_NO_TYPE = -1,				// ���� ���� ����				
	MSG_TEACH_TEACHER_TYPE = 0,			// ����
	MSG_TEACH_STUDENT_TYPE,				// �л�
	MSG_TEACG_NO_STUDENT_TYPE,			// �ѹ� ���� �ߴ� �л� : ���̻� �Ұ���

} MSG_TEACH_CHAR_TYPE;

typedef enum _tagMsgTeachEndType
{
	MSG_TEACH_END_FAIL,					// ����
	MSG_TEACH_END_SUCCESS,				// ����
} MSG_TEACH_END_TYPE;

typedef enum _tagMsgTeachErrType
{
	MSG_TEACH_ERR_SYSTEM,					// ������ �ȵǴ� ����
	MSG_TEACH_ERR_TEACHER_LEVEL,			// ���� ���ɷ����� �ƴ�
	MSG_TEACH_ERR_TEACHER_LIST_ALREADY,		// �̹� ���� ����Ʈ�� ����
	MSG_TEACH_ERR_TEACHER_LIST_NOT,			// ���� ����Ʈ�� ���� ����
	MSG_TEACH_ERR_TEACHER_REQ_ALREADY,		// �̹� ��û��
	MSG_TEACH_ERR_STUDENT_LEVEL,			// �л� ���ɷ����� �ƴ�
	MSG_TEACH_ERR_HAVE_TEACHER,				// �̹� ������ ����
	MSG_TEACH_ERR_TEACHER_NOT_CONNECT,		// ������ �������� �ƴ�
	MSG_TEACH_ERR_STUDENT_NOT_CONNECT,		// �л��� �������� �ƴ�
	MSG_TEACH_ERR_TEACHER_FULL,				// ���ڰ� �� �� ����
	MSG_TEACH_ERR_NOE_REQ,					// ��û�� �� ����
	MSG_TEACH_ERR_NOMORE_STUDENT,			// ���̻� �л� �� �� ����

} MSG_TEACH_ERR_TYPE;

typedef enum _tagMsgChangeJobType
{
	MSG_CHANGEJOB_ERROR,					// ����				: errcode(c)
	MSG_CHANGEJOB_REQ,						// ���� ��û		: job2(c)
	MSG_CHANGEJOB_REP,						// ���� �˸�		: charindex(n) job(c) job2(c)
	MSG_CHANGEJOB_RESET_REQ,				// ���� ���� ��û	: 
	MSG_CHANGEJOB_RESET_REP,				// ���� ���� �˸�	: charindex(n) job(c)
} MSG_CHANGEJOB_TYPE;

typedef enum _tagMsgChangeJobErrorType
{
	MSG_CHANGEJOB_ERROR_OK,							// RESERVED
	MSG_CHANGEJOB_ERROR_WRONGMSG,					// Ŭ���̾�Ʈ�� �̻��ϴ�
	MSG_CHANGEJOB_ERROR_ALREADY,					// �̹� ��������
	MSG_CHANGEJOB_ERROR_NOCONDITION_LEVEL,			// ���� ���� ����� : ���� ����
	MSG_CHANGEJOB_ERROR_NOCONDITION_SKILL,			// ���� ���� ����� : ��ų ����
	MSG_CHANGEJOB_ERROR_NOCONDITION_SKILLLEVEL,		// ���� ���� ����� : ��ų ���� ����
	MSG_CHANGEJOB_ERROR_NOMONEY,					// ���� ������
} MSG_CHANGEJOB_ERROR_TYPE;

//0502 kwon
typedef enum _tagEventMoonStoneType
{
	MSG_EVENT_MOONSTONE_START_REQ,		// ������ ���ۿ�û
	MSG_EVENT_MOONSTONE_START_REP,		// ������ ��������

	MSG_EVENT_MOONSTONE_TRY_REQ,		// ������ ���� ��û
	MSG_EVENT_MOONSTONE_TRY_REP,		// ������ ���� ����

	MSG_EVENT_MOONSTONE_RESULT_REQ,		// ������ ���� ��� ��û
	MSG_EVENT_MOONSTONE_RESULT_REP,		// ������ ���� ��� ����
	
} MSG_EVENT_MOONSTONE_TYPE;


typedef enum _tagEventMoonStoneChangeType
{
//5�� ��ġ.
	MSG_CHANGE_JACK_POT,						// ����.
	MSG_CHANGE_5PLUS_41LEVEL_WEAPON,			// 41���� +5 ����(������)	
	MSG_CHANGE_3PLUS_41LEVEL_WEAPON,			// 41���� +3 ����(������)	
	MSG_CHANGE_41LEVEL_WEAPON,					// 41���� ���� (������)
	MSG_CHANGE_3_SPECIAL_STONE,					// ������ü� 3��
	MSG_CHANGE_2_SPECIAL_STONE,					// ������ü� 2��
	MSG_CHANGE_1_SPECIAL_STONE,					// ������ü� 1��
//4����ġ
	MSG_CHANGE_CRYSTAL_OF_EFFORT,				// ����� ����.
	MSG_CHANGE_HIGH_CRYSTAL_OF_EXPERIMENCE,		// ��� ������ ����.
	MSG_CHANGE_150000_EXP,					    // ����ġ 150,000
	MSG_CHANGE_MIDDLE_CRYSTAL_OF_EXPERIMENCE,	// �߱� ������ ����
	MSG_CHANGE_10_PURE_STONE,					// ��ȭ�� 10��
	MSG_CHANGE_70000_EXP,						// ����ġ 70,000
	MSG_CHANGE_3_MIDDLE_CRYSTAL_OF_EXPERIMENCE,	// �ϱ� ������ ���� 3��
//3����ġ
	MSG_CHANGE_5_12GRADE_RED_KER,				//12���� ���� �ɸ� 5��
	MSG_CHANGE_5_12GRADE_RED_NEN,				//12���� ���� �� 5��
	MSG_CHANGE_5_12GRADE_BLUE_KER,				//12���� Ǫ�� �ɸ� 5��
	MSG_CHANGE_5_BIG_MP_POTION,					//���� MP���� 5��
	MSG_CHANGE_5_12GRADE_BLUE_NEN,				//12���� Ǫ�� �� 5��
	MSG_CHANGE_5_MOONSTONE,						//������ 5��
	MSG_CHANGE_25000_EXP,						// ����ġ 25,000

//2����ġ
	MSG_CHANGE_3_6GRADE_RED_KER,				//6���� ���� �ɸ� 3�� 
	MSG_CHANGE_3_6GRADE_RED_NEN,				//6���� ���� �� 3��
	MSG_CHANGE_3_6GRADE_BLUE_KER,				//6���� Ǫ�� �ɸ� 3��
	MSG_CHANGE_3_BIG_HEAL_POTION,				//���� HP���� 3��
	MSG_CHANGE_3_6GRADE_BLUE_NEN,				//6���� Ǫ���� 3��
	MSG_CHANGE_3_MIDDLE_MP_POTION,				//���� MP���� 3��
	MSG_CHANGE_3_MEMORY_SCROLL,					//�޸� ��ũ�� 3��

	MSG_CHANGE_3_C_GRADE_ELEMENTAL,				//c��� ���� 3��
	MSG_CHANGE_3_CRAK_BLUE_LEAF,			 	//ũ�� �Ķ��� 3��
	MSG_CHANGE_3_STONE_WEAVER,					//���� ���� 3��
	MSG_CHANGE_3_D_GRADE_ELEMENTAL,				//D��� ���� 3��
	MSG_CHANGE_3_MIDIUM_HEAL_POTION,			//����ȸ������ 5��
	MSG_CHANGE_3_CRAK_BRANCH,					//ũ�� �ٱ� 3��
	MSG_CHANGE_3_STONELISE,						//���� ����

	MSG_CHANGE_NO_MOONSTONE,		// �������� ����.	
	MSG_CHANGE_MOONSTONE_RULLET,				// 5���� �귿���� ������.	
	MSG_CHANGE_MOONSTONE_ACC_NAS,   //���� ����.

} MSG_EVENT_MOONSTONE_CHANGE_TYPE;


typedef enum _tagFriendType
{
	MSG_FRIEND_ERROR,
	MSG_FRIEND_REGIST_REQUEST,
	MSG_FRIEND_REGIST_ALLOW,
	MSG_FRIEND_SET_CONDITION, 
	MSG_FRIEND_CHATTING,
	MSG_FRIEND_REGIST_CANCEL,
	MSG_FRIEND_DELETE_MEMBER,
	MSG_FRIEND_REGIST_MEMBER_NOTIFY,
	MSG_FRIEND_DELETE_MEMBER_NOTIFY,
	MSG_FRIEND_MEMBERLIST
} MSG_FRIEND_TYPE;

typedef enum _tagFriendErrorType
{
	MSG_FRIEND_ERROR_OK,		//����.(ģ�����OK, ���� OK)
	MSG_FRIEND_ERROR_PACKET,    //��Ŷ����
	MSG_FRIEND_ERROR_NOT_EXIST, //�������� �ʴ´�.
	MSG_FRIEND_ERROR_FULLMEMBER, //ģ�� ���� �ʰ�.
	MSG_FRIEND_ERROR_ALREADY_EXIST, //�̹� ģ������Ʈ�� ����.
	MSG_FRIEND_ERROR_WAIT_OTHER, //�ٸ� ������κ��� ģ������� ��û���� ����..
	MSG_FRIEND_ERROR_NOT_MATCH_INDEX, //���ΰ� ģ�� ��û,���� ���̵� ��ġ���� �ʴ´�.
	MSG_FRIEND_ERROR_HELPER_SERVER, //���ۼ������� ���ӿ���.
	MSG_FRIEND_ERROR_GAMESERVER,
	MSG_FRIEND_ERROR_FRIENDNAME, //�̸��� �߸��Ǿ���..
	MSG_FRIEND_ERROR_ALREADY_BLOCK, //�̹� �� �Ǿ���.
	MSG_FRIEND_ERROR_NOT_BLOCK, //�̹� �� ���� ���� �ɸ��� 
	MSG_FRIEND_ERROR_REGIST_REFUSE_PVP		// pvp ������ ģ����� �ź�
} MSG_FRIEND_ERROR_TYPE;

typedef enum _tagTreasureBoxType
{
	MSG_EVENT_TREASUREBOX_TRY_REQ,		
	MSG_EVENT_TREASUREBOX_TRY_REP,		

	MSG_EVENT_TREASUREBOX_OPEN_REQ,
	MSG_EVENT_TREASUREBOX_OPEN_REP,

	MSG_EVENT_TREASUREBOX_RED_TRY_REQ,		
	MSG_EVENT_TREASUREBOX_RED_TRY_REP,		

	MSG_EVENT_TREASUREBOX_RED_OPEN_REQ,
	MSG_EVENT_TREASUREBOX_RED_OPEN_REP,
} MSG_EVENT_TREASUREBOX_TYPE;

typedef enum _tagEventTreasureBoxLevelType
{
	MSG_EVENT_TREASUREBOX_10LEVEL,
	MSG_EVENT_TREASUREBOX_14LEVEL,
	MSG_EVENT_TREASUREBOX_18LEVEL,
	MSG_EVENT_TREASUREBOX_22LEVEL,
	MSG_EVENT_TREASUREBOX_26LEVEL,
	MSG_EVENT_TREASUREBOX_30LEVEL,

	MSG_EVENT_TREASUREBOX_ERROR_NOT_LEVEL,  
	MSG_EVENT_TREASUREBOX_ERROR_NO_BOX,  

	MSG_EVENT_TREASUREBOX_RED_5LEVEL,
	MSG_EVENT_TREASUREBOX_RED_12LEVEL,
	MSG_EVENT_TREASUREBOX_RED_16LEVEL,

	MSG_EVENT_TREASUREBOX_RED_ERROR_NOT_LEVEL,  
	MSG_EVENT_TREASUREBOX_RED_ERROR_NO_BOX, 
	
} MSG_EVENT_TREASUREBOX_LEVEL_TYPE;

typedef enum _tagEventTreasureBoxChangeType
{
	MSG_EVENT_CHANGE_13LEVEL_WEAPON,
	MSG_EVENT_CHANGE_21LEVEL_WEAPON,
	MSG_EVENT_CHANGE_29LEVEL_WEAPON,
	MSG_EVENT_CHANGE_NAS,
	MSG_EVENT_CHANGE_CANDY,
	MSG_EVENT_CHANGE_ATTACK_POTION,
	MSG_EVENT_CHANGE_DEFENSE_POTION,

	MSG_EVENT_CHANGE_NO_TREASUREBOX,


	MSG_EVENT_CHANGE_HP_POTION,			// ����  HP Ȯ�� ����
	MSG_EVENT_CHANGE_MP_POTION,			// ����  MP Ȯ�� ����
	MSG_EVENT_CHANGE_EX_MEMORY,			// �޸� ��ũ�� Ȯ�� ī��
	MSG_EVENT_CHANGE_HPMP_POTION,		// ����  HP/MP Ȯ�� ����
	MSG_EVEVNT_CHAGE_EX_STAT,			// ���� â�� Ȯ�� ī��

	MSG_EVENT_CHANGE_PINK_DRAGON,		// ��ũ �巹��ũ �� ��ȯ - �±� 30���� ���� ����
	MSG_EVENT_CHANGE_BLUE_HORSE,		// �Ķ� ���� �Ǹ� ��ȯ - �±� 30���� ���� ����
} MSG_EVENT_TREASUREBOX_CHANGE_TYPE;

//0627
typedef enum _tagEventSuperStoneType
{
	MSG_EVENT_SUPERSTONE_REQ,		
	MSG_EVENT_SUPERSTONE_REP,		
			
} MSG_EVENT_SUPERSTONE_TYPE;

typedef enum __tagMsgExGoZoneType
{
	MSG_EX_GO_ZONE_FIND_REQ,		// �����̵���� �߰� ��û	: zone(n) extra(n) npcIdx(n)
	MSG_EX_GO_ZONE_SAVE_REQ,		// ������ ��ġ ����		: zone(n) extra(n) npcIdx(n)
	MSG_EX_GO_ZONE_MAP_REQ,			// ����� ��� ��û		: npcIdx(n)
	MSG_EX_GO_ZONE_MAP_REP,			// ����� ��� ���� 	: count(n) zone(n) extra(n)
	MSG_EX_GO_ZONE_MOVE_REQ,		// ���� �̵� ��û		: zone(n) extra(n) npcIdx(n)
	MSG_EX_GO_ZONE_FIELD_DOUNGEON_TAX_REQ,	// �ʵ���� �̵��� ��ݿ�û	: npcIdx(n)
	MSG_EX_GO_ZONE_FIELD_DOUNGEON_TAX_REP,	// �ʵ���� �̵��� �������	: tax(n)
	MSG_EX_GO_ZONE_FIELD_DOUNGEON_MOVE_REQ, // �ʵ���� �̵� ��û		: npcIdx(n), tax(n)
	MSG_EX_GO_ZONE_ERROR,			// �����޽���			: error(n)
}MSG_EX_GO_ZONE_TYPE;

typedef enum __tagMsgExGoZoneErrorType
{
	MSG_EX_GO_ZONE_FIND_ERROR_OK,				// ���ο� ��� �߰� ����	npcidx(n)
	MSG_EX_GO_ZONE_FIND_ERROR_ALREADY_EXIST,	// �̹� �߰ߵ� ���			npcidx(n)
	MSG_EX_GO_ZONE_SAVE_ERROR_OK,				// ��ġ���� ����			npcidx(n)
	MSG_EX_GO_ZONE_SAVE_ERROR_FAILED,			// ��ġ���� ����			npcidx(n)
	MSG_EX_GO_ZONE_MOVE_ERROR_NOMONEY,			// ������					npcidx(n)
	MSG_EX_GO_ZONE_MOVE_ERROR_CANNOT_MOVE,		// �̵��Ұ��� ����			npcidx(n)
	MSG_EX_GO_ZONE_MOVE_ERROR_OK,				// �̵�����					zone(n)	extra(n)
}MSG_EX_GO_ZONE_ERROR_TYPE;

typedef enum _tagHelperEventPhoenixErrorType			// yhj   081105  �Ǵн�
{
	MSG_HELPER_EVENT_PHOENIX_OK,						// HS -> GS  �Ǵн� ����
	MSG_HELPER_EVENT_PHOENIX_ERROR_REQUIREMENT,			// HS -> GS  �Ǵн� �ڰ� �̴���
} MSG_HELPER_EVENT_PHOENIX_ERROR_TYPE;

typedef enum _tagEventPhoenixErrorType			// yhj   081105  �Ǵн�
{
	MSG_EVENT_PHOENIX_OK,						// GS -> Client  �Ǵн� ����
	MSG_EVENT_PHOENIX_ERROR_ALREADY_APPLY,		// GS -> Client  �̹� �Ǵн� �����
	MSG_EVENT_PHOENIX_ERROR_FULL_INVENTORY,		// GS -> Client  �κ��丮�� �������� �̺�Ʈ �Ұ�
	MSG_EVENT_PHOENIX_ERROR_REQUIREMENT,		// GS -> Client  �Ǵн� �ڰ� �̴���
} MSG_EVENT_PHOENIX_ERROR_TYPE;

typedef enum __tagMsgTradeAgentType
{
	MSG_TRADEAGENT_ERROR,						// ����

	MSG_TRADEAGENT_REG_LIST_REQ,				// ��ǰ ��� ����Ʈ ��û 
	MSG_TRADEAGENT_REG_LIST_REP,				// ��ǰ ��� ����Ʈ ����	
	MSG_TRADEAGENT_REG_REQ,						// ��ǰ ��� ��û: tab_idx(c) row_idx(c) col_idx(c) item_idx(n) extra1(n)
	MSG_TRADEAGENT_REG_REP,						// ��ǰ ��� ����	
	MSG_TRADEAGENT_REG_CANCEL_REQ,				// ��ǰ ��� ��� ��û
	MSG_TRADEAGENT_REG_CANCEL_REP,				// ��ǰ ��� ����	
	MSG_TRADEAGENT_SEARCH_REQ,					// ��ǰ ��ȸ ��û 
	MSG_TRADEAGENT_SEARCH_REP,					// ��ǰ ��ȸ ���� 
	MSG_TRADEAGENT_BUY_REQ,						// ��ǰ ���� ��û 
	MSG_TRADEAGENT_BUY_REP,						// ��ǰ ���� ���� 
	MSG_TRADEAGENT_CALCLIST_REQ,				// ���� ����Ʈ ��û 
	MSG_TRADEAGENT_CALCLIST_REP,				// ���� ����Ʈ ����
	MSG_TRADEAGENT_CALCULATE_REQ,				// ���� ��û 
	MSG_TRADEAGENT_CALCULATE_REP,				// ���� ����
	MSG_TRADEAGENT_CHECKCALC_REQ,				// ���� �ʿ� üũ(�α���)
	MSG_TRADEAGENT_CHECKCALC_REP,				// ���� �ʿ� üũ ����	
	MSG_TRADEAGENT_NEEDCALC_NOTIFY,				// ���� �ʿ� �˸�(������)	

}MSG_TRADEAGENT_TYPE;

typedef enum __tagMsgTradeAgentErrorType
{
	MSG_TRADEAGENT_ERROR_NORMAL,				// �Ϲ��� ����
	MSG_TRADEAGENT_ERROR_NOT_TRADEITEM,			// �ŷ� �Ұ� ������
	MSG_TRADEAGENT_ERROR_NOT_ITEMCOUNT,			// ������ ���� ����Ȯ 
	MSG_TRADEAGENT_ERROR_NOT_SELL_TOTALMONEY,	// �Ǹ� �� �ݾ� ����Ȯ
	MSG_TRADEAGENT_ERROR_NOT_ENUGH_GUARANTY,	// ������ ����

	MSG_TRADEAGENT_ERROR_NOT_ENUGH_MONEY,		// ������(����) ����
	MSG_TRADEAGENT_ERROR_ALREADY_SELLITEM,		// �̹� �ĸŵ� ������
	MSG_TRADEAGENT_ERROR_FULL_INVENTORY,		// �κ��丮�� ���� ��(���� �Ұ�)
	MSG_TRADEAGENT_ERROR_NOT_BE_ITEM,			// �������� ����
	MSG_TRADEAGENT_ERROR_MAXREGCOUNT_FULL,		// ���� �ִ� ��� �� �ʰ�
	MSG_TRADEAGENT_ERROR_CHAR_MAXREGCOUNT_FULL,	// ĳ���� �ִ� ��� �� �ʰ�

	MSG_TRADEAGENT_ERROR_REGIST_ING_NOREG,		// ���� ��� ó�����̶� ��� �Ҽ� ����(���� ��� ó����)
	MSG_TRADEAGENT_ERROR_CALCULATE_ING_NOCALC	// ���� ���� ó�����̶� û�� �Ҽ� ����(���� ���� ó����)
}MSG_TRADEAGENT_ERROR_TYPE;

typedef enum __tagMsgTradeAgentErrorPart
{
	MSG_TRADEAGENT_ERROR_PART_SEARCH,			// ���� ��Ʈ: ��ȸ(����)
	MSG_TRADEAGENT_ERROR_PART_REGIST,			// ���� ��Ʈ: ���(��� ���)
	MSG_TRADEAGENT_ERROR_PART_CALCULATE,		// ���� ��Ʈ: ����
}MSG_TRADEAGENT_ERROR_PART;

typedef enum __tagMsgTradeAgentStateType		// ��ǰ ����
{	
	MSG_TRADEAGENT_STATE_SELL_BEFORE,			// �Ǹ� �� 
	MSG_TRADEAGENT_STATE_SELL_COMPLETE,			// �Ǹ� �Ϸ�
	MSG_TRADEAGENT_STATE_SELL_RETURNED,			// �Ǹ� ���� ����(�ݼ�)
	MSG_TRADEAGENT_STATE_CALCULATE_COMPLETE,	// ���� �Ͽ���
	MSG_TRADEAGENT_STATE_CALCULATE_OVERTIME,	// ���� ���� �ʰ�
	MSG_TRADEAGENT_STATE_BUY,			        // ����
}MSG_TRADEAGENT_STATE_TYPE;

typedef enum __tagMsgTradeAgentFinishDayType	// ��ǰ ������ ���� 
{	
	MSG_TRADEAGENT_FINISH_DAY,					// ��
	MSG_TRADEAGENT_FINISH_HOUR,					// �ð�
	MSG_TRADEAGENT_FINISH_MIN,					// ��
}MSG_TRADEAGENT_FINISHDAY_TYPE;

typedef enum __tagMsgTradeAgentAlignType	// ����Ʈ ���� Ÿ��
{	
	MSG_TRADEAGENT_ALIGN_NAME_ASC,			// ������ �̸�(���� ����)
	MSG_TRADEAGENT_ALIGN_NAME_DESC,			// ������ �̸�(���� ����)

	MSG_TRADEAGENT_ALIGN_QUANTITY_ASC,		// ���� (���� ����)
	MSG_TRADEAGENT_ALIGN_QUANTITY_DESC,		// ���� (���� ����)

	MSG_TRADEAGENT_ALIGN_TOTALMONEY_ASC,	// �ѱݾ� (���� ����)
	MSG_TRADEAGENT_ALIGN_TOTALMONEY_DESC,	// �ѱݾ� (���� ����)

	MSG_TRADEAGENT_ALIGN_LEVEL_ASC,			// ���� (���� ����)
	MSG_TRADEAGENT_ALIGN_LEVEL_DESC,		// ���� (���� ����)
}MSG_TRADEAGENT_ALIGN_TYPE;


typedef enum __tagGMGoZoneType		// ��� ���� �̵� ����
{	
	GM_GOZONE_NONE = 0,
	GM_GOZONE_PERSONAL,
	GM_GOZONE_COMBO,
}GM_GOZONE_TYPE;


typedef enum _tagMsgExpedType			//������ ���� �޼��� 
{
	MSG_EXPED_ERROR,						// ����
	
	MSG_CREATE_REQ,							// ������ ����(��Ƽ��ȯ) ��û			
	MSG_CREATE_REP,							// ������ ����(��Ƽ��ȯ) ����	

	MSG_INVITE_REQ,							// �ʴ� ��û
	MSG_INVITE_REP,							// �ʴ� ����

	MSG_EXPED_ADD,							// ĳ�� �߰� 
	MSG_EXPED_MEMBER_INFO,					// ��� ����

	MSG_ALLOW_REQ,							// �ʴ� ����
	MSG_ALLOW_REP,							// �ʴ� ����

	MSG_REJECT_REQ,							// �ʴ� �ź� ��û
	MSG_REJECT_DEST,						// �Ź�	
	MSG_REJECT_SRC,

	MSG_QUIT_REQ,							// Ż�� ��û
	MSG_QUIT_REP,							// Ż�� ����

	MSG_ENDEXPED_REQ,						// ������ ��ü
	MSG_ENDEXPED_REP,						// ������ ��ü	

	MSG_KICK_REQ,							// �߹� ��û
	MSG_KICK_REP,							// �߹� ����

	MSG_CHANGETYPE_REQ,						// ������ Ÿ�� ����(����ġ, ����, �Ϲ� ������, ����� ������ �й� ���)
	MSG_CHANGETYPE_REP,		

	MSG_MEMBERINFO_REQ,						// ������ ���(U.I)
	MSG_MEMBERINFO_REP,		

	MSG_ADMIN_REQ,							// ������ ����(U.I)
	MSG_ADMIN_REP,

	MSG_CHANGEBOSS_REQ,						// ���� ���� ����(����)
	MSG_CHANGEBOSS_REP,						// ���� ���� ����

	MSG_SETMBOSS_REQ,						// �δ��� �Ӹ�
	MSG_SETMBOSS_REP,

	MSG_RESETMBOSS_REQ,						// �δ��� �Ӹ� ����
	MSG_RESETMBOSS_REP,	

	MSG_MOVEGROUP_REQ,						// �׷� �̵� 
	MSG_MOVEGROUP_REP,						

	MSG_ADDMEMBER_REQ,						// ��� �߰�
	MSG_ADDMEMBER_REP,

	MSG_VIEWDETAIL_REQ,						// ���캸��
	MSG_VIEWDETAIL_INVEN,					// �κ�����
	MSG_VIEWDETAIL_PET,						// ������
	MSG_VIEWDETAIL_APET,					// ������

	MSG_SET_LABEL_REQ,						// ǥ�� ����
	MSG_SET_LABEL_REP,

} MSG_EXPEDITION_TYPE;

typedef enum __tagMsgExpedSetLabelIndex	// ǥ�� 
{
	MSG_EXPED_SETLABEL_INDEX_1,			// ����
	MSG_EXPED_SETLABEL_INDEX_2,			// ���� 
	MSG_EXPED_SETLABEL_INDEX_3,			// �߹ٴ� 
	MSG_EXPED_SETLABEL_INDEX_4,			// ����Į
	MSG_EXPED_SETLABEL_INDEX_5,			// �� 
	MSG_EXPED_SETLABEL_INDEX_6,			// �Ǹ� 
	MSG_EXPED_SETLABEL_INDEX_7,			// �ذ�	
}MSG_EXPEDITION_SETLABEL_INDEX;

typedef enum __tagMsgExpedSetLabelType	
{
	MSG_EXPED_SETLABEL_TYPE_PC,			
	MSG_EXPED_SETLABEL_TYPE_NPC,		
}MSG_EXPEDITION_SETLABEL_TYPE;

typedef enum __tagMsgExpedSetLabelMode	
{
	MSG_EXPED_SETLABEL_MODE_SET,			
	MSG_EXPED_SETLABEL_MODE_RESET,		
}MSG_EXPEDITION_SETLABEL_MODE;


typedef enum __tagMsgExpedErrorType
{
	MSG_EXPED_ERROR_NORMAL,					// �Ϲ�

	MSG_EXPED_ERROR_ALREADY_REQUEST,		// �ٸ� ������� �̹� ��û ��

	MSG_EXPED_ERROR_ALLOW_OK,				// �ʴ� ���� ����
	MSG_EXPED_ERROR_ALLOW_NOT_EXPED,		// ������ ���� �ƴҶ�

	MSG_EXPED_ERROR_REJECT_OK,				// ���� ����
	MSG_EXPED_ERROR_REJECT_FAIL,			// ����

	MSG_EXPED_ERROR_QUIT_OK,				// Ż�� ����
	MSG_EXPED_ERROR_QUIT_END,				// Ż�� ����, ������ ��ü

	MSG_EXPED_ERROR_KICK_OK,				// ���� ����
	MSG_EXPED_ERROR_KICK_END,				// ���� ����, ������ ��ü

	MSG_EXPED_ERROR_INVITE_PVP,				// ��û�ڳ� ����ڰ� PVP ��
	MSG_EXPED_ERROR_NOT_PARTY,				// ��Ƽ�� �Ҽӵ��� ����(��Ƽ ��ȯ �Ұ�)
	MSG_EXPED_ERROR_NOT_EXPED,				// ������ �Ҽӵ��� ����
	MSG_EXPED_ERROR_NOT_PARTYBOSS,			// ��Ƽ���� �ƴϴ�.	(��Ƽ��ȯ �Ұ�) 
	MSG_EXPED_ERROR_NOT_EXPEDBOSS,			// ���������� �ƴϴ�.
	MSG_EXPED_ERROR_ALREADY_JOIN_ME,		// �̹� �����뿡 �ҼӵǾ� ����
	MSG_EXPED_ERROR_ALREADY_JOIN_OTHER,		// �ٸ� �����뿡 �ҼӵǾ� ����
	MSG_EXPED_ERROR_NOT_BE_CHAR,			// ���� ĳ���� 
	MSG_EXPED_ERROR_FULL_EXPED,				// �� �̻� ������� �߰��� �� ���� 
	MSG_EXPED_ERROR_NOT_5MIN_GETBOX,		// �� �̻� ���� �ֿ� �� ���� 
	MSG_EXPED_ERROR_ALREADY_GETBOX,         // ������ ���� ���� ���� �ϰ� �ٽ� �õ�
	MSG_EXPED_ERROR_INVALID_LEVEL,			// ������ ���� ����
}MSG_EXPEDITION_ERROR_TYPE;

//������ �׷� Ÿ�� 
typedef enum _tagMsgExpedGroupType
{
	MSG_EXPED_GROUP_1,						// �׷� 1
	MSG_EXPED_GROUP_2,						// �׷� 2	
	MSG_EXPED_GROUP_3,						// �׷� 3
	MSG_EXPED_GROUP_4,						// �׷� 4

	MSG_EXPED_GROUP_COUNT,

} MSG_EXPED_GROUP_TYPE;

//������ ������ Ÿ��
typedef enum _tagMsgExpedMemberType
{
	MSG_EXPED_MEMBERTYPE_BOSS,				// ���� ���� 
	MSG_EXPED_MEMBERTYPE_MBOSS,				// ���� �δ���
	MSG_EXPED_MEMBERTYPE_NORMAL,			// ���� ���
	
	MSG_EXPED_MEMBERTYPE_COUNT,
}MSG_EXPED_MEMBER_TYPE;

//������ ����,������ Ż�� Ÿ��
typedef enum _tagMsgExpedQuitMode
{
	MSG_EXPED_QUITMODE_NORMAL,				// ���� ���� 
	MSG_EXPED_QUITMODE_UNUSUAL,				// ������ ����
}MSG_EXPED_QUIT_MODE;

//���� ����(����,�ڵ�) ���
typedef enum _tagMsgExpedChangeBossMode
{
	MSG_EXPED_CHANGEBOSS_MANUAL,			// ���� ����
	MSG_EXPED_CHANGEBOSS_AUTO,				// �ڵ� ����
}MSG_EXPED_CHANGEBOSS_MODE;

typedef enum _tagMsgPartyType2
{
	MSG_PARTY_TYPE_RANDOM=0,			// �յ� ��Ƽ
	MSG_PARTY_TYPE_FIRSTGET,			// �Լ� �켱
	MSG_PARTY_TYPE_BATTLE,				// ������
	MSG_PARTY_TYPE_OPENBOX,				// ���ڿ���
}MSG_PARTY_TYPE2;

typedef enum _tagMsgExpedType2
{
	MSG_EXPED_TYPE_RANDOM=0,			// �յ� ��Ƽ
	MSG_EXPED_TYPE_FIRSTGET,			// �Լ� �켱
	MSG_EXPED_TYPE_BATTLE,				// ������
	MSG_EXPED_TYPE_OPENBOX,				// ���ڿ���
}MSG_EXPED_TYPE2;

typedef enum _tagMsgDiviType
{
	MSG_DIVITYPE_EXP=0,						// �й� ���(����ġ)
	MSG_DIVITYPE_ITEM,		  				// �й� ���(������)
	MSG_DIVITYPE_SPECIAL,				    // �й� ���(����� ������)
}MSG_DIVI_TYPE;

//���̵� ����
typedef enum __tagMsgRaidErrorType
{
	MSG_RAID_ERROR_SUCESS=0,       // ����
	MSG_RAID_ERROR_INZONE_JOIN_CLEAR_COMPLETE,   // ���� ���� �Ұ�(���� Ŭ���� �Ϸ�) - %�� %�� �ڿ� ���尡��
	MSG_RAID_ERROR_INZONE_JOIN_ROOMCOUNT_FULL,   // ���� �ν��Ͻ� �ʹ� ���� ���̻� ���� �Ұ�
	MSG_RAID_ERROR_INZONE_JOIN_ALREADY,     // ���� �̹� �α��� 
	MSG_RAID_ERROR_INZONE_JOIN_MEMBER_FULL,    // ���� ���� ������ �ִ� �ο��� �ʰ�
	MSG_RAID_ERROR_INZONE_JOIN_ALREADY_OTHERTEAM,  // �ش� ���� �ٸ� ��Ƽ,�����밡 �ֽ��ϴ�.
	MSG_RAID_ERROR_INZONE_JOIN_THISZONE_PARTYZONE,  // ��Ƽ ���¿����� ���� ���� �մϴ�
	MSG_RAID_ERROR_INZONE_JOIN_THISZONE_EXPEDZONE,  // ������ ���¿����� ���� ���� �մϴ�  
	MSG_RAID_ERROR_INZONE_JOIN_NOTJOIN_PARTYOREXPED, // ��Ƽ�� �����뿡 ���� �Ǿ�  ���� ����
	MSG_RAID_ERROR_INZONE_QUIT_NOTINZONEJOINED,   // �ش� ������ ���� ���� �ʾ��� 
	MSG_RAID_ERROR_INZONE_NOT_5MIN_GETBOX,    // �� �̻� ���� �ֿ� �� ����(ȹ�� �ð� 5��) 
	MSG_RAID_ERROR_INZONE_ALREADY_GETBOX,    // ������ ���� ���� ���� �ϰ� �ٽ� �õ�
	MSG_RAID_ERROR_INZONE_JOIN_INVALIDELEVEL,			// ���� �������� �����Ҽ� ����
	MSG_RAID_ERROR_INZONE_JOIN_NOTSAMEBOSSROOMNO,		// �ͼӵ� ���� ������ �������� �޶� ���� �Ұ� (�߰� ���� �޼���)
	MSG_RAID_ERROR_INZONE_NOT_EXPED_RAID_SUBNUMBER,		// ������ ������ ���̵� ä���� �ƴ϶� ���� �Ұ�
	MSG_RAID_ERROR_INZONE_NOT_JOIN_BOSS,				// ���������� ���� ���̵忡 �������� �ʾҴ�.
}MSG_RAID_ERROR_TYPE;


#endif

