#include <stdio.h>
#define ROWS 2
#define COLS 3

void copy_ptr(double target[][COLS], double source[][COLS], int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            *(*(target + i) + j) = *(*(source + i) + j);
    }
}

void display(double array[][COLS], int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            printf("%.1lf\t", array[i][j]);
        printf("\n");
    }
}

int main()
{
    double source[ROWS][COLS] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
    double target[ROWS][COLS];
    copy_ptr(target, source, ROWS, COLS);
    display(target, ROWS, COLS);
    return 0;
}
