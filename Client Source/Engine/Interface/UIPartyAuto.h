// ----------------------------------------------------------------------------
//  File : CUIPartyAuto.h
//  Desc : Created by eons
// ----------------------------------------------------------------------------

#ifndef UIPARTY_AUTO_H_ 
#define UIPARTY_AUTO_H_
#ifdef	PRAGMA_ONCE
	#pragma once
#endif

// #include <Engine/Interface/UIButton.h>
// #include <Engine/Interface/UIEditBox.h>
// #include <Engine/Interface/UICheckButton.h>
// #include <Engine/Interface/UIListBox.h>
// #include <Engine/Interface/UIComboBox.h>
// #include <vector>

#define P_AUTO_WIDTH	598
#define P_AUTO_HEIGHT	423

//	Job Flags
#define JF_TITAN		0x00000001
#define JF_KNIGHT		0x00000002
#define JF_HEALER		0x00000004
#define JF_MAGE			0x00000008
#define JF_ROGUE		0x00000010
#define JF_SORCERER		0x00000020
#define JF_NIGHTSHADOW	0x00000040

#ifdef CHAR_EX_ROGUE
	#define JF_EX_ROGUE		0x00000080	// [2012/08/27 : Sora] EX�α� �߰�
		#ifdef CHAR_EX_MAGE
			#define JF_EX_MAGE 0x00000100	//	2013/01/08 jeil EX������ �߰� �÷��� �����ؼ� ����� �߰��� �����ʿ� �ӽð� 
			#define JF_ALLCLASS		0x000001FF	
		#else
			#define JF_ALLCLASS		0x000000FF
	#endif
#else
	#define JF_ALLCLASS		0x0000007F
#endif
/*
<<<<<<< .mine
#ifdef CHAR_EX_MAGE
	#define JF_EX_MAGE 0x00000100	//	2013/01/08 jeil EX������ �߰� �÷��� �����ؼ� ����� �߰��� �����ʿ� �ӽð� 
#endif
#define JF_ALLCLASS		0x0000007F	
=======
>>>>>>> .r2954
*/

enum eAutoPartySelection
{
	PARTY_REGIST,
	PARTY_REGIST_LEADER,
	INVITE_LIST,
	PARTY_LIST,
	PARTY_DEL,
};

// ----------------------------------------------------------------------------
// Name : CUIPartyAuto
// Desc : ��Ƽ���� ��Ī �ý���
// ----------------------------------------------------------------------------

class CUIPartyAuto : public CUIWindow
{
protected:
	typedef struct
	{
		CTString	strSubject;		// ��Ƽ ���� �� ĳ����
		DWORD		dwJobflag;		// ����
		int			nIndex;			// ĳ�� �ĺ��� �� ���� �ĺ���
		int			nLeveldiff;		// ���� ���� on/off
		int			nZone;			// ��Ƽ ��ġ
		int			nPartyType;		// ��Ƽ ����
		int			nLimitLv;		// ���� ����( ��� ���� )
		int			nPartyNum;		// ��Ƽ ���� ���� �ο�
	}PartyListData;

	// storage current page list
	std::vector<PartyListData>	m_vectorPartyListData;

	CTextureData	*m_ptdAddTexture;		// Add Texture resource

	// Button
	// Join set
	CUIButton	m_btnEqualDivide;			// �յ� �й� ��Ƽ
	CUIButton	m_btnFirstObtain;			// �Լ� �켱 ��Ƽ
	CUIButton	m_btnFight;					// ������ ��Ƽ
	CUIButton	m_btnClose;					// Close button

	CUIButton	m_btnRegistOK;				// ��Ƽ ��� Ȯ��( ��  ��Ƽ ���� ��û, ��Ƽ �ʴ� )
	CUIButton	m_btnRegistCancel;			// ��Ƽ ��� ���
	
	CUIButton	m_btnNextbtn;				// ���� ������
	CUIButton	m_btnPrevbtn;				// ���� ������
	CUIButton	m_btnRefresh;				// ���� ��ħ
	CUIEditBox	m_ebNoticeName;				// Input box

