#ifndef __CUILOGIN_NEW_H__
#define __CUILOGIN_NEW_H__

class CUIComboBox;
class CUISpriteAni;
class CUICheckButton;

class ENGINE_API CUILoginNew : public CUIWindow
{
public:
	CUILoginNew(void);
	virtual ~CUILoginNew(void);

	void	PressLoginBtn();
	void	PressCloseBtn();
	void	PressCheckSave();
	BOOL	TryToLogin();			// �α��� �õ�

	void	OpenUI();
	void	CloseUI();

	void	initialize();
	void	SetLogin();
	void	Reset();
	void	ResetBtn();

	void	Lock(BOOL bLock);

	void	ReadPreviousId();
	void	WritePreviousId();

	void	SetPWFocus() 
	{ 
		if (m_pEbPw != NULL)
			m_pEbPw->SetFocus(TRUE);
	}

	void	SetFocus( BOOL bVisible );
	BOOL	IsEditBoxFocused();
	void	KillFocusEditBox();
	void	OnTabKeyProc();

	void	OnRender(CDrawPort* pDraw);
	void	OnUpdate( float fDeltaTime, ULONG ElapsedTime );
	
	void setVersion(const char* strVer);
	const char* getVersion()		{ return m_strVersion.c_str(); }

#ifdef DEV_LOGIN
	void	ReadTextDevPreviousIdPw(); // Login.txt �� ����� ���̵� �н����� ������
#endif // DEV_LOGIN

	WMSG_RESULT OnKeyMessage(MSG* pMsg);
private:
	void	sendIP();

	CUISpriteAni*	m_pLogoFrame;
	CUIButton*		m_pBtnLogin;
	CUIButton*		m_pBtnClose;
	CUICheckButton*	m_pBtnSave;
	CUIComboBox*	m_pCbSelServer;
	CUIEditBox*		m_pEbId;
	CUIEditBox*		m_pEbPw;
	CUIImage*		m_pImgLogo;	// �⺻ ��ī �ΰ�
#ifdef	HOLLOWEEN_EVENT_LOGIN
	CUIImage*		m_pImgLogoHal; // �ҷ��� �̺�Ʈ�� �ΰ�
	CUIImage*		m_pImgHalEye; // �ҷ��� �̺�Ʈ �ΰ��� �� �̹���
#endif	// HOLLOWEEN_EVENT_LOGIN

#ifdef CHRISTMAS_LOGO
	CUIImage*		m_pImgLogoChris;
	CUIImage*		m_pImgChrisEffect1;
	CUIImage*		m_pImgChrisEffect2;
#endif	//	CHRISTMAS_LOGO
	std::string			m_strVersion;
};



#endif	//	__CUILOGIN_NEW_H__