//============================================================================
// Name        : assgn06-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#define MAX 27

class dictionary{
	string word ;
	string meaning ;
public:
	dictionary(){
	this->word[0]='\0';
	this->meaning[0]='\0';
	}
	void print(){
	cout<<"\n"<<word<<": "<<meaning;
	}
	void read(){
	cout<<"\nEnter Word: ";
	cin>>word;
	cout<<"\nEnter Meaning: ";
	cin.ignore();
	getline(cin,meaning);
	}
	friend class hash ;
};

class hash{
	dictionary store[MAX];
public:;
	int hash_function(dictionary node){
		int location=0;
		for(int i=0;i<node.word.length();i++){
			location=location+node.word[i];
		}
		location=location%MAX;
		return location;
	}
	bool insert_with(dictionary entry){
		int index=hash_function(entry);
		int count=0;
		if(!store[index].word.length()){
			store[index]=entry;
			cout<<"\nInserted!";
			return true;
		}
		for(int i=index;;i++){
			if(i==MAX)	i=0;
			if(!store[i].word.length()){
				store[i]=entry;
				cout<<"\nInserted!";
				return true;
			}
			count++;
			if(count>=MAX)	break;
		}
		cout<<"\nTable Full!";
		return false;
	}
	bool insert_without(dictionary node){
		int index=hash_function(entry);
		if(!store[index].word.length()){
			store[index]=entry;
			cout<<"\nInserted!";
			return true;		
		}
		dictionary current=store[index];
		if(index==hash_function(current))
			return insert_without(entry);
			
		store[index]=entry;
		if(insert_without(current)==false){
			store[index]=current;
			return false;
		}
		return true;
	}
	void print_table(){
		cout<<"\nindex\tword\tmeaning";
		for(int i=0;i<MAX;i++){
			cout<<"\n"<<i<<"\t"<<store[i].word<<"\t"<<store[i].meaning;
		}
	}
	void show_meaning(int index){
		cout<<"\n"<<store[index].word<<": "<<store[index].meaning;
	}
	int search_entry(string key){
		dictionary entry(key," ");
		int count=0;
		int index=hash_function(entry);
		for(int i=index; count<MAX;count++,i++){
			if(i==MAX)
				i=0;
			if(table[i].word==key){
				cout<<"\nNo. of Comparisons: "<<count+1;
				return i;
			}
		}
		cout<<"\nNo. of Comparisons: "<<count;
		return -1;
	}
	bool delete_entry(string key){
		int index=search_entry(key);
		if (index==-1)
			return false;
		dictionary blank;
		store[index] = blank;
		return true;
	}
};

int main() {
	int choice;
	Hash obj;
	Dictionary entry;
	string key;
	int index;
	bool flag;
	cout<<"\n          OPTION INDEX";
	cout<<"\nPress 1 : Add Word into Dictionary";
	cout<<"\nPress 2 : Search Word";
	cout<<"\nPress 3 : Delete Word";
	cout<<"\nPress 4 : Print Hash table";
	cout<<"\nPress 5 : To Exit";
	cout<<"\nEnter Choice: ";
	cin>>choice;

	while(choice){
		switch(choice){
		case 1:	
				int replacement=0;
				while(replacement!=1 and replacement!=2){
					cout<<"\nChoose Insertion Method.";
					cout<<"\n1. With Replacement";
					cout<<"\n2. Without Replacement";
					cout<<"\nEnter Choice: ";
					cin>>replacement;
				}
				if (replacement==2)
					replacement=0;
				entry.read();
				if(replacement)
					obj.insert_with(entry);
				else
					obj.insert_without(entry);
				break;

		case 2:	
				cout<<"\nEnter Word to Search: ";
				cin>>key;
				index=obj.search_entry(key);
				if(index!=-1){
					cout<<"\n"<<key<<" found at index: "<<index;
					obj.show_meaning(index);
				}
				else
					cout<<"\n"<<key<<" not Found!";
				break;

		case 3:	
				cout<<"\nEnter Word to Search: ";
				cin>>key;
				flag=obj.delete_entry(key);
				if(flag==true)
					cout<<"\n"<<key<<" Deleted Successfully!";
				else
					cout<<"\n"<<key<<" not Found!";
				break;

		case 4:	
				obj.print_table();
				break;

		case 5: 	
				
				break;

		default:
				cout<<"\nInvalid Choice! Please, Try Again.";
		}
		cout<<"\n\nEnter Choice: ";
		cin>>choice;
	}
	cout<<"\nEND...";
	return 0;
}




/*int hash(string s){
	time_t currentTime ;
    struct tm *localTime ;
    time( &currentTime ) ;
    localTime = localtime( &currentTime ) ;
    int Hour   = localTime->tm_hour ;
    int Min    = localTime->tm_min ;
    int Sec    = localTime->tm_sec ;
    return ((Hour + Min)/Sec) ;
}
*/
