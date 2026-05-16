it is a user defined data type *complex data type*, it is made of different variables of **heterogeneous** data types.

why do we need them? 
	it helps us group multiple of data types into **one** variable.
	
```C
// syntax
struct struct_name
{
	// member_1_type member_1_name;
};

struct Semployee // adding an S before the name is recommeneded for readability 
{
	char ID;
	int salary;
};
```
Now, you have created a new data type but, it is not taking any space.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.27 - 20.45pm.drawing",
	"width": 500,
	"aspectRatio": 1
}
```

```C
struct Semployee Ahmed;
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.27 - 20.46pm.drawing",
	"width": 470.4989013671875,
	"aspectRatio": 1.1445909377410501
}
```

```c
// initilization while declaration 
struct Semployee Ahmed = {1,10000};
```

```c
// creating an object while declaring the struct 
struct Semployee
{
	char ID;
	int Salary;
} ahmed;
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.27 - 21.21pm.drawing",
	"width": 439.8148193359375,
	"aspectRatio": 1.24801149166096
}
```



```
Struct member can be named after struct name

Struct member can be named after variable name 

Struct name can be named after variable name
```

## Accessing structure elements
we access the structure element by using the dot operator (.)
```c
ahmed.salary = 100000;
```
we need the structure object name and member name.

You can access all elements at the same time only during *definition time*;
otherwise, they are accessed one bye one.

***Operation***
1. $=$ : it is used to assign content of a structure into another.
2. `&`: it is used to obtain the address of the structure.
3. `sizeof()`: it is used to obtain the size of the structure.

***Notes***
```c
 // it is incorrect, the addresses would be comapred not the content
if(ali == Ahmed) 
{
}

ali += 20; // incorrect
int x = ali + Ahmed; // incorrect
```

when initializing one element in the structure, the remaining elements is initialized to zero.

if you have created a structure without structure name, you would only be able to create an object of type struct is when creating it.

```c
struct 
{
	char id;
	int salary;
}x,y; // x and y is instantiated 

int main()
{
	struct z; // 
	x.id = 1;
	y.id = 2;
	z.id = 2; // compilation error
}
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.28 - 0.19am.drawing",
	"width": 353.333251953125,
	"aspectRatio": 0.8091842289495995
}
```
***Structures with functions***
you can pass the structure as an argument *by reference or by value*.

passing by value => takes lots of time, memory.

***Structures with arrays***
1. array is a member inside the structures.
```c
// accessing a memmber in an array inside a Structure
f.z[i];
/*
f => Structure
z => array
i => index (element) in the array
*/
```
2. array of Structure
```c
struct car
{
	int x;
	short y;
};

void main()
{
	struct car Arr[3];
}
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.28 - 0.52am.drawing",
	"width": 460,
	"aspectRatio": 1.1773174438134848
}
```
***pointers to Structure***
you can create a pointer points to the structure and access its element using the pointer.

```c
struct data * ptr= &my_struct;
// now we have created a pointer of type struct data points to the address of my_struct

```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.28 - 1.01am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```

you can use ***Pointers*** to print bytes and that applies to pointers to structures too.
```c
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
}
```

***Notes***
1. functions takes and returns structure. and *it can take a pointer to struct (by reference)* 
2. you can have a pointer to structure as member in that structure
```c
struct bus
{
	int z;
	struct bus *ptr; // pointer of type bus   
};

// incorrect
struct bus
{
	int z;
	S_bus *ptr; // pointer of type bus   
}S_bus; 
```

3. you can't have an object of struct as member of that struct. But, you can have an object of struct as a member in another. *Nested struct*

## Nested Structure definition

![[Pasted image 20260502174154.png]]

***Notes***
- Ordering is important. 
- accessing members of the nested struct will be done by using multiple of dot operators.
- initializing members of the nested struct will be done by using multiple of curly brackets.

***Typedef with struct***
```c
struct my_struct 
{
	// members
};
typedef struct my_struct employee;

// or
typedef struct my_struct
{
	// members
}employee;
```
now you can use "employee" to instantiate objects of struct type

