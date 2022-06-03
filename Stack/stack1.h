#include <stdio.h>
#include <stdlib.h>

#define ITEM int
#define S 10
typedef struct 
{
    ITEM arr[S];
    int tos;
}stack;

void init(stack *);
int isFull(stack *);
int isEmpty(stack *);
int push(stack *,ITEM);
ITEM pop(stack *);
ITEM peek(stack *);