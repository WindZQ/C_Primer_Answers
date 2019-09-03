#include <stdio.h>

void function(char ch, int col, int row)
{
    int i, j;
    for(i = 0; i < row; ++i)
    {
        for(j = 0; j < col; ++j)
            printf("%c", ch);
        printf("\n");
    }
}


int main()
{
    char ch;
    int col, row;

    printf("Please enter the character:");
    ch = getchar();
    printf("Please enter the number of columns and the number of row:");
    scanf("%d%d", &col, &row);
    function(ch, col, row);

    return 0;
}
