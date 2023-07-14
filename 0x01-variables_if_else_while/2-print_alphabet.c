#include <stdio.h>

/**
 * main - Prints letters of the alphabet
 *
 * Return: 0 on success
 */
int main(void)
{
    char alphabets = 'a';

    while (alphabets <= 'z')
    {
        putchar(alphabets);
        alphabets++;
    }

    putchar('\n');

    return 0;
}
