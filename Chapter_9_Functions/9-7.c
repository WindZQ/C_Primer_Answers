#include <stdio.h>

double power(double n, int p)
{
    double pow = 1;
    int i;
    if(p > 0)
    {
        for(i = 1; i <= p; ++i)
            pow *= n;
        if(n == 0)
            pow = 0;
    }
    else if(p < 0)
    {
        for(i = -1; i >= p; --i)
            pow /= n;
        if(n == 0)
            pow = 0;
    }
    else if(p == 0 && n == 0)
    {
        printf("0 to the 0 is undefined, and it's using a value of 1.\n");
        pow = 1;
    }
    else
        pow = 1;
    return pow;
}

int main()
{
    double x, pow;
    int exp;

    printf("Please enter a number and the integer power");
    printf("to which the number will be raised. Enter q to quit.\n");
    while(scanf("%lf%d", &x, &exp) == 2)
    {
        pow = power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, pow);
        printf("Please enter next pair of numbers or q to quit:");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

    return 0;
}
