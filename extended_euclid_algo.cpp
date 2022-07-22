#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,d;
ll Euclid(ll n,ll m)
{
    if(m==0)
    {
        d=n;
        x=1;
        y=0;
    }
    else{
        Euclid(m,n%m);
        //cout<<x<<" "<<y<<endl;
        ll t=x;
        x=y;
        y=t-(n/m)*y;
    }
}
int main()
{
    ll a,b,n=0,m=0;
    cin>>a>>b;
    Euclid(a,b);
    cout<<"gcd = "<<d<<endl;
    cout<<"x = "<<x<<", y = "<<y<<endl;
}

