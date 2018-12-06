#include <iostream>
using namespace std;

void TestFunc(int &rParam)
{
	cout << "TestFunc(int &)" << endl;
}

void TestFunc(int &&rParam)
{
	cout << "TestFunc(int &&)" << endl;
}

int main(int argc, char* argv[])
{
	// 3+4 is r-value. It can be referred to &&. 
	// It cannot be referred to & because it is not lvalue but rvalue.
	TestFunc(3+4);
	
	return 0;
}