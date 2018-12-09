#include <iostream>
using namespace std;

class CMyData
{
public:
	// conversion constructor
	CMyData(int nParam): m_nData(nParam)
	{
		cout << "CMyData(int)" << endl;
	}
	
	// copy constructor
	CMyData(const CMyData &rhs): m_nData(rhs.m_nData)
	{
		cout << "CMyData(const CMyData &)" << endl;
	}
	
	// move symentic
	CMyData(const CMyData &&rhs): m_nData(rhs.m_nData)
	{
		cout << "CMyData(const CMyData &&)" << endl;
	}
	
	// type conversion
	operator int() { return m_nData; }
	
	// +
	CMyData operator+(const CMyData &rhs)
	{
		cout << "operator+" << endl;
		CMyData result(0);
		result.m_nData = this -> m_nData + rhs.m_nData;
		
		return result; 
 	}
 	
 	// =
 	CMyData operator=(const CMyData &rhs)
 	{
 		cout << "operator=" << endl;
 		m_nData = rhs.m_nData;
 		
 		return *this;
 	}
 
private:
	int m_nData = 0;
};

int main(int argc, char* argv[])
{
	cout << "*****Begin*****" << endl;
	CMyData a(0), b(3), c(4);
	
	// when b+c is executed, unreferred temporary object is created
	// substituting on "a" also create temporary object
	
	a = b + c;
	cout << a << endl;
	cout << "*****End******" << endl;
	
	return 0;
}