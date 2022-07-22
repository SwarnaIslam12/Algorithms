#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
ll dp[100003];
struct items{
    double weight;
    double value;
};
bool cmp(struct items a, struct items b){
    return a.weight<b.weight;
}
ll zero_one_knapsack_with_large_W(struct items item[],ll n, ll knapsack){
    //cerr<<"Entered"<<endl;
    ll i,j;
    for(i=0;i<=1000*n;i++)dp[i]=1e13;
    dp[0]=0;
    for(i=1;i<=n;i++){
        ll wt=item[i].weight;
        ll v=item[i].value;
        for(j=1000*n;j>=0;j--){
            if(v<=j){
                dp[j]=min(dp[j],dp[j-v]+wt);
            }
        }
    }
    //cerr<<dp[7]<<endl;
    ll ans=0;
    for(j=1000*n;j>=0;j--){
        if(dp[j]<=knapsack){
            ans=j;
            break;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    ll n,knapsack,i;
    cin>>n>>knapsack;
    ll wt,v;
    struct items item[n+1];
    item[0].weight=0;
    item[0].value=0;
    for(i=1;i<=n;i++){
        cin>>wt>>v;
        item[i].weight=wt;
        item[i].value=v;
    }
    sort(item,item+n,cmp);
    //cerr<<n<<endl;
    ll maxi=zero_one_knapsack_with_large_W(item,n,knapsack);
    cout<<maxi<<endl;
    return 0;
}