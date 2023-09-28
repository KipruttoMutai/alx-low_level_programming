#include"main.h"
/**
 * binary_to_uint - converts a binary number to unsigned integer
 * @b: String containing the binary number
 * Return: Converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal_value = 0;

	if (!b)
		return (0);
	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		decimal_value = 2 * decimal_value + (*b - '0');
		b++;
	}

	return (decimal_value);
}

