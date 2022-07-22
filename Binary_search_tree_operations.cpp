#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nodes{
          ll data;
          struct nodes *right,*left;
};
struct nodes *root=NULL;
map<ll,bool>mp;
map<ll,ll>mp2;
ll p;
void new_node(struct nodes *temp,ll value)
{
          struct nodes *temp2=NULL;
          temp2=(struct nodes*)malloc(sizeof(struct nodes));
          temp2->data=value;
          temp2->right=temp2->left=NULL;
          if(temp==NULL)
                    root=temp2;
          else if(value>temp->data)
                    temp->right=temp2;
          else if(value<temp->data)
                    temp->left=temp2;
          mp[temp2->data]=true;
}
void insert_node(struct nodes *temp,ll value)
{
         if(temp==NULL||(temp->right==NULL&&value>temp->data)||(temp->left==NULL&&value<temp->data)){
                    new_node(temp,value);
                    return;
          }
         else if(value>temp->data)insert_node(temp->right,value);
         else if(value<temp->data){insert_node(temp->left,value);}
}
void get_successor(struct nodes *temp,ll value)
{
          if(temp!=NULL){
                    get_successor(temp->left,value);
                    if(mp[temp->data]){
                              mp2[p]=temp->data;
                              if(mp2[p-1]==value){
                                        temp=NULL;
                                        return;
                              }
                              p++;
                    }
                    get_successor(temp->right,value);
          }
}
void delete_node(struct nodes *temp,ll value)
{
          get_successor(temp,value);
          if(temp!=NULL){
                    mp[temp->data]=false;
                    temp->data=mp2[p];}
          p=0;

}
void display(struct nodes *temp)
{
          if(temp!=NULL){
                    display(temp->left);
                    if(mp[temp->data])
                              cout<<temp->data<<" ";
                    display(temp->right);
          }
          return;
}
int main()
{
          char ch;
          ll value;
          cin>>ch;
          while(ch!='s'){
                    if(ch=='i'){
                              cin>>value;
                              insert_node(root,value);
                    }
                    else if(ch=='d'){
                              cout<<"Available nodes."<<endl;
                              display(root);
                              cin>>value;
                              if(!mp[value])cout<<"Not available."<<endl;
                              else
                                        delete_node(root,value);

                    }
                    else{
                              display(root);
                              cout<<endl;
                    }
                    cin>>ch;
          }
}
