#include<stdio.h>
#include"function_pointers.h"
/**
 * int_index - Searches for an integer in an array using a comparison function.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 * @cmp: Pointer to the comparison function.
 * Return: Index of the first element for which cmp doesnt return 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

