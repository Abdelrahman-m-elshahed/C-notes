
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.5 - 1.19am.drawing",
	"width": 488,
	"aspectRatio": 1.1019429147131798
}
```
all of those commands are understood by Preprocessor. *text replacement to directives*

## 1.`#include` 
it is used to include header files (.h)
1. `#include <file.h>` => used with standard libraries *built-in libraries*.
2. `#include "file.h/path"` => used with current directory or path , and then standard libraries.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.5 - 1.31am.drawing",
	"width": 520,
	"aspectRatio": 0.912343225275855
}
```
## 2.`#define` "macro"
1. object-like macro 
2. function-like macro 
```c
// syntax 1
#define identifier replacment_list

// syntax 2
#define identifier(parameters) replacment_list

// syntax 3
#define identifier() replacment_list

// syntax 4
#define identifier(parameters,...) replacment_list
```
### Object-like macro 
`#define name value`
`#define X 10` 
- the preprocessor will replace any 'x' with 10
- *It is recommended to write macro names in uppercase.*
```c
#define X 10

int y = X; 
// after preprocessing 
int y = 10;
// ---------------------------------------------------------------
int X = 50; 
// after preprocessing 
int 10 = 50; // compilation error

printf("X"); // it won't be expanded (preprocessor won't replace its value)
```

```c
#define Z 10
#define X Z 

int Y = X;
// int Y = Z;
// int Y = 10;
```
***Notes***
```c
#deifne x 10 
#deifne x 20 
```
it will generate a warning. *redefinition*.

```c
#deifne x 10 
int y = x+10; // x will be replaced by 10
#deifne x 20  // redefinition 
int z = x; // x will be replaced by 20
```

to avoid the warning you can use `undef`
```c
#deifne x 10 
int y = x+10; // x will be replaced by 10

#undef x
#deifne x 20  // redefinition 
int z = x; // x will be replaced by 20
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.6 - 4.10am.drawing",
	"width": 500.3333740234375,
	"aspectRatio": 1.405934847673821
}
```


| `#define`                               | `Enum`                                |
| --------------------------------------- | ------------------------------------- |
| text replacement at preprocessing stage | text replacement at compilation stage |
| we can use float, sentences,...         | only const integers allowed           |
| doesn't occupy any memory space         | occupy integer size = 4bytes          |
| can't be used inside a switch           | can be used inside a switch           |

| `typedef`                                                          | `#define`                                  |
| ------------------------------------------------------------------ | ------------------------------------------ |
| accomplished by the compiler                                       | accomplished by the preprocessor           |
| it is used with data types <br>Ex: instead of using `char` => `u8` | used with values & data types              |
| ***Syntax :***`typedef structstud ptr;`                            | ***Syntax :***`#define ptr struct_student` |

### Function-like macro *parameterized macro*
```c
#define Add(X,Y) X+Y
int z = Add(X,Y);
// after preprocessing 
int z = X + Y;
```
`Add(X,Y)` there is no space between `Add` and `X+Y`
```c
#define Add (x,y) x+y
int z = add(3,4);
// after preprocessing
int z = (x,y) x+y (3,4);
```
_**Concatenation operator**_ is `\` (_backslash_). It is used to write a macro across multiple lines.
```c
#define x \
5
// it is equivilant to #define x 5
```

***Adv of Function-like Macro***
1. Faster than functions 
***dis-Adv***
2. code size is bigger than normal functions 
3. No type checking *it won't check the return type*
4. difficult to debug 

when to use function-like macro?
5. it won't be used frequently *to mitigate code size problem* 
6. speed is super important to you
```c
#define set(x) (Reg | (1<< x))
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.10 - 12.24pm.drawing",
	"width": 511.0025634765625,
	"aspectRatio": 2.2754680161767262
}
```
```c
#define Reaper(...) printf(__VA_ARGS__)
```

```c
#define Reaper(a,...) printf(__VA_ARGS__,a)

