#include <stdio.h>
#include <cs50.h>

int total(int n, int array[]);

int main(void)
{
  int i,j;
  int n, mm=1,count=0;
  printf("Enter how many values you will enter :\n");
  scanf("%d", &n);

  int arr1[n];
  int arr2[n];
  int arr3[n];

  printf("Enter %d elements in array :\n", n);
  for(i=0;i<n;i++)
  {
    printf("arr1 - %d : ",i);
    scanf("%d", &arr1[i]);
    arr2[i] = arr1[i];
    arr3[i]=0;
  }

  /*printf("\nElements in array: ");
  for(i=0;i<n;i++)
  {
    printf("%d ", arr1[i]);
  }*/

  // printf("\nCheck to see if there are dupicate elements in first array: \n");
  for(i=0;i<n; i++)
        {
		for(j=0;j<n;j++)
			{
				if(arr1[i]==arr2[j])
				{
				arr3[j]=mm;
				mm++;
				}
			}
			mm=1;
        }
  for(i=0; i<n; i++)
    {
      if(arr3[i]==2){count++;}
    }
  printf("\nThe total number of duplicate elements found in the array is: %d \n", count);
  printf("\n");
}