// verifying that OMP environment actually works

#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel 
    {
        int ID = 0;
        printf("Hello(%d)", ID);
        printf("World(%d)\n", ID);
}}
