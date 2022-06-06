#include "queue1.h"

void init(Queue *q)
{
    q->rear = -1;
    q->front = -1;
}

int isempty(Queue *q)
{
    if((q->rear == -1) && (q->front == -1))
        return 1;
    else
        return 0;
}

int isfull(Queue *q)
{
    if((q->front == 0 && q->rear == S-1) || (q->front == q->rear+1))
        return 1;
    else
        return 0;
}

void enqueue(Queue *q , int value)
{
    if(isfull(q) == 1)
        return;
    else{
        if(q->front == -1)
            q->front = 0;
        if(q->rear == S-1)
            q->rear = 0;
        else
            q->rear++;

        q->arr[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    int tmp;
    if(isempty(q) == 1)
        return 0;
    else
    {
        tmp = q->arr[q->front];

        if(q->front == q->rear)
            q->front = q->rear = -1;
        else if(q->front == S-1)
            q->front = 0;
        else
            q->front++;
        return tmp;
    }
}