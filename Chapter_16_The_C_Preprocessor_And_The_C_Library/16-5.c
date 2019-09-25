#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPOTS  51
#define PICKS  6

void random_pick(int arr[], int arsize, int picks)
{
    int i, index, temp;

    srand((unsigned int)time(0));
    if(picks > arsize)
    {
        fputs("Number of picks > array size.\n",stderr);
        fputs("Setting picks = array size.\n", stderr);
        picks = arsize;
    }

    for(i = 0; i < picks; ++i)
    {
        index = rand() % (arsize - 1);
        temp = arr[index];
        printf("%2d ", temp);
        if(i % 20 == 19)
            putchar('\n');
        arr[index] = arr[arsize - 1];
        arr[arsize - 1] = temp;
        arsize--;
    }
    if(i % 20 != 0)
        putchar('\n');
}

int main()
{
    int lotto[SPOTS];
    int i;
    char ch;

    for(i = 0; i < SPOTS; ++i)
        lotto[i] = i + 1;

    do
    {
        random_pick(lotto, SPOTS, PICKS);
        printf("Again? <y/n> ");
        ch = getchar();
        while(getchar() != '\n')
            continue;
    }while(ch == 'y' || ch == 'Y');

    printf("See your again!\n");
    return 0;
}
