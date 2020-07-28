#include <stdio.h>

int main(void)
{
    int n, i, j = 0, k, m;
    printf("How many elements will you use?\n");
    scanf("%d", &n);
    int arr1[n];
    int arr2[n];

    printf("Input %d elements into the array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("arr1 - %d : ", i);
        scanf("%d", &arr1[i]);
        // stores array of how many times a number occurs
        arr2[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        m = 1;

        // Check every element after current element
        for (j = i + 1; j < n; j++)
        {
            if (arr1[i] == arr1[j])
            {
                m++;
                // if more than once then amount = 0 and skipped over during printing
                arr2[j] = 0;
            }
        }
        if (arr2[i]!=0)
        {
            arr2[i] = m;
        }
    }
    printf("The frequency of all elements of an array : \n");
    for (i = 0; i < n; i++)
    {
        if (arr2[i] != 0)
        {
            printf("%d occurs %d times\n", arr1[i], arr2[i]);
        }
    }
}