#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
void tower(int a,char from,char aux,char to)
{
    if(a==1){
        cout<<"Move disk "<<a<<" from "<<from<<" to "<<to<<endl;
        return;
    }
    else{
        tower(a-1,from,to,aux);
        cout<<"Move disk "<<a<<" from "<<from<<" to "<<to<<endl;
        tower(a-1,aux,from,to);
    }
    //let's think a simple case where n=2. the 1st disk's primary des will be aux tower. The biggest disk's des will
    //be to tower. After that 1st disk will move from aux to to tower
}
int main()
{
    ll n;
    cin>>n;
    assert(n<=64);
    tower(n,'A','C','B');
    cout<<"Minimum movement: "<<pow(2,n)-1<<endl;
    return 0;
}