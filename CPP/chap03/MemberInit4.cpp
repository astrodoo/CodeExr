/* MemberInit4.cpp */
#include <iostream>
using namespace std;

class CTest
{
public:

    // Creative Functions - initialization
    CTest()
        : m_nData1(10), m_nData2(20)
    {}

    // declare
    int m_nData1;
    int m_nData2;

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


