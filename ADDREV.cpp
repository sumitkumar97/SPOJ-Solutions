#include<iostream>
using namespace std;
int main()
{
    int i,j,k,l,a,b,c,d,x;
    cin>>j ;
  for(i=0;i<j;i++)
    {
        cin>>k;
        cin>>l;
        a=k; b = 0;
        while(a>0)
        {
            b=(b*10)+(a%10);
            a=a/10;
        }
        c=l;d=0;
        while(c>0)
        {
            d=(d*10)+(c%10);
            c=c/10;
        }
        int ans = 0 , c = b + d ;
        while ( c > 0){
            ans = ( ans*10) + ( c%10) ;
            c /= 10 ;
        }
        cout << ans << endl;
    }

    return 0;
}

