/*To insert a node at nth position we assume that the position to be inserted is valid.If in 
case we need to insert between 2 nodes we need the new node to point to the next node and 
node should point to the new node */


//Special cases : Inserting at begining and inserting at end


/*Logic : We have to iterate over nth node and then pass the address of the next node to the
newly inserted node before updating the previous node (next section) to point to the new node*/


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
    Print();
}
