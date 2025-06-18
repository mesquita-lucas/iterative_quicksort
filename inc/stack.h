#ifndef STACK_H
#define STACK_H

typedef struct stack{
    int* calls;
    int max;
    int top;
} t_stack;

t_stack* create_stack(int max);

void push(t_stack* stack, int p);

int pop(t_stack* stack);

int is_empty(t_stack* stack);

int is_full(t_stack* stack);

void clear(t_stack* stack);

#endif