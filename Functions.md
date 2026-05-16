## Functions 
why did we need functions?
imaging rewriting same code instructions over and over again, what if we could write it once and call it when we need it. 
that is what *functions* do
when you face the calling function to execute its body you would do **switching context/stacking** and when u getting back it is called **switch restore/unstacking**

| Adv            | dis-Adv                                             |
| -------------- | --------------------------------------------------- |
| less code size | execution time is increased **'cause of switching** |
| Organize code  |                                                     |
to make a function u need 3 things :
1. prototype 
2. implementation 
3. function calling 

***1. Prototype*** *declaration*
```c
// syntax 
return_type func_name(argument_list);
```
return_type is what the function return 
	what if the function return nothing then it is called *void*
	***default return_type :***  Int
	if return_type is not specified it returns *garbage value*
arguments
	if there is none then it should be *void*
no prototype
	1. it may generate a warning & implicitly declare the function *(tight possibility)*
	2. it would generate a *compilation error*
multiple definition of the function would cause *error*

***2. function Implementation*** *definition*

```c
// syntax 
return_type func_name(argument_list)
{
	// body
	// return statement 
}
```

return statement 
	returns what the function should return 
	it is only used one in the function 
	if you add some code after it, that code wouldn't work *unreachable code*
You can't implement a function inside another function
	so you can't declare a function inside of `main()` *'cause it is a function, duhh*

you can write the function in 2 ways ;
```
function prototype
main function
function implementation 
or
// define tree
function (definition and declaration)
main function 
```

***3. function calling***
```c
// syntax
func_name(argument_list);
```
the calling happen inside the `main()`

but as we said before `main()` is a function and functions needs to be called....**i didn't call the main()**, how did the program run it? 

it works because there is something else calls the main, and it is *startup code*
startup code operate certain steps and then branch to `main()` 
the name doesn't really matter if i called the function *start* in the startup code then it would branch to *start*

***Function errors :-***
1. didn't write the return 
	- the function returns garbage
2. added a return to a void function 
	- generates a compilation error 
3. return_type func_name (int x , y) 
	- generates compilation error
	- it should be (int x , int y)
4.  if you add `;` in the declaration
	- generates a syntax error

### Passing the arguments 
 1. pass by value 
 2. pass by reference 

```handdrawn-ink
{
	"versionAtEmbed": "0.3.4",
	"filepath": "Ink/Drawing/2026.2.11 - 20.43pm.drawing",
	"width": 500,
	"aspectRatio": 1
}
```
