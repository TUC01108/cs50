#include <stdio.h>

int main(void)
{
    printf("Demonstrate the use of & and * operator :\n");
    printf("--------------------------------------------------------\n");
    printf("m = 300\nfx = 300.600006\ncht = z\n");
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';

    printf("\nUsing & operator :\n");
    printf("-----------------------\n");
    printf("address of m = %p\n", &m);
    printf("address of fx = %p\n", &fx);
    printf("address of cht = %p\n", &cht);

    printf("\nUsing & and * operator :\n-----------------------------\n");
    printf("value at address of m = %i\n", *&m);
    printf("value at address of fx = %f\n", *&fx);
    printf("value at address of cht = %c\n", *&cht);

    int *n = &m;
    float *fz = &fx;
    char *chu = &cht;
    printf("\nUsing only pointer variable :\n----------------------------------\n");
    printf("address of m = %p\n", n);
    printf("address of fx = %p\n", fz);
    printf("address of cht = %p\n", chu);

    printf("\nUsing only pointer operator :\n----------------------------------\n");
    printf("value at address of m = %i\n", *n);
    printf("value at address of fx= %f\n", *fz);
    printf("value at address of cht= %c\n", *chu);

}