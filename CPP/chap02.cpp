/* Chapter 02: Default variables*/


//DefaultParam.cpp
#include <iostream>

int TestFunc(int nParam = 10)
{
    return nParam;
}

int main(int argc, char* argv[])
{
    std::cout << TestFunc() << std::endl;

    std::cout << TestFunc(20) << std::endl;

    return 0;
}


//========================================================
//DefaultParam2.cpp
#include <iostream>

int TestFunc(int nParam1, int nParam2 = 2)
{
    return nParam1 * nParam2;
}

int main(int argc, char* argv[])
{
    std::cout << TestFunc(10) << std::endl;

    std::cout << TestFunc(10,5) << std::endl;

    return 0;
}


//========================================================
//DefaultParam3.cpp
#include <iostream>

#define MYTYPE_A 0

int CalcLayout(int nWidth, int nHeight, int nType = MYTYPE_A)
{
    return nWidth + nHeight + nType;
}

int main(int argc, char* argv[])
{
    //std::cout << CalcLayout(10,5) << std::endl;
    std::cout << CalcLayout(10,5,MYTYPE_A) << std::endl;
}



//========================================================
// FuncPoly.cpp
// Example of Overloading: multiple functions with same name //
#include <iostream>

int Add(int a, int b, int c)
{
    std::cout << "Add(int, int, int): ";
    return a+b+c;
}

int Add(int a, int b)
{
    std::cout << "Add(int, int): ";
    return a*b;
}

double Add(double a, double b)
{
    std::cout << "Add(double, double): ";
    return a-b;
}

int main(int argc, char* argv[])
{
    std::cout << Add(3,4) << std::endl;
    std::cout << Add(3,4,5) << std::endl;
    std::cout << Add1(3.3,4.1) << std::endl;
    return 0;
}



//========================================================
// FuncTemplate.cpp
// function template for overloading //
#include <iostream>

template <typename T>
T Add(T a, T b)
{
    return a+b;
}

int main(int argc, char* argv[])
{
    //std::cout << Add(3,4) << std::endl;
    std::cout << Add<int>(3,4) << std::endl;  // <int> --> <typename T>
    std::cout << Add(3.3,4.4) << std::endl;

    return 0;
}


//========================================================
//InlineSample.cpp
// exercise inline function //
#include <cstdio>

#define ADD(a,b)((a)+(b))   // Macro: type cannot be determined

int Add(int a, int b)
{ 
    return a+b;
}

inline int Addnew(int a, int b) // inline function
{
    return a+b+10;
}


int main(int argc, char* argv[])
{
    int a,b;

    scanf("%d%d", &a,&b);  // scanf_s is not working //

    printf("ADD(): %d\n", ADD(a,b));
    printf("Add(): %d\n", Add(a,b));
    printf("Addnew(): %d\n", Addnew(a,b));

    return 0;
}


//========================================================
// NamespaceSample.cpp
#include <iostream>

namespace TEST
{
    int g_nData = 100;

    void TestFunc(void)
    {
        std::cout << "TEST::TestFunc()" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    TEST::TestFunc();
    std::cout << TEST::g_nData << std::endl;

    return 0;
}


//========================================================
// NamespaceUsing.cpp
#include <iostream>

using namespace std;

namespace TEST
{
    int g_nData = 100;

    void TestFunc(void)
    {
        cout << "TEST::TestFunc()" << endl;
    }
}

using namespace TEST;

int main(int argc, char* argv[])
{
    TestFunc();
    cout << g_nData << endl;

    return 0;
}


//========================================================
// NamespaceNested.cpp
#include <iostream>

using namespace std;

namespace TEST
{
    int g_nData = 100;
    
    namespace DEV
    {
        int g_nData = 200;

        namespace WIN
        {
            int g_nData = 300;
        }
    }
}

int main(int argc, char* argv[])
{
    cout << TEST::g_nData << endl;
    cout << TEST::DEV::g_nData << endl;
    cout << TEST::DEV::WIN::g_nData << endl;

    return 0;
}


//========================================================
// NamespaceOver.cpp
#include <iostream>

using namespace std;

//global
void TestFunc(void) { cout << "::TestFunc()" << endl; }

namespace TEST
{
    void TestFunc(void){
        cout << "TEST::TestFunc()" << endl;
    }
}

namespace MYDATA
{
    void TestFunc(void){
        cout << "DATA::TestFunc()" << endl;
    }
}

int main(int argc, char* argv[])
{
    TestFunc();    //global
    ::TestFunc();  //global
    TEST::TestFunc();
    MYDATA::TestFunc();

    return 0;
}


//========================================================
// IdSearchSeq1.cpp
#include <iostream>

using namespace std;

int nData(20);

int main(int argc, char* argv[])
{
    int nData(10);

    cout << nData << endl;
    cout << argc << endl;

    return 0;
}


//========================================================
// IdSearchSeq2.cpp
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int nInput = 0;
    cout << "input the number larger than 11" << endl;
    cin >> nInput;

    if (nInput > 10)
    {
        cout << nInput << endl;
    }
    else
        cout << "Error" << endl;

    return 0;
}


//========================================================
// IdSearchSeq3.cpp
#include <iostream>
using namespace std;

int nData = 200;

namespace TEST
{
    //int nData = 100;

    void TestFunc(void)
    {
        cout << nData << endl;
    }
    int nData = 100;
}

int main(int argc, char* argv[])
{
    TEST::TestFunc();

    return 0;
}
