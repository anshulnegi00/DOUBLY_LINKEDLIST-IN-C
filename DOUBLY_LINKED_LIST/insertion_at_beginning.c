#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

void beginninginsert(struct node **);

int main()
{
    struct node *head=NULL;
    struct node *temp;
    struct node *newnode;

    int choice=1;
    while(choice)
    {

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("ENTER DATA\n");
    scanf("%d",&newnode->data);
    newnode->previous=NULL;
    newnode->next=NULL;

    if(head==NULL)
    {
        head=temp=newnode;
    }

    else
    {
        temp->next=newnode;
        newnode->previous=temp;
        temp=newnode;
    }

    printf("DO YOU WANT TO CONITNUE 0|1 \n");
    scanf("%d",&choice);

    }

    printf("PRINTING DATA BEFORE INSERTION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }


    beginninginsert(&head);

    printf("PRINTING DATA AFTER INSERTION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }


}


void beginninginsert(struct node **headref)
{
    struct node *newnode;
    

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT AT BEGINNING\n");
    scanf("%d",&newnode->data);
    newnode->previous=NULL;
    (*headref)->previous=newnode;
     newnode->next=*headref;
    *headref=newnode;


}

