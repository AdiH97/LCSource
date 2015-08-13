#ifndef __LCLIST_H__
#define __LCLIST_H__

// DATATYPE�� LINKED LIST�� ����
template <class DATATYPE>
class CLCListNode
{
protected:
	int				m_nID;		// ������ ID
	DATATYPE		m_data;		// ������ ����
	CLCListNode*	m_prev;		// ���� ������
	CLCListNode*	m_next;		// ���� ������

public:
	CLCListNode(int nID, DATATYPE data)
	: m_data(data)
	{
		m_nID = nID;
		m_data = data;
		m_prev = m_next = 0;
	}

	~CLCListNode()
	{
		if (m_prev)
			m_prev->Next(m_next);
		if (m_next)
			m_next->Prev(m_prev);
		m_prev = 0;
		m_next = 0;
	}

	void			Prev(CLCListNode* prev)	{ m_prev = prev; }
	void			Next(CLCListNode* next)	{ m_next = next; }
	CLCListNode*	Prev()					{ return m_prev; }
	CLCListNode*	Next()					{ return m_next; }
	DATATYPE		Data()					{ return m_data; }
	int				ID()					{ return m_nID;  }
};

template <class DATATYPE>
class CLCList
{
protected:
	int						m_nID;		// ������ ID
	CLCListNode<DATATYPE>*	m_head;		// ��� ������
	CLCListNode<DATATYPE>*	m_tail;		// ���� ������
	int						m_nCount;	// ������ ��
	int (*m_fnComp)(DATATYPE, DATATYPE);	// ���Լ� ������, strcmp�� ���� ���ϰ�(������ 0, �ٸ���� ������ ���� -, �Ǵ� +)

public:
	CLCList(int (*fnComp)(DATATYPE, DATATYPE));
	
	~CLCList();


	////////////////////
	// Function name	: AddToHead
	// Description	    : data�� ó���� �߰�
	void AddToHead(DATATYPE data)
	{
		if (m_head == 0)
		{
			m_head = new CLCListNode<DATATYPE>(m_nID, data);
			m_tail = m_head;
		}
		else
		{
			CLCListNode<DATATYPE>* pNew = new CLCListNode<DATATYPE>(m_nID, data);
			pNew->Next(m_head);
			m_head->Prev(pNew);
			m_head = pNew;
		}
		m_nCount++;
	}


	////////////////////
	// Function name	: AddToTail
	// Description	    : data�� �������� �߰�
	void AddToTail(DATATYPE data)
	{
		if (m_tail == 0)
		{
			m_head = new CLCListNode<DATATYPE>(m_nID, data);
			m_tail = m_head;
		}
		else
		{
			CLCListNode<DATATYPE>* pNew = new CLCListNode<DATATYPE>(m_nID, data);
			pNew->Prev(m_tail);
			m_tail->Next(pNew);
			m_tail = pNew;
		}
		m_nCount++;
	}


	////////////////////
	// Function name	: RemoveData
	// Description	    : ����Ʈ���� data ����, == ������ ���
	void RemoveData(DATATYPE data)
	{
		CLCListNode<DATATYPE>* p = 0;
		CLCListNode<DATATYPE>* pNext = m_head;
		while ((p = pNext))
		{
			pNext = pNext->Next();
			if (m_fnComp == 0)
			{
				if (p->Data() == data)
				{
					Remove(p);
				}
			}
			else
			{
				if (m_fnComp(p->Data(), data) == 0)
				{
					Remove(p);
				}
			}
		}
	}


	////////////////////
	// Function name	: Remove
	// Description	    : ����Ʈ���� p ��带 ����
	void Remove(void* p)
	{
		CLCListNode<DATATYPE>* pNode = (CLCListNode<DATATYPE>*)p;
		if (pNode == m_head)
			m_head = m_head->Next();
		if (pNode == m_tail)
			m_tail = m_tail->Prev();
		delete pNode;
		m_nCount--;
	}


