#include <stdio.h>
#include <math.h>

#define NUM 2

void transform(double source[], double target[], int num, double pf(double))
{
    for(int i = 0; i < num; ++i)
        target[i] = (*pf)(source[i]);
}

double halve(double snum)
{
    return snum / 2;
}

double triple(double snum)
{
    return snum * 3;
}

int main()
{
    double source[NUM] = {3.14159265 / 2.0, 0};
    double target[NUM];

    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, sin);

    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, cos);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, halve);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    transform(source, target, NUM, triple);
    printf("Target numbers are:");
    for (int i = 0; i < NUM; i++)
        printf(" %.2lf", target[i]);
    puts("");

    return 0;
}
