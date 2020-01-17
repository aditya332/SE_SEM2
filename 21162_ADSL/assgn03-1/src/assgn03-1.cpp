//============================================================================
// Name        : assgn03-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
public:
	int data ;
	int rflag,lflag ;
	node *left,*right ;
	node(){
		rflag = lflag = 1 ;
		left = right = NULL ;
	}
};

class tbt{
	node *root = new node ;;
public:
	tbt(){
		root->left = root->right = root ;
	}

	void create(){
		int n;
		cout<<"\nEnter no. nodes :" ;
		cin>>n;
		for(int i = 0;i<n;i++){
			node *p = new node ;
			cout<<"\nEnter the Data to be entered in the node :" ;
			cin>>p->data;
			if(root->lflag == 1){
				root->left = p ;
				root->lflag = 0 ;
				p->left = root ;
				p->right = root ;
			}
			else{
				int side = 0 ;
				node *q = new node ;
				q = root->left ;
				int flag1 = 0 ;
				do{
					cout<<"\nEnter side(0/1) :" ;
					cin>>side ;
					if(side == 0){
						if(q->lflag == 1){
							p->left = q->left ;
							p->right = q ;
							q->lflag = 0 ;
							q->left = p ;
							flag1 = 1 ;
						}
						else
							q = q->left ;
					}
					else{
						if(q->rflag == 1){
							p->right = q->right ;
							p->left = q ;
							q->rflag = 0 ;
							q->right = p ;
							flag1 = 1 ;
						}
						else
							q = q->right ;
					}
				}while(flag1 == 0);
			}
		}
	}

	void inorder(){
		node *q = new node ;
		q = root->left ;
		int flag2 = 0 ;
		while(q->lflag==0)
			q=q->left;
		while(q!=root){
			cout<<q->data<<"\t";
			if(q->rflag==1)
				q=q->right;
			else{
				q=q->right;
				while(q->lflag==0)
					q=q->left;
			}
		}
	}

	void preorder(){
		node* q = root->left ;
		while(q!=root){
			cout<<q->data<<"\t" ;
			if(q->lflag == 0)
				q = q->left ;
			else{
				while(q->rflag == 1 && q != root)
					q = q->right ;
				q = q->right ;
			}
		}
	}
};

int main() {
	tbt a ;
	int ch ;
	do{
		cout<<"\nPress"
			<<"\n1 to create Threaded Binary Tree "
			<<"\n2 for Inorder traversal "
			<<"\n3 for Preorder traversal "
			<<"\n4 to Exit " ;
		cin>>ch ;
		switch(ch){
		case 1:
			a.create() ;
			break ;
		case 2:
			a.inorder() ;
			break ;
		case 3:
			a.preorder() ;
			break ;
		default:
			break ;
		}
	}while(ch != 4) ;
	cout<<"\nEND !!!" ;
	return 0 ;
}
