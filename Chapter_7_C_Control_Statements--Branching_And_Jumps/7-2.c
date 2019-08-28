#include <stdio.h>
#define N 8

int main()
{
    char ch;
    int count = 0;

    printf("Please enter your characters:");
    while((ch = getchar()) != '#')
    {
        count++;
        printf("%c-%3d ", ch, ch);

        if(count % N == 0)
            printf("\n");
    }
    return 0;
}
