#include <stdio.h>

#if 0
int main()
{
    // printf("%c\n",'a'); 
    // printf("%i\n",'a'); 
    // printf("%i\n","a"); 
    printf("hello" + 1);
    // printf("%i\n","hello"); 
    // printf("%c\n", *("hello")); 
    // printf("%i\n", *("hello")); 
}
#endif

#if 0
int main()
{
	char my_name[5];
	gets(my_name);
	puts(my_name);

}
#endif



#if 1
int main()
{
	char my_name[20];
	int x;
	
	// scanf("%i",&x);
	
	// gets skps reading the string		
	// gets(my_name);
	// puts(my_name);

	
	scanf("%i",&x);
	fflush(stdin);		
	gets(my_name);
	puts(my_name);

		
}
#endif