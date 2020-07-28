/*
6. Write a program in C to find the maximum number between two numbers using a pointer. Go to the editor
Test Data :
Input the first number : 5
Input the second number : 6
Expected Output :

6 is the maximum number.

*/
//int isMax();

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
    if (*p1 > *p2)
    {
        printf("\n%i is the max number.\n", *p1);
    }
    else
    {
        printf("\n%i is the max number.\n", *p2);
    }
    //int max = isMax(&m, &n);
    //printf("\n%i is the max number\n", max);
}
/*
int isMax(int *p1, int *p2)
{
    int z = 0;
    if (*p1 > *p2)
    {
        z = *p1;
    }
    else
    {
        z = *p2;
    }
    return z;
}
*/