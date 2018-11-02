/* MemberOver2.cpp
 */
#include <iostream>
using namespace std;

class CMyData
{
public:
    CMyData(): m_nData(0) {};

    int GetData(void) { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

    // prevent the unintended format from being inserted 
    void SetData(double dParam) = delete;

private:
    int m_nData;
};

int main(int argc, char* argv[])
{
    CMyData a;
    a.SetData(10);
    cout << a.GetData() << endl;

    CMyData b;
    b.SetData(5.5);
    cout << b.GetData() << endl;

    return 0;
}



