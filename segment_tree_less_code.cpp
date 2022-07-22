#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getMid(ll s,ll t){
    return s+(t-s)/2;
}
void built(ll arr[], ll tree[],ll n){
    for(ll i=0;i<n;i++){
        tree[n+i]=arr[i];
    }
    for(ll i=n-1;i>0;i--){
        tree[i]=tree[i<<1]+tree[i<<1|1];
    }
}
void update(ll tree[], ll ind, ll value,ll n){
    tree[n+ind]=value;
    ind+=n;
    for(ll i=ind;i>1;i>>=1){
        tree[i>>1]=tree[i]+tree[i^1];
    }
}
ll query(ll l, ll r, ll tree[],ll n){
    ll res=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1){
            res+=tree[l++];
        }
        if(r&1){
            res+=tree[--r];
        }
    }
    return res;
}
int main(){
    ll n;//size of the array
    cin>>n;
    ll a[n],i,choice=0;
    for(i=0;i<n;i++)cin>>a[i];
    ll tree[2*n+1]={};
    built(a,tree,n);
    cin>>choice;
    while(choice!=-1){
        if(choice==1){
            ll l,r;
            cin>>l>>r;
            cout<<query(l,r+1,tree,n)<<endl;
        }
        else{
            ll val,ind;
            cin>>ind>>val;
            update(tree,ind,val,n);
        }
        cin>>choice;
    }
}