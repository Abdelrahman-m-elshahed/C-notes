#include <stdio.h>

#if 0
void main()
{
    int x =5;

    int* ptr = &x;

    printf("x =%d\n",x); // x 
    printf("*ptr =%d\n",*ptr); // value of x
    printf("&x =%p\n",&x); // address of x 
    printf("ptr =%p\n",ptr); // address of x 
    printf("ptr =%d\n",ptr); // address of x 

    printf("sizeof(ptr) = %d\n",sizeof(ptr)); // 8 bytes
    printf("sizeof(x) = %d\n",sizeof(x)); // 8 bytes
}
#endif 

#if 0
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
#endif 


// pointer to function 
#if 1

int sum(int x, int y)
{
    return x + y;
}

int (*sum_pointer) (int,int);
int main()
{
    int op1 = 5, op2 = 8;
    sum_pointer = sum;
    printf("%i\n",sum_pointer(op1,op2));
}
#endif 

#if 0
int sum (int a , int b)
{
    return a + b;
}

// return_type (*ptr) (argumen_type);
int (*ptr) (int , int)=NULL;

int main()
{
    ptr = sum; // assigning the address of the function to the pointer 
    if (ptr != NULL)
    {
        int z = ptr(1,2);
        printf("%i\n",z);
    
        z = (*ptr)(3,4);
        printf("%i\n",z);   
    }
    
}

#endif

#if 0
void swap(int **c, int **v)
{
    int *tmp;
    tmp = *c;
    *c = *v;
    *v = tmp; 


} 

int main()
{
    int x = 5, y = 6;
    int *ptr1 = &x, *ptr2 = &y;
    printf("*ptr1 = %i\n",*ptr1);
    printf("*ptr2 = %i\n",*ptr2);

    swap(&ptr1,&ptr2);
    printf("\n*ptr1 = %i\n",*ptr1);
    printf("*ptr2 = %i\n",*ptr2);



}
#endif

#if 0

int main()
{
    int x = 5;
    int *ptr;
    ptr = &x;

    printf("%i\n",*ptr);
    printf("%i\n",x);

    printf("%p\n",ptr);
    printf("%p\n",&x);

    printf("%i\n",&*ptr);
}

#endif

#if 0

int main()
{
    int x = 5;
    int *ptr;
    ptr=&x;

    printf("%i\n",*ptr);
    printf("%i\n",x);
    
    printf("\n%p\n",ptr);
    printf("%p\n",&x);

    printf("\n%p\n",*&ptr);

    printf("\n%i\n",&*ptr);
    /*printf("%i\n",&*x); // error -> 'casue you can not dereference an integer*/

}
#endif 
