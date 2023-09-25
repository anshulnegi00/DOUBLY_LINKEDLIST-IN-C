#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

void enddelete(struct node **);

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


        printf("DO YOU WANNA CONTINUE\n");
        scanf("%d",&choice);
    
    }

    printf("PRINTING DATA BEFORE DELETION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

    enddelete(&head); 
    printf("PRINTING AFTER DELETION\n");
    temp=head;
    while(temp!=0)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
        
    }


}



void enddelete(struct node **headref)
{
    struct node *temp=*headref;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->previous->next=NULL;
    free(temp);
}