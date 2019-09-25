#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

typedef struct names
{
    char first[40];
    char last[40];
}NAME;

void showarray(const NAME array[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        printf("%s %s", array[i].first, array[i].last);
        putchar('\n');
    }
}

int comp(const void *p1, const void *p2)
{
    const struct names *ps1 = (const struct names *)p1;
    const struct names *ps2 = (const struct names *)p2;
    int res;

    res = strcmp(ps1->last, ps2->last);
    if(res != 0)
        return res;
    else
        return strcmp(ps1->first, ps2->first);
}

int main()
{
    struct names staff[N] =
    {
        {"yifan", "zhu"},
        {"fan", "long"},
        {"fan", "shaonv"},
        {"fan", "PG"}
    };

    puts("Before sorted list:");
    showarray(staff, N);
    qsort(staff, N, sizeof(struct names), comp);
    puts("\nSorted list:");
    showarray(staff, N);
    return 0;
}
