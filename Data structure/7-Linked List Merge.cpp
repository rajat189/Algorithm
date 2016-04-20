#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* MergeLists(node *headA, node* headB){ 
    
	if(headA==NULL)return headB;
    if(headB==NULL)return headA;
    
    node *new_head=NULL;
    node *last=NULL;
    if(headA->data < headB->data ){
        new_head=headA;
        headA=headA->next;
    }
    else {
        new_head=headB;
        headB=headB->next;
    }
    last=new_head;
    while(headA && headB){
       if(headA->data < headB->data){
           last->next=headA;
           headA=headA->next;
       } 
       else {
           last->next=headB;
           headB=headB->next;
       }
       last=last->next;
    }
    if(headA==NULL){
        last->next=headB;
    }
    else {
        last->next=headA;
    }
    return new_head;
}

void push(struct node** head, int data){
    node* tmp = new node();
    tmp->data  = data;
    tmp->next = (*head);
    (*head)    = tmp;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node){
    while (node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}
int main(){
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;
    
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
    
	res = MergeLists(a, b);
    
    printf("Merged Linked List is: \n");
    printList(res);
    return 0;
}
