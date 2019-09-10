#include <stdio.h>
#include <string.h>

char *mystrncpy(char *s1, char *s2, int n)
{
    if(strlen(s2) >= n)
    {
        for(int i = 0; i < strlen(s2); ++i)
            s1[i] = s2[i];
    }
    else
    {
        for(int i = 0; i < n; ++i)
            s1[i] = s2[i];
        for(int i = strlen(s2); i < n; ++i)
            s1[i] = '\0';
    }
    return s1;
}

int main()
{
    char s1[10] = "";
    char s2[] = "LonFan";

    for(int i = 0; i < strlen(s1); ++i)
        printf("%c", s1[i]);
    printf("\n");

    mystrncpy(s1, s2, 4);
    for(int i = 0; i < strlen(s1); ++i)
        printf("%c", s1[i]);
    printf("\n");

    mystrncpy(s1, s2, 10);
    for(int i = 0; i < strlen(s1); ++i)
        printf("%c", s1[i]);
    printf("\n");
    return 0;
}
