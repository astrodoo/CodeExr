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
