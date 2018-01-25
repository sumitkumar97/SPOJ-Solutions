#include <iostream>
#include <cstdio>
using namespace std ;

int leaf , maxlength , changinglength ;
bool checkforleaf ;
int adjlist[1000010][5] ;
void dfs ( int node , bool* visited , int* count ) {
  changinglength ++ ;
  for ( int i = 0 ; i < count[node] ; i ++ ) {
    if ( !visited[adjlist[node][i]]  ){
      visited[adjlist[node][i]] = true ;
      dfs(adjlist[node][i] ,visited ,  count ) ;
    }
    if ( changinglength > maxlength ){
      maxlength = max ( maxlength , changinglength ) ;
      leaf = node ;
    }
  }
  changinglength -- ;
}
// running dfs from a certain leaf ensures max length


int main() {
  int test ;
  scanf("%d",&test) ;
  int r , c ;
  char laby[1010][1010] , temp[1010] ;
  while ( test -- ) {
    scanf("%d%d", &c, &r ) ;
    maxlength = 0 ;
    int count[1000010]={0} ;
    bool visited[1000010]={false} ;
    for ( int i = 1 ; i <=  r ; i ++ ) {
      scanf("%s",temp) ;
      for ( int  j = 1 ; j <= c ; j ++ ){
	laby[i][j] = temp[j-1]  ;
      }
    }
    int startdfs ;
    for ( int i = 1 ; i <= r  ; i ++ ) {
      for ( int j = 1 ; j <= c ; j ++ ) {
	if ( laby[i][j] == '.' ) {
	  startdfs = ((i-1)*c) + j ;
	  if ( i+1 < r +1 &&  laby[i+1][j] == '.' ) {
	    adjlist[(i-1)*c + j][count[(i-1)*c + j]] = ((i*c) + j ) ;
	    count[(i-1)*c + j ] ++ ;
	    adjlist[(i*c) + j][count[(i*c) + j ]] = ((i-1)*c + j ) ;
	    count[(i*c) + j] ++ ;
	  }
	  if ( j+1 < c + 1 && laby[i][j+1] == '.' ) {
	    adjlist[(i-1)*c + j ][count[(i-1)*c + j]] = ((i-1)*c + j + 1 ) ;
	    count[(i-1)*c + j] ++ ;
	    adjlist[(i-1)*c + j + 1 ][count[(i-1)*c + j + 1]] = ((i-1)*c + j) ;
	    count[(i-1)*c + j + 1 ] ++ ;
	  }
	}
      }
    }
    leaf = startdfs ;
    visited[startdfs] = true ;
    dfs(startdfs,visited ,  count );
    maxlength = 0 ;
    bool visited2[1000010] = {false} ;
    visited2[leaf] = true ;
    changinglength = -1 ;
    dfs(leaf , visited2 , count ) ;
    printf("Maximum rope length is %d.\n",maxlength) ;
  }
  return 0 ;
}




    
