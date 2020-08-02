#include <stdio.h>
#include <cs50.h>

int get_range_int(string prompt);

int main(void)
{
    int rows = get_range_int("Height: "); // Call get_range_int function
    int i, j, dots, k;
    dots = rows - 1;
    for (i = 1; i <= rows; i++)
    {
        for (k = dots; k >= 1; k--)
        {
            printf(" "); // Print a space while k is greater than 0
        }
        for (j = 1; j <= i; j++)
        {
            printf("#"); // Print a hash while j is less than or equal to i
        }
        for (int m = 0; m < 2; m++)
        {
            printf(" "); // Print a space while k is greater than 0
        }
        for (int l = 1; l < j; l++)
        {
            printf("#");
        }
        printf("\n"); // Print a newline when j > i
        dots--;
    }

}

// Prompt user for positive integer between 1 to 8, inclusive
int get_range_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt); // Prompt user for int
    }
    while (n < 1 || n > 8); // Repeat loop unless n is between 1 to 8, inclusive
    return n;
}
