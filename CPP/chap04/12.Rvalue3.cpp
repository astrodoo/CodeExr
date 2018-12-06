/* Ambiguity for the multiple definitions of function regarding with r-value */

#include <iostream>
using namespace std;

// r-value reference
void TestFunc(int &&rParam)
{
	cout << "TestFunc(int &&)" << endl;
}

// r-value refer-type is the same as the simple int type
void TestFunc(int nParam)
{
	cout << "TestFunc(int)" << endl;
}

int main(int argc, char* argv[])
{
	// it calls the function ambiguously. 
	// so it causes error
	TestFunc(3+4);
	
	return 0;
}