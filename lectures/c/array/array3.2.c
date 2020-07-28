#include <stdio.h>

int main(void)
{
    int n;
    printf("How many elements will you use?\n");
    scanf("%d", &n);
    int element[n];
    int sum = 0;
    int i;
    printf("Input %d elements into the array.\n", n);
    for (i = 0; i < 3; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &element[i]);
        sum += element[i];
    }
    printf("Sum of all elements stored in the array is : %d\n", sum);
}