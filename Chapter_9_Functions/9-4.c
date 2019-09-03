#include <stdio.h>

double harmonic_mean(double i, double j)
{
    return 1 / ((1 / i + 1 / j) / 2);
}

int main()
{
    double i, j;

    printf("Please enter two numbers:");
    while(scanf("%lf%lf", &i, &j) == 2)
    {
        printf("The harmonic mean of %lf and %lf is %lf.\n", i, j, harmonic_mean(i, j));
        printf("The next two numbers(q to quit):");
    }
    printf("See your again!\n");
    return 0;
}