	CUICheckButton	m_cbtnTitan;			// Titan
	CUICheckButton	m_cbtnKnight;			// Knight
	CUICheckButton	m_cbtnHealer;			// Healer
	CUICheckButton	m_cbtnMage;				// Mage
	CUICheckButton	m_cbtnRogue;			// Rogue
	CUICheckButton	m_cbtnSorcerer;			// Socceror
	CUICheckButton	m_cbtnNightShadow;		// NightShadow
#ifdef CHAR_EX_ROGUE
	CUICheckButton	m_cbtnEXRogue;			// [2012/08/27 : Sora] EX�α� �߰�
#endif
#ifdef CHAR_EX_MAGE
	CUICheckButton	m_cbtnEXMage;			// 2013/01/08 jeil EX������ �߰� 
#endif
	CUICheckButton	m_cbtnLevelLimit;		// ���� ����
	CUIComboBox		m_cmbNeedClass;			// �ʿ� Ŭ����
	CUIComboBox		m_cmbPartyType;			// ��Ƽ Ÿ��

	// Region of each part
	// Join set
	UIRect		m_rcJoinTitle;				// Region of title
	UIRect		m_rcSelLine;				// line select rectangle

	// UV of each part
	// Join set
	UIRectUV	m_rtJoinTopL;				// UV of Top background
	UIRectUV	m_rtJoinTopM;				// UV of Top background
	UIRectUV	m_rtJoinTopR;				// UV of Top background
	UIRectUV	m_rtJoinGapL;				// UV of Gap
	UIRectUV	m_rtJoinGapM;				// UV of Gap
	UIRectUV	m_rtJoinGapR;				// UV of Gap
	UIRectUV	m_rtJoinMiddleL;			// UV of middle background
	UIRectUV	m_rtJoinMiddleM;			// UV of middle background
	UIRectUV	m_rtJoinMiddleR;			// UV of middle background
	UIRectUV	m_rtJoinBottomL;			// UV of bottom background
	UIRectUV	m_rtJoinBottomM;			// UV of bottom background
	UIRectUV	m_rtJoinBottomR;			// UV of bottom	background

	UIRectUV	m_rtSelListBackTopL;		// UV of List Background
	UIRectUV	m_rtSelListBackTopM;
	UIRectUV	m_rtSelListBackTopR;
	UIRectUV	m_rtSelListBackMiddleL;
	UIRectUV	m_rtSelListBackMiddleM;
	UIRectUV	m_rtSelListBackMiddleR;
	UIRectUV	m_rtSelListBackBottomL;
	UIRectUV	m_rtSelListBackBottomM;
	UIRectUV	m_rtSelListBackBottomR;
	UIRectUV	m_rtSelListMiddleL;			// UV of List middle background
	UIRectUV	m_rtSelListMiddleM;
	UIRectUV	m_rtSelListMiddleR;

	UIRectUV	m_rtStrTooltipTopL;				// tool tip
	UIRectUV	m_rtStrTooltipTopM;
	UIRectUV	m_rtStrTooltipTopR;
	UIRectUV	m_rtStrTooltipMiddleL;	
	UIRectUV	m_rtStrTooltipMiddleM;	
	UIRectUV	m_rtStrTooltipMiddleR;
	UIRectUV	m_rtStrTooltipBottomL;
	UIRectUV	m_rtStrTooltipBottomM;
	UIRectUV	m_rtStrTooltipBottomR;

	UIRectUV	m_rtNoticeNameL;			// UV of NoticeName background
	UIRectUV	m_rtNoticeNameM;			
	UIRectUV	m_rtNoticeNameR;

	UIRectUV	m_rtListSubjectRect;			// UV of Subject background
	UIRectUV	m_rtline;					// UV of line background
	UIRectUV	m_rtSelectBar;				// UV of select bar background

	UIRectUV	m_rtTitanImage;			// UV of Check box Job Image
	UIRectUV	m_rtKnightImage;
	UIRectUV	m_rtHealerImage;
	UIRectUV	m_rtMageImage;
	UIRectUV	m_rtRogueImage;
	UIRectUV	m_rtSorcererImage;
	UIRectUV	m_rtNightShadowImage;
#ifdef CHAR_EX_ROGUE
	UIRectUV	m_rtEXRogueImage;		// [2012/08/27 : Sora] EX�α� �߰�
#endif
#ifdef CHAR_EX_MAGE
	UIRectUV	m_rtEXMageImage;		// 2013/01/08 jeil EX������ �߰� 
#endif
	UIRectUV	m_rtPartyLvImage;		// UV of limitlevel image
	UIRectUV	m_rtPeaceeverImage;		// UV of PT_PEACEEVER image
	UIRectUV	m_rtSurvival;			// UV of PT_SURVIVAL image
	UIRectUV	m_rtAttack;				// UV of PT_ATTACK image

