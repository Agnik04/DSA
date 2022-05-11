#include "cll.h"

Node* create_node(int value)
{
    Node* temp;
    
    temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    return temp;
}

void append(Node** head , int value)
{
    Node* temp = create_node(value);
    Node* current = *head;

    if(*head == NULL)
    {
        *head = temp;
        temp->next = *head;
        return;
    }

    while(current->next != *head)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = *head;
}

void traverse(Node* head)
{
    Node* current = head;
    if(head == NULL)
        printf("Empty");

    do
    {
        printf("%d ",current->data);
        current = current->next;
    } while (current != head);
    
    printf("\n");
}
