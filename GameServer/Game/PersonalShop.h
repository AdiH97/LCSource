#ifndef __PERSONAL_SHOP_H__
#define __PERSONAL_SHOP_H__

// SHOP CONF
#define PS_MAX_SHOPNAME				100		// ���� �̸� �ִ� ���� 100 ����Ʈ
#define PS_MAX_NORMAL_ITEM			10		// �Ϲ� ������ �ŷ� �ִ� ��
#define PS_MAX_PACKAGE_ITEM			5		// ��Ű�� �Ǹ� �ŷ� �ִ� ��
//#define PS_NEED_MONEY_PREMIUM		5000	// �����̾� ���� ���� �ʿ� ����
#if defined (LC_TWN) || defined (LC_JPN)
#define PS_TEX_PREMIUM				1000	// ����: �����̾�: 10%
#else
#define PS_TEX_PREMIUM				200		// ����: �����̾�: 2%
#endif
#define PS_TEX_NORMAL				0		// ����: �Ϲ�: 0%

// PERSONAL SHOP TYPE
#define PST_NOSHOP			0
#define PST_SELL			(1 << 0)		// �Ǹ�
#define PST_BUY				(1 << 1)		// ����
#define PST_PREMIUM			(1 << 2)		// �����̾�
#define PST_PACKAGE			(1 << 3)		// ��Ű��
#define PST_SOLDOUT			(1 << 4)		// �Ǹ� ����

class CPersonalShop
{	
	char			m_type;
	CLCString		m_name;

	int				m_normalitemindex[PS_MAX_NORMAL_ITEM];
	LONGLONG		m_normalCount[PS_MAX_NORMAL_ITEM];
	LONGLONG		m_normalPrice[PS_MAX_NORMAL_ITEM];

	int				m_packageitemindex[PS_MAX_PACKAGE_ITEM];
	LONGLONG		m_packageCount[PS_MAX_PACKAGE_ITEM];
	LONGLONG		m_packagePrice;

public:

	CPersonalShop(char type, const char* name);

	bool AddItem(bool bNormal, int itemindex, LONGLONG count, LONGLONG price);

	int FindItem(bool bNormal, int itemindex);
	void RemoveNormalItem(int itemindex, LONGLONG count);
	void RemovePackage();

	char GetType() { return m_type; }
	const char* GetName() { return (const char*)m_name; }
	char GetNormalCount();
	int GetNextNormalItem(int pos);
	int GetNormalItemIndex(int pos) { return (pos < 0 || pos >= PS_MAX_NORMAL_ITEM) ? -1 : m_normalitemindex[pos]; }
	LONGLONG GetNormalItemCount(int pos) { return (pos < 0 || pos >= PS_MAX_NORMAL_ITEM) ? -1 : m_normalCount[pos]; }
	LONGLONG GetNormalItemPrice(int pos) { return (pos < 0 || pos >= PS_MAX_NORMAL_ITEM) ? -1 : m_normalPrice[pos]; }
	LONGLONG GetPackagePrice() { return m_packagePrice; }
	char GetPackageCount();
	int GetNextPackageItem(int pos);
	int GetPackageItemIndex(int pos) { return (pos < 0 || pos >= PS_MAX_PACKAGE_ITEM) ? -1 : m_packageitemindex[pos]; }
	LONGLONG GetPackageItemCount(int pos) { return (pos < 0 || pos >= PS_MAX_PACKAGE_ITEM) ? 0 : m_packageCount[pos]; }
};




// �븮 ����
#ifdef ALTERNATE_MERCHANT
class CAlternateMerchant
{
private:	
	// ���� Ÿ��
	char			m_cShopType;
	// ���� �̸�
	CLCString		m_strShopName;
	// ���� 
	CPC*			m_pShopOwner;


	// �Ϲ� ������ �ε��� arr
	int				m_nNormalItemIndex[PS_MAX_NORMAL_ITEM];
	// �Ϲ� ������ ī��Ʈ arr
	LONGLONG		m_lNormalItemCount[PS_MAX_NORMAL_ITEM];
	// �Ϲ� ������ ���� arr
	LONGLONG		m_lNormalItemPrice[PS_MAX_NORMAL_ITEM];


	// ��Ű�� ������ �ε��� arr
	int				m_nPackageItemIndex[PS_MAX_PACKAGE_ITEM];
	// ��Ű�� ������ ī��Ʈ arr
	LONGLONG		m_lPackageItemCount[PS_MAX_PACKAGE_ITEM];
	// ��Ű�� ������ ����
	LONGLONG		m_lPackagePrice;

	//������ �Ȱ� ������ �ִ� ���� 
	LONGLONG		m_lNasCount;
public:
	// ����Ʈ���� �ε���
	int				m_nlistIdx;

	CItem*			m_NormalItems[PS_MAX_PACKAGE_ITEM];
	CItem*			m_PackItems[PS_MAX_PACKAGE_ITEM];

public:
	// ������
	CAlternateMerchant( void );
	CAlternateMerchant( char cShopType, const char* strShopName );

	// ������ �߰�
	/*
	* FunName		: AddItem
	* Description	: ���� ���� ���� NPC����
	*
	*
	*/
	bool	AddItem( bool bNormal, int nItemIndex, LONGLONG lItemCount, LONGLONG lItemdPrice );

