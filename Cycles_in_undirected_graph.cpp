#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
const ll MAX=1000;
ll num=1;
void dfs(ll u,ll par,map<ll,ll>color,map<ll,ll>pre,vector<ll>*adj){
    cerr<<par<<" "<<u<<" "<<color[u]<<endl;
    if(color[u]==2)return;
    if(color[u]==1){
        ll cur=par;
        cout<<"Cycle "<<num<<": "<<endl;
        while(cur!=u){
            cout<<cur<<" ";
            cur=pre[cur];
        }
        cout<<cur<<endl;
        num++;
        return;
    }
    pre[u]=par;
    color[u]=1;
    for(auto v:adj[u]){
        if(v==pre[u])continue;
        dfs(v,u,color,pre,adj);
    }
    color[u]=2;
}
int main()
{
    ios::sync_with_stdio(false);
    ll t,n,e,u,v;
    cin>>t;
    while(t--){
        cin>>n>>e;
        vector<ll>adj[n+1];
        map<ll,ll>color,pre;
        while(e--){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,color,pre,adj);
        num=0;
    }
    return 0;
}