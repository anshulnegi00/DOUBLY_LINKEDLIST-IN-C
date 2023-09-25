#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
    struct node *previous; 
};

void specificdelete(struct node **);

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

        printf("DO YOU WANT TO CONTINUE \n");
        scanf("%d",&choice);
    }

    printf("PRINTING DATA BEFORE DELETION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

    specificdelete(&head);
    printf("PRINTING DATA AFTER DELETION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}


void specificdelete(struct node **headref)
{
    int i=1;
    int position;
    struct node *temp=*headref;
    printf("ENTER THE POSTION YOU WANT TO DELETE\n");
    scanf("%d",&position);
    while(i<position)
    {
        temp=temp->next;
        i++;
    }
    temp->previous->next=temp->next;
    temp->next->previous=temp->previous;
    free(temp);

}