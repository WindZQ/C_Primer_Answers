#include <stdio.h>
#define N 8

int main()
{
    int two_powers[N];
    int value = 1, i;
    for(i = 0; i < N; ++i)
    {
        two_powers[i] = value;
        value *= 2;
    }
    i = 0;
    do
    {
        printf("%d\t", two_powers[i]);
        ++i;
    }while(i < N);
    return 0;
}
