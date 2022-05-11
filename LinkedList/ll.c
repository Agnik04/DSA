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
    if(head == NULL)
        printf("Empty");
    
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

void delete(Node** head,int n)
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

/*void reverse(Node* head , int n)
{
    int i;
    ITEM arr[n];

    while(head != NULL)
    {
        for(i=0; i<n; i++)
        {
            arr[i] = head->data;
            head = head->next;
        }

    }

    for(i=n; i>=0; i--)
    {
        printf("%d ",arr[i]);
    }
}*/

void reverse_rec(Node* head)
{
    if(head != NULL)
    {
        reverse_rec(head->next);
        printf("%d ",head->data);
    }

}

int middle_node(Node* head , int n)
{
    Node* current = head;
    int i = 1, f = 0, size;
    size = (n+1)/2;

    if(n%2 == 0)
        f = 1;
    
    if(f == 1)
    {
        if(i == size+1)
            return current;
        else
        {
            current = current->next;
            i++;
        }
    }
    else
    {
        if(i == size)
            return current;
        else
        {
            current = current->next;
            i++;
        }
    }
}