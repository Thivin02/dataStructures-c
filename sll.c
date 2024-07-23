#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int num){       //head insertion
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = head;
    head = temp;
}

// TailInsert function will not work as there is not global pointer node to link all the nodes.It started working when a temporary node is used to point to the newly inserted node !!.

void TailInsert(int num){       
    struct Node* pointer = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temporary;  //Since we are inserting at tail we need an another node to point to the next new node
    pointer->data = num;
    if(head == NULL){
        head = pointer;
        temporary = head;
    }
    else{
        temporary->next = pointer;
        temporary = pointer;
    }
}

void Print(){
    struct Node* print = head;
    while(print != NULL){       //should stop when there is no node to point at
        printf("%d ",print->data);
        print = print->next;
    }
}



void main(){
    head = NULL;
    int x;
    while(1){
        scanf("%d",&x);
        if(x == -1){
            break;
        }
        TailInsert(x);
    }
    Print();
}