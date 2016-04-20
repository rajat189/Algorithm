#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
node* MergeLists(node *headA, node* headB){
	if (headA == NULL)
    	return headB;
	if (headB == NULL)
		return headA;
    node *result = NULL;

    if (headA-> data > headB -> data){
        result = headB;
        result->next = MergeLists(headA, headB->next);
    }
    else {
        result = headA;
        result->next = MergeLists(headA->next, headB);
    }
    return result;
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
