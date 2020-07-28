#include <stdio.h>

int addTwo();

int main(void)
{
    int m = 0;
    int n = 0;
    int *j = &m;
    int *k = &n;

    printf("Input the first number : ");
    scanf("%i", &m);
    printf("\nInput the second number : ");
    scanf("%i", &n);
    //int z = *j + *k;
    int z = addTwo(&m, &n);
    printf("\nThe sum of %i and %i is %i\n", m, n, z);
}




int addTwo(int *j, int *k)
{
    int z = *j + *k;
    return z;
}