#include<bits/stdc++.h>
#define For for(i=0;i<=1000;i++)
#define white 0
#define gray 1
#define black 2
#define NIL -1
#define inf -1
using namespace std;
typedef long long ll;
vector<ll>edge[1000];
ll pre[1000];
ll d[1000];
struct Queue{
    int front;
    int rear;
    int size;

    ll q[1000];
    Queue(){
        front=0;
        rear=0;
        size=0;
    }

    void push(ll val){
    q[rear++]=val;
    size++;
    }

    ll pop(){
        size--;
        return q[front++];
    }

    bool is_empty(){
        if(size<=0)return true;
        return false;
    }
};
ll bfs(ll s){
    ll i;
    ll color[1001];
    For{
        color[i]=white;
        pre[i]=NIL;
        d[i]=inf;
    }

    d[s]=0;
    color[s]=gray;
    pre[s]=NIL;

    Queue q;
    q.push(s);

    while(!q.is_empty()){
        ll u=q.pop();
        for(i=0;i<edge[u].size();i++){
            ll v=edge[u][i];
            if(color[v]==white){
                d[v]=d[u]+1;
                pre[v]=u;
                color[v]=gray;
                q.push(v);
            }
        }
        color[u]=black;
    }
}
void print_path(ll s,ll e){
    if(s==e)cout<<s<<" ";
    else if(pre[e]==NIL) cout<<"No path"<<endl;
    else{
        print_path(s,pre[e]);
        cout<<e<<" ";
    }   
}
int main()
{
    ios::sync_with_stdio(false);
    ll n,i,u,v;
    cout<<"Enter edges:"<<endl;
    while(1){
        cin>>u>>v;
        if(u==-1&&v==-1)break;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    ll s,e;
    cout<<"Enter source node and destination node: ";
    cin>>s>>e;
    bfs(s);
    cout<<"Shortest distance: "<<d[e]<<endl;
    print_path(s,e);
    return 0;
}