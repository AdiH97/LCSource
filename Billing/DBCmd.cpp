#include "stdhdrs.h"
#include "DBCmd.h"

CDBCmd::CDBCmd()
: m_sql(8192)
{
	m_dbconn = NULL;
	m_fieldinfo = NULL;
	m_nfields = 0;
	m_nrecords = 0;
	m_res = NULL;
	m_sqlLen = 0;
}

CDBCmd::~CDBCmd()
{
	Close();
	m_dbconn = NULL;
	m_nrecords = 0;
	m_res = NULL;
	m_fieldinfo = NULL;
	m_nfields = 0;
	m_sqlLen = 0;
}

bool CDBCmd::Init(MYSQL* conn)
{
	m_dbconn = conn;
	return true;
}

bool CDBCmd::Open()
{
	Close();

	if (mysql_real_query(m_dbconn, m_sql, m_sqlLen) == 0)
	{
		m_res = mysql_store_result(m_dbconn);

		if (m_res)
		{
			m_nrecords = (int)mysql_num_rows(m_res);
			m_nfields = (int)mysql_num_fields(m_res);
			m_fieldinfo = mysql_fetch_fields(m_res);
			return true;
		}
	}

	return false;
}

void CDBCmd::Close()
{
	if (m_res)
	{
		mysql_free_result(m_res);
		m_res = NULL;
	}
}

bool CDBCmd::MoveFirst()
{
	if (m_res == NULL)
		return false;

	mysql_data_seek(m_res, 0);

	m_row = mysql_fetch_row(m_res);
	if (m_row == NULL)
		return false;

	return true;
}

bool CDBCmd::MoveNext()
{
	if (m_res == NULL)
		return false;

	m_row = mysql_fetch_row(m_res);
	if (m_row == NULL)
		return false;

	return true;
}

void CDBCmd::SetQuery(const char* sql)
{
	char tmp[8192];
	BackSlash(tmp, 8192, sql);
	m_sql = tmp;
	m_sqlLen = m_sql.Length();
}

bool CDBCmd::Update()
{
	Close();

	if (mysql_real_query(m_dbconn, m_sql, m_sqlLen) == 0)
	{
		m_nrecords = mysql_affected_rows(m_dbconn);
		return true;
	}
	else
	{
		m_nrecords = 0;
		return false;
	}
}

bool CDBCmd::GetRec(const char* fieldname, int& n)
{
	return GetRec(FindField(fieldname), n);
}

bool CDBCmd::GetRec(const char* fieldname, unsigned int& n)
{
	return GetRec(FindField(fieldname), n);
}

bool CDBCmd::GetRec(const char* fieldname, short& n)
{
	return GetRec(FindField(fieldname), n);
}

bool CDBCmd::GetRec(const char* fieldname, unsigned short& n)
{
	return GetRec(FindField(fieldname), n);
}

bool CDBCmd::GetRec(const char* fieldname, char& ch)
{
	return GetRec(FindField(fieldname), ch);
}

bool CDBCmd::GetRec(const char* fieldname, unsigned char& ch)
{
	return GetRec(FindField(fieldname), ch);
}

bool CDBCmd::GetRec(const char* fieldname, CLCString& str, bool bTrim)
{
	return GetRec(FindField(fieldname), str, bTrim);
}

bool CDBCmd::GetRec(const char* fieldname, float& f)
{
	return GetRec(FindField(fieldname), f);
}

bool CDBCmd::GetRec(const char* fieldname, LONGLONG& ll)
{
	return GetRec(FindField(fieldname), ll);
}

bool CDBCmd::GetRec(int fieldno, int& n)
{
	char* ret = GetRec(fieldno);
	if (ret == NULL)
		return false;

	n = atoi(ret);
	return true;
}

bool CDBCmd::GetRec(int fieldno, unsigned int& n)
{
	int t;
	if (!GetRec(fieldno, t))
		return false;

	n = (unsigned int)t;
	return true;
}

bool CDBCmd::GetRec(int fieldno, short& n)
{
	int t;
	if (!GetRec(fieldno, t))
		return false;

	n = (short)t;
	return true;
}

bool CDBCmd::GetRec(int fieldno, unsigned short& n)
{
	int t;
	if (!GetRec(fieldno, t))
		return false;

	n = (unsigned short)t;
	return true;
}

bool CDBCmd::GetRec(int fieldno, char& ch)
{
	int t;
	if (!GetRec(fieldno, t))
		return false;

	ch = (char)t;
	return true;
}

bool CDBCmd::GetRec(int fieldno, unsigned char& ch)
{
	int t;
	if (!GetRec(fieldno, t))
		return false;

	ch = (unsigned char)t;
	return true;
}

bool CDBCmd::GetRec(int fieldno, CLCString& str, bool bTrim)
{
	// ������ �б�
	char* ret = GetRec(fieldno);

	// NULL�̸� ����
	if (ret == NULL)
		return false;

	char* p = ret;

	// left trim ó��
	if (bTrim)
	{
		while (*p && isspace(*p))
			p++;
	}

	// ���� ����Ʈ ����
	char* pStart = p;

	// ���� ����Ʈ ���� ���̰� 1���� ������
	if (strlen(pStart) < 1)
	{
		str = "";
		return true;
	}

	// �� ����Ʈ ����(NULL ���ڸ�)
	char* pEnd = pStart + strlen(pStart) - 1;

	// right trim ó��
	if (bTrim)
	{
		while (pEnd >= pStart)
		{
			if (isspace(*pEnd))
				pEnd--;
			else
				break;
	}
	}

	// trim�� ���� ���̰� 0�� �Ǹ� ����
	if (pEnd < pStart)
	{
		str = "";
		return true;
	}

	// ���⿡ ���� pStart���� pEnd���� ���ڸ� �����ϸ� ��
	int len = pEnd - pStart + 2;	// ��� ���ڿ� ���� (NULL ����)

	// ��� ������ ũ��� �� ���� ���� ����
	if (len > str.BufferSize())
		len = str.BufferSize();

	char* tmp = new char[len];
	memcpy(tmp, pStart, len - 1);
	tmp[len - 1] = '\0';
	str = tmp;
	delete [] tmp;

	return true;
}

bool CDBCmd::GetRec(int fieldno, float& f)
{
	char* ret = GetRec(fieldno);
	if (ret == NULL)
		return false;

	f = (float)atof(ret);
	return true;
}

bool CDBCmd::GetRec(int fieldno, LONGLONG& ll)
{
	char* ret = GetRec(fieldno);
	if (ret == NULL)
		return false;

	ll = ATOLL(ret);
	return true;
}

char* CDBCmd::GetRec(const char* fieldname)
{
	return GetRec(FindField(fieldname));
}

char* CDBCmd::GetRec(int fieldno)
{
	if (m_res == NULL || fieldno < 0 || fieldno >= m_nfields)
		return NULL;

	return m_row[fieldno];
}

int CDBCmd::FindField(const char* fieldname)
{
	if (m_fieldinfo == NULL) return -1;

	int i;
	for (i = 0; i < m_nfields ; i++)
		if (strcmp(fieldname, m_fieldinfo[i].name) == 0)
			return i;
	return -1;
}
