// mall.c -- use the Queue interface
// compile with queue.c
#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h>   // for time()
#include "queue.h"  // change Item typedef
#define MIN_PER_HR 60.0

bool newcustomer(double x);   // is there a new customer?
Item customertime(long when); // set customer parameters

int main(void)
{
    Queue line1;
    Queue line2;
    Item temp1; // new customer data
    Item temp2;
    int hours;              // hours of simulation
    int perhour;            // average # of arrivals per hour
    long cycle, cyclelimit; // loop counter, limit
    long turnaways = 0;     // turned away by full queue
    long customers = 0;     // joined the queue
    long served = 0;        // served during the simulation
    long sum_line = 0;      // cumulative line length
    int wait_time1 = 0;     // time until Sigmund is free
    int wait_time2 = 0;
    double min_per_cust; // average time between arrivals
    long line_wait = 0;  // cumulative time in line

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int)time(0)); // random initializing of rand()
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust)) // 新顾客来了
        {
            if (QueueIsFull(&line1) && QueueIsFull(&line2)) // 如果都满了 走的顾客就+1
                turnaways++;
            else // 肯定都没满 或者一个满了
            {
                customers++;

                if (QueueIsFull(&line1)) // line1满了加line2
                {
                    temp2 = customertime(cycle); // 创建客户数据
                    EnQueue(temp2, &line2);
                }
                else
                {
                    temp1 = customertime(cycle); // 创建客户数据
                    EnQueue(temp1, &line1);
                }
            }
        }
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp1, &line1);
            wait_time1 = temp1.processtime;    // 设置接下来的咨询时间
            line_wait += cycle - temp1.arrive; // 计算总的 到来时间-咨询时间之前
            served++;                          // 咨询人数加一
        }

        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp2, &line2);
            wait_time2 = temp2.processtime;
            line_wait += cycle - temp2.arrive;
            served++;
        }

        if (wait_time1 > 0)
            wait_time1--;

        if (wait_time2 > 0)
            wait_time2--;

        sum_line += QueueItemCount(&line1);
        sum_line += QueueItemCount(&line2);
    }

    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("       turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
               (double)sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double)line_wait / served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    system("pause");
    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}