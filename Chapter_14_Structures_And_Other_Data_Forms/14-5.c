#include <stdio.h>
#include <string.h>
#define N 14
#define CSIZE 4
#define SCORES 3

struct name
{
    char first[N];
    char last[N];
};

struct student
{
    struct name person;
    float scores[SCORES];
    float mean;
};

void get_scores(struct student array[], int lim)
{
    for(int i = 0; i < lim; ++i)
    {
        printf("Please enter %d scores for %s %s:", SCORES, array[i].person.first, array[i].person.last);
        for(int j = 0; j < SCORES; ++j)
        {
            while(scanf("%f", &array[i].scores[j]) != 1)
            {
                scanf("%*s");
                printf("Please use numberic input.\n");
            }
        }
    }
}

void find_means(struct student array[], int lim)
{
    float sum = 0.0;
    for(int i = 0; i < lim; ++i)
    {
        for(int j = 0; j < SCORES; ++j)
            sum += array[i].scores[j];
        array[i].mean = sum / SCORES;
    }
}

void show_class(const struct student array[], int lim)
{
    char wholename[2 * N];
    for(int i = 0; i < lim; ++i)
    {
        strcpy(wholename, array[i].person.first);
        strcat(wholename, " ");
        strcat(wholename, array[i].person.last);
        printf("%27s: ", wholename);
        for(int j = 0; j < SCORES; ++j)
            printf("%6.1f ", array[i].scores[j]);
        printf("Average = %5.2f\n", array[i].mean);
    }
}

void show_ave(const struct student array[], int lim)
{
    int i, j;
    float total;
    printf("\n%27s: ", "QUIZ AVERAGES");

    for(i = 0; i < SCORES; ++i)
    {
        for(total = 0.0, j = 0; j < lim; ++j)
            total += array[j].scores[i];
        printf("%6.2f ", total / lim);
    }
    for(total = 0.0, i = 0; i < lim; ++i)
        total += array[i].mean;
    printf("     All = %5.2f\n", total / lim);
}

int main()
{
    struct student class[CSIZE] =
    {
        { "Flip", "Snide"},
        { "Clare", "Voyans"},
        { "Bingo", "Higgs"},
        { "Fawn", "Hunter"}
    };

    get_scores(class, CSIZE);
    find_means(class, CSIZE);
    show_class(class, CSIZE);
    show_ave(class, CSIZE);

    return 0;
}
