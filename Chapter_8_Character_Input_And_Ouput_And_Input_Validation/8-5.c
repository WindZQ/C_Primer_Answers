#include <stdio.h>

int main()
{
    char response;
    int guess = 50;
    int upper_limit = 100, lower_limit = 0;

    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a l if my guess is lower, with a h if it is higher and with a c if it is correct.\n");
    printf("Uh...is your number %d?\n", guess);
    while((response = getchar()) != 'c')
    {
        if(response == 'l')
        {
            lower_limit = guess;
            guess = (upper_limit +lower_limit) / 2;
        }
        else if(response == 'c')
        {
            upper_limit = guess;
            guess = (upper_limit + lower_limit) / 2;
        }
        else
        {
            printf("Please enter h or l or c:");
            while(getchar() != '\n')
                continue;
            continue;
        }
        printf("Well, then, is it %d?\n", guess);
        while(getchar() != '\n')
            continue;
    }
    printf("I knew I could do it!\n");
    return 0;
}
