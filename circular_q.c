#include<stdio.h>
#include<stdlib.h>

#define max 5

int queue[max];
int front = -1;
int rear = -1;

void insert();
void delete();
void display();

void main()
{
	int op;
	do
	{
		printf("enter :\n 1 for insert \n 2 for delete \n 3 for display \n 4 for exit \n");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
			{
				insert();
				break;
			}
			case 2:
			{
				delete();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4:
			{
				exit (0);
				break;
			}
		}
	}while (op!=0);
}

void insert()
{
	if (rear>=max-1 && front==0)
	{
		printf("queue is full\n");
	}
    else if (rear<max-1)
    {
        if (front==-1)
        {
            front = 0;
        }
        rear++;
        int val;
        printf("enter the value to be inserted \n");
        scanf("%d",&val);
        queue[rear] = val;
    }
    else if (front!=0 && rear>=max-1)
    {
        int val;
        printf("enter the value that is to be entered \n");
        scanf("%d",&val);
		if (rear == 0)
		{
			do
			{
				rear++;
				queue[rear] = val;
			} while (rear<front);
			
		}
		else
		{
			rear = 0;
        	queue[rear] = val;
		}
    }
}

void delete()
{
	if (front==-1 || (front>rear))
	{
		printf("queue is empty \n");
	}
	int data = queue[front];
    queue[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == max-1)
        front = 0;
    else
        front++;
	printf("deleted element is %d \n",data);
}

void display()
{
	int val;
	if (front==-1 || (front>max-1))
	{
		printf("queue is empty \n");
	}
    else 
    {
        if (rear>front)
        {
            printf("values in the queue are : \n");
            for (int i=front;i<=rear;i++)
            {
                printf("%d \t",queue[i]);
            }
            printf("\n");
        }
        else
        {
            printf("values in queue are : \n");
            for (int j=front;j<max;j++)
            {
                printf("%d \t",queue[j]);
            }
			for (int i=0;i<=rear;i++)
			{
				printf("%d \t",queue[i]);
			}
            printf("\n");
        }
    }
	printf("\n");
}