#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
ll i;
struct node{
          int data=0;
          struct node *next,*prev;
};
struct node *head=NULL;
void print_list()
{
          struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp=head;
          while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
          }
          cout<<"\n";
}
void insert_at_the_beginning(int value)
{
          struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp->data=value;
          if(head==NULL){
                    temp->next=NULL;
                    temp->prev=NULL;
                    head=temp;
          }
          else{
                    temp->prev=NULL;
                    temp->next=head;
                    head->prev=temp;
                    head=temp;
          }
}
void insert_at_the_end(int value)
{
          struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp->data=value;
           if(head==NULL){
                    temp->next=NULL;
                    temp->prev=NULL;
                    head=temp;
          }
          else{
                   struct node *temp2=(struct node*)malloc(sizeof(struct node));
                   temp2=head;
                   while(temp2->next!=NULL){
                              temp2=temp2->next;
                   }
                   temp2->next=temp;
                   temp->prev=temp2;
                   temp->next=NULL;
          }
}
void insert_at_the_middle(ll value,ll pos)
{
          struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp->data=value;
          struct node *temp2=NULL;
          temp2=head;
           if(head==NULL){
                    temp->next=NULL;
                    temp->prev=NULL;
                    head=temp;
                    return;
          }
          for(ll j=2;j<pos;j++)
          {
                    if(temp2->next!=NULL)
                              temp2=temp2->next;
          }
          temp->prev=temp2;
          temp->next=temp2->next;
          temp2->next->prev=temp;
          temp2->next=temp;
          print_list();
}
void delete_from_beginning()
{
          head=head->next;
          head->prev=NULL;
}
void delete_from_end()
{
           struct node *temp=(struct node*)malloc(sizeof(struct node));
          temp=head;
          while(temp->next!=NULL)
                    temp=temp->next;
          temp->prev->next=NULL;
          free(temp);
}
void delete_from_middle(int pos)
{
          struct node *temp=(struct node*)malloc(sizeof(struct node)),*ptr;
          temp=head;
          for(ll j=2;j<pos;j++)
          {
            if(temp->next!=NULL)
                    temp=temp->next;
          }
          ptr=temp->next;
          temp->next=ptr->next;
          ptr->next->prev=temp;
          free(ptr);
}
int main()
{
          int n,list_value,position;
          cout<<"How many data do you want to insert at the beginning of the list"<<endl;
          cin>>n;
          for(i=0;i<n;i++)
          {
                    cin>>list_value;
                    insert_at_the_beginning(list_value);
          }
          print_list();
          cout<<"How many data do you want to insert at the end of the list"<<endl;
          cin>>n;
          for(i=0;i<n;i++)
          {
                    cin>>list_value;
                    insert_at_the_end(list_value);
          }
          print_list();
          cout<<"How many data do you want to insert at the middle of the list"<<endl;
          cin>>n;
          for(i=0;i<n;i++)
          {
                    cin>>list_value>>position;
                    insert_at_the_middle(list_value,position);
          }
          cout<<"Delete from the beginning"<<endl;
          delete_from_beginning();
          print_list();
          cout<<"Delete from the end"<<endl;
          delete_from_end();
          print_list();
          cout<<"Enter the position of the element that you want to delete"<<endl;
          cin>>position;
          delete_from_middle(position);
          print_list();
}
