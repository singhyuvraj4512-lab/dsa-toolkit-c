#ifndef QUEUE_H
#define QUEUE_H

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int queue_isfull(struct queue *q);
int queue_isempty(struct queue *q);
void enqueue(struct queue *q, int val);
int dequeue(struct queue *q);

#endif