#include <stdio.h>

/*
 * main -  prints the n times table, starting with 0.
 * return 0 success
 * */

void print_times_table(int n)
{       
        int i, x, prod;
        if (n == 0)
        {       
                printf("0\n");
        }       
        else if (!(n > 15 || n < 0))
        {       
                for (i = 0; i <= n; i++)
                {
                        for (x = 0; x <= n; x++) // Corrected the loop condition
                        {
                                prod = i * x;
                                if (x == 0) 
                                {       
                                        printf("%d", prod); // Removed the comma before prod
                                }       
                                else
                                {
                                        printf("%4d", prod); // Added width specifier to align columns
                                }
                        }       
                        printf("\n"); // Corrected the newline character
                }       
        }       
}
