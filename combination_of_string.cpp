#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
map<string,bool>mp;
ll k,c;
void combination(string str,ll pos,ll len,string a)
{
   ll i;
   if(a.length()==k&&mp[a]==false){
       mp[a]=true;
       cout<<a<<endl;
       c++;
       return;
    }
   for(i=pos;i<=len;i++){
       if(a.length()<k)
            combination(str,i+1,len+1,a+str[i]);
   }
   return;
}
int main()
{
    cin>>k;
    string str,line="__________";
    cin>>str;
    sort(str.begin(),str.end());
    cout<<line<<endl;
    combination(str,0,str.length()-k,"");
    cout<<c<<endl;
    return 0;
}