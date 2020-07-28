#include <stdio.h>
int main(void)
{
  int n, c, d, swap;

  printf("Enter how many values you will enter :\n");
  scanf("%d", &n);

  int array1[n];

  printf("Enter %d elements in array :\n", n);
  for(c=0;c<n;c++)
  {
    printf("array1 - %d : ",c);
    scanf("%d", &array1[c]);
  }
  for(c=0;c<(n-1);c++)
  {
    for(d=0;d<n-c-1;d++)
    {
      if(array1[d] > array1[d+1]) // < for descending
      {
        swap = array1[d];
        array1[d] = array1[d+1];
        array1[d+1] = swap;
      }
    }
  }
  printf("Sorted list in ascending order:\n");

  for(c=0;c<n;c++)
  {
    printf("%d ", array1[c]);
  }
  printf("\n");
  return 0;
}