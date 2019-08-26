#include <stdio.h>

int main()
{
    int ll, ul, result;
    printf("Enter lower and upper integer limits:");
    scanf("%d %d", &ll, &ul);
    while(ll < ul)
    {
        result = 0;
        for(int i = ll;  i <= ul; ++i)
            result += i * i;
        printf("The sum of the squares from %d to %d is %d\n", ll * ll, ul * ul, result);
        printf("Enter next set of limits:");
        scanf("%d %d", &ll, &ul);
    }
    printf("Done");
    return 0;
}
