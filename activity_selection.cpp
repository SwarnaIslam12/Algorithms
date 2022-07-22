#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
struct activities{
    ll startTime;
    ll finishTime;
};
bool cmp(struct activities a, struct activities b){
    return a.finishTime<b.finishTime;
}
ll selection(struct activities act[], ll start[],ll end[],ll n){
    ll i,k=0,c=0;
    start[c]=act[0].startTime;
    end[c]=act[0].finishTime;
    c++;
    for(i=1;i<n;i++){
        if(act[i].startTime>=act[k].finishTime){
            start[c]=act[i].startTime;
            end[c]=act[i].finishTime;
            c++;
            k=i;
        }
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    struct activities act[n];
    ll s,f,i;
    For{
        cin>>s>>f;
        act[i].startTime=s;
        act[i].finishTime=f;
    }
    ll start[n]={},end[n]={};
    sort(act, act+n,cmp);
    ll maxAct=selection(act,start,end,n);
    cout<<"Max activities: "<<maxAct<<endl;
    for(i=0;i<maxAct;i++){
        cout<<">"<<start[i]<<" "<<end[i]<<endl;
    }
    return 0;
}