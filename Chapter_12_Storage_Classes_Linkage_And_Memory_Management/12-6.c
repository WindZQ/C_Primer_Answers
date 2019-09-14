#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define TIMES 1000

int main()
{
    int i, j, k;
    int array[N];

    for(j = 0; j < 10; ++j)
    {
        printf("Round %d\t", j);
        srand((unsigned int)time(NULL));
        for(i = 0; i < TIMES; ++i)
            array[rand() % 10]++;
        printf("The time each number was produced:\n");
        for(k = 0; k < 10; ++k)
            printf("%d: %dtimes\t", k + 1, array[k]);
        printf("\n");
    }

    return 0;
}
