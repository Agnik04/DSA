#include "stack1.h"

void init(stack *pts)
{
    pts->tos = -1;
}

int isFull(stack *pts)
{
    if(pts->tos == S-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack *pts)
{
    if(pts->tos == -1)
        return 1;
    else
        return 0;
}

int push(stack *pts , ITEM data)
{
    if(isFull(pts)==1)
        return 0;
    pts->tos++;
    pts->arr[pts->tos] = data;
}

ITEM pop(stack *pts)
{
    ITEM tmp;
    if(isEmpty(pts)==1)
        return 0;
    tmp = pts->arr[pts->tos];
    pts->tos--;
    return tmp;
}

ITEM peek(stack *pts)
{
    if(isEmpty(pts)==1)
        return 0;
    return pts->arr[pts->tos];
}
