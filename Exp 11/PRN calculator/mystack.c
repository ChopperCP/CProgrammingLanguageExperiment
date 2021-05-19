//
// Created by win10 on 2021/5/12.
//

#include "mystack.h"
#include <stdio.h>
#include <memory.h>


void init_stack(struct MyStack* stack){
    memset(stack->stack,0,sizeof(int)*MAX_SIZE);
    stack->base=stack->stack;
    stack->upper_limit=stack->base+MAX_SIZE-1;
    stack->top=NULL;
}

void empty(struct MyStack* stack){
    init_stack(stack);
}

int is_empty(struct MyStack* stack){
    if (stack->top==NULL)
        return 1;
    return 0;
}

int is_full(struct MyStack* stack){
    if (stack->top==stack->upper_limit)
        return 1;
    return 0;
}

int push(struct MyStack* stack, int element){
    if (is_full(stack)){
        printf("[!] Stack is full, cannot push element.\n");
        return -1;
    }

    if (is_empty(stack)) {
        stack->top=stack->base;
        *(stack->top) = element;
    }
    else{
        ++stack->top;
        *(stack->top) = element;
    }

    return 0;
}

int pop(struct MyStack* stack){
    if (is_empty(stack)){
        printf("[!] Stack is empty, cannot pop element.\n");
        return 0xffffffff;
    }
    int top_element=*(stack->top);
    --stack->top;

    if (stack->top<stack->base)
        // Stack empty
        stack->top=NULL;
    return top_element;
}

int top(struct MyStack* stack){
    if (is_empty(stack)){
        printf("[!] Stack is empty, no top element.\n");
        return 0xffffffff;
    }
    return *(stack->top);
}

