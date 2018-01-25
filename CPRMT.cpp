#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int main() {
  char str1[1010] , str2[1010]  ;
  while ( scanf("%s",str1) != EOF ) {
    scanf("%s",str2) ;
    int count1[200]={0} , count2[200]={0} , len1 , len2 , i , count3[200]={0} ;
    len1 = strlen(str1) ;
    len2 = strlen(str2) ;
    for ( i = 0 ; i < len1 ; i ++ ) {
      count1[(int)str1[i]]++ ;
    }
    for ( i = 0 ; i < len2 ; i ++ ) {
      count2[(int) str2[i]] ++ ;
    }
    for ( i = 97 ; i < 200 ; i ++ ) {
      count2[i] > count1[i] ? count3[i] = count1[i] : count3[i] = count2[i] ;
    }
    for ( i = 97 ; i < 200 ; i ++ ){
      while ( count3[i]-- )
	printf("%c", i ) ;
    }
    printf("\n") ;
  }
  return 0 ;
}
    
    
    
