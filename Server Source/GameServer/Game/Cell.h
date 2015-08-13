#ifndef __ACELL_H__
#define __ACELL_H__

#include "Character.h"

class CCell  
{
public:
	bool Send(CNetMsg& msg, CPC* ch = NULL);
	CCell();
	~CCell();

	CCharacter*		m_listChar;		// �� ���� �ɸ��� ����Ʈ ���
	CItem*			m_listItem;		// �� ���� ������ ����Ʈ ��� 
	int				m_nCountNPC;	// npc ��
	int				m_nCountPC;		// PC ��
#ifdef NPC_REGEN_ADJUST
	int				m_nTotalRegen;	// �ش� ������ �����Ǵ� NPC ��
#endif // NPC_REGEN_ADJUST

	void CharToCell(CCharacter* ch);
	void CharFromCell(CCharacter* ch);
	void ItemToCell(CItem* item);
	void ItemFromCell(CItem* item);
};

#endif
