#include <stdio.h>
#include <time.h>

void delay(double time_delay)
{
    clock_t start, end;
    start = clock();
    do
    {
        end = clock();
    }while((end - start) / CLOCKS_PER_SEC < time_delay);
}

int main()
{
    double time_delay;
    printf("Please enter the elapsed time (in seconds): ");
    scanf("%lf", &time_delay);

    clock_t start, end;
    start = clock();
    delay(time_delay);
    end = clock();

    double time_elapsed = (end - start) / CLOCKS_PER_SEC;
    printf("The function costs %lf seconds.\n", time_elapsed);
    return 0;
}
