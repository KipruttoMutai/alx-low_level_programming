#include<stdio.h>

/**
*Main prints letters of the alphabet
*returns 0 if it is a success
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

