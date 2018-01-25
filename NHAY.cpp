#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std ;

int main()
{
  int test , ln , *lps , count = 0 , flag = 0 ;
  char *p , s;
  while (cin >> ln ){
    count = 0 ;
    p = (char * ) malloc ((ln+4)*sizeof(char)) ;
    scanf("%s",p) ;
    //cout<<p<<"\n" ;
    lps = ( int * ) malloc ( (ln+4)*sizeof(int)) ;
    for ( int i = 0 ; i< ln ; i ++ )
      lps[i] = 0 ;
    lps[0] = 0 ;
    for ( int i = 1 ;i < ln ;  i ++ ) {
      for( int j = 1 ; j<= i ; j ++ ) {
	int t = j , u = 0 ;
	while ( t <= i && p[t] == p[u] ) {
	  //    cout<<"t = "<<t<<endl<<"u = "<<u <<endl ;
	  t++ ;
	  u++ ;
	}t-- ;
	//  cout<<" j="<<j<<endl ;
	if ( t == i ) {
	  lps[i] = i - j + 1 ;
	  //cout<<"lps[i]="<< lps[i]<<endl ;
	  break ;
	}
	//  cout<<endl<<endl ;
      }
    }
    //      for ( int i = 0 ; i < ln ; i ++ )
    //cout<<lps[i]<<"," ;
    int k = 0 , l = 0 ;
    flag = 0 ;
    scanf("%c",&s) ;
    scanf("%c",&s);
    while (s != '\n'&& flag == 0 ){
      //cout<<s<<endl;
      //cout<<"s ="<<s<<"p[k] ="<<p[k]<<endl ;
    LOOP :
      if ( s == p[k] ) {
	// cout<<"l = "<<l <<endl <<"k = "<< k <<endl ;
	if ( k == ln - 1 ){
	  cout<<l - ln + 1<<"\n" ;
	  k = lps[ln - 1]-1 ;
	  count++ ;
	}
	k++ ;
      }
      else{
	if ( k != 0 ){
	  k = lps[k-1] ;
	  goto LOOP ;
	}
	else
	  k-- ;
      }
      //if ( scanf("%c",&s) == EOF ){
      //flag = 1 ;
      //break ;
      if ( scanf("%c",&s) == EOF ){
	flag = 1;
	return 0 ;
      }
      l++ ;
    }
    cout<<"\n" ;
  }
  return 0 ;
}


