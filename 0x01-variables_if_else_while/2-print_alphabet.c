#include<stdio.h>

/**
 * main - Prints the alphabet.
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	char alphabets = 'a';

	while (alphabets <= 'z')
	{
		putchar(alphabets);
		alphabets++;
	}
	putchar('\n');
	return (0);
}

