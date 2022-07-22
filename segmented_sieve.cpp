#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
const ll N=1e5;
void simple_sieve(ll n,vector<ll>&u){
    ll i,j=0;
    bool check[n+1]={};
    for(i=2;i*i<n;i++){
        if(!check[i]){
            for(j=i*i;j<n;j+=i){
                check[j]=true;
            }
        }
    }
    u.push_back(2);
    printf("2\n");
    for(i=3;i<n;i+=2){
        if(!check[i]){
            u.push_back(i);
            printf("%lld\n",i);
        }
    }
}
void segmented_sieve(){
    ll limit=floor(sqrt(N))+1;
    vector<ll>prime;
    prime.reserve(limit);
    simple_sieve(limit,prime);

    ll low=limit;
    ll high=2*limit;
    while(low<N){
        if(high>=N)
            high=N;
        bool check[limit+1]={};
        //memset(check,true,sizeof(check));

        for(ll i=0;i<prime.size();i++){
            ll loLim=floor(low/prime[i])*prime[i];
            if(loLim<low)
                loLim+=prime[i];
            
            for(ll j=loLim;j<high;j+=prime[i]){
                check[j-low]=true;
            }
        }
        for(ll i=low;i<high;i++){
            if(check[i-low]==false){
                printf("%lld\n",i);
            }
        }
        low+=limit;
        high+=limit;
    }
}
int main()
{
    segmented_sieve();
    return 0;
}