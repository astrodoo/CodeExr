/* ConstCastSample.cpp
 * const_cast<>: it makes the "const" method reference instances writable
*/
#include <iostream>
using namespace std;

// reference instance
void TestFunc(const int &nParam)
{
    // type would be changed from the "const" to "int" reference
    int &nNewParam = const_cast<int &>(nParam);
    nNewParam = 20;
}

int main(int argc, char* argv[])
{
    int nData = 10;

    TestFunc(nData);

    cout << nData << endl;

    return 0;
}


