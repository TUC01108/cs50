#include <stdio.h>

int main(void)
{
    int n;
    printf("Input the number of elements to store in array : ");
    scanf("%i", &n);
    int m[n];
    printf("Input %i elements into the array : \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("element %i : ", i);
        scanf("%i", &m[i]);
    }
    printf("The elements you entered are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("element - %i : %i\n", i, *(m + i));
    }
}