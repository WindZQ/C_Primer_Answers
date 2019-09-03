#include <stdio.h>

double min(double x, double y)
{
    return x < y ? x : y;
}

int main()
{
    double x, y;
    printf("Please enter two numbers(q to quit):");
    while(scanf("%lf%lf", &x, &y) == 2)
    {
        printf("The smaller one is %lf.\n", min(x, y));
        printf("The next two numbers(q to quit):");
    }
    printf("See your again!\n");
    return 0;
}
