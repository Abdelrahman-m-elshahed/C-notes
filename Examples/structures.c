#include <stdio.h>
#pragma pack (1)

// struct 
#if 0
struct st
{
    char id;
    int salary;
}x,y;

int main()
{
    struct st z;
    x.id= 1;
    y.id= 2;
    z.id= 3; // compilation error 

    printf("%p\n",&(x.id));
    printf("%p\n",&(x));
}
#endif

#if 0
struct S_Data
{
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
}MY_Struct;

void Printf_Mem_Range(char*base,int size)
{
    for(int i = 0; i < size;i++)
    {
        printf("%p \t %x \n",base,*(unsigned char*)base); 
        base++;
    }
}

int main()
{
    MY_Struct.data1=0x10;
    MY_Struct.data2=0xffff0000;
    MY_Struct.data3=0x11;
    MY_Struct.data4=0xabcd;
    Printf_Mem_Range((char*)&MY_Struct,sizeof(MY_Struct));// we will pass a char pointer pointing to MY_Struct

    printf("-----------------------------\n");

    struct S_Data *ptr = &MY_Struct;
    
    printf("%x \n", MY_Struct.data1);
    printf("%x \n", (*ptr).data1);
    printf("%x \n", ptr->data1);

}
#endif

#if 0
struct bus 
{
    int z;
    S_bus *ptr;
}S_bus;

int main()
{

}
#endif 

// bit field 
#if 0
struct byte
{
	int one : 1;
};

struct byte var = {1};

int main()
{
	printf("%d",var.one); // 1 or 0 depending on the machine
}
#endif

#if 0
int main()
{
    struct val 
    {
        int bit1:1;
        int bit2:4;
        int bit3:4;
    }BIT={1,2,13};

    printf("%d , %d , %d\n",BIT.bit1,BIT.bit2,BIT.bit3);

}
#endif

#if 0
struct Val
{
    unsigned char x : 3;
    unsigned char y : 6;
    unsigned char z : 3;
}VAL;

void main()
{
    printf("%d\n",sizeof(VAL));
}

#endif

// union 
#if 1
union test
{
    int container;
    char partition;
};

int main()
{
    union test first;
    first.container = 4;
    first.partition = 'c';
    printf("%p \n",first.container);
    printf("%p \n",first.partition);
}
#endif 