#include <stdio.h>

void Store(double array[][5])
{
    printf("Please enter three sets of five double numbers:\n");
    printf("Please enter the first set:");
    for(int i = 0; i < 5; ++i)
        scanf("%lf", &array[0][i]);
    printf("Please enter the second set:");
    for(int i = 0; i < 5; ++i)
        scanf("%lf", &array[1][i]);
    printf("Please enter the third set:");
    for(int i = 0; i < 5; ++i)
        scanf("%lf", &array[2][i]);
}

double Compute1(double array[][5], int index)
{
    double average = 0.0;
    double sum = 0.0;

    for(int i = 0; i < 5; ++i)
        sum += array[index][i];
    average = sum / 5;
    return average;
}

double Compute2(double array[][5])
{
    double average = 0.0;
    double sum = 0.0;
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 3; ++j)
            sum += *(*(array + i) + j);
    }
    average = sum / 15;
    return average;
}

double Largest(double array[][5])
{
    double largest = *(*array);
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(*(*(array + i) + j) > largest)
                largest = *(*(array + i) + j);
        }
    }
    return largest;
}

void Report(double array[][5])
{
    for (int i = 0; i < 3; i++)
        printf("The average of the %d set of five values is: %lf.\n", i, Compute1(array, i));

    printf("The average of all values is: %lf.\n", Compute2(array));

    printf("The largest value among these values is: %lf\n", Largest(array));
}

int main()
{
    double array[3][5];
    Store(array);
    Report(array);
    return 0;
}
