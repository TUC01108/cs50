#include <stdio.h>

int main(void)
{
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';
    int *p1 = &m;
    float *p2 = &fx;
    char *p3 = &cht;
    printf("\nPointer : Demonstrate the use of & and * operator :\n--------------------------------------------------------\n");
    printf("\nUsing & operator :\n-----------------------\n");
    printf("address of m = %p\n", &m);
    printf("address of fx = %p\n", &fx);
    printf("address of cht = %p\n", &cht);
    printf("\nUsing & and * operator :\n-----------------------------\n");
    printf("value at address of m = %i\n", *&m);
    printf("value at address of fx = %f\n", *&fx);
    printf("value at address of cht = %c\n", *&cht);
    printf("\nUsing only pointer variable :\n----------------------------------\n");
    printf("address of m = %p\n", p1);
    printf("address of fx = %p\n", p2);
    printf("address of cht = %p\n", p3);
    printf("\nUsing only pointer operator :\n----------------------------------\n");
    printf("value at address of m = %i\n", *p1);
    printf("value at address of fx = %f\n", *p2);
    printf("value at address of cht = %c\n", *p3);

}