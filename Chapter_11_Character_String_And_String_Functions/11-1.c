#include <stdio.h>

char *getnchar(char *str, int n)
{
    int i;
    char ch;
    for(i = 0; i < n; ++i)
    {
        ch = getchar();
        if(ch != EOF)
            str[i] = ch;
        else
            break;
    }
    if(ch == EOF)
        return NULL;
    else
    {
        str[i] = '\0';
        return str;
    }
}

int main()
{
    char input[10];
    char *check;

    check = getnchar(input, 9);
    if((check == NULL))
        printf("Input failed!\n");
    else
        puts(input);
    puts("Done!\n");
    return 0;
}
