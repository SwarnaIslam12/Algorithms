#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
struct item{
    double value;
    double weight;
};
bool cmp(struct item a, struct item b){
    double value1=a.value/a.weight;
    double value2=b.value/b.weight;
    return value1>value2;
}
double fractional_knapsack(struct item elements[],ll n,double knapsack){
    ll i;
    double currAmount=0,total=0;
    For{
        double wt=elements[i].weight;
        if(currAmount+wt<=knapsack){
            total+=elements[i].value;
            currAmount+=elements[i].weight;
        }
        else{
            double remain=knapsack-currAmount;
            double rw=remain*(elements[i].value/elements[i].weight);// remaining weight's value
            total+=rw;
            break;
        }
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    ll n,i;
    double knapsack;
    cin>>n>>knapsack;
    item elements[n];
    For{
        double w,a;
        cin>>a>>w;
        elements[i].weight=a;
        elements[i].value=w;
    }
    sort(elements,elements+n,cmp);
    double maxi=fractional_knapsack(elements,n,knapsack);
    cout<<maxi<<endl;
    return 0;
}