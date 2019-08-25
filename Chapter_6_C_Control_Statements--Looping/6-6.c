#include <stdio.h>

int main()
{
    int min = 0, max = 0;
    printf("Please enter the lower limit for the table:");
    scanf("%d", &min);
    printf("Please enter the upper limit for the table:");
    scanf("%d", &max);
    printf("%5s %10s %15s\n", "integer", "square", "cube");
    for(int i = min; i <= max; ++i)
        printf("%5d %10d %15d\n", i, i * i, i * i * i);
    return 0;
}
