#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
using namespace std;
typedef long long ll;
const ll MAX=1e5;
vector<ll>adj[MAX];
set<ll>art_point;
vector<pair<ll,ll>>bridge;
ll low[MAX];
ll pre[MAX];
ll dis_time;
ll root,flag=0;

void dfs_call(ll u,ll color[],ll d[],ll f[]){

    d[u]=dis_time++;
    color[u]=grey;
    low[u]=d[u];

    for(ll i=0;i<adj[u].size();i++){
        ll v=adj[u][i];

        if(color[v]==white){
            pre[v]=u;
            dfs_call(v,color,d,f);

            if(low[v]>=d[u]){
                if(u!=root)
                    art_point.insert(u);
                else flag++;
            }

            if(low[v]<low[u])
                low[u]=low[v];

            if(low[v]>d[u])
                bridge.push_back({u,v});
        }
        else if(color[v]==grey&&v!=pre[u]){
            if(d[v]<low[u])
                low[u]=d[v];
        }
    }
    color[u]=black;
    f[u]=dis_time++;
}
void dfs(set<ll>nodes,ll color[],ll d[],ll f[]){
    dis_time=0;
    for(auto it:nodes){
        if(dis_time==0)
            root=it;
        if(color[it]==white){
            dfs_call(it,color,d,f);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ll u,v,maxi=0;
    set<ll>s;
    while(1){
        cin>>u>>v;
        if(u==-1&&v==-1)break;
        adj[u].push_back(v);
        adj[v].push_back(u);
        s.insert(u);
        s.insert(v);
        maxi=max(maxi,u);
        maxi=max(maxi,v);
    }

    ll color[maxi+1]={},f[maxi+1]={},d[maxi+1]={};
    dfs(s,color,d,f);

    if(flag>1)
        art_point.insert(root);

    cout<<"Articulation points:"<<endl;
    for(auto it:art_point){
        cout<<it<<" ";
    }

    cout<<"\nBridges:"<<endl;
    for(auto it:bridge){
        cout<<it.first<<" - "<<it.second<<endl;
    }
    return 0;
}