#include "queue1.h"

int main()
{
    Queue q;
    int data;
    int ch;

    init(&q);
    while(1)
    {
        printf("\n\n************** M E N U **************\n\n");
        printf("Press 1 check it's ful or not.\n");
        printf("Press 2 check it's empty or not.\n");
        printf("Press 3 to enter value\n");
        printf("Press 4 to delete.\n");
        printf("Press 5 to EXIT.\n");
        printf("Enter your choice: ");  
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:            
                if(isfull(&q)==1)
                    printf("\nQueue is Full.\n\n");
                else    
                    printf("\nQueue is not Full\n\n");
                break;
            case 2:
                if(isempty(&q)==1)
                    printf("\nQueue is Empty.\n\n");
                else
                    printf("\nQueue is not Empty.\n\n");
                break;
            case 3:
                if(isfull(&q)==1)
                    printf("\nOverflow\n");
                else
                {
                    printf("Enter the data you want to push into your stack :");
                            scanf("%d", &data);
                    enqueue(&q, data);                    
                }
                break;
            case 4:
                if(isempty(&q)==1)
                    printf("Underflow\n");
                else
                {
                    printf("The deleted element is = %d\n\n",dequeue(&q));
                }             
                break;
            case 5:
                return 0;
                break;
            default:
                printf("\nEnter a Valid Choice!\n");
        }
    }
    return 0;
}