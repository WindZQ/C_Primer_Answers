#include <stdio.h>

int main()
{
    int days, week, day;
    printf("Please enter the days:");
    scanf("%d", &days);
    while(days > 0)
    {
        week = days / 7;
        day = days % 7;
        printf("%d days arte %d weeks, %d days.\n", days, week, day);
        printf("Please enter the days(days <= 0 to quit):");
        scanf("%d", &days);
    }
    return 0;
}
