#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert_in_the_front(int in_data)
{
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=in_data;
    if(head==NULL){
        head=temp;
        temp->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void insert_in_the_back(int in_data)
{
    struct node *temp1=NULL,*temp2=NULL;
    temp2=(struct node*)malloc(sizeof(struct node));
    temp1=head;
    temp2->data=in_data;
    if(head==NULL)
    {
        head=temp2;
        temp2->next=NULL;
        return;
    }
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp2;
    temp2->next=NULL;
}
void insert_in_the_middle(int position,int in_data)
{
    struct node *temp1=NULL,*temp2=NULL;
    temp2=(struct node*)malloc(sizeof(struct node));
    temp2->data=in_data;
    temp1=head;

    for(int i=2;i<position;i++)
    {
        if(temp1->next==NULL)
        {
            printf("previous node can't be empty.\n");
            return;
        }
        temp1=temp1->next;
    }
    temp2->next=temp1->next;
    temp1->next=temp2;
}
void print_linked_list(struct node *ptr)
{
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}
int main()
{
    insert_in_the_front(3);
    printf("Inserting node in front when there is no built node: ");
    print_linked_list(head);
    printf("\nInserting nodes in the front when there are nodes built before: ");
    insert_in_the_front(4);
    insert_in_the_front(1);
    print_linked_list(head);;

    printf("\nInserting nodes in the back(Both when there is no built node and when there are nodes built before): ");
    insert_in_the_back(7);
    insert_in_the_back(10);
    print_linked_list(head);

    printf("\nInserting nodes in the middle when there are nodes built before: ");
    insert_in_the_middle(3,5);
    insert_in_the_middle(5,8);
    print_linked_list(head);
}
