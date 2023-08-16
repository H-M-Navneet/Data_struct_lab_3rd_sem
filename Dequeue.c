#include<stdio.h>
#include<stdlib.h>

#define max 10

void front_insert();
void front_delete();
void rear_insert();
void rear_delete();
void display();

int dq[max];
int front = -1;
int rear = -1;

void main()
{
    int op;
    do
    {
        printf("enter \n 1 for front insertion \n 2 for front deletion \n 3 for rear insertion \n 4 for rear deletion \n 5 for display \n 6 for exit \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                front_insert();
                break;
            }
            case 2:
            {
                front_delete();
                break;
            }
            case 3:
            {
                rear_insert();
                break;
            }
            case 4:
            {
                rear_delete();
                break;
            }
            case 5:
            {
                display();
                break;
            }
            case 6:
            {
                exit (0);
                break;
            }
        }
    } while (op!=0);
}

void rear_insert()
{
    if (rear>=max-1 && front==0)
	{
		printf("queue is full\n");
	}
    else
    {
        if (front==-1)
        {
            front = 0;
        }
        rear++;
        int val;
        printf("enter the value to be inserted \n");
        scanf("%d",&val);
        dq[rear] = val;
    }
}

void front_delete()
{
    if (front==-1 || (front>rear))
	{
		printf("queue is empty \n");
	}
	printf("value that is deleted : %d \n",dq[front]);
	front++;
}

void front_insert()
{
    if (front<1 && rear!=-1)
    {
        printf("front side is full");
    }
    else
    {
        if (front==-1 && rear==-1)
        {
            rear_insert();
            return;
        }
        else
        {
            int val;
            printf("enter the value to  be inserted \n");
            scanf("%d",&val);
            front--;
            dq[front] = val;
        }
    }
}

void rear_delete()
{
    if (rear==-1 && rear<front)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("value that is deleted : %d \n",dq[rear]);
        rear--;
    }
}

void display()
{
    if (front==-1 && rear<front)
    {
        printf("queue is empty\n");
    }
    else
    {
        for (int i=0;i<max;i++)
        {
            printf("%d\t",dq[i]);
        }
        printf("\n");
    }
}