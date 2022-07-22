#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i;
    cin>>n;
    bool mp[n+1]={};
    for(i=2;i*i<=n;i++)
    {
        if(mp[i]==false)
         {
             for(ll j=i*i;j<=n;j+=i)
             {
                 mp[j]=true;
             }
         }
    }
    for(i=2;i<=n;i++)
    {
        if(mp[i]==false)
        {
            printf("%lld\n",i);
        }
    }
}


