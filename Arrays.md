Array is a data structure consisted of a number of elements *fixed size*.
the elements should have the same data types , and they are stored in a sequential memory locations.



```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.8 - 21.33pm.drawing",
	"width": 453.296630859375,
	"aspectRatio": 1.7083895852536046
}
```
it helps you when you want to store number of elements in sequential order.

***Definition & declaration***
```c
// Syntax 
type name[size];
//example 
int Arr[100];
```
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.9 - 0.18am.drawing",
	"width": 350,
	"aspectRatio": 0.7972665148063781
}
```

```c
// this way you acces the element and overwrite its value 
Arr[0] = 5; // or any value of the data type
```

indices from 0 to size - 1 *why?*
`Arr[0]` $\equiv$ `*(Arr + 0)`
so to access the first element you need to add nothing to the pointer address, guess what nothing means..........zero 

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.9 - 0.30am.drawing",
	"width": 398,
	"aspectRatio": 0.9683698296836983
}
```
***Type :*** any valid C data type 
***Size :*** integer *const* -> defined before compilation 

***hint***
Size can be a macro 
```c
#define size 5
int Arr[size]; // = int Arr[5]
```
size can't be a variable *because variable are defined at runtime*


***Initialization while declaration***
```c
// Syntax
type name[size] = {/*values (seperated by comma operator)*/};

// example
int arr[5]= {0,1,2,3,4};
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.9 - 0.51am.drawing",
	"width": 390,
	"aspectRatio": 0.9133489461358314
}
```
***hints***
1. what if Number of values between { } $>$ number of elements.
```c
int arr[5] = {0,1,2,3,4,5};
```
some of compilers will return an error, and others will produce a warning and ignore the extra element, and some do nothing.

2. what if  Number of values between { } $<$ number of elements.
```c
int arr[5] = {1};
```
the remaining values will be initialized to zero.
so if you need the initialization of the *local*  array to be zero :
```c
int arr[100] = {0}; // and now all the elements will be zero 
```
3. size is optional if you have initialized the array 
```c
int arr[] = {1,2,3,4,5,6}; // the size of the array will be 6
```
4. designated initialization of array
```c
int arr[10] = {[0] = 1, [3] = 10, [9] = 8};
```
the remaining elements with no initialization will be initialized by zero. 
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.9 - 1.29am.drawing",
	"width": 508,
	"aspectRatio": 0.7827426810477658
}
```
***Accessing array elements :-***
during declaration : you can access all elements at the same statement.
after declaration : element by element : `arr[i]` or `*(arr + i)`
5. sizeof operator with array
```c
sizeOfArray = sizeof(array) / sizeof(element);
```

***Notes***
1. the name of array *considered const pointer* $\equiv$ the address of the first element

| Array name               | Const pointer          |
| ------------------------ | ---------------------- |
| doesn't occupy any space | occupy space in memory |
Array name is considered a const pointer because you can't change the address its pointing to.

---
```c
int x[3] = {0,1,2};
printf("%i",x[50]);
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.9 - 2.32am.drawing",
	"width": 563.393798828125,
	"aspectRatio": 1.1155851724298795
}
```

```c
int (*ptr)[5];
// ptr is a pointer to an arry of five element of type integer

int *ptr[5];
// ptr is an array of five elements pointer to int 

int (*ptr[5])(int); 
// ptr is pointed to an array of five elements pointing to function that takes integer and returns integer 

```



```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.9 - 2.49am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```

step of pointer differ depends on pointee-type :
pointer to array of int 
```c
int (*ptr)[3];
```



```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.9 - 2.52am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
pointer step $=$ (data type size) * (size of the array) 


```c
int Arr[3];
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.11 - 2.52am.drawing",
	"width": 350,
	"aspectRatio": 1.2040961189716846
}
```
Array name is an address to the first location of the array.
```c
printf("%p\n",Arr);
printf("%p\n",Arr + 1);
printf("%p\n",&Arr);
printf("%p\n",&Arr + 1);
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 2.08am.drawing",
	"width": 673.3333740234375,
	"aspectRatio": 3.5295888255061953
}
```
### Array of Pointers 
```c
int *ptr[3];
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 3.29am.drawing",
	"width": 540,
	"aspectRatio": 1.4281485059046137
}
```
***WHY?***
to make it array of pointer to functions.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 3.44am.drawing",
	"width": 466,
	"aspectRatio": 1.224084451063438
}
```
### Passing array as function arguments

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 3.52am.drawing",
	"width": 535,
	"aspectRatio": 1.0845167303826928
}
```
**Hint :** the array size = 
```c
(sizeof(Arr) / sizeof(Arr[0]))
```

***Ex:*** write a function that prints all the elements in an array 
```c  
#include <stdio.h>
#define size 3

void scan(int x[])
{
    for(int i = 0 ; i < size ; ++i)
    {
        scanf("%d",x + i);
    }
    printf("done\n");
}

  

void print(int x[])
{
    for(int i = 0; i < size; ++i)
    {

        printf("%i\n",x[i]);
        // printf("%i\n",*(x + i));
    }
}

int sum(int arr[])
{
	int sum = 0;
	for(int i = 0 ; i < size;++i)
		sum += arr[i];
	return sum;
}

bool search(int arr[], int x)
{
	for(int i = 0 ; i < size ;++i)
	{
		if(arr[i] == x)
			return 1;
	}
	return 0;
}

int main()
{
    int arr[size];
    scan(arr);
    print(arr);
	printf("the sum of the element is %d",sum(arr));
	search(arr,2);
}
```

### Multi-Dimensional Arrays 
Arrays --> # dimensions

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 4.41am.drawing",
	"width": 521.666748046875,
	"aspectRatio": 1.3127991414493525
}
```
***General form of multi-dimensional array :-*** 
```c
type name [size1][size2][sizeN];

// example 2D array
int Arr[2][3];
// rows columns
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 4.46am.drawing",
	"width": 492.666748046875,
	"aspectRatio": 0.8069442464480107
}
```
***Initialization of 2D Array***
```c
int arr[2][3] = {1,2,3,4,5,6}; // first 3 are row 1 and the latter are row 2

int arr[2][3]= {
	{1,2,3},
	[4,5,6}
}; // same thing but way more readable
```
***Notes***
```c
/*
int arr[][] = { 1,2,2,3,3,3}; // incorrect even if initialized 
int arr[2][] = {1,2,3,4,5,6}; // also incorrect
int arr[][3] = {1,2,3,4,5,6}; // correct
*/
```

Name of 2D array is pointer to array, so `arr + 1` will move the pointer to the next row.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 5.10am.drawing",
	"width": 498,
	"aspectRatio": 1.8534542916957433
}
```
***2D array***
```c
/*
array_name -> step = Array
&array_name -> step = 2D Array
*/
```

***Variable length Array:-***

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.12 - 5.29am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```

[[Arrays.c]]