#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam)
	{
		m_pnData = new int;
		*m_pnData = nParam; 
	}
	
	/*
	// default the copy constructor
	CMyData(const CMyData &rhs)
	{	
		m_pnData = rhs.m_pnData;
	}*/
	
	// define the copy constructor
	CMyData(const CMyData &rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;
		
		// assign a memory
		m_pnData = new int;
		
		// copy the value by the pointer
		*m_pnData = *rhs.m_pnData;
	}
	
	// free the memory when the variable is eliminated
	~CMyData()
	{
		delete m_pnData;
	}
	
	// define a simple operator by a multiple definition of variable
	CMyData& operator=(const CMyData &rhs)
	{
		*m_pnData = *rhs.m_pnData;
		
		// return the reference of the object itself.
		return *this;
	}
	
	
	int GetData()
	{
		if(m_pnData != NULL)
			return *m_pnData;
		return 0;
	}
	
private:
	int *m_pnData = nullptr;
};

int main(int argc, char* argv[])
{
	// call the default generator
	CMyData a(10);
	CMyData b(20);
	
	// a simple operator //
	a = b;
	//a.operator=(b);
	
	cout << a.GetData() << endl;
	
	return 0;
}
