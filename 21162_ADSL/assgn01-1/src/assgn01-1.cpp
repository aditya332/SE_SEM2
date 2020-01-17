#include <iostream>
using namespace std;

class node{
		public:
		int data;
		node *left;
		node *right;
		node(){
			data = 0;
			left = right = NULL;
		}
};

class stacknode{
	public:
	node* link;
	int flag;
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

class btree{
	node *root;
	public:
		btree(){
			root = NULL ;
		}

		void create();
		void erase(node *r);
		void traerase();
		void mirror(node *root);
		void tramirror();
		void preorder();
		void inorder();
		void postorder();
		void recpreorder(node *root1);
		void recinorder(node *root2);
		void recpostorder(node *root3);
		void trarecorder(int a);
		void operator+ (btree);
		node *copy2(node*);
		int count();
		int countrec(node*);
		int compare(btree);
		int check(node*, node*);
		void show_int();
		void show_1(node *p);
		void leaf();
		void show2(node*);
};

void btree::create(){
	int n;
	cout<<"\nEnter total no. of nodes:";
	cin>>n;
	for(int i = 0;i<n;i++){
		node *p = new node;
		cout<<"\nEnter no. to be added in binary tree :";
		cin>>p->data;
		if(root == NULL)
				root = p;
		else{
			node *q = new node;
			q = root;
			int flag = 0;
			do{
				int c;
				cout<<"\nPress '0' to add the number to the left part of previous node"
					<<"\nPress '1' to add the number to the right part of previous node";
				cin>>c;
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
}

void btree::erase(node *r){
	if(r){
		erase(r->left);
		erase(r->right);
		delete(r);
	}
}

void btree::traerase(){
	erase(root);
}

void btree::mirror(node *root){
	if(root){
		mirror(root->left);
		mirror(root->right);
		swap(root->left,root->right);
	}
}

void btree::tramirror(){
	mirror(root);
}

void btree::preorder(){
	node *q = new node;
	q = root;
	stack <node*> b;
	int flag = 0 ;
	while(flag == 0){
		if(q!=NULL){
			cout<<q->data<<"\t";
			b.push(q);
			q = q->left;
		}
		else if(!b.empty()){
			q = b.pop();
			q = q->right;
		}
		else
			flag = 1;
	}
}

void btree::inorder(){
	node *q = new node;
	q = root;
	stack <node*> b;
	int flag = 0 ;
	while(flag == 0){
		if(q!=NULL){
			b.push(q);
			q = q->left;
		}
		else if(!b.empty()){
			q = b.pop();
			cout<<q->data<<"\t";
			q = q->right;
		}
		else
			flag = 1;
	}
}

void btree::postorder(){
	node *p=root;
	stack<stacknode> S;
	stacknode st;
	while(p!=NULL){
		st.link=p;
		st.flag=0;
		S.push(st);
		p=p->left;
	}
	while(!S.empty()){
		st=S.pop();
		if(st.flag==0){
			st.flag=1;
			p=st.link;
			S.push(st);
			p=p->right;
			while(p!=NULL){
				st.link=p;
				st.flag=0;
				S.push(st);
				p=p->left;
			}
		}
		else if(st.flag==1){
			p=st.link;
			cout<<p->data<<"\t";
		}
	}
}

void btree::recinorder(node *root1){
	if(root1 != NULL){
		recinorder(root1->left);
		cout<<root1->data<<"\t";
		recinorder(root1->right);
	}
}

void btree::recpostorder(node *root1){
	if (root1 != NULL){
			recpostorder(root1->left);
			recpostorder(root1->right);
			cout<<root1->data<<"\t";
	}
}

void btree::recpreorder(node *root1){
		if(root1 != NULL){
			cout<<root1->data<<"\t";
			recpreorder(root1->left);
			recpreorder(root1->right);
		}
	}

void btree::trarecorder(int a){
	if(a==1)
		recpreorder(root);
	if(a==2)
		recinorder(root);
	if(a == 3)
		recpostorder(root);
}

void btree::operator+ (btree obj)
{
	root=copy2(obj.root);
}

node *btree::copy2(node *p)
{
	if(p==NULL)
			return NULL;
	else
	{
		node *t = new node;
		t->data = p->data;
		t->left=copy2(p->left);
		t->right=copy2(p->right);
		cout<<"copied"<<endl;
		return t;
	}
}

int btree::count(){
	return countrec(root);
}

int btree::countrec(node *p){
	if(p==NULL){
		return 0;
	}
	else{
		return 1+countrec(p->left)+countrec(p->right);
	}
}

int btree::compare(btree var){
	if(count()!=var.count())
		return 0;
	else
	{
		return check(root, var.root);
	}
}

int btree::check(node *p, node *q){
	if(p==NULL && q==NULL)
			return 0;
	else if(p==NULL || q==NULL){
		return 0;
	}
	else{
		int l=check(p->left, q->left);
		int r=check(p->right, q->right);
		if(p->data==q->data)
			return 1+l+r;
		else
				return l+r;
	}
}

void btree::show_int(){
	show_1(root);
}

void btree::show_1(node *p){
	if(p==NULL)
		return;
	if(p->left==NULL && p->right==NULL)
		return;
	else{
		show_1(p->left);
		show_1(p->right);
		if(p!=root)
			cout<<p->data<<" ";
	}
}

void btree::leaf(){
	show2(root);
}

void btree::show2(node *p){
	if(p==NULL)
			return;
	else if(p->left==NULL && p->right==NULL){
		cout<<p->data<<" ";
	}
	else{
		show2(p->left);
		show2(p->right);
	}
}

int main(){
	btree c,second,second2;
	int ch = 1,res;
	while(ch != 8){
		cout<<"\n1 for Creating Binary Tree"
			<<"\n2 for assigning this tree to another"
			<<"\n3 for Erase all nodes of Tree"
			<<"\n4 for creating Mirror Image"
			<<"\n5 for two tree Equivalance"
			<<"\n6 for Preorder,Inorder and Postorder traversal of tree(recursive and non-recursive)"
			<<"\n7 for Internal and Leaf Nodes"
			<<"\n8 for EXIT:";
		cin>>ch;
		switch(ch){
			case 1:
				c.create();
				break;
			case 2:
				second=c;
				cout<<"\nTree copied into another tree";
				break;
			case 3:
				c.traerase();
				cout<<"\nTree Erased";
				break;
			case 4:
				c.tramirror();
				cout<<"\nMirror image of tree created";
				break;
			case 5:
				cout<<"\nEnter second Binary Tree";
				second2.create();
				res=c.compare(second2);
				if(res==c.count())
					cout<<"Equal"<<endl;
				else
					cout<<"Not equal"<<endl;

				break;
			case 6:
				cout<<"\nPreorder traversal:";
				c.preorder();
				cout<<"\nInorder traversal:";
				c.inorder();
				cout<<"\nPostorder traversal:";
				c.postorder();
				cout<<"\nRecursively:-";
				cout<<"\nPreorder traversal:";
				c.trarecorder(1);
				cout<<"\nInorder traversal:";
				c.trarecorder(2);
				cout<<"\nPostorder traversal:";
				c.trarecorder(3);
				break;
			case 7:
				cout<<"\nInternal nodes are:";
				c.show_int();
				cout<<"\nLeaf nodes are:";
				c.leaf();
				break;
			default:
				break;
		}
	}
	cout<<"\nTHE END !!!";
	return 0 ;
}
