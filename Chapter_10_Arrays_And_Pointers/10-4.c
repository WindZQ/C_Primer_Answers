#include <stdio.h>
#define SIZE 5

int function(double array[], int number)
{
    int largest = *array;
    int largest_index = 0;
    for(int i = 0; i < number; ++i)
    {
        if(largest < *(array + i))
        {
            largest = *(array + i);
            largest_index = i;
        }
    }
    return largest_index;
}

int main()
{
    double array[SIZE] = {1.1, 2.2, 5.5, 4.4, 3.3};
    printf("The index of the largest value stored in the array is %d.\n", function(array, SIZE));
    return 0;
}
