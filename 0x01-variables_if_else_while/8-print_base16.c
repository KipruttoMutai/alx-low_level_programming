#include<stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase
 *
 * Return: 0 on success
 */
int main(void)
{
	int number;

	for (number = 0; number < 10; number++)
		putchar('0' + number);
	for (number = 0; number < 6; number++)
		putchar('a' + number);
	putchar('\n');
	return (0);
}

