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