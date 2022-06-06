#include <stdio.h>
#define S 5

typedef struct
{
    int arr[S];
    int rear, front;    
}Queue;

void init(Queue *q);
int isempty(Queue *q);
int isfull(Queue *q);
void enqueue(Queue *q , int value);
int dequeue(Queue *q);