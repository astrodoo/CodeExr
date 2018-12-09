#include <iostream>
using namespace std;

class CMyData
{
public:
	explicit CMyData(int nParam)
	{
		m_pnData = new int(nParam);
	}
	
	~CMyData() { delete m_pnData; }
	
	operator int() { return *m_pnData; }
	
	// multiple assignment for the simple operator 
	CMyData& operator=(const CMyData &rhs)
	{
		// return when r-value is itself (e.g., a=a)
		if (this == &rhs)
			return *this;
		
		// delete the initially pointed memory
		delete m_pnData;
			
		// assign the value to new memory
		m_pnData = new int(*rhs.m_pnData); 
		
		return *this;
	}
	
private:
	int *m_pnData = nullptr;
};

int main(int argc, char* argv[])
{
	CMyData a(0), b(5), c(10);
	//a = b;
	a = b = c;
	
	cout << a << endl;
	
	return 0;
}