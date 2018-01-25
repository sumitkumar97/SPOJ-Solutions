#include <iostream>
#include <cstdio>
#include <cstring>
#define max_n 10010 
using namespace std ;

char t[max_n] ;
int SA[max_n] , tempSA[max_n] , RA[max_n] , tempRA[max_n] , count[max_n] , n ;

void countingsort( int k ){
  int maxi = max ( n , 300 ) , sum , temp ;
  memset ( count , 0 , sizeof count ) ;
  for ( int i = 0 ; i < n ; i ++ )
    count[RA[(i+k)%n]] ++ ;
  for ( int i = sum = 0 ; i < maxi ; i ++ ){
    temp = count[i] ;
    count[i] = sum ;
    sum += temp ;
  }
  for ( int i = 0 ; i < n ; i ++ )
    tempSA[ count[ RA[ (SA[i] + k )%n ] ]++ ] = SA[i] ;
  for ( int i = 0 ; i < n ; i ++ )
    SA[i] = tempSA[i] ;
}
  


void constructSA () {
  int r ;
  for ( int i = 0 ; i < n ; i ++ )
    RA[i] = t[i] ;
  for ( int i = 0 ; i < n ; i ++ )
    SA[i] = i ;
  for ( int k = 1 ; k < n ; k <<= 1 ){
    countingsort(k) ;
    countingsort(0) ;
    tempRA[SA[0]] = r = 0;
    for (int i = 1; i < n; i++)
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[(SA[i]+k)%n] == RA[(SA[i-1]+k)%n]) ? r : ++r;
    for (int i = 0; i < n; i++)
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;
  }
}

int main() {
  int test ;
  scanf("%d", &test ) ;
  while ( test -- ){
    scanf("%s" , t ) ;
    n = strlen(t) ;

    constructSA () ;
    //    for ( int i = 0 ; i < n ; i ++ )
    //      printf("i %d SA %d RA %d\n" , i , SA[i] , RA[SA[i]] ) ;
    printf("%d\n" , SA[0]+1 ) ;
  }
  return 0 ;
}
    
