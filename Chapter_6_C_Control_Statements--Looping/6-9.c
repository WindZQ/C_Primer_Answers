#include <stdio.h>

float calculation(float a, float b)
{
    float difference, product, answer;
    difference = a - b;
    product = a * b;
    answer = difference / product;
    return answer;
}

int main()
{
    float a, b;
    printf("Please enter twp floating-point numbers:");
    while(scanf("%f %f", &a, &b) == 2)
    {
        printf("The value of their difference divided by their product is: %f\n", calculation(a, b));
        printf("Please enter another pair (non-numeric toquit):");
    }
    printf("See you again!\n");
    return 0;
}
