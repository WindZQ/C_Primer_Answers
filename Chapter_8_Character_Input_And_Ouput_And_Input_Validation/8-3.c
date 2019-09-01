#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    int num_of_upper = 0, num_of_lower = 0, num_of_other = 0;

    printf("Please enter character:");
    while((ch = getchar()) != EOF)
    {
        if(isupper(ch))
            num_of_upper++;
        else if(islower(ch))
            num_of_lower++;
        else
            num_of_other++;
    }

    printf("The number of uppercase letters is %d,\n"
           "the number of lowercase letters is %d,\n"
           "and the number of other character is %d.\n",
           num_of_upper, num_of_lower, num_of_other);
    return 0;
}
