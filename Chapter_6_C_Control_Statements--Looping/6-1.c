#include <stdio.h>

int main()
{
    char array[26];
    for(int i = 0; i < 26; ++i)
        array[i] = 'a'+ i;
    printf("The array contents:\n");
    for(int i = 0; i < 26; ++i)
        printf("%c\t", array[i]);
    printf("\n");
    return 0;
}
