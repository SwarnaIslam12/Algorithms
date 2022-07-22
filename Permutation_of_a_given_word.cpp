#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
map<string,bool>already_exist;
ll c;
void permutation(string word,ll fixed,ll len){
    ll i;
    if(fixed+1==len&&already_exist[word]==false){
            already_exist[word]=true;
            cout<<word<<endl;
            c++;
            return;
    }
    for(i=fixed;i<len;i++){
        swap(word[fixed],word[i]);
        if(fixed+1<len&&already_exist[word]==false)
            permutation(word,fixed+1,len);
    }
    return;
}
int main()
{
    ll t;
    string line="___________";
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<line<<endl;
        permutation(str,0,str.size());
        cout<<c<<endl;
        c=0;
        already_exist.clear();
    }
    return 0;
}