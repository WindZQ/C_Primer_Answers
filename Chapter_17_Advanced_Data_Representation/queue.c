#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(Item, Node *);
static void CopyToItem(Node *, Item *);

void InitializeQueue(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->len = 0;
}

bool QueueIsFull(Queue * pq)
{
    return pq->len >= MAXQUEUE;
}

bool QueueIsEmpty(Queue * pq)
{
    if(pq->front == NULL && pq->rear == NULL && pq->len == 0)
        return true;
    else
        return false;
}

unsigned int QueueItemCount(Queue * pq)
{
    return pq->len;
}

bool EnQueue(Item item, Queue * pq)
{
    Node * pnode;

    if(QueueIsFull(pq))
        return false;
    else
    {
        pnode = (Node *)malloc(sizeof(Node));
        if(pnode == NULL)
            return false;
        CopyToNode(item, pnode);
        pnode->next = NULL;
        if(QueueIsEmpty(pq))
        {
            pq->front = pnode;
            pq->rear = pnode;
        }
        else
        {
            pq->rear->next = pnode;
            pq->rear = pnode;
        }
        pq->len++;
        return true;
    }
}

bool DelQueue(Item * pitem, Queue * pq)
{
    Node * pnode;

    if(QueueIsEmpty(pq))
        return false;
    pnode = pq->front;
    CopyToItem(pnode, pitem);
    if(pq->len == 1)
    {
        pq->front = NULL;
        pq->rear = NULL;
    }
    else
        pq->front = pnode->next;
    free(pnode);
    pq->len--;
    return true;
}

void FreeQueue(Queue * pq)
{
    Item dummy;
    while(!QueueIsEmpty(pq))
        DelQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}

static void CopyToItem(Node * pnode, Item * pitem)
{
    *pitem = pnode->item;
}
