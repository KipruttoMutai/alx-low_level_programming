#include<stdio.h>

/**
 * main - Prints letters of the alphabet in reverse
 *
 * Return: 0 on success
 */
int main(void)
{
	char alphabet = 'z';

	while (alphabet >= 'a')
	{
		putchar(alphabet);
		alphabet--;
	}
	putchar('\n');
	return (0);
}
