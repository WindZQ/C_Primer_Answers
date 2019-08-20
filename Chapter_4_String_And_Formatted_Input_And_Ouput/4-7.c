#include <stdio.h>

int main()
{
    float miles, gallons, miles_per_gallon, liters_per_km;
    const float liters_per_gallon = 3.785;
    const float kilometers_per_mile = 1.609;

    printf("Please enter the number of miles traveled:");
    scanf("%f", &miles);
    printf("Please enter the number of gallons of gasoline consumed:");
    scanf("%f", &gallons);

    miles_per_gallon = miles / gallons;
    printf("The value of miles-per-gallon is %.1f.\n", miles_per_gallon);

    liters_per_km = 1 / (miles_per_gallon * 100  * kilometers_per_mile / liters_per_gallon);
    printf("The value of liters-per-100-km id %.1f.\n", liters_per_km);
    return 0;
}
