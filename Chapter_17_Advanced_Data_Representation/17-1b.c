#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE  45

struct film
{
    char title[SIZE];
    int rating;
    struct film *next;
    struct film *prev;
};

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
        {
            while(getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

int main()
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[SIZE];

    puts("Please enter first movie title:");
    while(s_gets(input, SIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if(NULL == head)
        {
            head = current;
            head->prev = NULL;
        }
        else
        {
            prev->next = current;
            current->prev = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Please enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while(getchar() != '\n')
            continue;
        puts("Please enter next movie title(empty line to stop):");
        prev = current;
    }

    if(NULL == head)
        printf("No data entered.\n");
    else
        printf("Here is the movie list:\n");
    current = head;
    while(current != NULL)
    {
        printf("Movie: %s  Rating: %d\n", current->title, current->rating);
        prev = current;
        current = current->next;
    }

    if(head != NULL)
    {
        printf("\nHere is the list in reverse order:\n");
        current = prev;
        while(current != NULL)
        {
            printf("Movie: %s  Rating: %d\n", current->title, current->rating);
            current = current->prev;
        }
    }

    current = head;
    while(current != NULL)
    {
        free(current);
        current = current->next;
    }
    printf("See your again!\n");
    return 0;
}
