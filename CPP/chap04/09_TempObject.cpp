#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData(int nParam, char *pszName): m_nData(nParam), m_pszName(pszName)
	{
		cout << "CTestData(int)" << m_pszName << endl;
	}
	
	~CTestData()
	{
		cout << "~CTestData(): " << m_pszName << endl;
	}
	
	CTestData(const CTestData &rhs): m_nData(rhs.m_nData), m_pszName(rhs.m_pszName)
	{
		cout << "CTestData(const CTestData &): " << m_pszName << endl;
	}
	
	CTestData& operator=(const CTestData &rhs)
	{
		cout << "operator=" << endl;
		
		// convert the value but remain the m_pszName intact
		m_nData = rhs.m_nData;
		
		return *this;
	}
	
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
	
	// the member for keeping the object name
	char *m_pszName = nullptr;
};

// The function for converting the CTestData object
CTestData TestFunc(int nParam)
{
	// a, CTest Data class instance, is the local variable
	// therefore, it is deconstructed right after returning.
	CTestData a(nParam, "a");
	
	return a;
}

int main(int argc, char* argv[])
{
	CTestData b(5, "b");
	cout << "*****Before*****"  << endl;
	
	// As the function is returned, the temporary variable is created and deconstructed right after the operator.
	b = TestFunc(10);
	cout << "*****After******" << endl;
	cout << b.GetData()  << endl;
	
	return 0;
}