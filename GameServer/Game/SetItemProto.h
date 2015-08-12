#ifndef __SET_ITEM_PROTO_H__
#define __SET_ITEM_PROTO_H__

typedef struct __tagSetItemOption
{
	int		nWearCnt;									// ���� ����
	int		nType;										// �ɼ� Ÿ�� (�ɼ�/��ų)
	int		nIndex;										// �ɼ�/��ų index
	int		nLevel;										// �ɼ�/��ų ����
} SETITEMOPTION;

class CSetItemProto
{
	int				m_nIndex;
	int				m_nJob;
	int				m_nOptionCnt;						// �ɼ� ����
	int				m_nItemIdx[28];			// ���� ������
	SETITEMOPTION	m_option[11];		// �ɼ�/��ų

public:
	CSetItemProto();
	~CSetItemProto();

	int GetIndex() const					{ return m_nIndex;					}
	int GetOptionCnt() const				{ return m_nOptionCnt;				}
	int GetWearCnt(int nPos) const			{ return m_option[nPos].nWearCnt;	}

	void SetIndex(int nIndex)				{ m_nIndex = nIndex;				}
	
	void InitData(int nPos, int nIndex, int nJob, int nOptionCnt, int* pItemIdx, SETITEMOPTION * pOption);
	const SETITEMOPTION* FindOption(int nWearCnt) const	
	{ 
		for (int i = 0; i < 11; i++)
		{
			if (m_option[i].nWearCnt == nWearCnt)
				return (const SETITEMOPTION*)(m_option + i); 
		}
		return 0; 
	}
	const SETITEMOPTION* GetOption(int n) const	{ return (const SETITEMOPTION*)(m_option + n); }
};

class CSetItemProtoList
{
	CSetItemProto*	m_listSetItem;
	int				m_nCount;

public:
	CSetItemProtoList();
	~CSetItemProtoList();

	bool Load();
	CSetItemProto* Find(int nIndex);
	
protected:
	static int CompIndex(const void* p1, const void* p2)
	{
		CSetItemProto* d1 = (CSetItemProto*)p1;
		CSetItemProto* d2 = (CSetItemProto*)p2;
		return d1->GetIndex() - d2->GetIndex();
	}
};

#endif // __SET_ITEM_PROTO_H__