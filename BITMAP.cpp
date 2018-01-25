#include <iostream>
#include <cstdlib>
#include <utility>
#include <queue>
using namespace std ;

int dx[] = {0, -1, 0 , 1};
int dy[] = {-1, 0, 1 , 0};
int vis[190][190] ;
queue<pair<int,int > > myqueue ;
char arr[190][190] , temp[190] ;
int ans[190][190] ;
int n , m , i , j , test ;


int main()
{
  cin>> test ;
  pair<int,int> s ;
  for ( int t = 0 ; t < test ; t++ )
    {
      cin>>n>>m ;
      for ( i = 0 ; i < n ; i ++ )
	{
	  cin>>temp ;
	  for ( j = 0 ; j < m ; j ++ )
	    arr[i][j] = temp[j] ;
	}

      //for ( i = 0 ; i < n ;i ++ ){
      //for ( j = 0 ; j < m ; j ++ )
      //  cout<<arr[i][j]<<" " ;
      // cout<<endl ;
      // }
      for ( i = 0 ; i < n ; i ++ )
	{
	  for ( j= 0 ; j < m ; j ++ )
	    {
	      if ( arr[i][j] == '1' )
		{
		  ans[i][j] = 0 ;
		  //  cout<<"Entered here"<<endl ;
		  myqueue.push(make_pair(i,j) ) ;
		  vis[i][j] = 1 ;
		}
	    }
	}
      while ( !myqueue.empty() )
	{
	  s = myqueue.front() ;
	  // cout<<"Entered while loop"<<endl ;
	  for(int k = 0 ; k <= 3 ; k++){
	    //cout<<"Entered for loop"<<endl;
	    int x = s.first + dx[k] ;
	    int y = s.second + dy[k];
	    // cout<<x<<"    "<<y<<endl ;
	    if ( x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 ){
	      myqueue.push(make_pair(x,y));
	      ans[x][y] = ans[s.first][s.second]+1 ;
	      //    cout<<"ans"<<x<<","<<y<<"="<<ans[x][y]<<endl ;
	      vis[x][y] = 1 ;
	    }
	  }
	  myqueue.pop() ;
	}

      for ( i = 0 ; i < n ; i ++ )
	{
	  for ( j = 0 ; j < m ; j ++ )
	    cout<<ans[i][j]<<" " ;
	  cout<<"\n" ;
	}
      for ( i = 0 ; i < n ; i ++ )
	{
	  for ( j = 0 ; j < m ; j ++ )
	    vis[i][j] = 0 ;
	}
    }
  return 0 ;
}
