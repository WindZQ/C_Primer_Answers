#include <stdio.h>
#include <string.h>
#include <17-5a.h>
#define LEN 81

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}

int main()
{
    Stack stch;
    char temp[LEN];
    int i;
    char ch;

    InitializeStack(&stch);
    printf("Please enter a line(an empty line to quit): ");
    while(s_gets(temp, LEN) && temp[0] != '\0')
    {
        i = 0;
        while(temp[i] != '\0' && !FullStack(&stch))
            Push(temp[++i], &stch);

        while(!EmptyStack(&stch))
        {
            Pop(&ch, &stch);
            putchar(ch);
        }
        putchar('\n');
        printf("Please enter next line(empty line to quit): ");
    }
    puts("Done!");

    return 0;
}
