#include <stdio.h>
#include <cs50.h>

int total(int n, int array[]);

int main(void)
{
  int i;
  int n;
  printf("Enter how many values you will enter :\n");
  scanf("%d", &n);

  int element[n];
  int copy[n];

  printf("Enter %d elements in array :\n", n);
  for(i=0;i<n;i++)
  {
    printf("element - %d : ",i);
    scanf("%d", &element[i]);
    copy[i] = element[i];
  }

  printf("\nElements in array: ");
  for(i=0;i<n;i++)
  {
    printf("%d ", element[i]);
  }

  printf("\nElements copied into second array: ");
  for(i=0;i<n;i++)
  {
    printf("%d ", copy[i]);
  }
  printf("\n");
}