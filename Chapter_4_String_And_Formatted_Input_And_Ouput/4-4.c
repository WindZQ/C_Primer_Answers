#include <stdio.h>

int main()
{
    float centimeters, meters;
    char name[10];
    printf("Please enter your height in centimeters:");
    scanf("%f", &centimeters);
    printf("Please enter your name:");
    scanf("%s", &name);

    meters = centimeters / 100;
    printf("%s, your are %.2f meters tall.\n", name, meters);
    return 0;
}
