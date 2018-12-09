#include <iostream>
using namespace std;

class CMyData
{
public:
	explicit CMyData(int nParam)
	{
		cout << "CMyData(int)" << endl;
		m_pnData = new int(nParam);
	}
	
	CMyData(const CMyData &rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;
		m_pnData = new int(*rhs.m_pnData);
	}
	
	~CMyData() { delete m_pnData; }
	
	operator int() {return *m_pnData;}
	
	// + operator multiple assignment
	CMyData operator+(const CMyData	&rhs)
	{
		// generate unknown temporary object in function
		return CMyData(*m_pnData + *rhs.m_pnData);
	}
	
	// = operator multiple assignment
	CMyData& operator=(const CMyData &rhs)
	{
		cout << "operator=" << endl;
		if (this == &rhs)
			return *this;
		
		delete m_pnData;
		m_pnData = new int(*rhs.m_pnData);
		
		return *this;
	}
	
	// move symentic multiple assignment
	CMyData& operator=(CMyData &&rhs)
	{
		cout << "operator=(Move)" << endl;
		
		// soft copy and initialize with NULL
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = NULL;
		
		return *this;
	}
	
private:
	int *m_pnData = nullptr;	
};

int main(int argc, char* argv[])
{
	CMyData a(0), b(3), c(4);
	cout << "*****Before*****" << endl;
	
	// move symentic 
	a = b + c;
	cout << "*****After******" << endl;
	cout << a << endl;
	a = b;
	cout << a << endl;
	
	return 0;
}