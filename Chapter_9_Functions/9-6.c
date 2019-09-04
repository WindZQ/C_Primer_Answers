#include <stdio.h>
#include <ctype.h>

int report(char ch)
{
    if(isalpha(ch))
    {
        if(isupper(ch))
            return ch - 64;
        else
            return ch - 96;
    }
    else
        return -1;
}

int main()
{
    char ch;
    printf("Please enter your characters:");
    while((ch = getchar()) != EOF)
    {
        if(report(ch) == -1 &&ch != '\n')
            printf("%c isn't a letter.\n", ch);
        else if(report(ch) == -1 && ch == '\n')
            printf("Please enter your characters:");
        else
            printf("%c is a letter, its numeric location in the alphabet is %d.\n", ch, report(ch));
    }

    printf("See your again!\n");
    return 0;
}
