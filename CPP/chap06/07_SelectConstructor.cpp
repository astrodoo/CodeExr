#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	CMyData(int nParam) { cout << "CMyData(int)" << endl; }
	CMyData(double dParam) { cout << "CMyData(double)" << endl; }
};

class CMyDataEx : public CMyData
{
public:
	//using CMyData::CMyData;  // inherit all multi constructors from the upper class (only work for c++11 and not working in visual c++2013 )
	
	CMyDataEx() { cout << "CMyDataEx()" << endl; }
	
	// choose the constructor in the upper class
	CMyDataEx(int nParam) : CMyData(nParam)
	{ cout << "CMyDataEx(int)" << endl; }
	
	// choose the default constructor in the upper class
	CMyDataEx(double dParam) : CMyData()
	{ cout << "CMyDataEx(double)" << endl; }
};

int main(int argc, char* argv[])
{
	CMyDataEx a;
	cout << "***********" << endl;
	CMyDataEx b(5);
	cout << "***********" << endl;
	CMyDataEx c(3.3);
	
	return 0;
}