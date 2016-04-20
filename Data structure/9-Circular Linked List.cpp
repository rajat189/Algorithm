#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
 
// Function to insert a node at the begining of a Circular linked list 
void push(struct node **head, int data){
    struct node *ptr1 = new node();
    struct node *temp = *head;
    ptr1->data = data;
    ptr1->next = *head;
 
    // If linked list is not NULL then set the next of last node 
    if(*head != NULL){
        while (temp->next != *head)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next=ptr1; //For the first node
 
    *head=ptr1;
}
 
// Function to print nodes in a given Circular linked list 
void printList(struct node *head){
    struct node *temp = head;
    if (head != NULL){
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}
int main(){
    struct node *head = NULL;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
 
    printf("Contents of Circular Linked List\n ");
    printList(head);
 
    return 0;
}
