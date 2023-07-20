#include<stdio.h>
#include"main.h"

/*
 * Main -entry point
 * Description:checks for uppercase character
 * Return - 0 alwas success
 * */

int _isupper(int c)
{
	if (c >= 'A' &&  c <= 'Z')
		return 1;
	else
		return 0;
}
