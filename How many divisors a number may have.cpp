#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i,c=1,s=0;
    cin>>n;
    for(i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            s++;
        }
        c*=(s+1);
        s=0;
    }
    if(n!=1)
    {
        c*=2;
    }
    cout<<c;
}
