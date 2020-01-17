//============================================================================
// Name        : assgn02-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class node{
public:
	char key[16];
	char meaning[50] ;
	node *left,*right;
	node(){
		left = right = NULL ;
	}
};

template<typename T>
class stack{
	T data[100];
	int top;
	public:
		stack(){
			top=-1;
		}
		int full(){
			if(top==99)
				return 1;
			return 0;
		}
		int empty(){
			if(top==-1)
				return 1;
			return 0;
		}
		void push(T p){
			if(!full()){
				top++;
				data[top]=p;
			}
		}
		T pop(){
			if(!empty()){
				T p=data[top];
				top--;
				return p;
			}
		}
};

class dict{
	node *root ;
public:
	dict(){
		root = NULL ;
	}
	void create() ;
	void update() ;
	void recinorder(node * root1) ;
	void recdinorder(node * root1) ;
	void adis();
	void ddis();
	void operator+ (dict);
	node *copy2(node*);
	node *deletenode(node* root,char k[]);
	void tradelete();
	void maxsearch();

};

void dict::create(){
	node *p = new node;
	cout<<"\nEnter keyword to be added in binary tree :";
	cin>>p->key;
	cout<<"\nEnter the meaning :";
	cin.ignore(1) ;
	cin.getline(p->meaning,50) ;
	if(root == NULL)
			root = p;
	else{
		node *q = new node;
		q = root;
		int flag = 0;
		do{
			int c;
			if(strcmp(q->key,p->key) < 0)
				c = 1 ;
			else
				c = 0 ;
			if(c == 0){
				if(q->left == NULL){
					q->left = p;
					flag = 1;
				}
				else
					q = q->left;
			}
			else{
				if(q->right == NULL){
					q->right = p;
					flag = 1;
				}
				else
					q = q->right;
			}
		}while(flag == 0);
	}
}

void dict::update(){
	char toupdate[16];
	cout<<"\nEnter keyword whose meaning is to be updated :" ;
	cin>>toupdate ;
	node *q = new node;
	q = root;
	int flag = 0 ;
	while(flag == 0 ){
		int j = strcmp(toupdate,q->key) ;
		if(j == 0){
			cout<<"\nEnter new meaning :" ;
			cin.ignore(1) ;
			cin.getline(q->meaning,50) ;
			flag = 1 ;
			cout<<"\nMeaning updated" ;
		}
		else if(j > 0)
			q = q->right ;
		else
			q = q->left ;
	}
}

void dict::recinorder(node *root1){
	if(root1 != NULL){
		recinorder(root1->left);
		cout<<"\n"<<root1->key<<" :\t"<<root1->meaning<<endl;
		recinorder(root1->right);
	}
}

void dict::adis(){
	recinorder(root) ;
}

void dict::recdinorder(node *root1){
	if(root1 != NULL){
		recinorder(root1->right);
		cout<<"\n"<<root1->key<<" :\t"<<root1->meaning<<endl;
		recinorder(root1->left);
	}
}

void dict::ddis(){
	recdinorder(root) ;
}

void dict::operator+ (dict obj)
{
	root=copy2(obj.root);
}

node *dict::copy2(node *p)
{
	if(p==NULL)
			return NULL;
	else
	{
		node *t = new node;
		strcpy(p->key,t->key) ;
		strcpy(p->meaning,t->meaning) ;
		t->left=copy2(p->left);
		t->right=copy2(p->right);
		cout<<"copied"<<endl;
		return t;
	}
}

node *dict::deletenode(node *root,char k[]){
	if(root == NULL )
		return root;
	if(strcmp(root->key,k) > 0){
		root->left = deletenode(root->left,k);
		return root;
	}
	else if(strcmp(root->key,k) < 0){
		root->right = deletenode(root->right,k);
		return root ;
	}

	if(root->left == NULL )
		return(root->right) ;
	else if(root->right == NULL)
		return (root->left) ;
	else{
		node *succparent = root->right;
		node *succ = root->right ;
		while(succ->left != NULL ){
			succparent = succ ;
			succ = succ->left ;
		}
		succparent->left = succ->right;
		strcpy(root->key,succ->key) ;
		delete(succ);
		return root;
	}
}

void dict::tradelete(){
	char k[16];
	cout<<"\nEnter keyword to search :";
	cin>>k;
	deletenode(root,k) ;
}

void dict::maxsearch(){
	char tosearch[16];
	cout<<"\nEnter keyword whose No. of traversal in search is to found :" ;
	cin>>tosearch ;
	node *q = new node;
	q = root;
	int flag = 0 ;
	int count = 0 ;
	while(flag == 0 ){
		int j = strcmp(tosearch,q->key) ;
		count++;
		if(j > 0)
			q = q->right ;
		else if(j < 0)
			q = q->left ;
		else
			flag = 1 ;
	}
	cout<<"\nTotal "<<count<<" traversal are required" ;
}

int main() {
	dict d,second ;
	int ch = 1 ;
	while(ch != 0){
		cout<<"\nPress";
		cout<<"\n1 to insert in BST"
			<<"\n2 to delete a keyword"
			<<"\n3 for updating a keyword"
			<<"\n4 for Assinging to another tree"
			<<"\n5 for Ascending Order Display"
			<<"\n6 for DEscending Order Display"
			<<"\n7 to find maximum no. traversal required for particular search"
			<<"\n8 for exit"
			<<"\nChoice - ";
		cin>>ch ;
		switch(ch){
		case 1:
			d.create() ;
			break ;
		case 2:
			d.tradelete();
			cout<<"\nKeyword and meaning deleted .";
			cout<<"\nNew tree :-";
			d.adis();
			break ;
		case 3:
			d.update() ;
			d.adis() ;
			break ;
		case 4:
			second = d ;
			cout<<"\nCopied tree in sequence :-" ;
			second.adis() ;
			break ;
		case 5:
			cout<<"\nAscending Display :-";
			d.adis();
			break ;
		case 6:
			cout<<"\nDescending Display :-";
			d.ddis();
			break;
		case 7:
			d.maxsearch();
			break;
		case 8:
			ch = 0 ;
			break ;
		}
	}
	return 0;
}
