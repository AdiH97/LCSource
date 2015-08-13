#ifndef __STDHDRS_H__
#define __STDHDRS_H__

// ���� ������ �����ϴ� ��
#define __GAME_SERVER__

#include "Conf.h"
#include "Config.h"
#include "Sysdep.h"

#ifdef  PROC_BILLING
#	undef PROC_BILLING
#else
#	define PROC_BILLING	0
#endif

#include "Utils.h"

inline void BackSlash(char* dest, int nSizeOfDest, const char* src)
{
	if (nSizeOfDest < 1)
		return ;
	while (*src)
	{
		nSizeOfDest--;
		if (nSizeOfDest < 1)
			break;
		*dest++ = *src;
		if (*src == '\\')
		{
			nSizeOfDest--;
			if (nSizeOfDest < 1)
				break;
			*dest++ = '\\';
		}
		src++;
	}
	*dest++ = '\0';
}

#ifdef USING_NPROTECT
#ifndef CIRCLE_WINDOWS
#include <dlfcn.h>
#endif // #ifndef CIRCLE_WINDOWS
#include <ggsrv25.h>
#define NPROTECT_PATH						"./nProtect/"					// ���� ��� ���
#define	NPROTECT_LOG						(NPLOG_DEBUG | NPLOG_ERROR)		// ��� �α�
#define	NPROTECT_SECOND_QUERY_TIME			10								// �ι�° ���� ��û �޽��� ������ �ð� : 10��
#define	NPROTECT_QUERY_TIME					(3 * 60)						// ���� ��û �޽��� ������ �ð� : 3��
#define PULSE_NPROTECT_UPDATE				(5 * PULSE_REAL_MIN)			// nProtect GameGuard ��� ������Ʈ �ֱ� : 5��
#ifdef _DEBUG
#define NPROTECT_ACTIVE_NUM					10								// ���� ��� ������Ʈ ���� : �� ���� ������ ��
#define NPROTECT_UPDATE_CONDITION_TIME		15								// ���� ��� ������Ʈ ���� : �ð� ���� : 30��
#else
#define NPROTECT_ACTIVE_NUM					50								// ���� ��� ������Ʈ ���� : �� ���� ������ �� : �⺻ ���� 30%, 50����
#define NPROTECT_UPDATE_CONDITION_TIME		30								// ���� ��� ������Ʈ ���� : �ð� ���� : 30��
#endif // _DEBUG
#define NPROTECT_UPDATE_CONDITION_COUNT		50								// ���� ��� ������Ʈ ���� : ��� ��� ���� : 50%
#endif // USING_NPROTECT

#endif
