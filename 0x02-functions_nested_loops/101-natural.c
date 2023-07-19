#include <stdio.h>
/*
 * main - entry point
 * Description:Prints the sum of all multiples of 3 and 5
 * Return : 0 - Success
 */

int main (void)
{
	int i;
	int sum;

	for (i = 0,sum = 0; i < 1024; i++)
		if (i % 3 == 0 || i % 5 == 0)
			sum += 1;
	printf("%d\n", sum);
	return (0);
}
