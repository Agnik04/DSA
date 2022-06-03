#include "dll.h"

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
        printf("5: To delete a node from end.\n");
        printf("6: To delete a node from beginning.\n");
        printf("7: To search a value by position.\n");
        printf("8: To add a node after a position in the list.\n");
        printf("9: To add a node before a position in the list.\n");
        printf("10: To delete a node after a position in the list.\n");
        printf("11: To delete a node before a position in the list.\n");
        printf("12: To EXIT.\n\n");

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
                delete_end(&tail);
                break;
            case 6:
                delete_begin(&head);
                break;
            case 7:
                printf("Enter the position at which the value to be searched :");
                scanf("%d",&position);
                temp = search_by_pos(head , position);
                if(temp == NULL)
                    printf("INVALID POSITION\n");
                else
                    printf("%d ",temp->data);
                break;
            case 8:
                printf("Enter the position after which a node will be added :");
                scanf("%d",&position);

                printf("Enter the value :");
                scanf("%d",&value);

                temp = search_by_pos(head, position);
                if(temp == NULL)
                    printf("INVALID POSITION\n");
                else
                    add_in_between_after(temp , value);
                break;
            case 9:
                printf("Enter the position before which a node will be added :");
                scanf("%d",&position);

                printf("Enter the value :");
                scanf("%d",&value);

                temp = search_by_pos(head, position);
                if(temp == NULL)
                    printf("INVALID POSITION\n");
                else
                    add_in_between_before(temp, value);
                break;
            case 10:
                printf("Enter the position after which a node will be deleted :");
                scanf("%d",&position);

                temp = search_by_pos(head, position);
                if(temp == NULL)
                    printf("INVALID POSITION\n");
                else
                    delete_in_between_after(temp);
                break;
            case 11:
                printf("Enter the position before which a node will be deleted :");
                scanf("%d",&position);

                temp = search_by_pos(head, position);
                if(temp == NULL)
                    printf("INVALID POSITION\n");
                else
                    delete_in_between_before(temp);
                break;
            case 12:
                return 0;
            default:
                printf("Enter the correct choice.\n");
        }
    }

    return 0;
}