## Bit field
Status/flag register 
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.2 - 18.06pm.drawing",
	"width": 492,
	"aspectRatio": 1.399197272608451
}
```
1. `if((Reg &(1 << 7 /*bit number*/)) >> 7)` => may cause logical errors *ex: selecting incorrect bit*
2. bit field =>we will make the struct represents a register while its members represents bits

***General form:*** type name : length ; 

```c
// ex
struct status_type 
{
	unsigned char bit_0 : 1;
	unsigned char bit_1 : 1;
	unsigned char bit_2 : 1;
	unsigned char bit_3 : 1;
	unsigned char bit_4 : 1;
	unsigned char bit_5 : 1;
	unsigned char bit_6 : 1;
	unsigned char bit_7 : 1;
}status;

// code
status = get_port(); // assign the value returned by get_port to status
if(status.bit_0)
{
	// commands 
}
```
***Rules***
1. you will access 1 bit, but it's stored as 1 byte *at least*
2. 1 bit doesn't have an address *because the least amount of memory that has address is a byte* so you can't use a pointer.
3. reserved bits are unused bits but reserved for future use.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.3 - 2.27am.drawing",
	"width": 750,
	"aspectRatio": 0.9661673936903326
}
```

***Tricky Codes***
 ```c
 struct emp
 {
	 float pay; // 4 bytes
	 // all three would be an int  
	 unsigned lay_off: 1; 
	 unsigned houring: 1;
	 unsigned deduction: 1; 
 }
 ```

size = 4 + 4 = 8

**Hint**
- Bit fields can't be arrayed 
- Bit fields depend on machine *big Endian or little Endian* 

```c
struct byte
{
	int one : 1;
};

struct byte var = {1};

int main()
{
	printf("%d",var.one); 
}
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.3 - 3.13am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```

## Aligned & Un-Aligned data access 
```c
struct data
{
	unsigned char d1;
	unsigned int d2;
} x;
// the size of x is supposed to be 5 bytes, but that is incorrect. 
// it is 8 bytes  
```

![[Pasted image 20260503180627.png]]

![[Pasted image 20260503184113.png]]

**that is what causes structure padding.** but , what if i care about memory over time.
you would need to use ***packing***.
```c
#pragma pack (1)
```

another way to solve padding problem is by ordering struct members from largest to smallest. 

## Enum 
it is user defined data type.
```c
// example
enum flag {const1, const2,...,constN};
// this means const1 = 0 , const2 = 1, .....
```
***by default :***  it starts by zero. but, you can change it. 
it helps you to write a readable code

```c
enum boolean 
{
	false,
	true
}check;

//ex
if(check == true) // increases readability 
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.4 - 16.02pm.drawing",
	"width": 646,
	"aspectRatio": 1.3842393971584943
}
```


***Tricky Code***
```c
enum week
{
	sat = 0, sun = 1,mon = 4 , wed, thu = -1 , friday
};
// wed = 5 , friday = 2
```
it will be assigned with the "previous value" + 1, if it is reserved => increase 1 

---
**All Enum constants must be unique in their scope.** 
```c
enum state {working,failed};
enum result {failed,passed};
```
it will throw an error, 'cause it has common constants.

---
size of Enum => const int = 4bytes 
```c
enum stat {working = 1 000 000 000 000, failed = 0};
```
it will occupy 8 bytes instead of 4 bytes, 'cause  one value exceeds the 4-byte limit. 
## Union 
it is a user defined data type. supports different overlapped data types.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.5 - 0.17am.drawing",
	"width": 630,
	"aspectRatio": 1.4052862152634162
}
```

```c
// example
union Unum_value
{
	int int_value;
	float float_value;
	double double_value;
};
// new data type is defined "doesn't occupy any space yet"
```
when reading from union, you can only read from one member at a time. 
and when storing data in a member it overwrites the common bytes.

[[structures.c]]