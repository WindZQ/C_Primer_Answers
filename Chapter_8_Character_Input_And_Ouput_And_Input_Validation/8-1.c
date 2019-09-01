#include <stdio.h>

int main()
{
    int count = 0;
    printf("Please enter character(EOF to end):");
    while(getchar() != EOF)
        count++;

    printf("The number of character in the input is %d.\n", count);
    return 0;
}
