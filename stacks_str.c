#include<stdio.h>
#include<stdlib.h>

#define max 10

void push();
void pop();
void peek();
void display();

struct stacks
{
    int *stk;
    int top;
}st;

int main()
{
    st.stk = (int*)malloc(max*sizeof(int));
    st.top = -1;
    int op;
    do
    {
        printf("choose : \n 1 for insertion \n 2 for deletion \n 3 for peek \n 4 for display \n 0 for exit \n");
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
                peek();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 0:
            {
                exit(0);
            }
        }
    } while (op!=0);
}

void push()
{
    if (st.top==max-1)
    {
        printf("stack overflow\n");
    }
    int n;
    printf("enter the number you want to insert : \n");
    scanf("%d",&n);
    st.top++;
    st.stk[st.top]=n;
    return; 
}

void pop()
{
    if (st.top==-1)
    {
        printf("stack underflow\n");
    }
    int n=st.stk[st.top];
    printf("the element that is deleted : %d \n",n);
    st.top--;
    return;
}

void peek()
{
    if (st.top==-1)
    {
        printf("stack underflow\n");
    }
    int n=st.stk[st.top];
    printf("the element at top is : %d\n",n);
    return;
}

void display()
{
    if (st.top==-1)
    {
        printf("stack underflow\n");
    }
    int n;
    printf("the elements of stack are : \n");
    for(int i=st.top;i>-1;i--)
    {
        printf("%d \t",st.stk[i]);
    }
    return;
}