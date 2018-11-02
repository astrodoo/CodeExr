/*ThisPointer.cpp
*/
#include <iostream>
using namespace std;

class CMyData
{
public:
    CMyData(int nParam): m_nData(nParam) {};
    void PrintData()
    {
        // 1. basic print-out
        cout << m_nData << endl;
        // 2. print-out with class member
        cout << CMyData::m_nData << endl;
        // 3. call the method of "this" pointer
        cout << this->m_nData << endl;
        // 4. Best way for the print-out
        cout << this->CMyData::m_nData << endl;
    }

private:
    int m_nData;
};

int main(int argc, char* argv[])
{
    CMyData a(5), b(10);
    a.PrintData();
    b.PrintData();

    return 0;
}



