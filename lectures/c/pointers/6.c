#include <stdio.h>

int isMax();

int main(void)
{
    int m = 0;
    int n = 0;
    int *j = &m;
    int *k = &n;

    printf("Enter first number : ");
    scanf("%i", &m);
    printf("\nEnter second number : ");
    scanf("%i", &n);
    int z = isMax(&m, &n);
    printf("\n%i is the maximum number.\n", z);
}

int isMax(int *j, int *k)
{
    int z = 0;
    if (*j > *k)
    {
        z = *j;
    }
    else
    {
        z = *k;
    }
    return z;
}