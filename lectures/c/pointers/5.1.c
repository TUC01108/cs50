#include <stdio.h>

int addNums();

int main(void)
{
    int m;
    int n;
    int *p1 = &m;
    int *p2 = &n;
    printf("Input first number : ");
    scanf("%i", &m);
    printf("Input second numnber : ");
    scanf("%i", &n);
    int x = addNums(*p1, *p2);
    printf("\nThe sum of %i and %i is %i\n", m, n, x);
}

int addNums(w1, w2)
{
    int z = w1 + w2;
    return z;
}