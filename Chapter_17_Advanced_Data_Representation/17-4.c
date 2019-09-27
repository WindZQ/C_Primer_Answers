#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HOUR (60)

bool newcustomer(double);
Item customertime(long);


int main(void)
{
    Queue line;
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    double min_per_cust;
    long turnaway;
    long customers;
    long wait_time = 0;
    long line_wait = 0;
    long served = 0;
    long sum_line = 0;

    InitializeQueue(&line);
    srand(time(0));
    puts("Case study: Sigmund Lander's Adv ffice Booth");
    puts("Enter the number if simulation hours: ");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HOUR * hours;
    puts("Enter thr average number of customers per hour: ");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HOUR / perhour;

    for(cycle = 0; cycle < cyclelimit; cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if(QueueIsFull(&line))
                turnaway++;
            customers++;
            temp = customertime(cycle);
            EnQueue(temp, &line);
        }

        if(wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DelQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += wait_time;
            served++;
        }
        if(wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
    }

    if(customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("customers served: %ld\n", served);
        printf("turnaway: %ld\n", turnaway);
        printf("average queue size: %lf\n",
               (double)sum_line / cyclelimit);
        printf("average line wait time: %ld\n",
               (double)line_wait / served);
    }
    else
        puts("No customer.");
    FreeQueue(&line);
    puts("Bye!");

    return 0;
}

bool newcustomer(double x)
{
    if(rand()*x / RAND_MAX < 1)
        return true;
    else
        return false;
}

Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
