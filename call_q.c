#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 10

struct call
{
    int id;
    time_t arrival_time;
};

struct call_q
{
    struct call call[max];
    int rear;
    int front;
};

void inq(struct call_q* q,struct call calls)
{
    if((q->rear+1)%max == q->front)
    {
        printf("queue is full\n");
    }
    else
    {
        q->rear = (q->rear+1)%max;
        q->call[q->rear] = calls;
    }
}

struct call deq(struct call_q* q)
{
    if(q->front==q->rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        q->front = (q->front+1)%max;
        return q->call[q->front];
    }
}

int main()
{
    struct call_q q;
    q.front = 0;
    q.rear = 0;
    int op;
    struct call call;
    while(1)
    {
        printf("Enter : \n 1.Add call \n 2.Remove call \n 3.Exit \n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                call.id = rand();
                call.arrival_time = time(NULL);
                inq(&q,call);
                break;
            }
            case 2:
            {
                call = deq(&q);
                printf("Call with id %d and arrival time %ld removed from queue\n",call.id,call.arrival_time);
                break;
            }
            case 3:exit(0);
        }
    }
    return 0;
}