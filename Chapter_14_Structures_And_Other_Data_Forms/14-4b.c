#include <stdio.h>
#include <string.h>

struct name
{
    char first_name[20];
    char middle_name[20];
    char last_name[20];
};

struct identity
{
    char number[20];
    struct name handle;
};

void printing(char number[], char first_name[], char middle_name[], char last_name[])
{
    if (strcmp(middle_name, "") != 0)
        printf("%s, %s %c. -- %s\n", last_name, first_name, middle_name[0], number);
    else
        printf("%s, %s -- %s\n", last_name, first_name, number);
}

int main()
{
    struct identity array[5] =
    {
        {"302039823", {"Flossie", "Malan", "Dribble"}},
        {"001", {"Fan", "Yi", "Zhu"}},
        {"002", {"Fan", "", "Long"}},
        {"003", {"Fan", "Nv", "Shao"}},
        {"004", {"Fan", "G", "P"}}
    };

    for(int i = 0; i < 5; ++i)
        printing(array[i].number, array[i].handle.first_name, array[i].handle.middle_name, array[i].handle.last_name);

    return 0;
}
