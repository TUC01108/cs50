/*

4. Write a program in C to add two numbers using pointers. Go to the editor
Test Data :
Input the first number : 5
Input the second number : 6
Expected Output :

The sum of the entered numbers is : 11


*/
#include <stdio.h>

int main(void)
{
    int m;
    int n;
    int *p1 = &m;
    int *p2 = &n;

    printf("Enter first number : ");
    scanf("%i", p1);
    printf("Enter second number : ");
    scanf("%i", p2);
    printf("The sum of %i and %i is %i\n", *p1, *p2, *p1 + *p2);
}