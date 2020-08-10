#include <stdio.h>

// write a program replacing each tab by \t, backspace by \b, and backslash by '\\'
int main()
{
    int c, d;

    while ((c = getchar()) != EOF)
    {
        d = 0;
        if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
            d = 1;
        }
        if (c =='\b')
        {
            putchar('\\');
            putchar('b');
            d = 1;
        }
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
            d = 1;
        }
        if (d == 0)
            putchar(c);
    }
    return 0;
}