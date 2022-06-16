#include "cdll.h"

Node* create_node(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = value;
    temp->next = temp->prev = temp;

    return temp;
}

void append(Node** head , Node** tail , int value)
{
    Node* tmp = create_node(value);

    if(*head == NULL)
    {
        *head = tmp;
        *tail = tmp;
        return;
    }
    
    tmp->prev = *tail;
    (*tail)->next = tmp;    
    *tail = tmp;
}

void add_begin(Node** head , Node** tail , int value)
{
    Node* tmp = create_node(value);

    if(*head == NULL)
    {
        *head = tmp;
        *tail = tmp;
        return;
    }
    
    (*head)->prev = tmp;
    tmp->next = *head;
    tmp->prev = *tail;
    *tail = tmp;
}

void traverse_next(Node* head)
{
    Node* curr = head;
    while(curr->next != head)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}
