#include <stdio.h>

int main()
{
	const int a = 10;
	// int *p = (int*)&a;
	int * const p= (int*)&a;
	printf("a===>%d\n", a);
	*p = 11;
	printf("a===>%d\n", a);
	return 0;
}
