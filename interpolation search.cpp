#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll interpolation_search(ll a[],ll key)
{
    ll l=0,h=20-1;
    while(l<=h&&key>=a[l]&&key<=a[h])
    {
        if(l==h)
        {
            if(a[l]==key){return l;}
            return -1;
        }
        ll pos=l+(((double)(h-l)/(a[h]-a[l]))*(key-a[l]));
        if(a[pos]==key){return pos;}
        else if(a[pos]<key){l=pos+1;}
        else{h=pos-1;}
    }
    return -1;
}
int main()
{
    ll a[20]={1,4,5,7,8,9,10,20,23,24,25,26,30,40,45,46,47,48,49,50},key=23,index=0;
    index=interpolation_search(a,key);
    cout<<index;
}