Reaper(10,"x = %d");
```

***Pre-defined macros :*** are a built-in macros, you can use with your code.

## 3. `Conditional Directives`
```c
#if /*condition*/
#elif /*condition*/
#else /*condition*/
#endif /*used to end the if condition*/
```
this comparison happens in preprocessing stage so only the met condition is passed to the compiler.

| `if`             | `#if`                                                                              |
| ---------------- | ---------------------------------------------------------------------------------- |
| Compiler         | Preprocessor                                                                       |
| checks variables | it checks Macros and not variables *'cause variables value is assigned in runtime* |
**Usage***
1. *Comment :* 
```c
#if 0
// commands
#endif
```
2. *Configurations for drivers*
---
```c
#ifdef /*if you have defined this macro*/
#ifndef /*if you haven't defined this macro*/
``` 

```c
// example
#define

#ifdef x
	/*some code*/
#else 
	/*some code*/
#endif
```
***Usage in Embedded System***
1. *Header file guard :* it protects header files from re-definition ***added in the header file itself***.
---
```c
#if defined
#elif defined
```

```c
#if (defined X) && (defined Y)
/*code*/
#endif
```

## 4. `#error & #warning`

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.11 - 3.14am.drawing",
	"width": 501.6666259765625,
	"aspectRatio": 1.3851518230145554
}
```
it is used with `#if` but can't be used with normal `if condition`, 'Cause `if condition` is checked at runtime.

```c
#if /*condition*/
#error /*error message*/
```
```c
// incorrect

if /*condition*/
#error /*error message*/
// the error is genertaed wether the if condition is not met 
```

## 5. `Stringification & Concatination`
***1. Stringification => #***
```c
// example
#define printf(x) printf(#x)

printf(Reaper); 
// after preprocessing
printf("Reaper");
```

***2. Concatenation  => ##***
```c
// example
#define conc(x,y) x##y

int x = conc(3,8);
// after preprocessing
int x = 38;
```
***Common mistake***
```c
#include <stido.h>
#define MAX(a,b) a>b?a:b

int main()
{
	int x = 9, y = 7,z;
	z = MAX(x,y)*2;
	printf("%d",z);
}
```
you think the output would be : 18, but it will be 9.
that is because of operator precedence. 
turning : `z = x>y?x:y * 2` into `z = x = 9`
to avoid this problem, use `()`
```c
#include <stido.h>
#define MAX(a,b) (a>b?a:b)

int main()
{
	int x = 9, y = 7,z;
	z = MAX(x,y)*2;
	printf("%d",z);
}
```

## Usage of Preprocessor Directives
1. Configurability 
```c
// Example
#define SIZE 256
char arr[SIZE]; 
```
so now, if i need to change the size i would just change `SIZE`.
2. Readability 
3. Portability 
```c
// usually we use typedef
typedef unsigned char u8;

// or
#define u8 unsgigned char
// it won't work when declaring 2 pointer in the same line
```

***`#line`***
```c
#line 20 
/*code line*/ // this line would be seen as line 20
```

## `#pragma` 
it is considered a *compiler directive*, 'cause compiler is the one understand it and not the preprocessor.

***Usage***
1. `#pragma optimize ("",off)` => no optimization 
2.  `#pragma once` => it's used to define the file once <*file guard replacement*>.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.11 - 17.13pm.drawing",
	"width": 660,
	"aspectRatio": 1.9576703819492502
}
```
3. `#pragma startup function [priority]`
4. `#pragma Exit function [priority]`
priority is optional and it is an integer number in between $[64:255]$

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.5.11 - 17.52pm.drawing",
	"width": 485,
	"aspectRatio": 1.5743692658164747
}
```

C libraries priority is in between $[0:63]$
*default priority :* $100$
```c
void india();
void usa();
#pragma startup india 105
#pragma startup usa /*100*/ // higher priority than 105
#pragma exot india 105 // higher priority than 100
#pragma exot usa /*100*/

void main()
{
	printf("\nmain");
}
void india()
{
	printf("n\nindia");
}
void usa()
{
	printf("n\usa");
}
```
5. used to add memory section => `#pragma region name = "" origin =0x- size=0x-`
6. 