#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

struct structname {
  bool occ ;
  char s[30] ;
}ind[102] ;

int hash ( char* str ){
  int h = 0 ;
  for ( int i = 4 ; i < strlen(str) ; i ++ )
    h += ( (i-3)*str[i] ) ;
  h *= 19 ;
  return h%101 ;
}


int main() {
  int test , n ;
  char str[110] ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    int count = 0 ;
    for ( int i = 0 ; i < 101 ; i ++ )
      ind[i].occ = false ;
    while ( n -- ){
      scanf("%s" , str ) ;

      if ( str[0] == 'A' ){
	bool flag = true ;
	for ( int i = 0 ; i < 101 ; i ++ )
	  if ( ind[i].occ && !strcmp( str + 4 , ind[i].s ) ){
	    flag = false ;
	    break ;
	  }
	if ( flag ){
	  if ( ind[hash(str)].occ == false ){
	    strcpy( ind[hash(str)].s , str+4 ) ;
	    ind[hash(str)].occ = true ;
	    count ++ ;
	  }
	  else {
	    for ( int j = 1 ; j < 20 ; j ++ )
	      if ( ind[ (hash(str)+(j*j)+23*j) % 101 ].occ == false ){
		strcpy ( ind[ (hash(str)+(j*j)+23*j) % 101 ].s , str + 4 ) ;
		ind[ (hash(str)+(j*j)+23*j) % 101 ].occ = true ;
		count ++ ;
		break ;
	      }
	  }
	}
      }
      else {
	for ( int i = 0 ; i < 101 ; i ++ )
	  if ( ind[i].occ && !strcmp( str + 4 , ind[i].s ) ){
	    ind[i].occ = false ;
	    count -- ;
	    break ;
	  }
      }
    }
    printf("%d\n" , count ) ;
    for ( int i = 0 ; i < 101 ; i ++ )
      if ( ind[i].occ )
	printf("%d:%s\n" , i , ind[i].s ) ;
  }
  return 0 ;
}
