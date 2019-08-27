#include <stdio.h>
#define N 8
int main()
{
    int i;
    double fa[N] = {0};
    double sa[N] = {0};
    printf("Please enter eight numbers:");
    for(int i = 0; i < N; ++i)
        scanf("%lf", &fa[i]);
    sa[0] = fa[0];
    for(int i = 1; i < N; ++i)
        sa[i] = fa[i] + sa[i - 1];
    for(int i = 0; i < N; ++i)
        printf("%8g",fa[i]);
    printf("\n");
    for(int i = 0; i < N; ++i)
        printf("%8g", sa[i]);
    return 0;
}
