#include "ll.h"

int main()
{
    Node* head = NULL, head1;
    int size , value , i, index, ch, res;

    printf("Enter the size of list : ");
    scanf("%d",&size);

    printf("Enter the list values : \n");
    for(i=0 ; i<size ; i++)
    {
        printf("List value at %d : ",i+1);
        scanf("%d",&value);        
        append(&head , value);
    }

    while(1)
    {
        printf("1: To print the list values.\n");
        printf("2: To insert a values at the beginning.\n");
        printf("3: To insert a values at the nth position.\n");
        printf("4: To insert a values at the end.\n");
        printf("5: To delete a values from nth position.\n");
        printf("6: To reverse\n");
        printf("7: Find the value of middle node\n");
        printf("8: EXIT\n");

        printf("Enter your choise :\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                traverse(head);
                printf("\n");
                break;
            case 2:
                printf("Enter a value to insert at beginning : ");
                scanf("%d",&value);
                insert_at_begin(&head , value);
                printf("\n");
                break;
            case 3:
                printf("Enter a index to insert at middle : ");
                scanf("%d",&index);
                printf("Enter a value to insert at %d position : ",index);
                scanf("%d",&value);
                
                insert_at_npos(&head , value , index);
                printf("\n");
                break;
            case 4:
                printf("Enter a value to insert at end : ");
                scanf("%d",&value);
                insert_at_end(&head , value);
                printf("\n");
                break;
            case 5:
                printf("Enter a index to delete : ");
                scanf("%d",&index);

                if( index >= 1 || index <= size )
                    delete(&head , index); 
                else
                    printf("Invalid index input");   
                printf("\n");            
                break;
            case 6:
                reverse_rec(head);
                printf("\n");
                break;
            case 7:
                res = middle_node(head , size);
                printf("\n");
                break;
            case 8:
                return 0;
            
        }
    }

    return 0;
}