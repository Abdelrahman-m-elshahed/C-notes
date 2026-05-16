Strings doesn't exist in C language, so the solution is to make an *array of characters (1D)* and terminated by null char `\0`.
***Declaration & initialization***
```c
// 1
char String[] = {'H','e','l','l','o','\0'};

// 2
char string[] = "Hello"; // will add the '\0' automatically 
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.14 - 3.39am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
`%s` is used for reading and writing strings.
1. ***Write***
```c
// 1
printf("%s",string);

// 2
for(int i = 0 ; i < sizeof(string) && string[i] != '\0';++i)
{
	printf("%c",string[i]);
}

// 3
int i = 0;
while(string[i] != 0)
{
	printf("%c",string[i]);
	++i;
}
```

2. ***Read***
```c
scanf("%s",string);

// in case you want to limit the input width in scanf by specifying a filed width:
scanf("%ns",string) // where n is the MAXIMUM field width 
```

***Hint***
1) `sizeof()` returns the number of characters/bytes in the string *Null char included*.
2) string letters are saved in .rodata segment, when you do something like 
	```c
	printf("%s","hello"); // "hello" is saved in .rodata
	// and the nmae is an address to the word in the .rodata 
	```

```c
#include <stdio.h>

int main()
{
	printf("%c",'a'); // will print the char
	printf("%i",'a'); // will print the char's ASCII value
	printf("%i","a"); // will print its address -> saved in .rodata
	
	printf("%i","hello"); // will print its address -> saved in .rodata
	printf("%c", *("hello")); // will print the first char
	printf("%i", *("hello")); // will print the ASCII of the first char
}
```

***Pointers to string***
```c
char *ptr;

ptr = "hello"; 
```


```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 2.13am.drawing",
	"width": 494,
	"aspectRatio": 1.790044884396333
}
```
which means, you are not allowed to modify the text.

```c
#include <stdio.h>

int main()
{
	char* ptr; // this pointer will read 1 char
	ptr = "hello"; // "hello" will return the address in .rodata
	printf("%c\n",*(ptr + 2)) // will print the third char -> l
	*(ptr + 2) = 'k'; // runtime error 

```

***Scan string***
```c
char string[30];
scanf("%s",string); 
```
it Reads characters until you press Enter, but there is a problem which is Space.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 3.33am.drawing",
	"width": 461.659423828125,
	"aspectRatio": 1.1307380580642115
}
```
***Solution***
use `gets` instead of  `scanf`
```c
gets(string);  
```
the parameter is a pointer

Another problem arises:
```c
int x;
scanf("%i",&x);
gets(string) 
```     
`gets()` skips reading because '\n' (from pressing Enter after `scanf()`
is still left in the input buffer.
Solution: use `fflush(stdin)` to clear the buffer before gets().
```c
int x;
scanf("%i",&x);
fflush(stdin);
gets(string);
```
 ---
and instead of `printfs` you can use `puts` 
```c
puts(string);  
```
the parameter is a pointer to a const char, *why?*
'cause you don't need to modify the data but print it.

### Some functions in string library 
```c
#include <string.h>
```

1. `strcpy(destination,source)`  -> it is used to copy a string form an array to another.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 5.30am.drawing",
	"width": 501.82568359375,
	"aspectRatio": 1.087314669680993
}
```

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 5.35am.drawing",
	"width": 765.8258056640625,
	"aspectRatio": 1.162643776200462
}
```
```c
void cp(char * des, char * scr)
{
	int i = 0;
	while(true)
	{
		if(scr[i] == '\0')
		{
			des[i] = scr[i];
			return;
		}
		des[i] = scr[i];
		++i;
	}
}
```

***Notice*** `strcpy("ahmed",arr);` will cause an error, because you are trying to modify a string stored in .rodata

2. `strlen()` -> it counts the number of characters in the string.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 5.49am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```

```c
int len(char* ptr)
{
	int count = 0;
	for(int i = 0 ; ptr[i] != '\0';++i)
		count ++;
		
	return count;
}
```
 
 3. `strcat(destination,source)` -> it is used to concatenate 2 strings.
```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 5.57am.drawing",
	"width": 489.0455322265625,
	"aspectRatio": 1.0922317487894322
}
```
you can't concatenate somethings stored on .rodata *read only*

```c
void con(char* des,char* soc)
{
	int i = 0;
	while(des[i] != '\0') ++i;
	int j =0;
	while(true)
	{
		if(soc[j] == '\0')
		{
			des[i] =soc[j];
			return;
		}
		des[i] = soc[j];
		++j;
		++i;
	}
}
```

4. `strcmp(first,second);` -> it is used to compare two strings.

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 6.26am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
`strcmp()` -> is case-sensitive.

use `stricmp()` for case-insensitive comparison.

5. `strchr()` -> is used to search for the first occurrence of a char. *returns a pointer to the char*
6. `strrchr()` -> is used to search for the last occurrence of a char. *returns a pointer to the char*
7. `strlwr()` -> flips all the character of the string to *Lower case*
8. `strupr()` -> flips all the character of the string to *Upper case*

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.4.15 - 6.44am.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
[[Strings.c]]