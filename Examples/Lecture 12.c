#include <stdio.h>

int main()
{
	int x = 5;
	int* ptr1 = &x;

	printf("%d\n", *ptr1++);
	printf("%d\n", x);

	ptr1= &x;
	printf("%d\n", *++ptr1);
	
	ptr1= &x;
	(*ptr1)++;
	printf("%d\n", x);
	
	int y = 10;
	int* ptr2= &y;

	printf("%d\n", *ptr1 + *ptr2);
	
}