#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

double vol[10010] ;
int n , f ;

bool can ( double maxvol ){
  if ( maxvol <= 0.00009 )
    return true ;
  int count = 0 , i = n - 1 ;
  while ( i >= 0 && vol[i] >= maxvol && count < (f+1) ){
    count += vol[i]/maxvol ;
    i -- ;
  }
  if ( count >= (f+1) )
    return true ;
  return false ;
}

double binary_search ( double low , double high ){
  //  printf("%.4lf %.4lf\n" , low , high ) ;
  if ( low >= high )
    return low ;
  double mid = ( low + high )/2.0 ;
  if ( can ( mid ) ){
    double temp = binary_search ( mid + 0.000001 , high ) ;
    if ( can ( temp ) )
      return temp ;
    return mid ;
  }
  return binary_search ( low , mid - 0.000001 ) ;
}

int main() {
  int test , radius[10010] ;
  double pie = 3.141592653589 ;
  scanf("%d", &test ) ;

  while ( test -- ){
    scanf("%d%d" , &n , &f ) ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d" , &radius[i] ) ;

    sort ( radius , radius + n ) ;
    for ( int i = 0 ; i < n ; i ++ )
      vol[i] = pie*(radius[i]*radius[i] ) ;

    if ( can ( vol[n-1] ) )
      printf("%.4lf\n" , vol[n-1] ) ;
    else
      printf("%.4lf\n" , binary_search ( 0 , vol[n-1] ) ) ;
  }
  return 0 ;
}
	
