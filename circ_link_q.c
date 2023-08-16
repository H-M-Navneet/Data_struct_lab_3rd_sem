#include<stdio.h>
#include<stdlib.h>
#define max 10

struct ele
{
    int value;
    int next;
};

struct cirq
{
    struct ele q[max];
    int front;
    int rear;
};

void inq(struct cirq* q,int value);
int deq(struct cirq* q);

int main()
{
    struct cirq q;
    q.front = 0;
    q.rear = 0;
    int op;
    int val;
    do
    {
        printf("Enter : \n 1.Add \n 2.Delete \n 3.Exit \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                printf("enter the value to be inserted \n");
                scanf("%d",&val);
                inq(&q,val);
                break;
            }
            case 2:
            {
                val = deq(&q);
                printf("deleted value : %d\n",val);
                break;
            }
            case 3:exit(0);
        }
    } while (op!=0);
    return 0;
}

void inq(struct cirq* q,int val)
{
    if(q->q[q->rear].next==q->front)
    {
        printf("queue is full\n");
    }
    else
    {
        q->q[q->rear].value = val;
        q->q[q->rear].next = (q->rear+1)%max;
        q->rear = q->q[q->rear].next;
    }
}

int deq(struct cirq* q)
{
    if(q->front==q->rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        int val = q->q[q->front].value;
        q->front = q->q[q->front].next;
        return val;
    }
}