#include <stdio.h>
#define N 5

double function(double array[], int number)
{
    double largest = *array;
    double smallest = *array;

    for(int i = 0; i < number; ++i)
    {
        if(largest < *(array + i))
            largest = *(array + i);
        if(smallest > *(array + i))
            smallest = *(array + i);
    }
    return largest - smallest;
}

int main()
{
    double array[N] = {1.1, 2.2, 5.5, 4.4, 0.0};
    printf("The largest value stored in the array is %.1lf.\n", function(array, N));
    return 0;
}
