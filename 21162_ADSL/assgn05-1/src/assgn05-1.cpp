//============================================================================
// Name        : assgn05-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class graph{
	int **l ;
	int n ;
	int rec[2][10] ;
public:
	graph(int n){
		this->n = n ;
		l = new int *[n] ;
		for(int i = 0 ;i<n ;i++){
			l[i] = new int[n] ;
			rec[0][i] = 0 ;
			rec[1][i] = 0 ;
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++)
				l[i][j] = 0 ;
		}
	}

	void create(){
		int cont = 1 ;
		while(cont == 1){
			add() ;
			cout<<"Do you wish to add more phone lines (1/0):" ;
			cin>>cont ;
		}
	}

	void add(){
		int of1,of2,cost ;
		cout<<"Enter office numbers to be connected by phone line :"<<endl ;
		cin>>of1>>of2 ;
		cout<<"Cost of connection :" ;
		cin>>cost ;
		l[of1-1][of2-1] = cost ;
		l[of2-1][of1-1] = cost ;
	}

	void prims(){
		int j = 0 ,i = 0 ;
		while(check_rec() != -1){
			for(int m = 0 ;m<n;m++){
				if(l[i][m] != 0 && rec[0][m] != -1){
					rec[0][m] = l[i][m] ;
					rec[1][m] = i ;
				}
			}
			cout<<endl<<"Phone line between offices "<<min(1) + 1<<" and "<<rec[1][min(1)] + 1
				<<" with a cost of "<<min(0) ;
			j += min(0) ;
			rec[0][min(1)] = -1 ;
			i++ ;
		}
		cout<<endl<<"This set of Phone lines connect all the offices with minimum cost of "<<j ;
	}

	int check_rec(){
		int flag = 0 ;
		for(int i = 0 ;i<n;i++){
			if(rec[0][i] == -1)
				flag++ ;
		}
		if(flag == n)
			return -1 ;
		return 0 ;
	}
	
	int min(int decide){
		int mink = 1000 ,index = 0 ;
		for(int i = 0;i<n;i++){
			if(rec[0][i] != -1 && rec[0][i] < mink ){
				mink = rec[0][i] ;
				index = i ;
			} 
		}
		if(decide = 0 )
			return mink ;
		else
			return index ;
	}
};

int main() {
	int nn ;
	cout<<endl<<"Enter total no. of offices : " ;
	cin>>nn ;
	graph *network ;
	network = new graph(nn) ;
	int ch ;
	do{
		cout<<endl<<"Press"
			<<endl<<"1 to create the network "
			<<endl<<"2 to add a phone line "
			<<endl<<"3 to claculate set of lines for minimum cost(Prim's)"
			<<endl<<"4 to Exit" ;
		cin>>ch ;
		switch(ch){
			case 1 :
				network->create() ;
				break ;
			case 2:
				network->add() ;
				break ;
			case 3:
			 	network->prims() ;
			 	break ;
		}
	}while(ch != 4) ;
	return 0;
}
