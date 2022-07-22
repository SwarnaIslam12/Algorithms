#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
struct items{
    double weight;
    double value;
};
bool cmp(struct items a, struct items b){
    return a.weight<b.weight;
}
// ll knapsack_01(struct items item[],ll n, ll knapsack){
//     ll i,j;
//     ll m[2][knapsack+1];
//     for(i=0;i<=n;i++){
//         ll wt=item[i].weight;
//         ll p=item[i].value;
//         for(j=0;j<=knapsack;j++){
//             if(i==0||j==0)
//                 m[i%2][j]=0;
//             else if(wt<=j)
//                 m[i%2][j]=max(m[(i-1)%2][j],m[(i-1)%2][j-wt]+p);
//             else
//                 m[i%2][j]=m[(i-1)%2][j];
//         }
//     }
//     return m[n%2][knapsack];
// }
ll knapsack_01(struct items item[],ll n, ll knapsack){
    ll i,j;
    ll dp[knapsack+1]={};
    for(i=1;i<=n;i++){
        ll wt=item[i].weight;
        ll v=item[i].value;
        for(j=knapsack;j>=0;j--){
            if(wt<=j)
                dp[j]=max(dp[j],dp[j-wt]+v);
        }
    }
    return dp[knapsack];
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
    ll maxi=knapsack_01(item,n,knapsack);
    cout<<maxi<<endl;
    return 0;
}