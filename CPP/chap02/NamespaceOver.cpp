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




