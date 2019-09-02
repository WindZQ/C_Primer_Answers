#include <stdio.h>

char get_first()
{
    char ch;
    while((ch = getchar()) == ' ')
        continue;
    while(getchar() != '\n')
        continue;
    return ch;
}

int main()
{
    char ch;
    printf("Enter your characters:");
    ch = get_first();
    printf("The first non-whitespace character encountered is %c.\n", ch);
    return 0;
}
