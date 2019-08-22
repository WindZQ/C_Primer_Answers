#include <stdio.h>

int cude(double n)
{
    double cuded = 0.0;
    cuded = n * n * n;
    return cuded;
}
int main()
{
    double n, m   ;
    printf("Please enter double number:");
    scanf("%lf", &n);
    m = cude(n);
    printf("The value of %lf cubed is %lf.\n", n, m);
    return 0;
}
