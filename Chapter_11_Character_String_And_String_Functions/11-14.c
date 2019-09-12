#include <stdio.h>
#include <string.h>

int my_atoi(char *ch)
{
    int answer = 0, place = 1;

    for(int i = strlen(ch) - 1; i >= 0; --i)
    {
        if(ch[i] - '0' < 0 || ch[i] - '0' > 9)
        {
            printf("The input string is not a pure number.\n");
            return 0;
        }
        answer += (ch[i] - '0') * place;
        place *= 10;
    }
    return answer;
}

int main()
{
    int converd = my_atoi("5GGG");
    printf("%d\t", converd);
    return 0;
}
