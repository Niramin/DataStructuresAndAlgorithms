#include <stdlib.h>
#include <stdio.h>

// Singly Linked List
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
    struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data, int item);
struct node *addbefore(struct node *start,int data, int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

main()
{
    struct node *start=NULL;
    int choice,data,item,pos;
    while(1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add to empty list / Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add after node\n");
        printf("8.Add before node\n");
        printf("9.Add at position\n");
        printf("10.Delete\n");
        printf("11.Reverse\n");
        printf("12.Quit\n");
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
                count(start);
                break;
            case 4:
                printf("Enter the element you want to be searched for : ");
                scanf("%d",&data);
                search(start,data);
                break;
            case 5:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start=addatbeg(start,data);
                break;
            case 6:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start=addatend(start,data);
                break;
            case 7:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                printf("Enter the element after which to insert : ");
                scanf("%d",&item);
                start=addafter(start,data,item);
                break;
            case 8:
                 printf("Enter the element to be inserted : ");
                 scanf("%d",&data);
                 printf("Enter the element before which to insert : ");
                 scanf("%d",&item);
                 start=addbefore(start,data,item);
                 break;
            case 9:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                printf("Enter thr position at which to insert : ");
                scanf("%d",&pos);
                start=addatpos(start,data,pos);
                break;
            case 10:
                printf("Enter the element to be deleted : ");
                scanf("%d",&data);
                start=del(start,data);
                break;
            case 11:
                start=reverse(start);
                break;
            case 12:
                exit(1);
            default:
                printf("Wrong Choice\n");
        }

    }
}


void start(struct node *start)
{
    if(start==NULL)
    {
        printf("The List is Empty/There is no List \n");
        return;
    }

    struct node *p;
    p=start;
    printf("The list elements are : ");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n\n");

}

void display(struct node *start)
{
    struct node *p=start;
    if(p==NULL)
    {
        printf("List is empty\n");
    }
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n");
}

void count(struct node *start)
{
    int cnt=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        cnt++;
    }
    printf("The number of elements in the list are : %d\n",cnt);

}

void search(struct node *start, int item)
{
    struct node *p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            printf("The element %d is present at position : %d \n",item,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    printf("The element %d is not present in the list\n",item);
}

struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node *addatend(struct node *start, int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=NULL;
    struct node *p=start;
    while(p->link!=NULL)
        p=p->link;
    p->link=tmp;
    return start;
}

struct node *addafter(struct node *start,int data,int item)
{
    struct node *p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("Entered item not found in list!\n");
    return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
    struct node *tmp,*p;
    if(start==NULL)
    {
        printf("The list is empty\n");
        return start;
    }

    p=start;
    if(start->info==item)
    {
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
    }

    while(p->link!=NULL)
    {
        if(p->link->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("The item %d is not present in the list\n",item);
    return start;
}

struct node *addatpos(struct node *start,int data, int pos)
{
    struct node *p=start;
    if(pos==1)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
    }
    int i=0;
    for(i=1;i<pos-1;i++)
    {
        p=p->link;
    }

    if(p==NULL)
    {
        printf("There are not enough elements present in the list");
        return start;
    }
    else{
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=p->link;
        p->link=tmp;
        return start;
    }

}

struct node *create_list(struct node *start)
{
    int i,n,data;
    start=NULL;
    printf("Enter the number of elements to be inserted : ");
    scanf("%d",&n);
    printf("\n");
    if(n==0)
    return start;
    printf("Enter the first element to be inserted : ");
    scanf("%d",&data);
    printf("\n");
    start=addatbeg(start,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter next element to be inserted: ");
        scanf("%d",&data);
        printf("\n");
        start=addatend(start,data);
    }

    return start;

}

struct node *del(struct node *start,int data)
{
    struct node *tmp,*p;
    if(start==NULL)
    {
        printf("The list is empty\n");
        return start;
    }

    if(start->info==data)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==data)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return start;

        }
        p=p->link;
    }
    printf("Element not found\n");
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *p,*next,*prev;
    prev=NULL;
    p=start;
    while(p!=NULL)
    {
        next=p->link;
        p->link=prev;
        prev=p;
        p=next;
    }
    start=prev;
    return start;
}




