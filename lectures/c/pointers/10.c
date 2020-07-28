/*

10. Write a program in C to Calculate the length of the string using a pointer. Go to the editor
Test Data :
Input a string : w3resource
Expected Output :

The length of the given string w3resource
is : 10


*/
int calculateLength(char*);

#include <stdio.h>

int main(void)
{
    char str1[25];
    char *ch = &str1[0];


    printf("Input a string : ");
    //scanf("%s", str);
    fgets(str1, sizeof str1, stdin);

    int cntr = 0;
    while (*ch != '\0')
    {
        cntr++;
        ch++;
    }
        //return



    printf("The strlen is %i\n", cntr - 1);
}