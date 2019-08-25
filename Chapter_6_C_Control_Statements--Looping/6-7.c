#include <stdio.h>
#include <string.h>

int main()
{
    char ch[32];
    printf("Please enter a single word:");
    scanf("%s", &ch);
    for(int i = strlen(ch); i > 0; --i)
        printf("%c", ch[i - 1]);
    return 0;
}
