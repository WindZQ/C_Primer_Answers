#include <stdio.h>

int main()
{
    float a, b;
    float difference, product;
    printf("Please enter two float-point number:");
    while(scanf("%f %f", &a, &b) == 2)\
    {
        difference = a - b;
        product = a * b;
        printf("The value of their difference divided by their product is: %f\n", difference / product);
        printf("Please enter another pair(non-numeric to quit):");
    }
    printf("See you again!\n");
    return 0;
}
