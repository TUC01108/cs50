#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printBinary(int array[], int i);

int main(void)
{
    // We start with a string let's use 'word'
    printf("Enter a word : ");
    char *word = malloc(3 * sizeof(char));
    scanf("%s", word);
    printf("The start of your word is : ");
    printf("%c", *(word));
    printf("\n");

    // We change the first letter to binary
    int n = sizeof(int);
    int array[n], i;
    int m = (int)(*(word));
    int *p1 = array;
    
    for(i = 0; m > 0; i++)    
    {    
        array[i] = m % 2;    
        m = m / 2;    
    }
    // We optionally print the binary
    printBinary(p1, i);
    
    free(word);
    return 0;
}

int printBinary(int *p1, int i)
{
    for(i = i - 1; i >= 0; i--)    
    {    
        printf("%d", *(p1 + i));    
    }
    printf("\n");
    return 0;
}