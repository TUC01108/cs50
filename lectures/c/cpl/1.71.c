#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 with function*/

float fahrToCelsius(int fahr);

int main()
{
    int fahr;
    float celsius;
    int lower, upper, step;

    lower = 0;      // lower limit of temperature table
    upper = 300;    // upper limit
    step = 20;      // step size

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahrToCelsius(fahr);
        printf("%3d %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float fahrToCelsius(int fahr)
{
    float celsius;
    celsius = (5.0 / 9.0) * (fahr - 32);
    return celsius;
}