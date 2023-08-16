#include<stdio.h>
#include<stdlib.h>

#define max 10

int* queue;
int front = -1;
int rear = -1;

void insert();
void delete();
void display();

void main()
{
	int op;
    queue = (int*)malloc(max*sizeof(int));
	printf("enter :\n 1 for insert \n 2 for delete \n 3 for display \n 4 for exit \n");
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
	if (rear>=max-1 && front==0)
	{
		printf("queue is full\n");
	}
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

void delete()
{
	if (front==-1 || (front>rear))
	{
		printf("queue is empty \n");
	}
	printf("value that is deleted : %d \n",queue[front]);
	front++;
}

void display()
{
	int val;
	if (front==-1 || (front>rear))
	{
		printf("queue is empty \n");
	}
	printf("values in the queue are : \n");
	for (int i=front;i<=rear;i++)
	{
		printf("%d \t",queue[i]);
	}
	printf("\n");
}