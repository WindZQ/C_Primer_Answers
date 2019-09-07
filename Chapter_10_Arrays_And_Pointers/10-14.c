#include <stdio.h>
#define N 5
void reverse(double array[], int number)
{
    double temp;
    for(int i = 0; i < number / 2; ++i)
    {
        temp = *(array + i);
        *(array + i) = *(array + number - i - 1);
        *(array + number - i - 1) = temp;
    }
}

int main()
{
    double array[N] = {1.1, 2.2, 4.4, 3.3, 5.5};

    printf("The contents of the array are:");
    for(int i = 0; i < N; ++i)
        printf("%.1lf\t", array[i]);
    printf("\n");

    reverse(array, N);
    printf("The contents of the array now are:");
    for(int i = 0; i < N; ++i)
        printf("%.1lf\t", array[i]);

    return 0;
}
