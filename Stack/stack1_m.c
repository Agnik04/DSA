#include "stack1.h"

int main()
{
    stack s;
    ITEM data;
    int ch;

    init(&s);
    while(1)
    {
        printf("******M E N U*****\n\n");
        printf("Press 1 check it's ful or not.\n");
        printf("Press 2 check it's empty or not.\n");
        printf("Press 3 to push\n");
        printf("Press 4 to pop.\n");
        printf("Press 5 to peek.\n");
        printf("Press 6 to EXIT.\n");
        printf("Enter your choice: ");  
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:            
                if(isFull(&s)==1)
                    printf("\nStack is Full.\n\n");
                else    
                    printf("\nStack is not Full\n\n");
                break;
            case 2:
                if(isEmpty(&s)==1)
                    printf("\nStack is Empty.\n\n");
                else
                    printf("\nStack is not Empty.\n\n");
                break;
            case 3:
                if(isFull(&s)==1)
                    printf("Overflow\n");
                else
                {
                    printf("Enter the data you want to push into your stack :");
                            scanf("%d", &data);
                    push(&s, data);                    
                }
                break;
            case 4:
                if(isEmpty(&s)==1)
                    printf("Underflow\n");
                else
                {
                    printf("The poped out element = %d\n\n",pop(&s));
                }             
                break;
            case 5:
                printf("\nThe Last Element in the stack is: %d\n\n",peek(&s));
                break;
            case 6:
                return 0;
                break;
            default:
                printf("\nEnter a Valid Choice!\n");
        }
    }
    return 0;
}