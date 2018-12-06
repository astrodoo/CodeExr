#include <iostream>
using namespace std;

class CTestData
{
public:
	// type conversion is possible only for the constructor with one parameter
	// "explicit" prevent the tacit type conversion
	explicit CTestData(int nParam): m_nData(nParam)
	{
		cout << "CTestData(int)" << endl;
	}
	
	CTestData(const CTestData &rhs): m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}
	
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
	
	// destructor
	~CTestData()
	{
		cout << "~CTestData()" << endl;
	}
	
private:
	int m_nData = 0;
};

// the type of parameter is Class and is possible to convert
void TestFunc(const CTestData &param)
{
	cout << "TestFunc():" << param.GetData() << endl;
}

int main(int argc, char* argv[])
{
	cout << "*****Begin*****" << endl;
	
	// from int to CTestData type
	//TestFunc(5);    // This should raise an error.
	TestFunc(CTestData(5));
	
	// deconstruct the temporary object as the function is convertee
	
	cout << "*****End*****" << endl;
	
	return 0;
}