//============================================================================
// Name        : assgn08-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
	string key ;
	double p , q ;
	node *left , *right ;
public :
	node(){
		this->key[0] = '\0' ;
		this->p = 0 ;
		this->q = 0 ;
		this->left = NULL ;
		this->right = NULL ;
	}
	
	void read(){
		cout<<"\nEnter the Key : " ;
		cin>>key ;
		cout<<"\nEnter probability of searching this key : " ;
		cin>>p ;
	}
	
	void read_q(){
		cout<<"\nEnter probability of failure : " ;
		cin>>q ;
	}
	
	void disp(){
		cout<<"\nKey : "<<key<<" with probability of "<<p<<" ." ;
	}
	
	friend class cost_class ;
};

class cost_class{
	node *list[10] ;
	int n ;
	double weight[10][10] , cost[10][10] ;
	int root[10][10] ;
public:
	cost_class(){
		n = 0 ;
		for(int i =0 ;i<10 ; i++){
			list[i] = new node ;
			cost[i][i] = 0 ;
			root[i][i] = 0 ;
		}
	}
	
	void input(){
		cout<<"\nEnter total no. of nodes : " ;
		cin>>n ;
		int i ;
		for( i=1 ;i<=n ; i++){
			list[i]->read() ;
			list[i-1]->read_q() ;
		}
		list[--i]->read_q() ;
	}
	
	void calculate(){
		for(int i = 0 ; i<n ; i++){
			weight[i][i] = list[i]->q ;
			weight[i][i+1] = list[i]->q + list[i+1]->q + list[i+1]->p ;
			root[i][i+1] = i+1 ;
			cost[i][i+1] = weight[i][i+1] ;
			//cout<<i<<"\t"<<i+1<<"\t"<<weight[i][i+1]<<"\n" ;
		}
		weight[n][n] = list[n]->q ;
		root[n][n] = 0 ;
		cost[n][n] = 0 ;
		int j = 0 ,k = 0,i = 0;
		for( int m = 2 ;m <= n ; m++){
			for( i = 0 ;i <= n - m ; i++){
				j = i + m ;
				weight[i][j] = weight[i][j-1] + list[j]->p + list[j]->q ;
				//cout<<i<<"\t"<<j<<"\t"<<weight[i][j]<<"\n" ;
				double min = 100 ,tryy = 0 ;
				for(int kk = i + 1 ; kk<=j ; kk++){
					tryy = cost[i][kk-1] + cost[kk][j] ;
					if(tryy < min){
						min = tryy ;
						k = kk ;
					}
				}
				cost[i][j] = weight[i][j] + min ;
				root[i][j] = k ;
				//cout<<i<<"\t"<<j<<"\t"<<cost[i][j]<<"\n" ;
			}
		}
		obst(i,j,k)
		//cout<<"\n"<<root[0][3]<<"\t"<<cost[0][3] ; 
	}
	
	void obst(int i , int j , int k){
		node *roott ;
		roott = list[k] ;
		if(root[i][k-1] == 0)
			roott->left = NULL ;
		else
			roott->left = list[root[i][k-1]] ;
		if(root[k,j] == 0)
			roott->right = NULL ;
		else
			roott->right = list[root[k,j]] ;
		
	}
};

int main() {
	cost_class c ;
	c.input() ;
	c.calculate() ;
	return 0;
}
