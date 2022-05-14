#include "dll.h"

int main()
{
    Node* head = NULL, *tail = NULL;

    int ch, value;

    while(1)
    {
        printf("*********MENU***********\n");
        printf("1: To add node at the end.\n");
        printf("2: To add node at the begin.\n");
        printf("3: To print the list.\n");
        printf("4: To print the list in reverse order.\n");
        printf("5: To EXIT.\n\n");

        printf("Enter your choice :\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the value to be inserted at the end : ");
                scanf("%d",&value);
                add_end(&head, &tail, value);
                break;
            case 2:
                printf("Enter the value to be inserted at the beginning : ");
                scanf("%d",&value);
                add_begin(&head, &tail, value);
                break;
            case 3:
                traverse_next(head);
                break;
            case 4:
                traverse_prev(tail);
                break;
            case 5:
                return 0;
            default:
                printf("Enter the correct choice.\n");
        }
    }

    return 0;
}