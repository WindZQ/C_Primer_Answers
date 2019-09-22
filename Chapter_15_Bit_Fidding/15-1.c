#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

bool check_val(const char *str)
{
    bool valid = true;
    while(valid && *str != '\n')
    {
        if(*str != '0' && *str != '1')
            valid = false;
        ++str;
    }
    return valid;
}

int bstr_to_dec(const char *str)
{
    int val = 0;
    while(*str != '\0')
        val = 2 * val + (*str++ - '\0');
    return val;
}

int main()
{
    const size_t N = CHAR_BIT * sizeof(int) + 1;
    char value[N];

    printf("Please enter a binary number with up to %zu digits: ", N - 1);

    while(s_gets(value, N) && value[0] != '\0')
    {
        if(!check_val(value))
            puts("A binary number contains just 0s and 1s.");
        else
            printf("%s is %d\n", value, bstr_to_dec(value));
        puts("Please enter next value(empty line to quit):");
    }
    puts("Done!");
    return 0;
}
