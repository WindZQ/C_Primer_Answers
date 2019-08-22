#include <stdio.h>

void Temperatures(double Fahrenhelt)
{
    const double Celsius = 1.8 * Fahrenhelt + 32.0;
    const double Kelvin  = Celsius + 273.16;
    printf("The Fahrenhelt temperature is %.2lf.\n", Fahrenhelt);
    printf("The Celsius temperature is %.2lf.\n", Celsius);
    printf("The Kelvin temperature is %.2lf.\n", Kelvin);
}

int main()
{
    double Fahrenhelt;
    printf("Please enter a Fahrenhelt temperature:");
    while(scanf("%lf", &Fahrenhelt) == 1)
    {
        Temperatures(Fahrenhelt);
        printf("Please enter the next Fahrenhelt temperature (q to quit):");
    }
    printf("See you again!\n");
    return 0;
}
