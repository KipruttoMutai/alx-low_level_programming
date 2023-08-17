#include<stdio.h>
#include<stdarg.h>
#include"variadic_functions.h"
/**
 * sum_them_all - Calculate the sum of variable arguments.
 * @n: The number of arguments.
 * @...: The variable arguments to be summed.
 *
 * Return: The sum of the variable arguments, or 0 if @n is 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i, sum = 0;

	va_start(numbers, n);

	for (i = 0; i < n; i++)
		sum += va_arg(numbers, int);

	va_end(numbers);

	return (sum);
}

