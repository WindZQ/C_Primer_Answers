#include <stdio.h>

int main()
{
    float height_centimeters, height_inches;
    float centimeters_to_inch = 2.54;
    printf("Please enter your height in centimeters:");
    scanf("%f", &height_centimeters);
    height_inches = height_centimeters / centimeters_to_inch;
    printf("Your height in inches is %f", height_inches);
    return 0;
}
