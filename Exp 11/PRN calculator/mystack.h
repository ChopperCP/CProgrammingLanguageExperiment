//
// Created by win10 on 2021/5/12.
//

#ifndef PRN_CALCULATOR_MYSTACK_H
#define PRN_CALCULATOR_MYSTACK_H

#include <stddef.h>

#define MAX_SIZE 200

struct MyStack{
    int stack[MAX_SIZE];
    int* base;
    int* upper_limit;   // Upper limit, stack top cannot go beyond this address.
    int* top;
    size_t size;
};

void init_stack(struct MyStack* stack);

void empty(struct MyStack* stack);

int is_empty(struct MyStack* stack);

int is_full(struct MyStack* stack);

int push(struct MyStack* stack, int element);

int pop(struct MyStack* stack);

int top(struct MyStack* stack);




#endif //PRN_CALCULATOR_MYSTACK_H
