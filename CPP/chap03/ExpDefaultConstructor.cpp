/* ExpDefaultConstructor.cpp 
*/
#include <iostream>
using namespace std;

class CTest
{
public:
    CTest(void) = default;
    //CTest(void);
    int m_nData = 5;
};

// creat the default constructor out of the class
//CTest::CTest(void) {}

int main(int argc, char* argv[])
{
    CTest a;
    cout << a.m_nData << endl;

    return 0;
}



