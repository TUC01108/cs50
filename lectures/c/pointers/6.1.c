#include <stdio.h>

int isMax();

int main(void)
{
    int m;
    int n;
    int *p1 = &m;
    int *p2 = &n;
    printf("Enter first number : ");
    scanf("%i", &m);
    printf("Enter second number : ");
    scanf("%i", &n);
    int x = isMax(*p1, *p2);
    printf("\n%i is the max number\n", x);
}

int isMax(int p1, int p2)
{
    int z = 0;
    if (p1 > p2)
    {
        z = p1;
    }
    else
    {
        z = p2;
    }
    return z;
}