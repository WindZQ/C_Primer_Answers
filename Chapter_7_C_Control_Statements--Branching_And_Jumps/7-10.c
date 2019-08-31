#include <stdio.h>
#define rate1 0.15
#define rate2 0.28


int main()
{
    char choice;
    int rate_tier;
    float income, tax;
    int flag;

    do
    {
        printf("Your are (enter 1~4 to choose your situation):\n");
        printf("1. Single\n");
        printf("2. Head of Household\n");
        printf("3. Married, Joint\n");
        printf("4. Married, Separate\n");

        choice = getchar();
        while(getchar() != '\n')
            continue;

        while(choice < '1' || choice > '4')
        {
            printf("Please enter 1~4 to choose:");
            choice = getchar();
            while(getchar() != '\n')
                continue;
        }

        switch(choice)
        {
        case '1':
            rate_tier = 17850;
            break;
        case '2':
            rate_tier = 23900;
            break;
        case '3':
            rate_tier = 29750;
            break;
        case '4':
            rate_tier = 14875;
            break;
        default:
            break;
        }

        printf("The please enter your taxtable income:");
        while(scanf("%f", &income) != 1)
        {
            printf("Please enter a number:");
            while(getchar() != '\n')
                continue;
        }
        while(getchar() != '\n')
            continue;

        if(income < rate_tier)
            tax = income * rate1;
        else
            tax = rate_tier * rate1 + (income - rate_tier) * rate2;

        printf("The tax you need to pay is $%g.\n", tax);
        printf("Anthoer run? (Enter 'y' to continue, enter other characters to exit):\n");
        flag = 0;
        if(getchar() == 'y')
            flag = 1;
        while(getchar() != '\n')
            continue;
        printf("\n");
    }while(flag == 1);

    printf("See you again!\n");
    return 0;
}
