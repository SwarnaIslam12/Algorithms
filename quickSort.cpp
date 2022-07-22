#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
ll partitioning(ll *b,ll left,ll right){
    ll p=left,l=left,r=right;
    while(l<r){
        while(l<right&&b[l]<=b[p])l++;
        while(r>left&&b[r]>b[p])r--;
        if(l<r)swap(b[l],b[r]);
    }
    swap(b[left],b[r]);
    return r;
}
void quickSort(ll *b,ll left,ll right){
    if(left<right){
        ll p=partitioning(b,left,right);
        quickSort(b,left,p-1);
        quickSort(b,p+1,right);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[n],i;
    For{
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    For{
        cout<<a[i]<<" ";
    }
    return 0;
}