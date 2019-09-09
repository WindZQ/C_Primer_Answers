#include <stdio.h>
#include <ctype.h>
char * getword(char *str)
{
    char ch;
    char *orig = str;
    while((ch = getchar()) != EOF && isspace(ch))
        continue;
    if(ch == EOF)
        return NULL;
    else
        *str++ = ch;
    while((ch = getchar()) != EOF && isspace(ch))
        *str++ = ch;
    *str = '\0';
    if(ch == EOF)
        return NULL;
    else
    {
        while(ch != '\n')
            ch = getchar();
        return orig;
    }
}

int main()
{
    char input[80];
    while(getword(input) != NULL)
        puts(input);
    puts("Done!\n");
    return 0;
}
