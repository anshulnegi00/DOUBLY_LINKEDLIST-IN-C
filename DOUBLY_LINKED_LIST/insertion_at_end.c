#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

void endinsert(struct node**);

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

    printf("DO YOU WANT TO CONTINUE\n");
    scanf("%d",&choice);
    
    }

    printf("PRINTING DATA BEFORE INSERTION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

      endinsert(&head);

      printf("PRINTING DATA AFTER INSERTION\n");
      temp=head;
      while(temp!=0)
      {
        printf("%d\n",temp->data);
        temp=temp->next;
      }


}


void endinsert(struct node **headref)
{
    struct node *temp=*headref;
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    while(temp->next!=0)
    {
        temp=temp->next; 
    }
    temp->next=newnode;
    newnode->previous=temp;

}