#include <stdio.h>

int main()
{
    char ch;
    int pairs = 0;

    printf("Please enter character:");
    while((ch = getchar()) != EOF)
    {
        if(ch == 9)
            printf("\\t");
        else if(ch == 10)
        {
            printf("\\n");
            printf("-%d\t", ch);
            printf("\n");
            pairs = 0;
            continue;
        }
        else if(ch < 32)
            printf("^%c", ch + 64);
        else
            printf("%c", ch);
        printf("-%d\t", ch);
        pairs++;
        if(pairs % 10 == 0)
            printf("\n");
    }
    return 0;
}
