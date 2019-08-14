#include <stdio.h>

int main(int argc, char *argv[])
{

	double tmp;
	
	printf("%d \n",argc);

	sscanf(argv[2], "%lf", &tmp);
	printf("hey !!");
	printf("%lf \n", tmp);
}
