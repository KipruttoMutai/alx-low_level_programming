/**
 * main  Prints the first 98 fibonacci numbers
 *
 * Return: Always 0 (success)
 */
#include "main.h"
#include <stdio.h>

/*
 * main -  prints the n times table, starting with 0.
 * return 0 success
 * */

int main(void)
{       int n;
	int i, x, prod;
	if (n == 0)
	{       
		printf("0\n");
	}
	else if (!(n > 15 || n < 0))
	{       
	for (i = 0; i <= n; i++)
	{
		for (x = 0; x <= n; x++)
		{
			prod = i * x;
				if (x == 0) 
				{
					printf("%d", prod);
				}
				else
				{
					printf("%4d", prod);
				}
		}      
			printf("\n");
	}    
	return (0);
}
