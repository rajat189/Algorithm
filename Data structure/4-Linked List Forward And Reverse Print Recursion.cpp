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
void forwdrecur(node* tmp){
	if(tmp==NULL) return;
	cout<<tmp->data<<" ";
	forwdrecur(tmp->next);
}
void revrecur(node* tmp){
	if(tmp==NULL) return;
	revrecur(tmp->next);
	cout<<tmp->data<<" ";
}
int main(void){
	std::ios_base::sync_with_stdio(0);
	//std::cin.tie(0); //use this only when no std::cout statement used
	int n,x;
	cout<<"how many no. you want to add :- ";
	cin>>n;
	while(n--){
		cout<<"enter the no. to insert";
		cin>>x;
		insert(x);
		cout<<"\n";
		print();
	}
	cout<<"\nprinting forward linked list using recursion: ";
	forwdrecur(head);
	cout<<"\nprinting reverse linked list using recursion: ";
	revrecur(head);
	//print();
}
