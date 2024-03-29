#include <stdio.h>
#include <string.h>

void reverse(char *s)
{
    char *begin;
    char *end;
    char temp;

    begin = s;
    end = s + strlen(s) - 1;

    for(int i = 0; i < strlen(s) / 2; ++i)
    {
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

int main()
{
    char s[] = "longfan";
    char s1[] = "zhuyifan";

    reverse(s);
    reverse(s1);

    for(int i = 0; i < strlen(s); ++i)
        printf("%c", s[i]);
    printf("\n");

    for(int i = 0; i < strlen(s1); ++i)
        printf("%c", s1[i]);
    printf("\n");
    return 0;
}
