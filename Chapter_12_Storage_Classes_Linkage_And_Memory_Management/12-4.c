#include <stdio.h>

int function()
{
    static int times = 0;
    return ++times;
}

int main()
{
    int times;
    scanf("%d", &times);
    for(int i = 0; i < times; ++i)
        printf("The function has been called for %d times.\n", function());
    return 0;
}
