//============================================================================
// Name        : assgn09-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
	int data ;
	node *next ;
public:
	node(int d){
		data = d ;
		next = NULL ;
	}

	friend class set ;
};

class set{
	node *head ;
public:
	set(){
		head = NULL ;
	}

	void insert(){
		int x ;
		cout<<"Enter element to insert in set:" ;
		cin>>x ;
		if(!find(x)){
			if(head==NULL){
				head=new node(x);
				return;
			}
			node* t=head;
			while(t->next!=NULL)
				t=t->next;
			t->next= new node(x);
		}
		else
			cout<<"Element already present\n";
	}

	void del(){
		int x ;
		cout<<"Enter element to delete:" ;
		cin>>x ;
		if(!find(x)){
			node* t = head ;
			if(t->data==x){
				head=t->next ;
				delete t ;
				return ;
			}
			while(t->next != NULL){
				if(t->next->data == x){
					node* p = t->next ;
					t->next = p->next ;
					delete p ;
					return ;
				}
				t = t->next ;
			}
		}
		else
			cout<<"\nElement already not present ." ;
	}

	void dis(){
		node *temp = head ;
		if(temp == NULL)
			cout<<"\nSet is empty" ;
		else{
			cout<<"\nElements of set are : ";
			while(temp != NULL ){
				cout<<temp->data ;
				temp = temp->next ;
			}
		}
	}

	bool find(int x){
		node* temp = head ;
		while(temp != NULL){
			if(temp->data == x)
				return true;
			temp = temp->next;
		}
		return false;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
