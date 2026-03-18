#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queue_isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int queue_isempty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int val)
{
    if (queue_isfull(q))
    {
        printf("queue overflow");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (queue_isempty(q))
    {
        printf("no element to dequeue");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    return a;
}
