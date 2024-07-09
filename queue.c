#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct queue
{
    int a[MAX];
    int front;
    int rear;
}q1;
void enqueue(int n,q1* ptr)
{
    int data;
    if (ptr->rear==n-1)
    {
        printf("Queue is full !!");
    }
    else
    {
        printf("Enter the data to enqueue \n");
            scanf("%d",&data);
        if(ptr->front==-1)
        {
            ptr->front=0;
        }
        ptr->rear++;
        ptr->a[ptr->rear]=data;
    }
}
int dequeue(q1*ptr)
{
    if (ptr->front==-1)
    {
        printf("Queue is empty!!\n");

    }
    else
    {
        printf("Item deleted = %d\n",ptr->a[ptr->front]);
        ptr->front++;
        if(ptr->front>ptr->rear)
        {
            ptr->front=ptr->rear=-1;
        }
        return(ptr->a[ptr->front-1]);

    }
}
void display(q1* ptr)
{
    if(ptr->rear==-1)
    {
        printf("Queue!! is empty\n");
    }
    else
    {
        for (int i=ptr->front;i<=ptr->rear;i++)
        {
            printf("%d->",ptr->a[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter size\n");
    scanf("%d",&n);
    q1* ptr=(q1*)malloc(sizeof(q1));
    ptr->front=-1;
    ptr->rear=-1;
    int data;
    while(1)
    {
        int ch;
        printf("\n Enter 1 for enqueue\t 2 for dequeue \t 3 to display\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:enqueue(n,ptr);
            break;
        case 2:
            dequeue(ptr);
            break;
        case 3:
            display(ptr);
            break;
        default:
            break;
        }
    }
    return 0;
}
