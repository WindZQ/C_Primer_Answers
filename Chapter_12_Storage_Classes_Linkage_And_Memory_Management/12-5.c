#include <stdio.h>
#include <stdlib.h>
#define N 100

void print(const int array[], int limit)
{
    int index;
    for(index = 0; index < limit; ++index)
    {
        printf("%2d\t", array[index]);
        if(index % 10 == 9)
            printf("\n");
    }
    if(index % 10 != 0)
        printf("\n");
}

void sort(int array[], int limit)
{
    int top, search, temp;
    for(top = 0; top < limit - 1; ++top)
    {
        for(search = top + 1; search < limit; ++search)
        {
            if(array[search] > array[top])
            {
                temp = array[search];
                array[search] = array[top];
                array[top] = temp;
            }
        }
    }
}

int main()
{
    int array[N];
    for(int i = 0; i < N; ++i)
        array[i] = rand() % 10 + 1;
    printf("Initial array:\n");
    print(array, N);
    sort(array, N);
    printf("\nsorted array:\n");
    print(array, N);
    return 0;
}
