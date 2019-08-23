#include <stdio.h>

int main()
{
    char ch, ch1;
    printf("Please enter an uppercase letter:");
    scanf("%c", &ch);
    ch1 = ch;

    for(int i = 0; i < ch - 'A' + 1; ++i)
    {
        for(int space = 0; space < ch - 'A' - i; space++)
            printf(" ");
        for(ch = 'A'; ch < 'A' + i + 1; ch++)
            printf("%c", ch);
        for(ch = 'A' + i - 1; ch >= 'A'; ch--)
            printf("%c", ch);
        printf("\n");
        ch = ch1;
    }
    return 0;
}
