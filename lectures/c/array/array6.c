#include <stdio.h>
#include <cs50.h>

int total(int n, int array[]);

int main(void)
{
  int i,j, k;
  int n, mm=1,count=0;
  int arr1[100];

  printf("Enter how many values you will enter :\n");
  scanf("%d", &n);

  printf("Enter %d elements in array :\n", n);
  for(i=0;i<n;i++)
  {
    printf("arr1 - %d : ",i);
    scanf("%d", &arr1[i]);
  }

  // Check to see if there are duplicate elements in array
  for(i=0;i<n; i++)
  {
    count = 0;

        // Check duplicate before the current position and
		// increase counter by 1 if found.
		for(j=0;j<i;j++)
		{
			if(arr1[i]==arr1[j])
			{
			count++;
			}
		}
		// Check duplicate in position after
		for(k=i+1;k<n;k++)
		{
		  if(arr1[i]==arr1[k])
		  {
		    count++;
		  }
		}
		if(count==0)
		{
		  printf("%d ",arr1[i]);
		}
  }
  printf("\n");
}