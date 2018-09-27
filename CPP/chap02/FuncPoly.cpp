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
