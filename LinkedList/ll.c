#include "ll.h"

Node* create_node(int value)
{
    Node* temp;

    temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    return temp;
}

void append(Node** head, int value)
{
    Node* temp = create_node(value);
    Node* current = *head;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp;
}

void traverse(Node* head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_at_begin(Node** head , int value)
{
    Node* temp = create_node(value);
    Node* current = *head;
    *head = temp;
    (*head)->next = current;
}

void insert_at_npos(Node** head , int value , int n)
{
    Node* temp = create_node(value);
    Node* current = *head , *store;
    int i = 1;

    while(n>0)
    {
        if(i == n-1)
        {
            store = current->next;
            current->next = temp;
            temp->next = store;
            return;
        }
        else
        {
            current = current->next;
            i++;
        }
    }
}

void insert_at_end(Node** head , int value)
{
    Node* temp = create_node(value);
    Node* current = *head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp;
}

void delete(Node **head,int n)
{
    Node* current = *head, *temp;
    int i=1;

    while(i<n-1)
    {
        current = current->next;
        i++;
    } 
    temp = current->next;
    current->next = temp->next;
    free(temp);
}