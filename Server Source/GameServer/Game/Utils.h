#ifndef  __GAME_UTILS_H__
#define  __GAME_UTILS_H__

#include "LCString.h"
#include "LCList.h"

#include "Character.h"
float GetDistance(CCharacter* ch, CCharacter* tch);
float GetDistance(float x, float z, float h, CCharacter* tch);
void GetSerial(char *buf, int index);
void GetSerial(CLCString& buf, int index);

//char* __ltoa(int value, char *string)
//{
//	char p_buf[128];
//	int idx, i;
//
//	// �ʱ�ȭ
//	*string = '\0';
//	idx = 0;
//	i = 0;
//
//	// ������ -��ȣ�� ���̰� value�� ����� ������
//	if (value < 0)
//	{
//		strcpy(string, "-");
//		value = -value;
//		i = 1;
//	}
//	if (value == 0)
//	{
//		strcpy(string, "0");
//		return string;
//	}
//
//	// ���ڸ����� ���ڿ��� ����
//	while (value)
//	{
//		switch (value % 10)
//		{
//		case 0:
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//		case 6:
//		case 7:
//		case 8:
//		case 9:
//			p_buf[idx++] = (char)((value % 10) + '0');
//			break;
//		default:
//			p_buf[idx++] = '0';
//			break;
//		}
//
//		value /= 10;
//	}
//
//	while (idx)
//	{
//		string[i++] = p_buf[--idx];
//	}
//	string[i++] = '\0';
//
//	return string;
//}
//
//char* __ftoa(float f, char *buf, int place)
//{
//	char p_buf[128];
//
//	*buf = '\0';
//
//	// �Ҽ��� ���ڸ� ���ڿ���
//	// ��� ���� ������
//	if (f < 0)
//	{
//		// ������ ����� �����
//		f = -f;
//		__ltoa((int)f, p_buf);
//		// ���ڿ� �տ� -�� ���̰�
//		strcpy(buf, "-");
//		strcat(buf, p_buf);
//	}
//	else
//	{
//		__ltoa((int)f, buf);
//	}
//
//	// �Ҽ��� ���ڸ� ����?
//	if (place <= 0)
//	{
//		return buf;
//	}
//
//	// �Ҽ��� 8�ڸ�������
//	if (place > 8)
//		place = 8;
//
//	// �Ҽ��� �ںκи� �����
//	f -= (int)f;
//
//	// ���ϴ� �Ҽ� �ڸ����� ���ؼ�
//	while (place > 0)
//	{
//		f *= 10;
//		place--;
//	}
//
//	// ���� �κи� �ٽ� ��ȯ
//	__ltoa((int)f, p_buf);
//	strcat(buf, ".");
//	strcat(buf, p_buf);
//
//	return buf;
//}


#endif
