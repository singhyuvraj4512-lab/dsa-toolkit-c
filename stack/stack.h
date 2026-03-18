#ifndef STACK_H
#define STACK_H

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *sp);
int isfull(struct stack *sp);
void push(struct stack *sp, int value);
int pop(struct stack *sp);
int peek(struct stack *sp, int i);

#endif