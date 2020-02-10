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
	int n , rec[2][n] ;
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
			int of1,of2,cost ;
			cout<<"\nEnter office numbers to be connected by phone line :" ;
			cin>>of1>>of2 ;
			cout<<"\nCost of connection :" ;
			cin>>cost ;
			l[of1-1][of2-1] = l[of2-1][of1-1] = cost ;
			cout<<"Do you wish to add more phone lines (1/0):" ;
			cin>>cont ;
		}
	}

	void add(){
		int of1,of2,cost ;
		cout<<"\nEnter office numbers to be connected by phone line :" ;
		cin>>of1>>of2 ;
		cout<<"\nCost of connection :" ;
		cin>>cost ;
		l[of1-1][of2-1] = l[of2-1][of1-1] = cost ;
	}

	void prims(){

	}

	int check_rec01(){
		int flag = 0 ;
		for(int i = 0 ;i<n;i++){
			if(rec[0][i] == -1)
				flag++ ;
		}
		if(flag == n)
			return -1 ;
		return 0 ;
	}
};

int main() {
	return 0;
}
