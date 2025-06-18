#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack* create_stack(int max){
    t_stack* stack = (t_stack*)malloc(sizeof(t_stack));
    
    stack->calls = (int*)malloc(max * sizeof(int));
    stack->max = max;
    stack->top = 0;

    return stack;
}

void push(t_stack* stack, int p){
    if(is_full(stack)){
        return;
    }

    stack->calls[stack->top++] = p;
}

int pop(t_stack* stack){
    return stack->calls[--stack->top];
}

int is_full(t_stack* stack){
    return stack->top == stack->max - 1;
}

int is_empty(t_stack* stack){
    return stack->top == 0;
}

void clear(t_stack* stack){
    stack->top = 0;
}