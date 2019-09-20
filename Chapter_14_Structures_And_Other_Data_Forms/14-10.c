#include <stdio.h>
#include <math.h>

#define NUM 4

void show_menu()
{
    puts("Enter one of the following choices:");
    puts("0) double the value        1) halve the value");
    puts("2) triple the value        3) squareroot the value");
    puts("4) next number");
}

double twice(double x)  { return 2.0 * x;}
double half(double x)   { return x / 2.0;}
double thrice(double x) { return 3.0 * x;}

int main()
{
    double (*pf[NUM])(double) = {twice, half, thrice, sqrt};
    double val, ans;
    int sel;

    printf("Please enter a number(negative to quit): ");
    while(scanf("%lf", &val) && val >= 0)
    {
        show_menu();
        while (scanf("%d", &sel) && sel >= 0 && sel <= 3)
        {
            ans = (*pf[sel])(val);
            printf("answer = %f\n", ans);
            ans = pf[sel](val);
            printf("to repeat, answer = %f\n", ans);
            show_menu();
        }
        printf("Please enter next number (negative to quit): ");
    }
    puts("See your again!");
    return 0;
}
