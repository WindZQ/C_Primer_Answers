#include <stdio.h>

int main()
{
    float n;
    printf("Please Enter a floating-point value:");
    scanf("%f", &n);
    printf("The input is %f or %e.\n", n, n);
    return 0;
}
