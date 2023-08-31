#include"main.h"
#include<stdio.h>
/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a binary string containing '0' and '1' characters
 * Return: The converted unsigned int.
 * If 'b' is NULL or contains non-binary characters, returns 0.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);
	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);
		result = result * 2 + (*b - '0');
		b++;
	}
	return (result);
}
