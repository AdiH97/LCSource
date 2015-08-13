#ifndef  __GAME_UTILS_H__
#define  __GAME_UTILS_H__

#include "LCString.h"
#include "LCList.h"

#ifdef __GAME_SERVER__
#include "Character.h"
float GetDistance(CCharacter* ch, CCharacter* tch);
float GetDistance(float x, float z, float h, CCharacter* tch);
void GetSerial(char *buf, int index);
void GetSerial(CLCString& buf, int index);
#endif

// �� Ÿ��
extern struct timeval a_NullTime;

// ���߿� �������� ���� ����
extern char		g_buf[MAX_STRING_LENGTH];
extern char		g_buf2[MAX_STRING_LENGTH];
extern char		g_buf3[MAX_STRING_LENGTH];


char* __ltoa(int value, char *string);
char* __ltoa(LONGLONG value, char *string);
char* __ftoa(float f, char *buf, int place);
void MakeMath();
float get_sin(float radian);
float get_cos(float radian);
void GetTimeofDay(struct timeval *t, struct timezone *dummy);
void TimeDiff(struct timeval *rslt, struct timeval *a, struct timeval *b);
void TimeAdd(struct timeval *rslt, struct timeval *a, struct timeval *b);
float GetDistance(float x1, float x2, float z1, float z2, float h1, float h2);
const char* SkipSpaces(const char* string);
char* RemoveTailSpaces(char* string);
char* TrimString(char* string);
const char* AnyOneArg(const char* argument, char* first_arg, bool toLower = false);
#ifndef __BILLING_SERVER__
char* StrDup(const char* source);
char* StrCat(char* dest, const char* src);
#endif
char* IntCat(char *dest, int i, bool bInsertSpace = true);
char* IntCat(char *dest, LONGLONG ll, bool bInsertSpace = true);
char* IntCat0(char* dest, int i, int width, bool bInsertSpace = true);
char* IntCat0(char* dest, LONGLONG i, int width, bool bInsertSpace = true);
char* FloatCat(char *dest, float f, int place, bool bInsertSpace = true);
bool strinc(const char *str, const char *inc);
void IPtoi(const char *org_IP,int *i_one, int *i_two, int *i_thr, int *i_for);

int GetRandom(int from, int to);

bool CheckIP(const char *u_IP);

char* TransDateStr(int time, char* convbuf);	//0627 // ��ȣ ����

///////////////////////////////////
// ��ũ�� & �ζ��� �Լ���

#define MAX(a, b)	((a > b) ? a : b)										// �ִ�
#define MIN(a, b)	((a < b) ? a : b)										// �ּ�
#define LOWER(c)   (((c)>='A'  && (c) <= 'Z') ? ((c)+('a'-'A')) : (c))		// �ҹ��ڷ�
#define UPPER(c)   (((c)>='a'  && (c) <= 'z') ? ((c)+('A'-'a')) : (c) )		// �빮�ڷ�
#define ABS(c)		((c) < 0 ? -(c) : (c))									// ���밪
#define SIGN(i)		((i) < 0 ? (-1) : (1))									// ��ȣ
#define ISNEWL(ch) ((ch) == '\n' || (ch) == '\r')							// ���� ���� �˻�
#define is_space(c)		(c == 0x20 || (c >= 0x09 && c <= 0x0D))				// ���� �˻�


// LINKED LIST MANAGEMENT

// REMOVE NODE FROM LIST
#define REMOVE_FROM_BILIST(item, head, before, next) { \
			if (item->before) { \
				item->before->next = item->next; \
				if (item->next) { \
					item->next->before = item->before; \
				} \
			} else { \
				head = item->next; \
				if (item->next) { \
					item->next->before = NULL; \
				} \
			} \
			item->before = NULL; \
			item->next = NULL; }

// ADD NODE TO LIST
#define ADD_TO_BILIST(item, head, before, next) { \
			if (head) { \
				head->before = item; \
			} \
			item->next = head; \
			item->before = NULL; \
			head = item; }


////////////////////
// Function name	: Rad2Deg
// Description	    : ������ �� ���� ������ ��ȯ
// Return type		: float 
//					: �� ���� ����
// Argument         : float rad
//					: ���� ����
inline float Rad2Deg(float rad)
{
	float deg = rad * 180 / PI;
	if (deg > 180)
		deg -= 360;
	else if (deg < -180)
		deg += 360;
	return deg;
}


////////////////////
// Function name	: Deg2Rad
// Description	    : �� ���� ������ �������� ��ȯ
// Return type		: float 
//					: ���� ����
// Argument         : float deg
//					: �� ���� ����
inline float Deg2Rad(float deg)
{
	if (deg > 180)
		deg -= 360;
	else if (deg < -180)
		deg += 360;

	return deg * PI / 180;
}

#ifdef __BILLING_SERVER__
////////////////////
// Function name	: DT2TM
// Description	    : DBTIMESTAMP���� struct tm���� ��ȯ (�д�����)
inline struct tm DT2TM(MYSQL_TIME dt)
{
	struct tm ret;
	memset(&ret, 0, sizeof(ret));
	ret.tm_year = dt.year - 1900;
	ret.tm_mon = dt.month - 1;
	ret.tm_mday = dt.day;
	ret.tm_hour = dt.hour;
	ret.tm_min = dt.minute;
	return ret;
}
#endif

inline struct tm NOW()
{
	time_t t;
	time(&t);
	struct tm ret;
	memcpy(&ret, localtime(&t), sizeof(ret));
	return ret;
}

// nSizeOfDest�� NULL�� ����
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

inline void StrUpr(char* src)
{
	while (*src)
	{
		if( *src >= 97 && *src <= 122 )
		{
			*src -= 32;
		}
		src++;
	}
}

inline void StrLwr(char* src)
{
	while (*src)
	{
		if( *src >= 65 && *src <= 90 )
		{
			*src += 32;
		}
		src++;
	}
}

#ifdef CIRCLE_WINDOWS
#define strcmp2(a, b)	_stricmp(a, b)
#else
#define strcmp2(a, b)	strcasecmp(a, b)
#endif

#endif
