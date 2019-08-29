#include <stdio.h>

int main()
{
    char ch;
    int count = 0;

    printf("Please enter your characters:");
    while((ch = getchar()) != '#')
    {
        switch(ch)
        {
        case '.':
            putchar('!');
            count++;
            continue;
        case '!':
            putchar('!');
            putchar('!');
            count++;
            continue;
        default:
            putchar(ch);
        }
    }
    printf("\nIt has made %d substitutions.\n", count);
    return 0;
}
