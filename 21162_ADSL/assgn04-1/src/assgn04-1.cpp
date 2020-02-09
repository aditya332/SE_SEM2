//============================================================================
// Name        : assgn04-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
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
			cout<<"\nEnter destination city : " ;
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
		node *queue[n] ;
		int queue_index = 0 , counter = 0 ;
		int visit[n] ;
		for(int i = 0 ;i<n ; i++){
			queue[i] = new node ;
			visit[i] = 0 ;
			}
		string tname ;
		cout<<"\nEnter city name to start traversal from :" ;
		cin>>tname ;
		cout<<"\nTraversal result is :" ;
		queue[queue_index] = list[incoming(tname,0)] ;
		visit[incoming(tname,0)] = 1 ;
		while(counter < n){
			node* temp = queue[counter++] ;
			cout<<temp->city ;
			while(temp->link != NULL){
				temp = temp->link ;
				if(visit[incoming(temp->city , 0)] != 1 ){
					queue[++queue_index] = temp ;
					visit[incoming(temp->city , 0)] = 1 ;
					}
				}
			}
				
	/*
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
		*/
	}
	
	void delete_vertice(){
		string tname ;
		cout<<"\nEnter city to be deleted : " ;
		cin>>tname ;
		int j = incoming(tname,0) ;
		list[j]->link = NULL ;
		for(int  i = j ;i<(n - j);i++){
			list[i] = list[i+1] ;
			}
	}
	
	void delete_link(){
		string tname , uname ;
		cout<<"\nEnter name of starting city : " ;
		cin>>tname ;
		cout<<"\nEnter name of destination city : " ;
		cin>>uname ;
		node *temp = list[incoming(tname,0)] ;
		node* r ;
		list[incoming(tname,0)]->out-- ;
		list[incoming(uname,0)]->in-- ;
		while(temp->link != NULL){
			r = temp ;
			temp = temp->link ;
			if(uname.compare(temp->city) == 0){
				r->link = temp->link ;
				temp->link = NULL ;
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
			<<"\n6 to delete city from network "
			<<"\n7 to delete a link between two cities "
			<<"\n8 to exit ";
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
		case 6:
			g.delete_vertice() ;
			break ;
		case 7:
			g.delete_link() ;
			break ;
		}
	}while(ch != 8) ;
	return 0;
}
