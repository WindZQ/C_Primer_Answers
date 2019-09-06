#include <stdio.h>
#define SIZE 5

int function(int array[], int number)
{
    int largest = *array;

    for(int i = 0; i < number; ++i)
    {
        if(largest < *(array + i))
            largest = *(array + i);
    }
    return largest;
}

int main()
{
    int array[SIZE] = {1, 2, 3, 4, 5};
    printf("The largest value stored in the array is %d.\n", function(array, SIZE));
    return 0;
}
