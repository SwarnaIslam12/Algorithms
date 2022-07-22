#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void count_lsp(string pat,ll patl,ll *lsp){
    ll i=1,len=0;
    lsp[0]=0;
    while(i<patl){
        if(pat[i]==pat[len]){
            len++;
            lsp[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lsp[len-1];
            }
            else{
                lsp[i]=0;
                i++;
            }
        }
    }
}
int kmp(string text,string pattern,ll *b){
    ll N=text.length();
    ll M=pattern.length();
    ll lsp[M];
    count_lsp(pattern,M,lsp);
    ll i=0,j=0,c=0;
    while(i<N){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j)j=lsp[j-1];
            else{
                i++;
            }
        }
        if(j==M){
            b[c]=i-j+1;
            c++;
            j=lsp[j-1];
        }

    }
    return c;
}
int main()
{
    string t,p;
    ll tc;
    cin>>tc;
    while(tc--){
        cin>>t>>p;
        ll a[t.length()];
        ll Count=kmp(t,p,a);
        if(Count){cout<<Count<<endl;for(ll i=0;i<Count;i++){cout<<a[i]<<" ";}cout<<endl;}
        else cout<<"Not Found"<<endl;
    }
    return 0;
}
