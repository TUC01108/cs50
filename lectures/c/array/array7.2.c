#include <stdio.h>

void bubbleSort();

int main(void)
{
    int n;
    printf("How many elements will you use in both arrays?\n");
    scanf("%d", &n);
    int arr1[n];
    int arr2[n];
    int arr3[n*2];
    int i;
    printf("Input %d elements into first array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("arr1 - %d : ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Input %d elements into second array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("arr2 - %d : ", i);
        scanf("%d", &arr2[i]);
    }
    int j = 0;
    // Merge into one array
    for (i = (n * 2) - 1, j = 0; i >= 0; i--, j++)
    {
        if (i >= n)
        {
            arr3[i] = arr1[j];
        }
        if (i >= 0 && i < n)
        {
            arr3[i] = arr2[i];
        }
    }
    int temp = 0;
    /*
    // Sort in descending order
    for (i = 0; i < (n * 2) - 1; i++)
    {
        for (j = i + 1; j < n * 2; j++)
        {
            if (arr3[i] < arr3[j])
            {
                temp = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = temp;
            }
        }
    }
    */
    bubbleSort(arr3, n*2);

    // Print sorted array
    for (i = 0; i < n * 2; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}









void bubbleSort(int arr3[], int n)
{
    int i, j, temp = 0;
    // Sort in descending order
    for (i = 0; i < (n) - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr3[i] < arr3[j])
            {
                temp = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = temp;
            }
        }
    }
}