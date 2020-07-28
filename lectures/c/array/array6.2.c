#include <stdio.h>

int main(void)
{
    int n;
    printf("How many elements will you use?\n");
    scanf("%d", &n);
    int element[n];
    int i;
    printf("Input %d elements into the array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &element[i]);
    }
    int j, k, count = 0;
    // Check before the current element and check after
    printf("Total number of unique elements found in the array is : \n");
    for (i = 0; i < n; i++)
    {
        int m = 0;
        // Check every element before current element
        for (j = 0; j < i; j++)
        {
            if (element[i] == element[j])
            {
                m++;
            }
        }
        // Check every element after current element
        for (k = i + 1; k < n; k++)
        {
            if (element[i] == element[k])
            {
                m++;
            }
        }
        if (m == 0)
        {
            count ++;
            printf("element[%d]- : %d\n", i, element[i]);
        }
    }
    printf("\nUnique number count- %2d\n", count);
}