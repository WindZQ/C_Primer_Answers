#include <stdio.h>

int main()
{
    float centimeters, inches;
    int feet;
    printf("Enter a height in centimeters:");
    scanf("%f", &centimeters);
    while(centimeters > 0)
    {
        feet = centimeters / 30.48;
        inches = (centimeters - feet * 30.48) / 2.54;
        printf("%.1f cm = %d feet, %.1f inches.\n", centimeters, feet,inches);
        printf("Enter a height in centimeters (<= 0 to quit): ");
        scanf("%f", &centimeters);
    }
    printf("bye\n");
    return 0;
}
