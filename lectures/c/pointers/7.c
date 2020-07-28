#include <stdio.h>

int main(void)
{
    int n = 0;

    printf("How many elements will you enter : ");
    scanf("%i", &n);
    int m[n];
    printf("\nEnter %i elements into the array : \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("element %i : ", i);
        scanf("%i", m + i);
    }
    printf("These are the elements you entered : \n");
    for (int i = 0; i < n; i++)
    {
        printf("element %i : %i\n", i, *(m + i));
    }
}