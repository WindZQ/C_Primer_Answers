#include <stdio.h>

int main()
{
    int i = 0;
    char a[255] = {'\0'};
    printf("Please enter a line of input:");
    do
    {
        scanf("%c", &a[i]);
        ++i;
    }while(a[i - 1] != '\n');

    while(i >= 2)
    {
        printf("%c", a[i - 2]);
        --i;
    }
    printf("\nSee you again!\n");
    return 0;
}
