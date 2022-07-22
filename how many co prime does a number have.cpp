#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    while(1){
    ll n,i,c=1,s=0;
    cin>>n;

    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                s++;
            }
            c*=(pow(i,s)-pow(i,s-1));
        }
        s=0;
    }
    if(n!=1)
    {
        c*=(n-1);
    }
    cout<<c<<endl;}
}

