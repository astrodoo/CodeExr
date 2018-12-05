#include <iostream>
using namespace std;

class CTestData
{
public:
	CTestData(int nParam): m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}
	
	CTestData(const CTestData &rhs): m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}
	
	// read only
	int GetData() const {return m_nData; }
	
	// attempt to write member variable
	void SetData(int nParam) { m_nData = nParam; }
	
private:
	int m_nData = 0;
};

// call variable by CTestData class
void TestFunc(CTestData &param)
{
	cout << "TestFunc()" << endl;
	
	// change the value of instance
	param.SetData(20);
}

int main(int argc, char* argv[])
{
	cout << "****Begin****" << endl;
	CTestData a(10);
	TestFunc(a);
	
	// call the TestFunc and print out the value of a
	cout << "a: " << a.GetData() << endl;
	cout << "****End****"  << endl;
	
	return 0;
}