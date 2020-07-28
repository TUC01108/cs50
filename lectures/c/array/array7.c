#include <stdio.h>
#include <cs50.h>

// int bubbleSort(int array[], int n);
int total(int n, int array[]);

int main(void)
{
  int i,j,k;
  int n1, n2, n3, mm=1,count=0;

  printf("Enter how many values you will enter :\n");
  scanf("%d", &n1);

  n2 = n1;
  n3 = n1 + n2;

  int arr1[n1];
  int arr2[n2];
  int arr3[n3];

  printf("Enter %d elements in array :\n", n1);
  for(i=0;i<n1;i++)
  {
    printf("arr1 - %d : ",i);
    scanf("%d", &arr1[i]);
  }

  printf("Enter %d elements in second array :\n", n2);
  for(i=0;i<n2;i++)
  {
    printf("arr2 - %d : ",i);
    scanf("%d", &arr2[i]);
  }

  // insert in the third array
  for(i=0;i<n1; i++)
      {
          arr3[i] = arr1[i];
       }
   for(j=0;j<n2; j++)
      {
          arr3[i] = arr2[j];
          i++;
      }
  // sort the array in decending order
   for(i=0;i<n3; i++)
        {
           for(k=0;k<n3-1;k++)
             {

                if(arr3[k]<=arr3[k+1])
                 {
                   j=arr3[k+1];
                   arr3[k+1]=arr3[k];
                   arr3[k]=j;
                 }
              }
         }
  // Prints the merged array
     printf("\nThe merged array in decending order is :\n");
    for(i=0; i<n3; i++)
    {
        printf("%d   ", arr3[i]);
    }

  printf("\n");
}