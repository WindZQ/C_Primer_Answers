#include <stdio.h>

int main()
{
    int count = 0;
    for(int i = 0; i < 6; ++i)
    {
        for(char ch = 'A' + count; ch <= 'A' + count + i; ++ch)
            printf("%c",ch);
        count += i + 1;
        printf("\n");
    }
    return 0;
}
