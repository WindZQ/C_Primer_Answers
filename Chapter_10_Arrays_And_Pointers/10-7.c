#include <stdio.h>

void copy_arr(double target[], double source[], int number)
{
    for(int i = 0; i < number; ++i)
        target[i] = source[i];
}

int main()
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target[3];
    copy_arr(target, &source[2], 3);

    for(int i = 0; i < 3; ++i)
        printf("%.1lf\t", target[i]);
    printf("\n");
    return 0;
}
