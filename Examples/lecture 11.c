#include <stdio.h>

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