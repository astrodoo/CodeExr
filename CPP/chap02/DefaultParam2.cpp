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
