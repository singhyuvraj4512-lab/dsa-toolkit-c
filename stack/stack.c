#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isempty(struct stack *sp)
{
    if (sp->top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *sp, int value)
{
    if (isfull(sp))
    {
        printf("stack overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

int pop(struct stack *sp)
{
    if (isempty(sp))
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        int val = sp->arr[sp->top];
        sp->top = sp->top - 1;
        return val;
    }
}

int peek(struct stack *sp, int i)
{
    int arrayind = sp->top - i + 1;
    if (arrayind < 0)
    {
        printf("not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayind];
    }
}
