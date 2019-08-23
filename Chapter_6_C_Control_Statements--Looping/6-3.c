#include <stdio.h>

int main()
{
    for(int i = 0; i < 6; ++i)
    {
        for(char ch = 'F'; ch >= 'F' - i; --ch)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}
