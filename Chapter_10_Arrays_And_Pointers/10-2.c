#include <stdio.h>

void copy_arr(double target[], double source[], int number)
{
    for(int i = 0; i < number; ++i)
    {
        target[i] = source[i];
    }
}

void copy_ptr(double target[], double source[], int number)
{
    for(int i = 0; i < number; ++i)
    {
        *(target + i) = *(source + i);
    }
}

void copy_ptrs(double target[], double source[], double f_source[])
{
    double *k;
    int l = 0;
    for(k = source; k < f_source; ++k, ++l)
    {
        *(target + l) = *(source + l);
    }
}

int main()
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    for(int i = 0; i < 5; ++i)
        printf("%.1lf\t", target1[i]);
    printf("\n");

    for(int i = 0; i < 5; ++i)
        printf("%.1lf\t", target2[i]);
    printf("\n");

    for(int i = 0; i < 5; ++i)
        printf("%.1lf\t", target3[i]);
    printf("\n");

    return 0;
}
