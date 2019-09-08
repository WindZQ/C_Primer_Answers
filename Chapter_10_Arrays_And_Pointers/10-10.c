#include <stdio.h>
#define ROWS 3
#define COLS 5

void display(int array[][COLS], int rows)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < ROWS; ++j)
            printf("%3d\t", array[i][j]);
    }
}

void doubling(int array[][COLS], int rows)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < ROWS; ++j)
            array[i][j] *= 2;
    }
}

int main()
{
    int array[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    display(array, ROWS);
    doubling(array, ROWS);
    printf("\n");
    display(array, ROWS);
    return 0;
}
