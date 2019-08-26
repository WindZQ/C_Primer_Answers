#include <stdio.h>

int main()
{
    int n, sign = 1;
    float result1, result2;
    printf("Please enter the number of terms:");
    scanf("%d", &n);
    while(n > 0)
    {
        for(float i = 1; i <= n; ++i)
        {
            result1 += 1 / i;
            result2 += 1 / i * sign;
            sign = -sign;
        }
        printf("1.0 + 1.0 / 2.0 + 1.0 / 3.0 + 1.0 / 4.0 +... 1.0 / %d.0 = %f\n", n, result1);
        printf("1.0 - 1.0 / 2.0 + 1.0 / 3.0 + 1.0 / 4.0 +... 1.0 / %d.0 = %f\n", n, result2);
        printf("Please enter the number of terms(<= 0 to quit):");
        scanf("%d", &n);
        result1 = 0.0;
        result2 = 0.0;
    }
    printf("See you again!\n");
    return 0;
}
