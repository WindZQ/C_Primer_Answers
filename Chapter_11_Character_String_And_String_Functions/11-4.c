#include <stdio.h>
#include <ctype.h>
#define LEN 80
#define MAX 10
char *getword(char *str, int n)
{
    char ch;
    char *orig = str;

    while((ch = getchar()) != EOF && isspace(ch))
        continue;
    if(ch == EOF)
        return NULL;
    else
        *str++ = ch;
    while((ch = getchar()) != EOF && !isspace(ch) && --n)
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
    char input[LEN];

    while(getword(input, MAX) != NULL)
        puts(input);
    puts("Done!\n");

    return 0;
}
