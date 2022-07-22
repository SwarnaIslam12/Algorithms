#include<stdio.h>
struct node()
{
    int data;
    struct node *next;
};

void print_linked_list(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

int main()
{
    struct node *head,*one=NULL,*two=NULL,*three=NULL;
    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));

    one->next=two;
    two->next=three;
    three->next=NULL;

    one->data=1;
    two->data=1;
    three->data=1;

    head=one;

    printl_linked_list(head);
}
