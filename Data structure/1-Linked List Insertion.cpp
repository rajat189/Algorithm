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
void pos(int data,int n){   
	node* tmp1 =new node();
	tmp1->data=data;
	tmp1->next=NULL;
	if(n==1){
    	tmp1->next=tmp;
    	head=tmp1;
	}
	node* tmp2=head;
	for(int i=1;i<n-1;i++){
		tmp2=tmp2->next;
	}
	tmp1->next=tmp2->next;
	tmp2->next=tmp1;
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
	cout<<"enter element to insert at nth position";
	int p,e;
	cin>>e>>p;
	pos(e,p);
	print();
}

