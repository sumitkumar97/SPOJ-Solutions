#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int giveneggs , givenflour ,givensugar , givenmilk , reqeggs, reqflour , reqsugar, reqmilk ;
  scanf("%d%d%d%d%d%d%d%d",&giveneggs,&givenflour,&givensugar,&givenmilk,&reqeggs,&reqflour,&reqsugar,&reqmilk) ;
  while ( giveneggs != -1 ) {
    int ratio1 , ratio2 , ratio3 , ratio4 ;
    ratio1 = giveneggs/reqeggs ;
    if ( giveneggs % reqeggs )
      ratio1++ ;
    ratio2 = givenflour/reqflour ;
    if ( givenflour % reqflour )
      ratio2++ ;
    ratio3 = givensugar/reqsugar ;
    if ( givensugar % reqsugar )
      ratio3 ++ ;
    ratio4 = givenmilk/reqmilk ;
    if ( givenmilk % reqmilk )
      ratio4++ ;
    int realratio = max ( max ( ratio1 , ratio2 ) , max ( ratio3 , ratio4 ) ) ;
    printf("%d %d %d %d\n", (realratio*reqeggs) - giveneggs , (realratio*reqflour)-givenflour,(realratio*reqsugar)-givensugar , (realratio*reqmilk)-givenmilk ) ;
    scanf("%d%d%d%d%d%d%d%d",&giveneggs,&givenflour,&givensugar,&givenmilk,&reqeggs,&reqflour,&reqsugar,&reqmilk) ;
  }
  return 0 ;
}





    
