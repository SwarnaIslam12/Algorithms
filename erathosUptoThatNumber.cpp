#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i,t,m=1,c=0;
    map<ll,bool>mp;
    map<ll,ll>mp_count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<=m)
        {
            cout<<mp_count[n]<<endl;
        }
        else
        {
            for(i=2;i*i<=n;i++)
            {
                if(mp[i]==false)
                {
                    for(ll j=max(i*i,(m-i+2)/i*i);j<=n;j+=i)
                    {
                        mp[j]=true;
                    }
                }
            }
            ll p=2;
            for(i=max(p,m+1);i<=n;i++)
            {
                if(mp[i]==false)
                {
                    c++;
                }
                mp_count[i]=c;
            }
            cout<<mp_count[n]<<endl;
            m=max(m,n);
        }
    }
}
