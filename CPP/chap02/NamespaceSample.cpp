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
