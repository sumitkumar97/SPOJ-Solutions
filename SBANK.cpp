#include <iostream>
#include <algorithm>
using namespace std ;

struct account {
  string controller;
  string bank ;
  string usercode[4] ;
} ;

bool custom_sort( account a  , account b ){
  if ( b.controller > a.controller )
    return true ;

  if ( b.controller == a.controller ) {
    if ( b.bank > a.bank )
      return true ;
    if ( b.bank == a.bank ) {
      if ( b.usercode[0] > a.usercode[0] )
	return true ;
      if ( b.usercode[0] == a.usercode[0] ) {
	if ( b.usercode[1] > a.usercode[1] )
	  return true ;
	if ( b.usercode[1] == a.usercode[1] ) {
	  if ( b.usercode[2] > a.usercode[2] )
	    return true ;
	  if ( b.usercode[2] == a.usercode[2] ) {
	    if ( b.usercode[3] > a.usercode[3] )
	      return true ;
	    else
	      return false;
	  }
	  else
	    return false;
	}
	else
	  return false;
      }
      else
	return false;
    }
    else
      return false;
  }
  else
    return  false;
}

int main() {
  int test , count ;
  cin >> test ;
  while (test--){
    int n ;
    cin >> n ;
    account customers[n] ;
    for ( int i = 0 ; i < n ; i++)
      {
	cin >> customers[i].controller;
	cin >> customers[i].bank ;
	for( int j = 0 ; j < 4 ; j ++)
	  cin >> customers[i].usercode[j] ;
      }
    sort(customers, customers+n, custom_sort) ;
    int orig ;
    int i = 0 ;
    while ( i < n ) {
      count = 1 ;
      orig = i ;
      i ++ ;
      while (( i < n) && customers[orig].controller == customers[i].controller && customers[orig].bank == customers[i].bank && customers[orig].usercode[0] == customers[i].usercode[0] && customers[orig].usercode[1] == customers[i].usercode[1] && customers[orig].usercode[2] == customers[i].usercode[2] && customers[orig].usercode[3] == customers[i].usercode[3] ) {
	i += 1 ;
	count ++ ;
      }
      cout<<customers[orig].controller<<" ";
      cout<<customers[orig].bank<<" ";
      for ( int j = 0 ; j < 4 ; j++ )
	cout<<customers[orig].usercode[j]<<" " ;
      cout<<count<<"\n" ;
    }
    cout<<"\n" ;
  }
  return 0 ;
}
