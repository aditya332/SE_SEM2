//============================================================================
// Name        : assgn06-1.cpp
// Author      : adi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int hash(string s){
	time_t currentTime ;
    struct tm *localTime ;
    time( &currentTime ) ;
    localTime = localtime( &currentTime ) ;
    int Hour   = localTime->tm_hour ;
    int Min    = localTime->tm_min ;
    int Sec    = localTime->tm_sec ;
    return ((Hour + Min)/Sec) ;
}

int main() {


	return 0;
}
