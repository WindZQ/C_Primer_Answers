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

void printing(struct identity array[])
{
    for(int i = 0; i < 5; ++i)
    {
        if(strcmp(array[i].handle.middle_name, "") != 0)
            printf("%s, %s %c. -- %s\n", array[i].handle.last_name, array[i].handle.first_name, array[i].handle.middle_name[0], array[i].number);
        else
            printf("%s, %s -- %s\n", array[i].handle.last_name, array[i].handle.first_name, array[i].number);
    }
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

    printing(array);

    return 0;
}
