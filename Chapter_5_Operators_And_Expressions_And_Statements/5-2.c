#include <stdio.h>

int main()
{
    int n, m;
    printf("Please enter the number:");
    scanf("%d", &n);
    m = n + 10;
    while(n <= m)
    {
        printf("%d\t", n);
        n++;
    }
    printf("\n");
    return 0;
}
