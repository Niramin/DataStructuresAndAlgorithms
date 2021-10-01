
#include <stdlib.h>
#include <stdio.h>

// Doubly Linked List
/*
Traversal of a Linked List
Searching of an element
Insertion of an element
Deletion of an element
Creation of a linked list
Reversal of a linked list
*/

struct node
{
    int info;
    struct node *next;
    struct node *prev;

};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addtoempty(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data, int item);
struct node *addbefore(struct node *start,int data, int item);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

int main()
{
    struct node *start=NULL;
    int choice,data,item,pos;
    while(1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Add to empty List\n");
        printf("4.Add at beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after\n");
        printf("7.Add before\n");
        printf("8.Delete\n");
        printf("9.Reverse\n");
        printf("10.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                start=create_list(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("Insert element to be inserted :");
                scanf("%d",&data);
                start=addtoempty(start,data);
                break;
            case 4:
                printf("Enter the element  to be inserted : ");
                scanf("%d",&data);
                start=addatbeg(start,data);
                break;
            case 5:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start=addatend(start,data);
                break;
            case 6:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                printf("Enter the element after which insertion is to be done : ");
                scanf("%d",&item);
                start=addafter(start,data,item);
                break;
            case 7:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                printf("Enter the element before which to insert : ");
                scanf("%d",&item);
                start=addbefore(start,data,item);
                break;
            case 8:
                printf("Enter the element to be deleted : ");
                scanf("%d",&data);
                start=del(start,data);
                break;
            case 9:
                start=reverse(start);
                break;
            case 10:
                exit(1);
            default:
                printf("Wrong Choice\n");
        }

    }
    return 0;
}


void display(struct node *start)
{
    struct node *p=start;
    printf("\n\n");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n\n");

}

struct node *addatbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->prev=NULL;
    tmp->info=data;
    tmp->next=start;
    start->prev=tmp;
    start=tmp;
    return start;
}

struct node *addtoempty(struct node *start,int data)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->next=NULL;
    tmp->prev=NULL;
    start=tmp;
    return start;
}

struct node *addatend(struct node *start,int data)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->next=NULL;
    struct node *p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    tmp->prev=p;
    p->next=tmp;
    return start;
    
}

struct node *addafter(struct node *start,int data,int item)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;

    struct node *p=start;
     while(p!=NULL)
     {
         if(p->info==item)
         {
             tmp->next=p->next;
             tmp->prev=p;
             if(p->next!=NULL)
                p->next->prev=tmp;
            p->next=tmp;
            return start;
         }
         p=p->next;
             
     }
     printf("Element not present in the list \n\n");
     return start;

}

struct node *addbefore(struct node *start, int data,int item)
{
    if(start==NULL)
    {
        printf("List is empty\n\n");
        return start;
    }
    struct node *p=start;
    if (p->info==item)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->prev=NULL;
        tmp->next=p;
        p->prev=tmp;
        start=tmp;
        return start;
    }

    while(p!=NULL)
    {
        if(p->info==data)
        {
            struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->prev=p->prev;
            tmp->next=p;
            p->prev->next=tmp;
            p->prev=tmp;
            return start;

        }
        p=p->next;
    }
    printf("Element not present in list\n\n");
    return start;
        
}

struct node *create_list(struct node *start)
{
    int n=0;
    int f=0;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    printf("\n");
    start=NULL;
    if(n==0)
    {
        return start;
    }
    printf("Enter first element to be inserted :");
    scanf("%d",&f);
    printf("\n");
    start=addtoempty(start,f);
    int i=0;
    for(i=2;i<=n;i++)
    {
        printf("Enter next element to be inserted :");
        scanf("%d",&f);
        printf("\n");
        start=addatend(start,f);

    }
    return start;
}

struct node *del(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("List is empty\n\n");
        return start;
    }
    struct node *tmp;
    if(start->next==NULL)
    {
        if(start->info==data)
        {
            tmp=start;
            start=NULL;
            free(tmp);
            return start;
        }
        else{
            printf("Element not present in List\n\n");
            return start;
        }
    }
    tmp=start->next;
    while(tmp->next!=NULL)
    {
        if(tmp->info==data)
        {
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            free(tmp);
            return start;
        }
        tmp=tmp->next;
    }

    if(tmp->info==data)
    {
        tmp->prev->next=NULL;
        free(tmp);
        return start;
    }
    printf("Element not found in list\n\n");
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    printf("List is reversed\n\n");
    return start;
}


