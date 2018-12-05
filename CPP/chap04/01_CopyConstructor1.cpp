#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(){ cout << "CMyData()" << endl;}

	// generate copy constructor
	CMyData(const CMyData &rhs)
		// : m_nData(rhs.m_nData)
	{
		this->m_nData = rhs.m_nData;
		cout << "CMyData(const CMyData &)" << endl;
	}
	
	int GetData(void) const {return m_nData;}
	void SetData(int nParam) {m_nData = nParam; }
	
private:
	int m_nData = 0;
};

int main(int argc, char* argv[])
{
	// call the default generator
	CMyData a;
	a.SetData(10);
	
	// copy constructor
	CMyData b(a);
	cout << b.GetData() << endl;
	
	return 0;
}
