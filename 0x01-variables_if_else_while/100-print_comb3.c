#include<stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a;
	int b;
	for (a = 48; a< 57; a++)
	{
		for (b = a + 1; b <= 57; b++)
		{
			putchar(a);
			putchar(b);
			if ((a+b) != (56 + 57))
			{
				putchar(44);
				putchar(32);
			}
		}
	}
	putchar(10);
	return(0);
}
