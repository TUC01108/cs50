#include <stdio.h>

int main(void)
{
    int i;
    int n;

    printf("How many values will you store in array?\n");
    scanf("%d", &n);

    int element[n];

    printf("Input %d elements into the array : \n", n);

    for (i = 0; i < n; i++)
    {
    printf("element - %d : ", i);
    scanf("%d", &element[i]);
    }

    printf("The values stored in the array are : \n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", element[i]);
    }

    printf("\n");

    printf("The values stored in the array in reverse are : \n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", element[i]);
    }

    printf("\n");
}