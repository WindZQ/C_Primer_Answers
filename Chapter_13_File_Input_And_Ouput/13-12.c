#include <stdio.h>
#include <stdlib.h>

#define ROWS    20
#define COLS    30
#define LEVELS  10
const char trans[LEVELS + 1] = " .':~*=&%@";

void init(char arr[][COLS], char ch)
{
    int r, c;
    for(r = 0; r < ROWS; ++r)
    {
        for(c = 0; c < COLS; ++c)
            arr[r][c] = ch;
    }
}

void makePic(int data[][COLS], char pic[][COLS], int rows)
{
    int row, col;
    for(row = 0; row < rows; ++row)
    {
        for(col = 0; col < COLS; ++col)
            pic[row][col] = trans[data[row][col]];
    }
}

int main()
{
    int row, col;
    int picIn[ROWS][COLS];
    char picOut[ROWS][COLS];
    char fileName[81];
    FILE *infile;

    init(picOut, 'S');

    printf("Please enter name of file:");
    scanf("%80s", fileName);
    if((infile = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "Could not open data file.\n");
        exit(EXIT_FAILURE);
    }

    for(row = 0; row < ROWS; ++row)
    {
        for(col = 0; col < COLS; ++col)
            fscanf(infile, "%d", &picIn[row][col]);
    }

    if(ferror(infile))
    {
        fprintf(stderr, "Error getting data from file.\n");
        exit(EXIT_FAILURE);
    }
    makePic(picIn, picOut, ROWS);

    for(row = 0; row < ROWS; ++row)
    {
        for(col = 0; col < COLS; ++col)
            putchar(picOut[row][col]);
        putchar('\n');
    }
    fclose(infile);
    return 0;
}
