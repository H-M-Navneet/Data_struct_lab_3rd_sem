#include<stdio.h>
#include<stdlib.h>

#define max 10
int top=-1;
int st[max];

void push(int st[]);
void pop(int st[]);
void peek(int st[]);
void display(int st[]);

int main()
{
    int op;
    do
    {
        printf("choose : \n 1 for insertion \n 2 for deletion \n 3 for peek \n 4 for display \n 0 for exit \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                push(st);
                break;
            }
            case 2:
            {
                pop(st);
                break;
            }
            case 3:
            {
                peek(st);
                break;
            }
            case 4:
            {
                display(st);
                break;
            }
            case 0:
            {
                exit(0);
            }
        }
    } while (op!=0);
}

void push(int st[])
{
    if (top==max-1)
    {
        printf("stack overflow\n");
    }
    int n;
    printf("enter the number you want to insert : \n");
    scanf("%d",&n);
    top++;
    st[top]=n;
    return; 
}

void pop(int st[])
{
    if (top==-1)
    {
        printf("stack underflow\n");
    }
    int n=st[top];
    printf("the element that is deleted : %d \n",n);
    top--;
    return;
}

void peek(int st[])
{
    if (top==-1)
    {
        printf("stack underflow\n");
    }
    int n=st[top];
    printf("the element at top is : %d\n",n);
    return;
}

void display(int st[])
{
    if (top==-1)
    {
        printf("stack underflow\n");
    }
    int n;
    printf("the elements of stack are : \n");
    for(int i=top;i>-1;i--)
    {
        printf("%d \t",st[i]);
    }
    return;
}