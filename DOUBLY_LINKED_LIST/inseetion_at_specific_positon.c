#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

void specificinsert(struct node **);

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

    specificinsert(&head);

    printf("PRINTING DATA AFTER INSERTION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

  


}


void specificinsert(struct node**headref)
{ 
    int i=1;
    int position;
    struct node *temp=*headref;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("ENTER DATA YOU WANT TO INSERT\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->previous=NULL;

    printf("ENTER POSTION AT WHICH YOU WANT TO INSERT\n");
    scanf("%d",&position);

    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    
    newnode->previous=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->previous=newnode;


}
