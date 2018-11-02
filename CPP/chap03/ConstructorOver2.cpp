/* ConstructorOver2.cpp
*/
#include <iostream>
using namespace std;

class CMyPoint
{
public:
    CMyPoint(int x)
    { 
        cout << "CMyPoint(int)" << endl;

        if (x>100)
            x = 100;

        m_x = x;
    }

    CMyPoint(int x, int y)
    // The upper constructor can be re-used
        : CMyPoint(x)
    {
        cout << "CMyPoint(int,int)" << endl;

        if (y>200)
            y=200;

        m_y = y;
    }

    void Print()
    {
        cout << "X: " << m_x << endl;
        cout << "Y: " << m_y << endl;
    }

private:
    int m_x=0;
    int m_y=0;
};

int main(int argc, char* argv[])
{
    CMyPoint ptBegin(110);
    ptBegin.Print();

    CMyPoint ptEnd(50,250);
    ptEnd.Print();

    return 0;
}


