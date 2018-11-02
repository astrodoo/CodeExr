/* MemberInit5.cpp 
 
   icc MemberInit5.cpp -std=c++11 */
#include <iostream>
using namespace std;

class CTest
{
public:

    // Creative Functions - initialization
    CTest() {}

    // declare and initialize (c++11 style)
    int m_nData1 = 10;
    int m_nData2 = 20;

    // seperate the declaration and definition
    void PrintData(void)
    {
        cout << m_nData1 << endl;
        cout << m_nData2 << endl;
    }
};

int main(int argc, char* argv[])
{
    CTest t;
    t.PrintData();

    return 0;
}


