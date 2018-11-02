/* ConstMethod2.cpp
 *
 *  Mutable (normal instance) and const_cast<> (reference instance) in using Constant Method
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
        // The member instance can be written if it is mutable !!
        m_nData = 20;
        return m_nData;
    }
private:
    mutable int m_nData = 0;
};

int main(int argc, char* argv[])
{
    CTest a(10);
    cout << a.GetData() << endl;

    return 0;
}
