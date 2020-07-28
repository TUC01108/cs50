#include <stdio.h>
#include <cs50.h>

int main(void)
{

  int element[10];
  int i;

  printf("Enter 10 elements in array :\n");
  for(i=0;i<10;i++)
  {
    printf("element - %d : ",i);
    scanf("%d", &element[i]);
  }

  printf("\nElements in array: ");
  for(i=0;i<10;i++)
  {
    printf("%d ", element[i]);
  }
  printf("\n");
}