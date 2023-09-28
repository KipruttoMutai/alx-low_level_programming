#include "main.h"
/**
 * get_endianness - checks if the machine is little or big endian
 * Return: 0 for big endian, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int number = 1;
	char *byte = (char *)&number;

	if (*byte == 1)
	{		return (1);
	}
	return (0);
}
