#include <iostream>
using namespace std;

class CMyData
{
public:
	int GetData() { return m_nData; }
	
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

class CMyDataEx : public CMyData
{
public:
	// override the method in the parent class
	void SetData(int nParam)
	{
		if (nParam < 0)
			CMyData::SetData(0);
			
		if (nParam > 0)
			CMyData::SetData(10);
	}
};

int main(int argc, char* argv[])
{
	CMyData a;
	a.SetData(-10);
	
	cout << a.GetData() << endl;
	
	CMyDataEx b;
	b.SetData(15);
	cout << b.GetData() << endl;

	// The method in the parent class can also be called 
	CMyDataEx c;
	c.CMyData::SetData(15);
	cout << c.GetData() << endl;
	
	return 0;
}