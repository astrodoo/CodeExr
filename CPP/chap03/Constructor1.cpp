/* Constructor1.cpp 
   Every classes have both constructor and destructor
*/
#include <iostream>

using namespace std;

class CTest
{
public:
    CTest()
    {
        cout << "CTest::CTest()" << endl;
    }

    ~CTest()
    {
        cout << "~CTest::CTest()" << endl;
    }
};

int main(int argc, char* argv[])
{
    cout << "Begin" << endl;
    CTest a;
    cout << "End" << endl;

    return 0;
}



