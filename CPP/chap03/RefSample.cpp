/* RefSample.cpp
*/
#include <iostream>
using namespace std;

class CRefTest
{
    public:
        // reference variables should be initialized in this initialization 
        CRefTest(int &rParam): m_nData(rParam) {};
        int GetData(void) { return m_nData; }

    private:
        int &m_nData;
};

int main(int argc, char* argv[])
{
    int a = 10;
    CRefTest t(a);

    cout << t.GetData() << endl;

    a = 20;
    cout << t.GetData() << endl;

    return 0;
}