	////////////////////
	// Function name	: RemoveAll
	// Description	    : ����Ʈ �ʱ�ȭ
	void RemoveAll()
	{
		while (m_head)
		{
			CLCListNode<DATATYPE>* p = m_head;
			m_head = m_head->Next();
			delete p;
		}
		m_head = m_tail = 0;
		m_nCount = 0;
	}


	////////////////////
	// Function name	: GetHead
	// Description	    : ��� ������ ��ȯ
	void* GetHead()				{ return (void*)m_head; }

	////////////////////
	// Function name	: GetTail
	// Description	    : ���� ������ ��ȯ
	void* GetTail()				{ return (void*)m_tail; }

	////////////////////
	// Function name	: GetPrev
	// Description	    : pos ���� ��� ������ ��ȯ
	void* GetPrev(void* pos)	{ CLCListNode<DATATYPE>* p = (CLCListNode<DATATYPE>*)pos; return ((p->ID() == m_nID)) ? p->Prev() : 0; }

	////////////////////
	// Function name	: GetNext
	// Description	    : pos ���� ��� ������ ��ȯ
	void* GetNext(void* pos)	{ CLCListNode<DATATYPE>* p = (CLCListNode<DATATYPE>*)pos; return ((p->ID() == m_nID)) ? p->Next() : 0; }

	////////////////////
	// Function name	: GetData
	// Description	    : pos ����� �����͸� ��ȯ
	DATATYPE GetData(void* pos)
	{
		CLCListNode<DATATYPE>* p = (CLCListNode<DATATYPE>*)pos;
		if (pos != 0 && p->ID() == m_nID)
			return p->Data();
		else
		{
			char empty[sizeof(DATATYPE)];
			memset(empty, 0, sizeof(DATATYPE));
			return *((DATATYPE*)empty);
		}
	}

	////////////////////
	// Function name	: GetCount
	// Description	    : ����Ʈ�� ������ ���� ��ȯ
	int GetCount()				{ return m_nCount; }


	////////////////////
	// Function name	: FindDataWithCompareFunction
	// Description	    : ������ ��� ã��
	// Return type		: void* 
	//                  : ã�� ��� ������, ������ NULL
	// Argument         : DATATYPE data
	//                  : ã�� ������
	// Argument         : int (*m_fnComp)(DATATYPE, DATATYPE)
	//                  : ã�⿡ ����� �Լ�, NULL�̸� == ������ ���
	void* FindDataWithCompareFunction(DATATYPE data, int (*fnComp)(DATATYPE, DATATYPE))
	{
		CLCListNode<DATATYPE>* p = 0;
		CLCListNode<DATATYPE>* pNext = (CLCListNode<DATATYPE>*)GetHead();
		while ((p = pNext))
		{
			pNext = pNext->Next();
			if (fnComp == 0)
			{
				if (p->Data() == data)
				{
					return (void*)p;
				}
			}
			else
			{
				if (fnComp(p->Data(), data) == 0)
				{
					return (void*)p;
				}
			}
		}

		return 0;
	}

	////////////////////
	// Function name	: FindData
	// Description	    : ������ ��� ã��
	// Return type		: void* 
	//                  : ã�� ��� ������, ������ NULL
	// Argument         : DATATYPE data
	//                  : ã�� ������
	void* FindData(DATATYPE data)
	{
		return FindDataWithCompareFunction(data, m_fnComp);
	}


	////////////////////
	// Function name	: GetPosition
	// Description	    : nIndex��°�� �ش��ϴ� �����͸� ��ȯ, 0 base
	// Return type		: void* 
	//                  : �ش� ��� ������
	// Argument         : int nIndex
	//                  : ã���� �ϴ� ����� ��ġ
	void* GetPosition(int nIndex)
	{
		if (nIndex < 0)
			return 0;
		if (nIndex >= GetCount())
			return 0;
		void* ret = GetHead();
		while (nIndex > 0)
		{
			ret = GetNext(ret);
			if (!ret)
				return 0;
			nIndex--;
		}

		return ret;
	}
};

#endif // __LCLIST_H__
