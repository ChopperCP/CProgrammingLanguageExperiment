#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystack.h"

#define MAX_EXPRESSION_LEN 200

int main() {
    char expression[MAX_EXPRESSION_LEN];
    memset(expression,0,sizeof(char)*MAX_EXPRESSION_LEN);
    gets(expression);

    size_t expression_len=strlen(expression);
    struct MyStack stack;
    init_stack(&stack);

    for (int i = 0;i<expression_len;++i){
        if (expression[i]>='0' && expression[i]<='9'){
            // If numbers, push it to the stack.
            push(&stack,atoi(&expression[i]));
        }
        else if (expression[i]=='='){
            break;
        }
        else{
            // If operator, pop 2 elements/numbers to calculator.
            int rhs=pop(&stack);
            int lhs=pop(&stack);
            char operator=expression[i];
            switch (operator) {
                case '+':
                    push(&stack,lhs+rhs);
                    break;
                case '-':
                    push(&stack,lhs-rhs);
                    break;
                case '*':
                    push(&stack,lhs*rhs);
                    break;
                case '/':
                    push(&stack,lhs/rhs);
                    break;
                default:
                    // Restore stack.
                    push(&stack,lhs);
                    push(&stack,rhs);
                    break;
            }
        }
    }
    printf("%d", pop(&stack));

    return 0;
}
