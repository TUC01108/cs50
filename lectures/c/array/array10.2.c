#include <stdio.h>

int main(void)
{
    int n;
    printf("How many elements will you use in the array?\n");
    scanf("%d", &n);
    int arr1[n];
    int arr2[n];
    int arr3[n];
    int i, m = 0, j = 0;
    printf("Input %d elements into the array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("arr1 - %d : ", i);
        scanf("%d", &arr1[i]);
    }

    for (i = 0; i < n; i ++)
    {
        if (arr1[i] % 2 == 0)
        {
            arr2[m] = arr1[i];
            m++;
        }
        else
        {
            arr3[j] = arr1[i];
            j++;
        }
    }

    printf("The Even elements are : \n");
    for (i = 0; i < m; i++)
    {
        printf("%d ", arr2[i]);
    }

    printf("\nThe Odd elements are : \n");
    for (i = 0; i < j; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}