#include"main.h"
/**
 * flip_bits - Counts the number of bits needed to flip to get from n to m.
 * @n: The first unsigned long integer.
 * @m: The second unsigned long integer.
 * Return: The number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
