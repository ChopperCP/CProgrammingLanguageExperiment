#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Student{
    char number[20];
    char name[20];
    char gender[5];
    unsigned age;
    char address[100];
};

struct Node {
    struct Student data;
    struct Node* next;
};

//struct Student* create_list(struct Student head)


int main() {
    // Initialize the example data
    struct Student student1;
    strcpy(student1.number,"1111111");
    strcpy(student1.name,"ChopperCP");
    strcpy(student1.gender,"Male");
    student1.age=21;
    strcpy(student1.gender,"Earth");

    // Init array;
    struct Student students_arr[10];
    for (int i=0;i<10;++i){
        students_arr[i]=student1;
    }

    // Init list
    struct Node head;
    head.data=student1;
    head.next=NULL;

    struct Node* curr=&head;
    for (int i=0;i<9;++i){
        struct Node* new_node=malloc(sizeof(struct Node));
        struct Student* student1_clone=malloc(sizeof(struct Student));
        memcpy(student1_clone,&student1,sizeof(struct Student));
        new_node->data=*student1_clone;
        new_node->next=NULL;
        curr->next=new_node;
        curr=new_node;
    }


    // Print out the address.
    for (int i=0;i<10;++i){
        printf("[Array] the %dth element is at: 0x%x\n",i,&students_arr[i]);
    }

    curr=&head;
    for (int i=0;i<10;++i){
//        for (int deref=i;deref>0;--deref) {
//            curr=curr->next;
//        }
        printf("[List] the %dth element is at: 0x%x\n", i, &(curr->data));
        curr=curr->next;
    }


    return 0;
}
