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
