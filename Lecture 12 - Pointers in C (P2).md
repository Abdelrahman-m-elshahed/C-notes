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

[[Lecture 12.c]]
