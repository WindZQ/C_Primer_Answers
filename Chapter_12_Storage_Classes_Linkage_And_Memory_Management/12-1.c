#include <stdio.h>
void critic(int *u)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", u);
}

int main()
{
    int units;
    printf("How many pounds to a firkin of buffer?\n");
    scanf("%d", &units);
    while(units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}
