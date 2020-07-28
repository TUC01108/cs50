#include <stdio.h>

int main(void)
{
    int i;
    int element[10];
    printf("Input 10 elements in array : \n");
    for (i = 0; i < 10; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &element[i]);
    }
}