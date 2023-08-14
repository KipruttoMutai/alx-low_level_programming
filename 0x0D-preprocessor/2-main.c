/**
 * main - Entry point
 * Description:
 * Prints the characters of the current source file name followed by a newline
 * Return: Always 0 (Success)
 */
#include <stdio.h>
int main(void)
{
	const char *filename = __FILE__;

	for (; *filename; filename++)
	{
		putchar(*filename);
	}
	putchar('\n');
	return (0);
}
