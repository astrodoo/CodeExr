#include "MyString.h"
#include <iostream>
using namespace std;

CMyString TestFunc(void)
{
	CMyString strTest("TestFunc() return");
	cout << strTest << endl;
	
	return strTest;
}

int main(int argc, char* argv[])
{
	// generate the temporary object without name
	TestFunc();
	
	return 0;
}