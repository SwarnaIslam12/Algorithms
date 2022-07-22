#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n],i,m=0,sum=0,p=1;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(i<k)sum+=a[i];
        else{
            if(p){m=sum;p=0;}
            sum+=(a[i]-a[i-k]);
            m=max(m,sum);
        }
    }
    cout<<m<<endl;
    return 0;
}