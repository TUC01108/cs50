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
            if(array1[k]>=array1[k+1])
            {
                temp=array1[k+1];
                array1[k+1]=array1[k];
                array1[k]=temp;
            }
        }
    }
    // Prints the sorted array
    printf("\nThe array in ascending order is :\n");
    for(i=0; i<n; i++)
    {
        printf("%d   ", array1[i]);
    }
    printf("\n");
    // Check to see if there are dupicate elements in first array
    for(i=0;i<n; i++)
    {
    count = 1;

    // Check duplicate before the current position and
	// increase counter by 1 if found.
		for(j=0;j<i;j++)
		{
			if(array1[i]==array1[j])
			{
			count++;
			}
		}
		for(k=i+1;k<n;k++)
		{
		  if(array1[i]==array1[k])
		  {
		    count++;
		  }
		}
		for(m=0;m<1;m++)
		{

    	    printf("%d occurs %d times\n",array1[i], count);

		}
    }

    printf("\n");
}