#include <stdio.h>

int main()
{
    float n;
    printf("Please enter a floating-point number:");
    scanf("%f", &n);
    printf("The input is %f or %e", n, n);
    return 0;
}
