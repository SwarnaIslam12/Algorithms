#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getMid(ll s,ll t){
    return s+(t-s)/2;
}
void updateST_Util(ll *st,ll ss,ll se, ll i,ll diff,ll si){
    if(i<ss||i>se){
        return;
    }
    //cout<<"Updating"<<endl;
    st[si]+=diff;
    if(ss!=se){
        ll mid=getMid(ss,se);
        updateST_Util(st,ss,mid,i,diff,2*si+1);
        updateST_Util(st,mid+1,se,i,diff,2*si+2);
    }
}
void updateST(ll arr[], ll *st, ll n, ll i,ll new_val){
    if(i<0||i>n-1){
        //cout<<i<<n<<endl;
        cout<<"Invalid index"<<endl;
        return;
    }
    ll diff=new_val-arr[i];
    arr[i]=new_val;
    updateST_Util(st,0,n-1,i,diff,0);
}
ll getSum_Util(ll *st, ll ss, ll se, ll qs, ll qe, ll si){
    if(qs<=ss&&qe>=se){
        return st[si];
    }
    if(se<qs||ss>qe){
        return 0;
    }
    ll mid=getMid(ss,se);
    return getSum_Util(st,ss,mid,qs,qe,2*si+1)+getSum_Util(st,mid+1,se,qs,qe,2*si+2);
}
ll getSum(ll *st, ll n, ll qs, ll qe){
    if(qs<0||qe>n-1||qe<qs){
        cout<<"Invalid"<<endl;
        return -1;
    }
    return getSum_Util(st,0,n-1,qs,qe,0);
}
ll constructST_util(ll arr[],ll ss, ll se, ll *st,ll si){
    if(ss==se){
        st[si]=arr[ss];
        return st[si];
    }
    int mid=getMid(ss,se);
    st[si]=constructST_util(arr,ss,mid,st,si*2+1)+constructST_util(arr,mid+1,se,st,si*2+2);
    return st[si];
}
ll *constructST(ll arr[],ll n){
    ll x=(ll)ceil(log2(n));
    ll max_size=2*(ll)pow(2,x)-1;

    ll *st=new ll[max_size];
    constructST_util(arr,0,n-1,st,0);
    return st;
}
int main(){
    ll n;//size of the array
    cin>>n;
    ll a[n],i,choice=0;
    for(i=0;i<n;i++)cin>>a[i];
    ll *st=constructST(a,n);
    cin>>choice;
    while(choice!=-1){
        if(choice==1){
            ll l,r;
            cin>>l>>r;
            cout<<getSum(st,n,l,r)<<endl;
        }
        else{
            ll val,ind;
            cin>>ind>>val;
            updateST(a,st,n,ind,val);
            //cout<<"Update completed"<<endl;
        }
        cin>>choice;
    }
}