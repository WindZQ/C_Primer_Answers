#include <stdio.h>
const int m_h = 60;

int main()
{
    int time, hour, mintues;
    printf("Please enter the time to convert in mintues:");
    scanf("%d", &time);
    while(time > 0)
    {
        hour = time / m_h;
        mintues = time % m_h;
        printf("%d mintues equals to %d hours and %d mintues.\n", time, hour, mintues);
        printf("Please enter another time(time <= 0 to quit):");
        scanf("%d", &time);
    }
    printf("See your again!\n");
    return 0;
}
