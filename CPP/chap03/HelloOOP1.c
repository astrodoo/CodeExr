/* Chapter 03: CLASS */

/* HelloOOP1.c */
#include <stdio.h>

typedef struct USERDATA
{
    int nAge;
    char szName[32];
} USERDATA;

int main(void)
{
    USERDATA user = {20, "hey"};
    printf("%d, %s\n", user.nAge, user.szName);
}




