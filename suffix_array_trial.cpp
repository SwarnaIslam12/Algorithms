#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    cin>>s;
    string str[s.length()+1];
    map<string,ll>mp;
    ll i;
    for(i=0;s[i]!='\0';i++){
        str[i]=s.substr(i,s.length()-i);
        mp[str[i]]=i;
    }
    str[s.length()]="\n";
    mp[str[s.length()]]=s.length();
    sort(str,str+s.length()+1);
    for(i=0;i<=s.length();i++)cout<<mp[str[i]]<<" "<<str[i]<<endl;

    return 0;
}
