#include <stdio.h>

void print_address_copy(int i){
    printf("[print Address(copy)] parameter: %d, parameter address: 0x%x\n",i,&i);
}
void print_address_reference(int* i){
    printf("[print Address(reference)] parameter: %d, parameter address: 0x%x\n",*i,i);
}


int main() {
    int i=233;
    printf("[main] variable: %d, Address: 0x%x\n",i,&i);
    print_address_copy(i);
    print_address_reference(&i);
    return 0;
}
