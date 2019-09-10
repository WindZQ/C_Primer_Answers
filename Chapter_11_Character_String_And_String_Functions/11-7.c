#include <stdio.h>
#include <string.h>
#define LEN 20

char *string_in(const char *s1, const char *s2)
{
    int tries;
    int nomatch = 1;

    tries = strlen(s1) + 1 - strlen(s2);
    if(tries > 0)
        while((nomatch = strncmp(s1, s2, strlen(s2))) && tries--)
            s1++;
    if(nomatch)
        return NULL;
    else
        return (char *)s1;
}

int main()
{
    char orig[LEN] = "transportation";
    char *find;

    puts(orig);
    find = string_in(orig, "port");
    if(find)
        puts(find);
    else
        puts("Not found!");

    return 0;
}
