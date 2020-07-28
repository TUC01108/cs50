#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int i;
  int n;
  printf("Enter how many values you will enter :\n");
  scanf("%d", &n);

  int element[n];

  printf("Enter %d elements in array :\n", n);
  for(i=0;i<n;i++)
  {
    printf("element - %d : ",i);
    scanf("%d", &element[i]);
  }

  printf("\nElements in array in reverse: ");
  for(i=n-1;i>=0;i--)
  {
    printf("%d ", element[i]);
  }
  printf("\n");
}