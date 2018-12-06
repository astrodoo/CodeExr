#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();
	
	int SetString(const char* pszParam);
	const char* GetString();
	void Release();

	// conversion constructor
	explicit CMyString(const char *pszParam);
	
	// copy constructor
	CMyString (const CMyString &rhs);
	
	// move semantic
	CMyString (CMyString &&rhs);
	
private:
	char* m_pszData;
	int m_nLength;
};