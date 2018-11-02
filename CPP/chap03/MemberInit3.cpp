/* MemberInit3.cpp */
#include <iostream>
using namespace std;

class CTest
{
public:

    // Creative Functions - initialization
    CTest()
    {
        m_nData = 10;
    }

    int m_nData;

    // seperate the declaration and definition
    void PrintData(void);
};

void CTest::PrintData(void)
{
    cout << m_nData << endl;
}

int main(int argc, char* argv[])
{
    CTest t;
    t.PrintData();

    return 0;
}



