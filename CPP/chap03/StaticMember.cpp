/* StaticMember.cpp
 */
#include <iostream>
using namespace std;

class CTest
{
public:
    CTest(int nParam): m_nData(nParam) { m_nCount++; }
    int GetData() { return m_nData; };
    void ResetCount() { m_nCount = 0; };

    // declaration and definition of static method
    static int GetCount()
    {
        return m_nCount;
    };
private:
    int m_nData;
    // declaration of static member instance
    static int m_nCount;
};

// definition of the static member 
int CTest::m_nCount = 0;

int main(int argc, char* argv[])
{
    CTest a(5), b(10);
    cout << a.GetCount() << endl;

    b.ResetCount();
    cout << CTest::GetCount() << endl;

    return 0;
}



