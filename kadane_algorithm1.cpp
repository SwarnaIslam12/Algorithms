#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a,i,dp[200001]={},p=0,*q;
        for(i=1;i<=n;i++){
            cin>>a;
            dp[i]=max(dp[i-1],p)+a;
        }
        q=max_element(dp+1,dp+n+1);
        cout<<*q<<endl;
    }
}