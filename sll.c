#include<stdio.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head;
struct node* insert_at_beg(struct node *);
struct node* insert_at_end(struct node *);
struct node* delete_at_beg(struct node *);
struct node* delete_at_end(struct node *);
struct node* insert_at_pos(struct node *,int);
struct node* delete_at_pos(struct node *,int);
void display(struct node *);
int count_nodes(struct node *);
void search_node(struct node *,int);
struct node *temp,*temp1,*newnode;
main()
{
int ch,c,pos,d;
head=NULL;
   while(1)
   {
     printf("1--insert at begining\n");
     printf("2--insert at end\n");
     printf("3--delete from begining\n");
     printf("4--delete from end\n");
     printf("5--display linked list\n");
     printf("6--count nodes\n");
     printf("7--insert at specific position\n");
     printf("8--Search the given data\n");
     printf("9--delete at specific position\n");
     printf("10--delete from lhs\n");
     printf("11--exit\n");
     printf("enter your choice\n");
     scanf("%d",&ch);
     switch(ch)
     {
      case 1:newnode=(struct node*)malloc(sizeof(struct node));
             printf("enter data\n");
             scanf("%d",&newnode->data);
             head=insert_at_beg(newnode);
             break;
    case 2: newnode=(struct node*)malloc(sizeof(struct node));
             printf("enter data\n");
             scanf("%d",&newnode->data);
             head=insert_at_end(newnode);
             break;
    case 3: if(head==NULL)
             printf("linked list is empty---cant delete\n");
             else
             {
                head=delete_at_beg(head);
             }
             break;
    case 4: if(head==NULL)
             printf("linked list is empty---cant delete\n");
             else
             {
                head=delete_at_end(head);
             }
             break;
    case 5: display(head);break;
    case 6: c=count_nodes(head);
            printf("\n no of codes = %d\n",c);
            break;
    case 7: printf("Enter position\n");
            scanf("%d",&pos);
            if(pos<1||pos>count_nodes(head)+1)
                printf("Invalid position\n");
            else
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("Enter data\n");
                scanf("%d",&newnode->data);\
                head=insert_at_pos(newnode,pos);
            }
            break;
    case 8:printf("Enter the data to be searched\n");
           scanf("%d",&d);
           search_node(head,d);
           break;
    case 9: printf("Enter position\n");
            scanf("%d",&pos);
            if(pos<1||pos>count_nodes(head)+1)
                printf("Invalid position\n");
            else
            {
                head=delete_at_pos(head,pos);
            }
            break;
    case 10: exit(0);break;
    default: printf("Invalid choice\n");
     }
   }
}
struct node* insert_at_beg(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     newnode->next=head;
     head=newnode;
     return(head);
   }
}
struct node* insert_at_end(struct node *newnode)
{
   if(head==NULL)
   {
     head=newnode;
     head->next=NULL;
     return(head);
   }
   else
   {
     temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;

     }
     temp->next=newnode;
        newnode->next=NULL;
        return(head);

   }
}
void display(struct node *head)
{
   if(head==NULL)
   {
     printf("the linkded list is empty\n");
   }
   else
   {
      temp=head;
      while(temp!=NULL)
      {
         printf("%d->",temp->data);
         temp=temp->next;
      }
      printf("\n");
   }
}
struct node* delete_at_beg(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           head=head->next;
           printf("node deleted=%d\n",temp->data);
           free(temp);
           return(head);
       }
    }
}
struct node* delete_at_end(struct node *head)
{
    if(head==NULL)
    {
        printf("linkded list is empty\n");
    }
    else
    {
       if(head->next==NULL)
       {
           printf("node deleted=%d\n",head->data);
           free(head);
           head=NULL;
           return(head);
       }
       else
       {
           temp=head;
           //temp1=head->next;
           while(temp->next!=NULL)
           {
               temp1=temp;
               temp=temp->next;
           }
           printf("node deleted=%d\n",temp->data);
           free(temp);
           temp1->next=NULL;
           return(head);
       }
    }
}
int count_nodes(struct node *head)
{
    int count=0;
    if(head==NULL)
        return(count);
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return(count);
    }
}

struct node* insert_at_pos(struct node *newnode,int pos)
{
    if(pos==1)
    {
        head=insert_at_beg(head);
    }
    else
    {
        int p=1;
        temp=head;
        while(p!=pos)
        {
            temp1=temp;
            temp=temp->next;
            p++;
        }
        temp1->next=newnode;
        newnode->next=temp;
    }
    return(head);
}
struct node* delete_at_pos(struct node *head,int pos)
{
    if(pos==1)
    {
        head=delete_at_beg(head);
    }
    else
    {
        int p=1;
        temp=head;
        while(p!=pos)
        {
            temp1=temp;
            temp=temp->next;
            p++;
        }
        temp1->next=temp->next;
        printf("Node deleted =%d\n",temp->data);
        free(temp);
    }
    return(head);
}
void search_node(struct node *head,int d)
{
    int found=0;
    if(head==NULL)
        printf("Linked list is empty Cant Search");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==d)
            {
                printf("Node found\n");
                found=1;
                break;
            }
    temp=temp->next;
        }
        if(found==0)
        {
            printf("Node not found\n");
        }
    }
}


