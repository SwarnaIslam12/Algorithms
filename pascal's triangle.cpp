#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,j=0,i=0;
    cout<<"nCm:\nn=?\n";
    cin>>n;
    cout<<"m=?\n";
    cin>>m;
    ll p=max(m,n-m);
    ll dp[p+1][p+1];
    for(i=0;i<=p;i++)
    {
        dp[0][i]=1;
        dp[i][0]=1;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n-m;j++)
        {
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
        for(i=0;i<=m;i++)
    {
        for(j=0;j<=n-m;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<dp[m][n-m];
}
