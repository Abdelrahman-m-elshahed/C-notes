#include <stdio.h>

#if 0
int main()
{
	int arr[5]={1,2,3,4,5,6};
	printf("%i\n",*(arr+0)); 
	printf("%i\n",arr[0]);
	
	printf("\n%i\n",*(arr+4)); 
	printf("%i\n",arr[4]);
}
#endif 

#if 0
int main()
{
	int arr[20]={[0] = 10,[4] = 90, [11] = 100};
	
	for(int i = 0; i < 20;++i)
		printf("%i\n",arr[i]);
}
#endif 


#if 1
int main()
{
	int arr[20];
	printf("%i bytes\n",sizeof(arr)); // 80 byte
	printf("%i bytes\n",sizeof(arr[0])); // 4 bytes
	printf("%i elements\n",sizeof(arr)/sizeof(arr[0])); // 20 element 
}
#endif 