#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char c;
    int low_cnt = 0;
    int up_cnt = 0;
    int dig_cnt = 0;
    int n_words = 0;
    int punc_cnt = 0;
    bool inword = false;

    printf("Please enter text to be analyzed(EOF to terminate):");
    while((c = getchar()) != EOF)
    {
        if(islower(c))
            low_cnt++;
        else if(isupper(c))
            up_cnt++;
        else if(isdigit(c))
            dig_cnt++;
        else if(ispunct(c))
            punc_cnt++;

        if(!isspace(c) && !inword)
        {
            inword = true;
            n_words++;
        }
        if(isspace(c) && inword)
            inword = false;
    }
    printf("\nwords = %d, lowercase = %d, uppercase = %d,digits = %d, punctuation = %d\n", n_words, low_cnt, up_cnt, dig_cnt, punc_cnt);
    return 0;
}
