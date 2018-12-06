#include "MyString.h"
#include <iostream>
using namespace std;

CMyString::CMyString()
	: m_pszData(NULL), m_nLength(0)
{
}

CMyString::~CMyString()
{
}

int CMyString::SetString(const char* pszParam)
{
	return 0;
}

const char* CMyString::GetString()
{
	return NULL;
}

void CMyString::Release()
{
}

// move semantic
CMyString::CMyString(CMyString &&rhs)
	: m_pszData(NULL), m_nLength(0)
{
	cout << "CMyString call move semantic" << endl;
	
	// its okay to soft copy because it would be deconstructed immediately.
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;
	
	// initialize the temporary parameters. Must not release.
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}