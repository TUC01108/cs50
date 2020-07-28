/*

Pointer : Demonstrate the use of & and * operator :
--------------------------------------------------------
 m = 300
 fx = 300.600006
 cht = z

*/
#include <stdio.h>

int main(void)
{
    int m = 300;
    float fx = 300.600006;
    char cht = 'z';
    int *ptr1 = &m;
    float *ptr2 = &fx;
    char *ptr3 = &cht;

    printf("address of m : %p", &m);
    printf("\naddress of fx : %p", &fx);
    printf("\naddress of cht : %p\n", &cht);
    printf("\nvalue of m : %i", *&m);
    printf("\nvalue of fx : %f", *&fx);
    printf("\nvalue of cht : %c\n", *&cht);
    printf("\naddress of m : %p", ptr1);
    printf("\naddress of fx : %p", ptr2);
    printf("\naddress of cht : %p\n", ptr3);
    printf("\nvalue of m : %i", *ptr1);
    printf("\nvalue of fx : %f", *ptr2);
    printf("\nvalue of cht : %c\n", *ptr3);
}