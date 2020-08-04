#include<stdio.h>
#include<stdlib.h>

int intToBinary();
int printBinary();

int main()
{  
    int array[10],n,i; 
    int *p1 = &n;   

    printf("Enter the number to convert: ");    
    scanf("%d",&n);    
    for(i = 0; n > 0; i++)    
    {    
        array[i] = n % 2;    
        n = n / 2;    
    }
    // intToBinary(n);

    printf("\nBinary of Given Number is=");   
    // printf("%d", array[0]);
    
    for(i = i - 1; i >= 0; i--)    
    {    
        printf("%d", *(array + i));    
    }
    
    // printBinary(array);
    printf("\n");

    return 0;  
}
/*
int intToBinary(int *p1, int array[])
{
    for(int i = 0; *p1 > 0; i++)    
    {    
        array[i] = *p1 % 2;    
        *p1 = *p1 / 2;    
    }
    return 0;
}

int printBinary(int array[])
{
    for(int i = i - 1; i >= 0; i--)    
    {    
        printf("%d", array[i]);    
    }
    return 0;
}*/