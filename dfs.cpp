#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
#define white 0
#define gray 1
#define black 2
#define NIL -1
#define inf -1
using namespace std;
typedef long long ll;
ll d[1000];
ll f[1000];
ll color[1000];
vector<ll>node[1000];
pair<ll,ll>tree_edge[1000];
pair<ll,ll>back_edge[1000];
pair<ll,ll>forward_edge[1000];
pair<ll,ll>cross_edge[1000];
ll m,n,o,p;
set<ll>s;
ll Time;
void dfs_call(ll u){
    color[u]=gray;
    d[u]=++Time;
    for(ll i=0;i<node[u].size();i++){
        ll v=node[u][i];
        if(color[v]==gray)back_edge[n++]=make_pair(u,v);
        if(color[v]==black){
            if(d[u]<d[v])forward_edge[o++]=make_pair(u,v);
            else if(d[u]>d[v])cross_edge[p++]=make_pair(u,v);
        }
        if(color[v]==white){
            tree_edge[m++]=make_pair(u,v);
            dfs_call(v);
        }
    }
    color[u]=black;
    f[u]=++Time;
}
void dfs(){
    set<ll>::iterator it;
    Time=0;
    for(it=s.begin();it!=s.end();it++){
        if(color[*it]==white)
            dfs_call(*it);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout<<"Enter edges:\n";
    ll u,v;
    while(1){
        cin>>u>>v;
        if(u==-1&&v==-1)break;
        node[u].push_back(v);
        s.insert(u);
        s.insert(v);
    }
    dfs();
    if(o>0)cout<<"Circle exists."<<endl;
    cout<<"Tree edges:"<<endl;
    for(ll i=0;i<m;i++){
        cout<<tree_edge[i].first<<" -> "<<tree_edge[i].second<<endl;
    }
    cout<<"Back edges:"<<endl;
    for(ll i=0;i<n;i++){
        cout<<back_edge[i].first<<" -> "<<back_edge[i].second<<endl;
    }
    cout<<"Forward edge:"<<endl;
    for(ll i=0;i<o;i++){
        cout<<forward_edge[i].first<<" -> "<<forward_edge[i].second<<endl;
    }
    cout<<"Cross edge:"<<endl;
    for(ll i=0;i<p;i++){
        cout<<cross_edge[i].first<<" -> "<<cross_edge[i].second<<endl;
    }
    return 0;
}