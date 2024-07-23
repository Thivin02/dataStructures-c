/* Node deletion involves applying the logic of insertion of node at nth position reciprocally.
That is, the node which is to be removed, before removing the next part of the node pointing to
the next node should be retrieved before deleting it.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int num, int n){
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = num;
    ptr1->next = NULL;
    if(n == 1 || head == NULL){  //Incase if the insert function doesn't start with index (n = 1) *or function is used to validate
        ptr1->next = head;
        head = ptr1;
        return;
    }
    struct Node* ptr2 = head;
    for(int i=1; i<=n-2;i++){
        ptr2 = ptr2->next;
    }
    ptr1->next = ptr2->next;
    ptr2->next = ptr1;
}

void Delete(int n){     // what happens if n is 1
    struct Node* ptr1 = head;
    if(n ==1){      // This handles if n is 1
        head = ptr1->next;
        free(ptr1);
        return;
    }

    for(int i=1 ; i<=n-2; i++){
        ptr1 = ptr1->next;
    }
    struct Node* ptr2 = ptr1->next;
    ptr1->next = ptr2->next;
    free(ptr2);
}

void Print(){
    struct Node* print = head;
    while(print != NULL){
        printf("%d ",print->data);
        print = print->next;
    }
}


void main(){
    head = NULL;
    Insert(1,1);
    Insert(2,1);
    Insert(3,2);
    Insert(4,2);
    Insert(5,5);
    Delete(1);
    Print();
}