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

[[Lecture 15.c]]