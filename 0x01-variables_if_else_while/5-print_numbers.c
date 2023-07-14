#include<stdio.h>

/**
 * main - Prints all numbers of base 10
 *
 * Return: 0 on success
 */

int main(void)
{
	int i = 0;

	while (i < 10)
	{
		printf("%u\n", i);
		i++;
	}
	putchar('\n');
	return (0);
}
