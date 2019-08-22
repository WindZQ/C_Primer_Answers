#include <stdio.h>

int main()
{
    int count = 0, sum = 0, end;
    printf("Please enter the end:");
    scanf("%d", &end);
    while(count++ < end)
        sum = sum + count * count;
    printf("sum = $%d\n", sum);
    return 0;
}
