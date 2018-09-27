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
