#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
struct node* head;
void insert (int x){
	node* temp = new node();
	temp->data=x;
	temp->next=head;
	head=temp;
}
void print(){
	node* tmp=head;
	cout<<"linked list is: ";
	while(tmp!=NULL){
		cout<<tmp->data<<"  ";
		tmp=tmp->next;
	}
	cout<<"\n";
}
void reverse(struct node* p){
	if(p->next==NULL){
		head=p;
		return ;
	}
	reverse(p->next);
	struct node* q=p->next;
	q->next=p;
	p->next=NULL;
}
int main(void){
	std::ios_base::sync_with_stdio(0);
	//std::cin.tie(0); //use this only when no std::cout statement used
	int n,x;
	cout<<"how many no. you want to add";
	cin>>n;
	while(n--){
		cout<<"enter the no. to insert";
		cin>>x;
		insert(x);
		cout<<"\n";
		print();
	}
	cout<<"\n reverse linked list is: ";
	reverse(head);
	print();
}
