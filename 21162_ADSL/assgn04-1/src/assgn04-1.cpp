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
	int in , out ;
	node *link ;
	node(){
		city = " " ;
		time = 0 ;
		in = 0 ;
		out = 0 ;
		link = NULL ;
	}
};

class graph{
	node *list[10] ;
	int n ;
public:
	graph(){
		n = 0 ;
		for(int i =0 ;i<10 ; i++)
			list[i] = new node ;
	}

	void create_network(){
		cout<<"\nEnter no. of cities" ;
		cin>>n ;
		for(int i = 0;i<n ;i++){
			cout<<"\nEnter name of the city to be added in network :" ;
			cin>>list[i]->city ;
		}
		int m ;
		for(int i = 0;i<n ;i++){
			node *q = list[i] ;
			cout<<"\nNo. of links from "<<list[i]->city<<":" ;
			cin>>m ;
			q->out = m ;
			for(int j = 0 ; j < m ; j++){
				node *p = new node ;
				cout<<"\nEnter destination city" ;
				cin>>p->city ;
				incoming(p->city,1) ;
				cout<<"\nEnter time taken :" ;
				cin>>p->time ;
				q->link = p ;
				q = q->link ;
			}
		}
	}

	void add_vert(){
		node *q = list[n] ;
		cout<<"\nEnter name of the city to be added in network :" ;
		cin>>list[n]->city ;
		int m ;
		cout<<"\nNo. of links from "<<list[n]->city<<":" ;
		cin>>m ;
		q->out = m ;
		for(int j = 0 ; j < m ; j++){
			node *p = new node ;
			cout<<"\nEnter destination city" ;
			cin>>p->city ;
			incoming(p->city,1) ;
			cout<<"\nEnter time taken :" ;
			cin>>p->time ;
			q->link = p ;
			q = q->link ;
		}
		n++ ;
	}

	void add_edge(){
		string scity ;
		cout<<"\nEnter start city :" ;
		cin>>scity ;
		for(int i = 0 ; i<n ; i++){
			if(list[i]->city.compare(scity) == 0){
				list[i]->out++ ;
				break ;
			}
		}
		node *p = new node ;
		cout<<"\nEnter destination city :" ;
		cin>>p->city ;
		cout<<"\nEnter time taken for travel :" ;
		cin>>p->time ;
		incoming(p->city,1) ;
		for(int i = 0 ; i<n ; i++){
			if(list[i]->city.compare(scity) == 0){
				node *q = list[i] ;
				while(q->link != NULL)
					q = q->link ;
				q->link = p ;
				break ;
			}
		}
	}

	void cal(){
		string dcity ;
		cout<<"\nEnter name of the city :" ;
		cin>>dcity ;
		for(int i = 0 ; i<n ; i++){
			if(list[i]->city.compare(dcity) == 0){
				cout<<"\nTotal no. of incoming flights = "<<list[i]->in ;
				cout<<"\nTotal no. of outgoing flights = "<<list[i]->out ;
				break ;
			}
		}
	}

	int incoming(string find , int x){
		int i ;
		for(i = 0 ; i<n ; i++){
			if(list[i]->city.compare(find) == 0){
				if(x == 1)
					list[i]->in++ ;
				break ;
			}
		}
		return i ;
	}

	void traversal(){
		int visit[n] , next[n] ;
		for(int i =0 ;i<n ; i++)
			visit[i] = next[i] = 0 ;
		string tname ;
		cout<<"\nEnter city name to start traversal from :" ;
		cin>>tname ;
		cout<<"\nTraversal result is :" ;
		cout<<"\n"<<tname ;
		visit[incoming(tname,0)]++ ;
		int counter = 0 ;
		node *q = list[incoming(tname,0)] ;

		for( int i = incoming(tname,0) ;i<n ; i++){
			while(q != NULL){
				int j = incoming(q->city,0) ;
				visit[j]++ ;
				if(visit[j] == 1)
					cout<<"\n"<<q->city ;
				q = q->link ;
			}
		}
	}
};

int main() {
	graph g ;
	int ch ;
	do{
		cout<<"\nPress"
			<<"\n1 to add cities and it's links "
			<<"\n2 to add new city and it's links "
			<<"\n3 to add new link between two cities "
			<<"\n4 to get total no. of incoming and outgoing flights from a city "
			<<"\n5 for traversal of network "
			<<"\n6 to exit ";
		cin>>ch ;
		switch(ch){
		case 1:
			g.create_network() ;
			break ;
		case 2:
			g.add_vert() ;
			break ;
		case 3:
			g.add_edge() ;
			break ;
		case 4 :
			g.cal() ;
			break ;
		case 5:
			g.traversal() ;
			break;
		}
	}while(ch != 6) ;
	return 0;
}
