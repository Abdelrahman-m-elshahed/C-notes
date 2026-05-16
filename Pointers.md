```C
int x = 3;  // 4 byte 
int *ptr = &x; // 4 bytes
x = 4;
*ptr = 4;
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.3.8 - 6.11am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
what if i have made the `ptr` as a char
```C 
char *ptr = &x;
```
it will only access the first byte of `x` 

![[Lecture 11.png]]

subscript Operator [ ]

```c
int x = 257;
short *ptr = &x;
printf("%i",*(ptr+1));  // it will access 0x02
```



```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.5 - 15.09pm.drawing",
	"width": 696.806640625,
	"aspectRatio": 1.8578460876010179
}
```

```c
ptr[i] = *(ptr + 1);
```

## Pointer Types
### 1. Null pointer  
null char -> `\0` and its ASCII is *Zero* = (0000 0000) in binary 

```C
printf("%c", '\0'); // nothing
printf("%i", '\0'); // zero
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.5 - 15.25pm.drawing",
	"width": 496.3485107421875,
	"aspectRatio": 2.131984363859968
}
```
```c
int *ptr = 0;    // <--
int *ptr = Null; // ---|

printf("%i",ptr)   // zero
printf("%p",*ptr) // error -> "it is in the reserved addresses"
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.5 - 15.30pm.drawing",
	"width": 809.6630859375,
	"aspectRatio": 2.459030432946639
}
```

### 2. wild Pointer 
it is a pointer without an initialization, leaving you with undefined behavior if you ever try to access it.

```c
int main()
{
	int *ptr; // Local variable
	printf("%p",ptr); // garbage
	*ptr = 1; 
}
```

**hint***
Operators with pointers  
1. `*ptr++`  the $++$ will be implemented in the **next** line
2. `*++ptr`  the $++$ will be implemented in the **same** line
3. `(*ptr)++` will add $1$ on the value stored in the location `ptr` pointing to 
4. `*ptr + *ptr2` will add the $2$ values, 'cause the precedence of $*$ is higher than $+$

Const with Pointers 
1. value is const (when const is on the left side of dereference operator)
	`int const *ptr &x;` -> const value 
2. Pointer is const (when const is on the right side of dereference operator)
	`int *const ptr = &x;` -> const pointer 

 
 ***pointers with functions (Pass by ref)***
when we pass the argument, we pass a pointer letting you modify the value stored in that specific location.

what if you want the function to return an address 

```c
int * pointer(void)
{
	int x;
	retun &x;
}
```
but `x` in that case is a local variable, so when the functions finishes execution, that location is not reserved for that variable anymore.
letting you with what's know as *dangling pointer*

to avoid that you can use the `static` keyword making it a global variable

### 3. dangling pointer 
it is a pointer pointing to a deallocated/deleted location on memory.

### void pointer 
it's also known as {generic, unknown, General Purpose} pointer.
`void *ptr;` 
void pointers can store memory addresses of any datatype. but how?
using **casting** , it is *mandatory*  when dereferencing or otherwise you'll face syntax error.
```c
int x = 5;
void *ptr;

ptr = &x;
printf("%i",*ptr); // error, you have to cast it as int type (x is int)
printf("%i",*(int*)ptr); // this way, it will work 

ptr++; // (one byte) 
printf("%i",*(int*)ptr); 
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.6 - 2.23am.drawing",
	"width": 478,
	"aspectRatio": 1.040098405950043
}
```
### pointer to function 
it is holding the first location of the function.
giving you the ability to call the function through the pointer.

***declaring a pointer to a function***
```c
retrun_type (*ptr) (argument_type)
```

example :-
```c 
// pointer to the function
void (*ptr) (void);
void (*ptr) (int); 
int (*ptr) (int, int); 

ptr = func_name; // points the pointer to the function 
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.6 - 2.50am.drawing",
	"width": 478.091064453125,
	"aspectRatio": 1.462656623633097
}
```
***Calling***
```c
ptr(x,y); 
x = ptr(x,y);
x = (*ptr)(x,y);
```

and to avoid wild pointers you can assign it to *null*
```c
int (*ptr)(int,int) = null;
```

### Pointer to Pointer 
```C
int x = 5
int *ptr1  = &x;
int **ptr2 = &ptr1;
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.6 - 13.50pm.drawing",
	"width": 475.568359375,
	"aspectRatio": 0.7838943989218237
}
```
```c
const int x = 5; // protected by the software
int *ptr = &x; // will bypass that kind of protection 
```
can we do the same thing with *const pointers*?

```c
int * const ptr1 = &x; // protected by the software
int **ptr2 = &ptr1; // will bypass the protection 
```

#### How to read a complex expression

***Numeration***
You need to know the precedence and its translation. 
and how you read things :
1) from right to left
2) from left to right 

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.8 - 2.02am.drawing",
	"width": 536.5980224609375,
	"aspectRatio": 1.219490972403461
}
```

**Example:**
```c
char (*ptr)[5];
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.8 - 2.11am.drawing",
	"width": 733.6514892578125,
	"aspectRatio": 1.769782899452228
}
```


```c
void (*(*Arr[])())()
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.8 - 3.05am.drawing",
	"width": 770,
	"aspectRatio": 1.455748888486299
}
```

---
***Spiral outwards anti clockwise (SOAC)***
you will go from inside to outside (anti clockwise).

**Example:**
```c
char (*ptr)[5];
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.8 - 2.19am.drawing",
	"width": 417.3109130859375,
	"aspectRatio": 1.8587698833596562
}
```


```c
void (*(*Arr[])())()
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.8 - 2.50am.drawing",
	"width": 824.9822998046875,
	"aspectRatio": 1.6881662648638673
}
```
***Hint***
Pointers is used to read stream of data.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.8 - 3.14am (2).drawing",
	"width": 463.485107421875,
	"aspectRatio": 1.1154139728083197
}
```
[[pointers.c]]
