#include "dll.h"

Node* create_node(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void add_end(Node** head, Node** tail, int value)
{
    Node* new_node = create_node(value);

    if(*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
        return;
    }

    (*tail)->next = new_node;
    new_node->prev = *tail;
    *tail = new_node;
}

void add_begin(Node** head, Node** tail, int value)
{
    Node* new_node = create_node(value);

    if(*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
        return;
    }

    (*head)->prev = new_node;
    new_node->next = *head;
    *head = new_node;
}

void traverse_next(Node* head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void traverse_prev(Node* tail)
{
    while(tail != NULL)
    {
        printf("%d ",tail->data);
        tail = tail->prev;
    }
    printf("\n");
}