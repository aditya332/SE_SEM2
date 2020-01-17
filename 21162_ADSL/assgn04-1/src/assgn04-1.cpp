//============================================================================
// Name        : assgn04-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
public :
	string city ;
	float time ;
	node *link ;
	node(){
		city = " " ;
		time = 0 ;
		link = NULL ;
	}
};

class graph{
	node *list[10] ;
	int n ;
public:
	graph(){
		n = 0 ;
	}

	void create_vert(){
		cout<<"\nEnter no. of cities :" ;
		cin>>n ;
		for(int i = 0;i<n;i++){
			cout<<"\nEnter name of the city :" ;
			cin>>list[i]->city ;
		}
	}

	void create_edge(){
		for(int i = 0 ; i<n ; i++){
			int m ;
			cout<<"\nNo. of links from "<<list[i]->city<<":" ;
			cin>>m ;
			node *q = list[i] ;
			for(int j = 0 ; j < m ; j++){
				node *p = new node ;
				cout<<"\nEnter destination city" ;
				cin>>p->city ;
				cout<<"\nEnter time taken :" ;
				cin>>p->time ;
				q->link = p ;
				q = q->link ;
			}
		}
	}
};

int main() {
	graph g ;
	g.create_edge() ;
	g.create_vert() ;
	return 0;
}
