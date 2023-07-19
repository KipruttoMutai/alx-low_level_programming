#include<stdio.h>
/**
* main - prints the fibonacci sequence
* starting with 1 and 2 
* return 0 sucess
 */
int main (void)
{
	long int a = 1;
	long int b = 2;
	long int sum = b;

	while(a + b <= 4000000)
	{
	b += a;
	if (b % 2 == 0)
	sum += b;
	a = b - a;
	}	
	printf("%ld\n",sum);
	return 0;
}
