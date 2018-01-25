#include<iostream>
using namespace std;
int main()
{
    int test , n ;
    cin >> test ;
     while ( test -- ){
        cin >> n ;
        int ans = 0 ;
        while ( n > 0 ){
             ans += n/5 ;
             n = n/5;
        }
        cout << ans << "\n";
     }
}

