#include "cdll.h"

int main()
{
    Node* head = NULL, *tail = NULL, *temp;

    int i, ch, value, position;

    while(1)
    {
        printf("*********MENU***********\n");
        printf("1: To add node at the end.\n");
        printf("2: To add node at the begin.\n");
        printf("3: To print the list.\n");
        printf("4: To print the list in reverse order.\n");

        printf("Enter your choice :\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the value to be inserted at the end : ");
                scanf("%d",&value);
                append(&head, &tail, value);
                break;
            case 2:
                
        }
    }
}