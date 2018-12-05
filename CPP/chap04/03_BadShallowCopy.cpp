#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	// pointers
	int *pA, *pB;
	
	pA = new int;
	*pA = 10;
	
	pB = new int;
	//pB = pA;
	*pB = *pA;
	
	cout << *pA << endl;
	cout << *pB << endl;
	
	// error
	delete pA;
	delete pB;
}