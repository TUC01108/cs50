/*
5. Write a program in C to add numbers using call by reference. Go to the editor
Test Data :
Input the first number : 5
Input the second number : 6
Expected Output :

 The sum of 5 and 6  is 11

*/

int addTwo();

#include <stdio.h>

int main(void)
{
    int m;
    int n;
    int *ptr1 = &m;
    int *ptr2 = &n;

    printf("input first number : ");
    scanf("%i", ptr1);
    printf("input second number : ");
    scanf("%i", ptr2);

    int sum = addTwo(&m, &n);

    printf("The sum of %i and %i is %i.\n", *ptr1, *ptr2, sum);
}

int addTwo(int *ptr1, int *ptr2)
{
    int sum = *ptr1 + *ptr2;
    return sum;
}