	// ������ �˻�
	CItem*	FindItem( bool bNormal, int nItemIndex );
	int		FindItemPos( bool bNormal, int nItemIndex );

	// ������ ����
	void	RemoveNormalItem( int nItemIndex, LONGLONG lItemCount );

	// ��Ű�� ������ ����
	void	RemovePackage( void );

	// ���� Ÿ�� ��ȯ
	char	GetShopType( void )					{ return m_cShopType; }

	// ���� �̸� ��ȯ
	const char* GetShopName( void )				{ return (const char*)m_strShopName; }

	// ��ü �Ǹ� ���� �Ϲ� ������ ����
	char	 GetNormalCount( void );

	// �Ϲ� ������ ��ġ
	int		GetNextNormalItem( int nPos );

	// ���� Ŭ���� �Ϲ� ������ �ε���  
	int		GetNormalItemIndex( int nPos )			{ return (nPos < 0 || nPos >= PS_MAX_NORMAL_ITEM) ? -1 : m_nNormalItemIndex[nPos]; }

	// ���� Ŭ���� �Ϲ� ������ ����
	LONGLONG GetNormalItemCount( int nPos )		{ return (nPos < 0 || nPos >= PS_MAX_NORMAL_ITEM) ? -1 : m_lNormalItemCount[nPos]; }

	// ���� Ŭ���� �Ϲ� ������ ����
	LONGLONG GetNormalItemPrice( int nPos )		{ return (nPos < 0 || nPos >= PS_MAX_NORMAL_ITEM) ? -1 : m_lNormalItemPrice[nPos]; }

	// ��Ű�� ������ ����
	LONGLONG GetPackagePrice( void )			{ return m_lPackagePrice; }

	// ��ü ��Ű�� ������ ����
	char	GetPackageCount( void );

	// ��Ű�� �������� ���� ������ ���� ����
	int		GetNextPackageItem( int nPos );

	// ��Ű�� ������ �ε��� ��������
	int		GetPackageItemIndex( int nPos )			{ return (nPos < 0 || nPos >= PS_MAX_PACKAGE_ITEM) ? -1 : m_nPackageItemIndex[nPos]; }

	// ��Ű�� ������ ���� ��������
	LONGLONG GetPackageItemCount( int nPos )	{ return (nPos < 0 || nPos >= PS_MAX_PACKAGE_ITEM) ? 0 : m_lPackageItemCount[nPos]; }

	// ���� �߰�
	void	AddNas( LONGLONG lCount )			{ 	m_lNasCount = m_lNasCount + lCount; }

	// ���� ��ȯ
	LONGLONG GetNas( void )						{ return m_lNasCount;	};

	// ������ ��ȯ
	CPC*	GetOwnerPC( void )					{ return m_pShopOwner;	};

	// ������ ���� ������ ����
	void	SetOwnerPC( CPC* pOwner )			{ m_pShopOwner = pOwner;	};

	// �븮 ���� �ʱ�ȭ
	void	InitAlternateMerchant( void );

	// �븮 ���� ��Ÿ���� ��
	void	AppearAlternateMerchant( bool bIncludeOwner );

	// �븮 ���� ������� ��
	void	DisappearAlternateMerchant( void );
};


class CAlternateMerchantList
{
public: 
	CAlternateMerchant* m_pAlternateMerchantList[MAX_PLAYER_LIST];		//  �迭�� ���
	int	m_nMax;
	int m_nCur;

	CAlternateMerchantList()
	{
		int i;
		for ( i = 0; i < MAX_PLAYER_LIST; i++ )
			m_pAlternateMerchantList[i] = NULL;
		m_nMax = 0;
		m_nCur = 0;
	}

	~CAlternateMerchantList()
	{
		m_nMax = m_nCur = 0;
	}

	int AddAlternateMerchant( CAlternateMerchant* pAlternateMerchant )
	{
		int i;
		if (m_nMax >= MAX_PLAYER_LIST )
			return -1;

		if (pAlternateMerchant->m_nlistIdx != -1 && m_pAlternateMerchantList[pAlternateMerchant->m_nlistIdx] == pAlternateMerchant) 
			return pAlternateMerchant->m_nlistIdx;

		for (i = 0; i < m_nMax && m_pAlternateMerchantList[i]; i++)
			;

		m_pAlternateMerchantList[i] = pAlternateMerchant;
//		pAlternateMerchant->m_nlistIdx = i;
		if (i == m_nMax)
			m_nMax++;

		m_nMax++;

		return i;
	}

	void RemoveAlternateMerchant( CAlternateMerchant* pAlternateMerchant )
	{
		int i;
//		DelAttackList(pAlternateMerchant);

		i = pAlternateMerchant->m_nlistIdx;
		if (i < 0 || i >= MAX_PLAYER_LIST)	return ;

		m_pAlternateMerchantList[i] = NULL;
		pAlternateMerchant->m_nlistIdx = -1;
		if (i == m_nMax) m_nMax--;
		m_nCur--;
	}

	CAlternateMerchant* Find(int nAlternateMerchantIndex)
	{
		int i;

		for (i = 0; i < m_nMax; i++)
			if (m_pAlternateMerchantList[i] && m_pAlternateMerchantList[i]->m_nlistIdx == nAlternateMerchantIndex )
				return m_pAlternateMerchantList[i];

		return NULL;
	}

};
#endif // ALTERNATE_MERCHANT



#endif