	CTString	m_strNoticeName;			// Party Notice Name
	
	DWORD		m_dwJobFlag;				// Job Flag
	
	BOOL		m_bIsPartyRequested;			// 
	BOOL		m_bShowTextScroll;
	BOOL		m_bTextDir;

	TIME		mtmTextScrollTime;

	int			m_nSelectState;				// selection state
	int			m_nLevelLimit;				// level limit num
	int			m_nCurrentPageNum;			// Current Page number
	int			m_nSelectLine;				// List select line
	int			m_nCharIndex;				// Allow and Reject CharIndex

	int			m_FrontChPos;				// string start pos;

protected:
	void		AdjustUIPos();
	void		PressOKBtn();
	void		PartyMatchJoin( SBYTE sbType, SLONG slBoss, CTString strBossName, SLONG slChar,
							CTString strCharName, SBYTE sbCharJob );
	void		SendPartyReq( int nNum );	// 1-> Next, 0->Current, -1-> Prev
	void		RenderTooltip();		// ���� ����
	BOOL		Is2ByteChar( int nCharIndex, int nFirstCheck, CTString strText );
public:
	CUIPartyAuto();
	~CUIPartyAuto();

	// Create
	void		Create(CUIWindow *pParentWnd, int nX, int nY, int nWidth, int nHeight );
	void		Clear();
	// Render
	void		Render();
	void		JoinRender();
	void		LeaderJoinRender();
	void		SelectListRender();
	void		ListRecordRender();

	// Adjust position
	void		ResetPosition( PIX pixMinI, PIX pixMinJ, PIX pixMaxI, PIX pixMaxJ );
	void		AdjustPosition( PIX pixMinI, PIX pixMinJ, PIX pixMaxI, PIX pixMaxJ );

	void		OpenPartyMatching();										// system select mode
	void		OpenAutoParty( int nType );			// Oepn AutoParty Menu
	void		CloseAutoParty();						

	// Edit box focus
	BOOL		IsEditBoxFocused() { return m_ebNoticeName.IsFocused();	}
	void		KillFocusEditBox() { m_ebNoticeName.SetFocus( FALSE ); }

	// Messages
	WMSG_RESULT	MouseMessage( MSG *pMsg );
	WMSG_RESULT KeyMessage( MSG *pMsg );
	WMSG_RESULT IMEMessage( MSG *pMsg );
	WMSG_RESULT CharMessage( MSG *pMsg );

	WMSG_RESULT JoinMouseMsg( MSG *pMsg ); // ���� ��� ��Ƽ ���
	WMSG_RESULT LeaderRegMouseMsg( MSG *pMsg ); // ��Ƽ�� ��Ƽ ���
	WMSG_RESULT	PartyListMouseMsg( MSG *pMsg ); // ��Ƽ ����Ʈ �� ��Ƽ�� �ʴ� ����Ʈ 

	// Command functions
	void		MsgBoxCommand( int nCommandCode, BOOL bOK, CTString &strInput );
	void		MsgBoxLCommand( int nCommandCode, int nResult );

	// Error Msg
	void		MatchRegMemberRep( int nErrorcode );
	void		MatchRegPartyRep( int nErrorcode );

	// Network receive
	void		ReceiveMemberData( CNetworkMessage *istr );
	void		ReceivePartyData( CNetworkMessage *istr );
	void		ReceivePartyInviteMessage( int nErrorcode, CNetworkMessage *istr );
	void		ReceivePartyJoinMessage( int nErrorcode, CNetworkMessage *istr );

	// Add list
	void		AddPartyData( int nIndex, int nLvdiff, int nZone,
										CTString strComment, DWORD dwFlag, int limitLv, int nPtType );
	void		AddCharData( int nIndex, int nLvdiff, int nZone, 
										CTString strCharName, int nJob, int limitLv, int nPtType );

	// text scroll
	void		TextScroll( CTString strText );

	// select line
	int			ListSelectLine( int nY );

};

#endif