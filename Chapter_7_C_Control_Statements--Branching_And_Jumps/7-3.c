#include <stdio.h>

int main()
{
    int i = 0;
    float sum_even = 0, sum_add = 0;
    int count_even = 0, count_odd = 0;
    float average_even, average_odd;

    printf("Please enter your number:");
    while(scanf("%d", &i) == 1 && i != 0)
    {
        if(i % 2 == 0)
        {
            sum_even += i;
            count_even++;
        }
        else
        {
            sum_add += i;
            count_odd++;
        }
    }

    average_even = sum_even / count_even;
    average_odd = sum_add / count_odd;

    printf("The number of evens:%d\n", count_even);
    if(count_even > 0)
        printf("The average value of evens:%g\n", average_even);
    printf("The number of odds:%d\n", count_odd);
    if(count_odd > 0)
        printf("The average value of odds:%g\n", average_odd);
    return 0;
}
