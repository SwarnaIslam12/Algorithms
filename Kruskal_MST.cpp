#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
const ll MAX=10000;
ll parent[MAX];
struct node{
    ll node1;
    ll node2;
    ll weight;
};
bool cmp(struct node a, struct node b){
    return a.weight<b.weight;
}
void makeSet(int n){
    parent[n]=n;
}
ll find_set(int n){
    if(parent[n]==n)return n;
    return find_set(parent[n]);
}
void Union(ll u, ll v,ll parentOfu,ll parentOfv){
    parent[parentOfv]=parentOfu;
}
int main()
{
    ios::sync_with_stdio(false);
    ll nodeNum,edgeNum,wt,u,v,ans=0,c=0;
    cin>>nodeNum>>edgeNum;
    struct node nodes[edgeNum];
    for(ll i=0;i<edgeNum;i++){
        cin>>u>>v>>wt;
        nodes[i].node1=u;
        nodes[i].node2=v;
        nodes[i].weight=wt;
    }
    sort(nodes,nodes+edgeNum,cmp);
    for(ll i=1;i<=nodeNum;i++)makeSet(i);
    for(ll i=0;i<edgeNum;i++){
        u=nodes[i].node1;
        v=nodes[i].node2;
        wt=nodes[i].weight;
        ll parentOfu=find_set(u);
        ll parentOfv=find_set(v);
        if(parentOfu!=parentOfv){
            Union(u,v,parentOfu,parentOfv);
            ans+=wt;
        }
    }
    cout<<ans<<endl;
    return 0;
}