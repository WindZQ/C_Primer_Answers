#ifndef QUEUE_H_
#define QUEUE_H_

/*决定使用哪种结构的Item*/
#define MALL
/*#define TEST*/

#include <stdbool.h>

#ifdef TEST
typedef int Item;
#endif

#ifdef MALL
struct customer
{
    long arrive;
    int processtime;
};
typedef struct customer Item;
#endif

#define MAXQUEUE 10

struct node
{
    Item item;
    struct node * next;
};
typedef struct node Node;

struct queue
{
    Node * front;
    Node * rear;
    unsigned int len;
};
typedef struct queue Queue;

void InitializeQueue(Queue *);

bool QueueIsFull(Queue *);

bool QueueIsEmpty(Queue *);

unsigned int QueueItemCount(Queue *);

bool EnQueue(Item, Queue *);

bool DelQueue(Item *, Queue *);

void FreeQueue(Queue *);

#endif
