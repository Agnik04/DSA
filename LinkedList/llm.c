#include "ll.h"

int main()
{
    Node* head = NULL;
    int size , value , i;

    printf("Enter the size of list : ");
    scanf("%d",&size);

    printf("Enter the list values : \n");
    for(i=0 ; i<size ; i++)
    {
        printf("List value at %d : ",i+1);
        scanf("%d",&value);        
        append(&head , value);
    }
    
    printf("\n");

    traverse(head);

    return 0;
}