#include <stdio.h>

int main(void)
{
    int n, k, i, temp, j, count, m;

    printf("Enter the amount of elements to be stored in the array : \n");
    scanf("%d", &n);

    int array1[n];

    printf("Enter %d elements in array : \n", n);
    for(i=0;i<n;i++)
    {
        printf("element %d - ", i);
        scanf("%d", &array1[i]);
    }

    // print the elements sorted
    for(i=0;i<n;i++)
    {
        for(k=0;k<n-1;k++)
        {
            if(array1[k]<=array1[k+1])
            {
                temp=array1[k+1];
                array1[k+1]=array1[k];
                array1[k]=temp;
            }
        }
    }
    // Prints the sorted array
    printf("\nThe array maximum is : ");
    printf("%d   ", array1[0]);

    printf("\n");

    printf("\nThe array minimum is : ");
    printf("%d   ", array1[n-1]);


    printf("\n");
}