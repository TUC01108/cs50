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

  printf("Enter %d elements in array :\n", n);
  for(i=0;i<n;i++)
  {
    printf("element - %d : ",i);
    scanf("%d", &element[i]);
  }

  printf("\nSum of all elements stored in array: ");

  // Print sum
  printf("Total: %d\n", total(n, element));

  printf("\n");
}

int total(int n, int array[])
{
    int add = 0;
    for (int i = 0; i < n; i++)
    {
        add += array[i];
    }
    return add;
}