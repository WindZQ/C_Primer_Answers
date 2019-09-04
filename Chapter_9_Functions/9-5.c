#include <stdio.h>

void larger_of(double *i, double *j)
{
    if(*i > *j)
        *j = *i;
    else
        *i = *j;
}

int main()
{
    double i, j;
    printf("Please enter two numbers:");
    while(scanf("%lf%lf", &i, &j) == 2)
    {
        larger_of(&i, &j);
        printf("Now they are reset to the larger one of the two, so they are: %lf %lf\n", i, j);
        printf("The next two numbers(q to quit):");
    }
    printf("See your again!\n");
    return 0;
}
