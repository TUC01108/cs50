#include <stdio.h>

int main(void)
{
    int n;
    printf("How many elements will you use in the array?\n");
    scanf("%d", &n);
    int arr1[n];
    int arr3[n];
    int i, j;
    printf("Input %d elements into the array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("arr1 - %d : ", i);
        scanf("%d", &arr1[i]);
    }

    int temp = 0;
    // Sort in descending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr1[i] < arr1[j])
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }

    // Print Max and Min
    printf("Maximum element is : %d\n", arr1[0]);
    printf("Minimum element is : %d\n", arr1[(n - 1)]);
}