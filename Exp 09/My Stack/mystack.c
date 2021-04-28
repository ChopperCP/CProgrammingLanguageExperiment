#include <stdio.h>
#include <memory.h>

#define MAX_SIZE 10

struct MyStack{
    int stack[MAX_SIZE];
    int* base;
    int* upper_limit;   // Upper limit, stack top cannot go beyond this address.
    int* top;
};

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

int main() {
    struct MyStack stack;
    init_stack(&stack);

    // Fill up the stack
    for (int i=0;i<MAX_SIZE;++i){
        push(&stack,i);
    }

    // Stack overflow, or is it?
    push(&stack,2333);

    int top_element=top(&stack);
    printf("[*] Top element: %d\n", top_element);

    // Pop empty the stack.
    for (int i=0;i<MAX_SIZE;++i){
        int element=pop(&stack);
        printf("[*] Poped %d\n",element);
    }

    // Segmentation fault, or is it?
    pop(&stack);

    // Fill up the stack
    for (int i=0;i<MAX_SIZE;++i){
        push(&stack,i);
    }
    empty(&stack);
    if (is_empty(&stack))
        printf("%s","[*] Stack empty");

    return 0;
}
