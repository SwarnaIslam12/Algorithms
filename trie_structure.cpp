//https://www.geeksforgeeks.org/trie-insert-and-search/
#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
#define Alphabets 26
using namespace std;
typedef long long ll;
struct trie
{
    struct trie *characters[Alphabets];
    bool IsEndOfWord;
};
struct trie *root=NULL;
struct trie* get_node()
{
    struct trie *parent=(struct trie*)malloc(sizeof(struct trie));//Malloc gives only base address of allocated memory , because it allocates the memory in contiguous fashion so we can access further blocks of memory by simply incrementing the base address.
    ll i;
    parent->IsEndOfWord=false;
    for(i=0;i<Alphabets;i++)
        parent->characters[i]=NULL;
    return parent;
}
void insert(struct trie *parent,string str)
{
    ll i;
    for(i=0;str[i]!='\0';i++){
        ll index=str[i]-'a';
        if(!parent->characters[index])
            parent->characters[index]=get_node();
        parent=parent->characters[index];
    }
    parent->IsEndOfWord=true;
}
bool does_exist_in_trie(string query)
{
    ll i;
    struct trie *temp=root;
    for(i=0;query[i]!='\0';i++){
        ll index=query[i]-'a';
        if(!temp->characters[index])
            return false;
        temp=temp->characters[index];
    }
    return (temp!=NULL&&temp->IsEndOfWord);
}
int main()
{
    ll n,k,i;
    cin>>n>>k;
    root=get_node();
    string str[n],query;
    For{
        cin>>str[i];
        insert(root,str[i]);
    }
    for(i=0;i<k;i++){
        cin>>query;
        does_exist_in_trie(query)?cout<<"YES"<<endl:
                            cout<<"NO"<<endl;
    }
    return 0;
}