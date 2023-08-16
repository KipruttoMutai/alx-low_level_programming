#include<stdio.h>
#include"function_pointers.h"
/**
 * print_name - Prints a name character by character using a function pointer.
 * @name: The name to be printed.
 * @f: Function pointer to a func that takes a char argument and returns void.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;


	f(name);
}
