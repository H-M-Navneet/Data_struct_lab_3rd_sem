#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node* next;
};

struct node* top = NULL;

struct node* create()
{
        struct node* new;
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data you want to insert\n");
        int val;
        scanf("%d",&val);
        new->data = val;
        new->next = NULL;
        return new;
}

void push()
{
        struct node* new;
        new = create();
        if(top==NULL)
                top = new;
        else
        {
                new->next = top;
                top = new;
        }
}

void pop()
{
        if(top==NULL)
                printf("list is empty\n");
        else
        {
                printf("element deleted is %d \n",top->data);
                top = top->next;
        }
}

void display()
{
        if(top==NULL)
                printf("list is empty\n");
        else
        {
                struct node* ptr;
                ptr = top;
                while(ptr!=NULL)
                {
                        printf("%d \t",ptr->data);
                        ptr = ptr->next;
                }
        }
}

void main()
{
        int op;
        do
        {
                printf("enter : \n 1.Push \n 2.Pop \n 3.Display \n 4.Exit \n");
                scanf("%d",&op);
                switch(op)
                {
                        case 1:
                        {
                                push();
                                break;
                        }
                        case 2:
                        {
                                pop();
                                break;
                        }
                        case 3:
                        {
                                display();
                                break;
                        }
                        case 4: exit(0);
                }
        }while(op!=0);
}