#include<bits/stdc++.h>
#define For for(i=0;i<n;i++)
using namespace std;
typedef long long ll;
struct linked_list{
    int info;
    struct linked_list *next;
};
struct linked_list *head=NULL;
void print_list(){
    struct linked_list *temp=(struct linked_list*)malloc(sizeof(struct linked_list));
    temp=head;
    cout<<"Modified linked list: ";
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insert_position(int item,int pos){
    struct linked_list *temp=(struct linked_list*)malloc(sizeof(struct linked_list));
    temp->info=item;
    struct linked_list *temp2=head;
    if(pos==1||temp2==NULL){
        temp->next=temp2;
        head=temp;
        print_list();
        return;
    }
    int c=1;
    while(temp2->next!=NULL&&c+1!=pos){
        temp2=temp2->next;
        c++;
    }
    temp->next=temp2->next;
    temp2->next=temp;
    print_list();
}
int main()
{
    ios::sync_with_stdio(false);
    char ch;
    cout<<"a.Insert at a given position."<<endl;

    while(1){
        cin>>ch;
        switch (ch)
        {
            ll val;
            case 'a':
                ll pos;
                cout<<"Enter a value: ";
                cin>>val;
                cout<<"Enter a position: ";
                cin>>pos;
                insert_position(val,pos);
                break;
            default:
                exit(1);
        }
    }
    return 0;
}