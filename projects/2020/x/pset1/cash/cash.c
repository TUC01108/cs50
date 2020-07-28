#include <stdio.h>
#include <cs50.h>
#include <math.h>
float get_pos_float(string prompt);

int main(void)
{
    float c = get_pos_float("Change owed: "); // Takes user input only allowing positive decimal values
    int cents = round(c * 100); // Changing change from float to rounded integer
    int quarter = 25;
    int dime = 10;
    int nickel = 05;
    int penny = 01;
    int coins = 0;
    if (cents - quarter >= 0) // If total change minus 25 is greater than or equal to 0 then do the following
    {
        do
        {
            cents = cents - quarter;
            coins = coins + 1;
            printf("you are at this many quarters: %i, %i\n", coins, cents);
        }
        while (cents >= quarter);
    }
    if (cents - dime >= 0) // If total change minus 10 is greater than or equal to 0 then do the following
    {
        do
        {
            cents = cents - dime;
            coins = coins + 1;
            printf("you are at this many dimes: %i, %i\n", coins, cents);
        }
        while (cents >= dime);
    }
    if (cents - nickel >= 0) // If total change minus 5 is greater than or equal to 0 then do the following
    {
        do
        {
            cents = cents - nickel;
            coins = coins + 1;
            printf("you are at this many nickels: %i, %i\n", coins, cents);
        }
        while (cents >= nickel);
    }
    if (cents - penny >= 0) // If total change minus 1 is greater than or equal to 0 then do the following
    {
        do
        {
            cents = cents - penny;
            coins = coins + 1;
            printf("you are at this many pennys: %i, %i\n", coins, cents);
        }
        while (cents >= penny);
    }
    printf("This is your number of coins: %i\n", coins);
}



// Prompt user for positive float
float get_pos_float(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt); // Prompt user for float
    }
    while (n < 0); // Repeat loop unless n is postive
    return n;
}