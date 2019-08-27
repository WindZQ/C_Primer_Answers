#include <stdio.h>
#define rate 0.08
#define initial 1000000
#define withdraw 100000

int main()
{
    int years = 0;
    float money = initial;
    while(money > 0)
    {
        money += money * rate;
        money -= withdraw;
        years++;
    }

    printf("It takes %d years for Chuckie to empty his account.\n", years);
    return 0;
}
