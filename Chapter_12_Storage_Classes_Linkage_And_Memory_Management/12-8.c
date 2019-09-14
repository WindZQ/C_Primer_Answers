#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val)
{
    int *array = (int *)malloc(elem * sizeof(int));

    for(int i = 0; i < elem; ++i)
        *(array + i) = val;
    return array;
}

void show_array(const int array[], int n)
{
    int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        printf("%d\t", array[cnt]);
        cnt++;
        if(cnt % 8 == 0)
            printf("");
    }
    printf("");
}

int main()
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("\nEnter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}
