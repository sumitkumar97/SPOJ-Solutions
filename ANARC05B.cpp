#include <iostream>
#include <cstdio>
#define tenk 10000
using namespace std ;

int main() {
  int arr[10010] , brr[10010] , na , nb ;
  scanf("%d",&na) ;
  while ( na ){
    bool fob[20010] = {false} ;
    for ( int i = 1 ; i <= na ; i ++ )
      scanf("%d",&arr[i] ) ;
    scanf("%d",&nb) ;
    for ( int i = 1 ; i <= nb ; i ++ ) {
      scanf("%d",&brr[i]) ;
      fob[brr[i] + tenk] = true ;
    }
    int common[10010] , pointtocommon = 0 ;
    for ( int i = 1 ; i <= na ; i ++ )
      if ( fob[arr[i] + tenk] ) {
	common[pointtocommon] = arr[i] ;
	pointtocommon ++ ;
      }
    int iterator_for_arr = 1 , iterator_for_brr = 1 , count = 0 , ans = 0 , sumarr , sumbrr ;
    while ( count < pointtocommon ){
      sumarr = 0 , sumbrr = 0 ;
      while ( arr[iterator_for_arr] != common[count] ){
	sumarr += arr[iterator_for_arr] ;
	iterator_for_arr ++ ;
      }
      sumarr += common[count]  ;
      iterator_for_arr ++ ;
      while ( brr[iterator_for_brr] != common[count] ){
	sumbrr += brr[iterator_for_brr] ;
	iterator_for_brr ++ ;
      }
      sumbrr += common[count] ;
      iterator_for_brr ++ ;
      count ++ ;
      ans += max ( sumarr , sumbrr ) ;
    }
    sumarr = 0 , sumbrr = 0 ;
    while ( iterator_for_arr <= na ){
      sumarr += arr[iterator_for_arr] ;
      iterator_for_arr ++ ;
    }
    while ( iterator_for_brr <= nb ){
      sumbrr += brr[iterator_for_brr] ;
      iterator_for_brr ++ ;
    }
    ans += max ( sumarr , sumbrr ) ;
    printf("%d\n",ans) ;
    scanf("%d",&na) ;
  }
  return 0 ;
}
  
