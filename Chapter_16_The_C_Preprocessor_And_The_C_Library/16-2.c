#include <stdio.h>
#define HMEAN(X, Y) (2.0 * (X) *(Y) / ((X) + (Y)))

int main()
{
    double x, y, ans;

    puts("Please enter a pair of numbers(q to quit): ");
    while(scanf("%lf %lf, &x, &y") == 2)
    {
        ans = HMEAN(x, y);
        printf("%g = harmonic mean of %g %g.\n", ans, x, y);
        ans = HMEAN(x + y, x * y);
        printf("%g = harmonic mean of %g %g.\n", ans, x + y, x * y);
        puts("Please enter a pair of numbers(q to quit): ");
    }
    puts("See your again!");
    return 0;
}
