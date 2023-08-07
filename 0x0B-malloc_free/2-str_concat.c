#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * str_concat - returns concatenated string
 * @s1: first string
 * @s2: second string
 * Return: Null on failure
 */
char *str_concat(char *s1, char *s2)
{
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	size_t len_s1 = strlen(s1);
	size_t len_s2 = strlen(s2);
	size_t total_length = len_s1 + len_s2 + 1;
	char *s3 = (char *)malloc(total_length);

	if (s3 == NULL)
	{
		return (NULL);
	}
	strcpy(s3, s1);
	strcat(s3, s2);
	return (s3);
}
