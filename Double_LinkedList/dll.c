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

void delete_end(Node** tail)
{
    Node* store;

    if(*tail == NULL)
        return;

    store = *tail;
    (*tail)->prev->next = NULL;
    (*tail) = (*tail)->prev;
    free(store);
}

void delete_begin(Node** head)
{
    Node* store;

    if(*head == NULL)
        return;

    store = *head;
    (*head)->next->prev = NULL;
    (*head) = (*head)->next;
    free(store);
}

Node* search_by_pos(Node* head , int position)
{
    int i = 1, count = 1;
    Node* temp = head;

    if(head == NULL)
        return NULL;

    if(position <= 0)
        return NULL;

    while(head->next != NULL)
    {
        head = head->next;
        count++;
    }

    head = temp;

    if(position > count)
        return NULL;

    for(i=1; i<position; i++)
    {
        head = head->next;
    }

    return head;
}

void add_in_between_after(Node* pos , int value)
{
    Node* temp = create_node(value);

    temp->prev = pos; 
    temp->next = pos->next;
    if(pos->next != NULL)
        pos->next->prev = temp;
    pos->next = temp;
}

void add_in_between_before(Node* pos , int value)
{
    Node* temp = create_node(value);

    if(pos->prev != NULL)
        pos->prev->next = temp;
    temp->prev = pos->prev;
    temp->next = pos;
    pos->prev = temp;
}

void delete_in_between_after(Node* pos)
{
    Node* temp;
    if(pos->next == NULL)
        return;
    temp = pos->next;
    pos->next = temp->next;
    temp->next->prev = pos;
    free(temp);
}

void delete_in_between_before(Node* pos)
{
    Node* temp;

    if(pos->prev == NULL)
        return;
    temp = pos->prev;
    pos->prev = temp->prev;
    temp->prev->next = pos;
    free(temp);
}