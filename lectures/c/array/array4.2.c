#include <stdio.h>

int main(void)
{
    int n;
    printf("How many elements will you use?\n");
    scanf("%d", &n);
    int element[n];
    int copy[n];
    int i;
    printf("Input %d elements into the array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &element[i]);
        copy[i] = element[i];
    }
    printf("The elements stored in the first array are : ");
    for (i = 0; i < n; i++)
    {
        printf("%2d", element[i]);
    }
    printf("\nThe elements stored in the second array are : ");
    for (i = 0; i < n; i++)
    {
        printf("%2d", copy[i]);
    }
    printf("\n");
}