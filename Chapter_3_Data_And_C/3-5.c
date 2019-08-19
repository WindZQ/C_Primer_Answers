#include <stdio.h>

int main()
{
    float age_years, age_seconds;
    printf("Please enter you age in years:");
    scanf("%f", &age_years);
    age_seconds = age_years * 3.156e7;
    printf("Your age in seconds is %f seconds.\n", age_seconds);
    return 0;
}
