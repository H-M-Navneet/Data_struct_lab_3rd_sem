#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
}*first;

void getnode();
void insert_rear();
void delete_rear();
void insert_front();
void delete_front();
void insert_after();
void insert_before();
void insert();
void display();

struct node *temp;
int size=0;

void getnode()
{
        int x;
        printf("enter the value to be inserted\n");
        scanf("%d",&x);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;
}

void insert_rear()
{
        if (first==NULL)
                first=temp;
        else
        {
                struct node *ptr;
                ptr = first;
                while(ptr->next!=NULL)
                {
                        ptr = ptr->next;
                }
                ptr->next = temp;
                temp->next = NULL;
        }
        size++;
}

void delete_rear()
{
    if (first==NULL)
        printf("list is empty\n");
    else if (first->next==NULL)
        first = NULL;
    else
    {
        struct node *ptr,*p;
        ptr = first;
        p = first;
        while(ptr->next!=NULL)
        {
            p = ptr;
            ptr = ptr->next;
        }
        p->next = NULL;
        free(ptr);
    }
    size--;
}

void display()
{
        if (first==NULL)
                printf("list is empty\n");
        else if (first->next==NULL)
        {
                struct node *ptr;
                ptr = first;
                printf("%d",ptr->data);
                free(ptr);
        }
        else
        {
                struct node *ptr;
                ptr = first;
                while(ptr!=NULL)
                {
                        printf("%d \t",ptr->data);
                        ptr = ptr->next;
                }
        }
        printf("\n Size of list = %d \n",size);
}

void main()
{
        int op;
        do
        {
                printf("Enter : \n 1.Create node \n 2.Insert from rear \n 3.Delete from rear \n 4.Insert from front \n 5.Delete from front \n 6.Insert at given position \n 7.Display \n 8.Exit \n");
                scanf("%d",&op);
                switch(op)
                {
                        case 1:
                                {
                                        getnode();
                                        break;
                                }
                        case 2:
                                {
                                        insert_rear();
                                        break;
                                }
                        case 3:
                                {
                                        delete_rear();
                                        break;
                                }
                        case 4:
                                {
                                        insert_front();
                                        break;
                                }
                        case 5:
                                {
                                        delete_front();
                                        break;
                                }
                        case 6:
                                {
                                        insert();
                                        break;
                                }
                        case 7:
                                {
                                        display();
                                        break;
                                }
                        case 8:exit(0);
                }
        }while(op!=0);
}

void insert_front()
{
       if (first==NULL)
                first=temp;
       else
       {
                temp->next = first;
                first = temp;
       }
       size++;
}

void delete_front()
{
        if (first==NULL)
        {
                printf("list is empty\n");
        }
        else
        {
                struct node *ptr;
                ptr = first;
                first = ptr->next;
                free(ptr);
        }
        size--;
}

void insert()
{
        printf("Enter the position at which the node is to be inserted \n");
        int pos;
        scanf("%d %d",&pos);
        if (pos<1 || pos > size+1)
        {
                printf("Invalid position \n");
        }
        else
        {
                struct node* ptr;
                if (pos=1)
                {
                        first=temp;
                }
                ptr = first;
                for (int i=1;i<pos-1;i++)
                {
                        ptr = ptr->next;
                }
                temp->next = ptr->next;
                ptr->next = temp;
        }
}