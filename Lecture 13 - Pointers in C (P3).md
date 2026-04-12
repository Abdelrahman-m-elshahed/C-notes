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
[[Lecture 13.c]]