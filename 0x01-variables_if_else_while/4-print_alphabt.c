#include<stdio.h>

/**
 * main - Prints letters of the alphabet (except 'q' and 'e')
 *
 * Return: 0 on success
 */
int main(void)
{
	char alphabet = 'a';
	while (alphabet <= 'z')

	{
		if (alphabet != 'q' && alphabet != 'e')
			putchar(alphabet);
		alphabet++;
	}
	putchar('\n');
	return (0);
}


