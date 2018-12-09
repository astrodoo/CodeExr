#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam): m_nData(nParam) {}
	
	// type conversion
	operator int() { return m_nData; }
	
	// fore- increment operator
	int operator++()
	{
		cout << "operator++()" << endl;
		return ++m_nData;
	}
	
	// after- increment operator
	int operator++(int)
	{
		cout << "operator++(int)" << endl;
		int nData = m_nData;
		m_nData++;
		
		return nData;
	}

private:
	int m_nData = 0;
};

int main(int argc, char* argv[])
{
	CMyData a(10);
	
	// call by fore- increment operator
	cout << ++a << endl;
	
	// call by after- increment operator
	cout << a++ << endl;
	cout << a << endl;
	
	return 0;
}