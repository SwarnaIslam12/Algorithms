#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
const ll MAX=1e5+1;
ll pre[MAX];
void dijkstra(vector<pair<ll,ll>>*node,ll *wei,ll n,ll src){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
	bool vis[n+1]={};
	pre[src]=-1;
	pq.push(make_pair(0,src));
	wei[src]=0;
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(ll i=0;i<node[u].size();i++){
			ll v=node[u][i].second;
			ll w=node[u][i].first;
			if((wei[u]+w<wei[v]||wei[v]==0)&&vis[v]==false){
				wei[v]=wei[u]+w;
				pre[v]=u;
				pq.push(make_pair(wei[v],v));
			}
		}

	}
}
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	pair<ll,ll>w;
	w=make_pair(n,m);
	cout<<w.first<<" "<<w.second<<endl;
	vector<pair<ll,ll>>node[n+1];
	while(m--){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		node[u].push_back({w,v});
		node[v].push_back({w,u});
	}
	ll wei[n+1]={};
	pre[n]=-1;
	dijkstra(node,wei,n,1);
	ll cur=n;
	stack<ll>s;
	if(pre[n]==-1&&n>1){
		printf("-1");
		exit(0);
	}
	while(cur!=-1){
		s.push(cur);
		cur=pre[cur];
	}
	while(!s.empty()){
		printf("%lld ",s.top());
		s.pop();
	}
	return 0;
}