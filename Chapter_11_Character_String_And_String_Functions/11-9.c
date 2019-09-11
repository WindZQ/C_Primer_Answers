#include <stdio.h>
#include <string.h>

char *s_gets(char *ch, int n)
{
    char *ret_val, *find;

    ret_val = fgets(ch, n, stdin);
    if(ret_val)
    {
        find = strchr(ch, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

int drop_space(char *s)
{
    char *pos;
    while(*s)
    {
        if(*s == ' ')
        {
            pos = s;
            do
            {
                *pos = *(pos + 1);
                pos++;
            }while(*pos);
        }
        else
            s++;
    }
    return 0;
}

int main()
{
    char ch[80];

    printf("Please enter a string of 80 characters or less:");
    while(s_gets(ch, 80) && ch[0] != '\0')
    {
        drop_space(ch);
        puts(ch);
        printf("Please enter next string(or just enter to quit):");
    }
    printf("See your again!\n");
    return 0;
}
