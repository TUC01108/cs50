#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

long get_cc_long(string prompt);
int get_first_two(long);
int get_count(long);
int lengthDigit();
bool isCardValid();
bool isAmex();
bool isMastercard();
bool isVisa();
char *printValidCard();

int main(void)
{
    long card = get_cc_long("Enter CC: ");
    long valid = get_first_two(card);
    int count = get_count(card);

    if (isCardValid(card, count) == false)
    {
        printf("INVALID\n");
        return 0;
    }
    printValidCard(valid);
}









// Prompt user for valid credit card long
long get_cc_long(string prompt)
{
    long n;
    int count = 0;
    do
    {
        n = get_long("%s", prompt); // Prompt user for long
        long m = n;
        while (m != 0)
        {
            m /= 10;     // m = m/10
            ++count;
        }
    }
    while (count != 10 && (count < 13 || count > 16)); // Repeat loop unless n is between 13-16 digits
    return n;
}

// Get first 2 digits of credit card
int get_first_two(long card)
{
    //long card;
    long card1 = card, card2 = card; // n2 will hold the first two digits.
    while (card)
    {
        card2 = card1;
        card1 = card;
        card /= 10;
    }
    return card2;
}

// Provide count for credit card number entered
int get_count(long card)
{
    int count = 0;
    do
    {
        long m = card;
        while (m != 0)
        {
            m /= 10;     // m = m/10
            ++count;
        }
    }
    while (count < 9 || count > 16); // Repeat loop unless n is between 13-16 digits
    return count;
}

// Provide count for credit card number entered
int lengthDigit(int total)
{
    int count = 0;
    long m = total;
    while (m != 0)
    {
        m /= 10;     // m = m/10
        ++count;
    }
    //while (count < 9 || count > 16); // Repeat loop unless n is between 13-16 digits
    return count;
}

// Luhn's Algorithm
bool isCardValid(long card, int count)
{
    // Check cards length
    if (count == 10)
    {
        return false;
    }

    int array[count];
    int i, j, sum = 0, otherSum = 0;
    int newArray[count];
    for (i = count - 1; i >= 0; i--)
    {
        array[i] = card % 10;
        card = card / 10;
    }

    for (i = count - 2, j = count - 1; j >= 0; i = i - 2, j = j - 2)
    {
        otherSum = otherSum + array[j];
        newArray[i] = array[i] * 2;
        if (newArray[i] < 10)
        {
            sum = sum + newArray[i];
        }
        else if (newArray[i] == 18)
        {
            sum = sum + (newArray[i] / 2);
        }
        else
        {
            sum = sum + (newArray[i] % 9);
        }
    }
    int total = otherSum + sum;
    int temp = total;
    int totalArray[100];

    // Turn total into array
    for (i = lengthDigit(total); i > 0; i--)
    {
        totalArray[i] = temp % 10;
        temp = temp / 10;
    }
    if (totalArray[lengthDigit(total)] != 0)
    {
        return false;
    }
    return true;
}

bool isAmex(long valid)
{
    if (valid == 34 || valid == 37)
    {
        //printf("AMEX\n");
        //printf("%li\n", card);
        return true;
    }
    return false;
}

bool isMastercard(long valid)
{
    if (valid == 51 || valid ==  52 || valid ==  53 || valid ==  54 || valid ==  55)
    {
        return true;
    }
    return false;
}

bool isVisa(long valid)
{
    if ((valid / 10) == 4)
    {
        return true;
    }
    return false;
}

char *printValidCard(long valid)
{
    if (isAmex(valid) == true)
    {
        printf("AMEX\n");
    }

    else if (isMastercard(valid) == true)
    {
        printf("MASTERCARD\n");
    }

    else if (isVisa(valid) == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}