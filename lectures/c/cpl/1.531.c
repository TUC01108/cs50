#include <stdio.h>

// program to count blanks, tabs, and newlines in input
int main()
{
    int c, nl, b, t;

    nl = 0, b = 0, t = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++b;
        else if (c == '\t')
            ++t;
    printf("nl- %d, b- %d, t- %d\n", nl, b, t);
}