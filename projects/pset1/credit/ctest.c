#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card = get_long("Enter CC: ");
    int count = 0;
    do
    {
        long m = card;
        while (m != 0) {
        m /= 10;     // m = m/10
        ++count;
    }
    }
    while (count != 10); // Repeat loop unless n is between 13-16 digits
    printf("%i\n", count);
}