/* ConstMethod1.cpp
*/
#include <iostream>
using namespace std;

class CTest
{
public:
    // Constructor
    CTest(int nParam): m_nData(nParam) {};
    // Destructor
    ~CTest() {}

    // declaration and definition of the constant method
    int GetData() const
    {
        // Only read the values of the member instance, 
        // but cannot write on it
        return m_nData;
    }
private:
    int m_nData = 0;
};

int main(int argc, char* argv[])
{
    CTest a(10);
    cout << a.GetData() << endl;

    return 0;
}
