#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollem(int sides)
{
    int roll;

    roll = rand() % sides + 1;
    return roll;
}

int main()
{
    int dice, count, roll;
    int sides;
    int set, sets;

    srand((unsigned int)time(0));

    printf("Enter the number of sets; enter q to stop:");
    while(scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice? ");
        if(scanf("%d %d", &sides, &dice) != 2)
        {
            printf("not integers -- terminating input loop.\n");
            break;
        }
        printf("Here are %d sets of %d %d-sides throws.\n", sets, dice, sides);
        for(set = 0; set < sets; ++set)
        {
            for(roll = 0, count = 0; count < dice; ++count)
                roll += rollem(sides);
            printf("%4d\t", roll);
            if(set % 15 == 14)
                printf("\n");
        }
        if(set % 15 != 0)
            printf("\n");
        printf("How many sets? Enter q to stop:");
    }
    printf("Good Fortune to you!\n");
    return 0;
}
