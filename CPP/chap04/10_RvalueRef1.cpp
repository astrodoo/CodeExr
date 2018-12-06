#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int&& data = 3+4;
	cout << data << endl;
	data++;
	cout << data << endl;
	
	return 0;
}