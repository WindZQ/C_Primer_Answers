#include <stdio.h>

void chline(char ch, int i, int j)
{
    int k;
    for(k = 0; k < i; ++k)
        printf(" ");
    for(k = i; k <=j; ++k)
        printf("%c", ch);
}

int main()
{
    char ch;
    int i, j;
    printf("Please enter ch, i, j:");
    ch = getchar();
    scanf("%d%d", &i, &j);
    chline(ch, i, j);
    return 0;
}
