#ifndef __INVENTORY_H__
#define __INVENTORY_H__

class CPC;
class CInventory;
class CItem;

class CInventoryRow
{
	friend class CInventory;
	friend class CDBThread;

	CInventory*			m_inven;
	CItem*				m_items[ITEMS_PER_ROW];

public:

	CInventoryRow(CInventory* inven);
	~CInventoryRow();

private:
	// ���ڸ� ã��
	bool FindEmpty(int* col);

	// ������ ã�� (���ǿ� �����ϴ� ó�� ������)
	bool FindItem(int* col, int itemdbindex, int plus, int flag);
	bool FindItem(int* col, int itemindex);

	// ������� �˻�
	bool IsEmpty();

	// �����
	bool Remove(int col, bool bFreeMem, bool removeQuickSlot, bool bCalcStatus);

	// ����� �� ã��
	int GetSpace();
};

class CInventory
{
	friend bool AddToInventory(CPC* ch, CItem* item, bool bSendWarning, bool bCheckWeight, int row, int col);
	friend bool AddToPreInventory(CPC* ch, CItem* item, bool bSendWarning, bool bCheckWeight, int tab, int row, int col);
	friend bool DecreaseFromInventory(CPC* ch, CItem* item, LONGLONG count);
	friend bool RemoveFromInventory(CPC* ch, int tab, int row, int col, bool bFreeMem, bool removeQuickSlot);
	friend bool RemoveFromInventory(CPC* ch, CItem* item, bool bFreeMem, bool removeQuickSlot);

public:
	CPC*				m_ch;
	int					m_tab;
	CInventoryRow*		m_rows[20];

	CInventory();
	~CInventory();

	void Init(CPC* ch, int tab)
	{
		m_ch = ch;
		m_tab = tab;
	}

	// ���ڸ� ã��
	bool FindEmpty(int* row, int* col);

	// ������ ���
	CItem* GetItem(int row, int col)
	{
		return ((CItem*(*)(CInventory*, int, int))0x0810F9C6)(this, row, col);
	}
	CItem* GetItem(int itemindex) { int r, c; return (FindItem(&r, &c, itemindex)) ? GetItem(r, c) : NULL; }
	CItem* GetItemBySerial(const char* serial);

	// ������ ���� ���
	int GetItemLevel(int nItemIndex, bool bOriginalLevel) const;

	// ������ ã��
	bool FindItem(int* row, int* col, int itemdbindex, int plus, int flag) const
	{
		return ((bool(*)(const CInventory*, int*, int*, int, int, int))0x0810FA6A)(this, row, col, itemdbindex, plus, flag);
	}
	bool FindItem(int* row, int* col, int itemidx) const
	{
		return ((bool(*)(const CInventory*,int*, int*, int))0x0810FB1A)(this, row, col, itemidx);
	}

	// ������ �ڸ� �ٲ�
	bool Swap(int row1, int col1, int itemidx1, int row2, int col2, int itemidx2);

	// ����
	void Arrange();

	// ����� �� ã��
	int GetSpace();



	////////////////////
	// Function name	: AddItem
	// Description	    : ������ �߰�(Ȥ�� ������ ��� ��ġ��)
	// Return type		: bool 
	//                  : ���� ����
	// Argument         : CItem* item
	//                  : �߰��� ������
	// Argument         : CPC* ch
	//                  : �κ��丮 ����
	// Argument         : bool bSendWarning
	//                  : ���� �ʰ� ��� �˸���
	// Argument         : bool bCheckWeight
	//                  : ���� �ʰ��� ������ ��ȯ���� ����, false�̸� ���Ը� �ʰ��ؼ� �κ��丮�� ���� �� �ִ�
	// Argument         : int row = -1
	//                  : Ư�� ��ġ�� �����ؼ� ������ �ֱ�
	// Argument         : int col = -1
	//                  : Ư�� ��ġ�� �����ؼ� ������ �ֱ�
	bool AddItem(CItem* item, CPC* ch, bool bSendWarning, bool bCheckWeight, bool bCalcStatus, int row = -1, int col = -1);

	// ������ ���� ����
	bool Decrease(CItem* item, LONGLONG count);

	// �����
	bool Remove(int row, int col, bool bFreeMem, bool removeQuickSlot, bool bCalcStatus);
	bool Remove(CItem* item, bool bFreeMem, bool removeQuickSlot);

	// 060227 : bs : �ð��� ������ �˻�
	void CheckItemTime();

	// ���� �̻� ���� �˻�
	void CheckCompositeValidation();
};

#endif
