#include <stdio.h>

int isPrime(int n)
{
    for(int i = 2; i * i <= n; ++ i)
    {
        if(n % i == 0)
            return 0;
        else
            continue;
    }
    return 1;
}

int main()
{
    int n, i;
    printf("Please enter  a positive integer:");
    scanf("%d", &n);

    printf("All the prime numbers that smaller than or equal to %d are:\n", n);
    for(i = 2; i <= n; ++i)
    {
        if(isPrime(i))
            printf("%d ", i);
    }
    return 0;
}
