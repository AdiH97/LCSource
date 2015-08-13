#ifndef __STASH_H__
#define __STASH_H__

#if defined (LC_KOR)
#define MAX_STASH_ITEM			300
#define MAX_STASH_ITEM_SPACE	150
#elif defined (LC_JPN)
#define MAX_STASH_ITEM			300
#define MAX_STASH_ITEM_SPACE	150
#else
#define MAX_STASH_ITEM			300
#define MAX_STASH_ITEM_SPACE	100
#endif
#define MAX_STASH_ITEM_NORMAL	50
#define MAX_STASH_KEEP			10
#define MAX_STASH_TAKE			10

class CStash
{
	CItem *m_item[300];
    GoldType_t m_stashMoney;

public:
	CStash();
	~CStash();

	CItem* item(int idx) { return (idx < 0 || idx >= MAX_STASH_ITEM) ? NULL : m_item[idx]; }


	////////////////////
	// Function name	: add
	// Description	    : ������ �߰�
	// Return type		: int 
	//                  : -1: ����, �׿ܴ� ������ ����Ʈ �ε���
	int add(CItem* item);
	int add(int itemdbindex, int plus, int flag, LONGLONG count);


	////////////////////
	// Function name	: remove
	// Description	    : ������ ����
	// Return type		: int 
	//                  : -1: �ش� ������ ����, -2: ���� ����, �׿ܴ� ���� ����
	int remove(int itemindex, LONGLONG count);

	////////////////////
	// Function name	: remove
	// Description	    : ������ ����
	// Return type		: CItem* 
	//                  : �ش� ������ ������, ������ NULL
	CItem* remove(int itemindex);


	////////////////////
	// Function name	: find
	// Description	    : ������ ã��
	// Return type		: int 
	//                  : -1: ����, �׿ܴ� ������ ����Ʈ �ε���
	int find(int itemdbindex, int plus, int flag) const;
	int find(int itemindex) const;


	////////////////////
	// Function name	: space
	// Description	    : ���� ���� ��ȯ
	int space(bool bremain = false);
};

#endif