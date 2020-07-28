#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Enter your name : "); //Get name from user
    printf("hello, %s\n", name); //Print name of user after hello,
}