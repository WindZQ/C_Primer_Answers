#include <stdio.h>

int main()
{
    char ch;
    int space = 0, character = 0, other_character = 0;
    printf("Please enter your character:");
    while((ch = getchar()) != '#')
    {
        if(ch == ' ')
            space++;
        else if(ch == '\n')
            character++;
        else
            other_character++;
    }

    printf("The number of spaces read is %d.\n", space);
    printf("The number of newline characters read is %d.\n", character);
    printf("The number of all other characters read is %d.\n", other_character);

    return 0;
}
