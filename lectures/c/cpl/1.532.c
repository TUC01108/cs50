#include <stdio.h>

// program to replace string of one or more blanks by a single blank
int main()
{
    int c, b;

    b = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (b == 0)
            {
                b = 1;
                putchar(c);
            }
        }
        if (c != ' ')
        {
            b = 0;
            putchar(c);
        }
    }
        
    return 0;
}