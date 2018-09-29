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




