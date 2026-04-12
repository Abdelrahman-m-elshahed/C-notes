#include <stdio.h>

#if 1
int main()
{
	printf("1D Array:\n");
	int Arr_1D[2] = {1,2};

	printf("%p\n",Arr_1D); 
	printf("%p\n",Arr_1D + 1); // +4b
	printf("%p\n",&Arr_1D); 
	printf("%p\n",&Arr_1D + 1); // +4B * 2

	printf("\n2D Array:\n");
	int Arr_2D[2][3] = {{1,2,3},
						{4,5,6}};
	
	printf("%p\n",Arr_2D);
	printf("%p\n",Arr_2D + 1); 
	printf("%p\n",&Arr_2D); // +12 (it will point to the next row)
	printf("%p\n",&Arr_2D + 1); // +24 (the whole 2D Array)
}
#endif