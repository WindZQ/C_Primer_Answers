#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#define N 81
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

char menu()
{
    int ch;

    puts("Word counting program");
    puts("Please enter the letter corresponding to your choice:");
    puts("s) show word list          f) find a word");
    puts("q) quit");
    while((ch = getchar()) != EOF)
    {
        while(getchar() != '\n')
            continue;
        ch = tolower(ch);
        if(strchr("sfq", ch) == NULL)
            puts("Please enter an s, f or q:");
        else
            break;
    }

    if(ch == EOF)
        ch = 'q';
    return ch;
}

void showwords(const Tree *pt)
{
    if(TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, prinritem);
}

void findword(const Tree *pt)
{
    char word[N];
    Item entry;
    const Item *pi;

    if(TreeIsEmpty(pt))
    {
        puts("No entries!");
        return ;
    }

    printf("Please enter the word to find:");
    scanf("%s", word);
    while(getchar() != '\n')
        continue;
    strcpy(entry.wrd, word);
    pi = WhereInTree(&entry, pt);
    if(NULL == pi)
        printf("%s is not in the list.\n", word);
    else
        printf("%s appears %d times.\n", word, pi->count);
}

void printitem(Item item)
{
    printf("%3d: %s", item.count, item.wrd);
}

int main()
{
    Tree wordcount;
    FILE * fp;
    char filename[SLEN];
    char word[SLEN];
    Item entry;
    char choice;


    printf("Enter name of file to be processed: \n");
    s_gets(filename, SLEN);

    if ((fp = fopen(filename, "r")) == 0)
    {
        printf("Can't open file %s. Bye.\n", filename);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&wordcount);

    while (fscanf(fp, "%s", word) == 1 && !TreeIsFull(&wordcount))
    {
        strcpy(entry.wrd, word);
        AddItem(&entry, &wordcount);
    }

    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 's' :  showwords(&wordcount);
            break;
        case 'f' :  findword(&wordcount);
            break;
        default  :  puts("Switching error");
        }
    }

    fclose(fp);
    puts("Done!");
    return 0;
}
