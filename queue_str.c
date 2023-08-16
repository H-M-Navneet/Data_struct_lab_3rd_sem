#include<stdio.h>
#include<stdlib.h>

#define max 10

struct queue 
{
	int* queue;
	int rear;
	int front;
}q;

void insert();
void delete();
void display();

void main()
{
	int op;
    q.queue = (int*)malloc(max*sizeof(int));
	printf("enter :\n 1 for insert \n 2 for delete \n 3 for display \n 4 for exit \n");
    q.front = -1;
    q.rear = -1;
	do
	{
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
	if (q.rear>=max-1 && q.front==0)
	{
		printf("queue is full\n");
	}
	if (q.front==-1)
	{
		q.front = 0;
	}
	q.rear++;
	int val;
	printf("enter the value to be inserted \n");
	scanf("%d",&val);
	q.queue[q.rear] = val;
}

void delete()
{
	if (q.front==-1 || (q.front>q.rear))
	{
		printf("queue is empty \n");
	}
	printf("value that is deleted : %d \n",q.queue[q.front]);
	q.front++;
}

void display()
{
	int val;
	if (q.front==-1 || (q.front>q.rear))
	{
		printf("queue is empty \n");
	}
	printf("values in the queue are : \n");
	for (int i=q.front;i<=q.rear;i++)
	{
		printf("%d \t",q.queue[i]);
	}
	printf("\n");
}