#include "music.h"

Node* create_node(char* str)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = strdup(str);
    temp->next = temp->prev = temp;    

    return temp;
}

void add_end(Node** head, char* str)
{
    Node* new_node = create_node(str);

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    new_node->prev = (*head)->prev;
    new_node->next = *head;
    (*head)->prev->next = new_node;
    (*head)->prev = new_node;
}

void play(Node* temp)
{
    if(temp == NULL)
        return;
    printf("Playing -----------> %s\n", temp->data);
}

Node* search_track(Node* head , int position)
{
    int i = 1, count = 1;
    Node* temp = head;

    if(head == NULL)
        return NULL;

    if(position <= 0)
        return NULL;

    while(temp->next != head)
    {
        temp = temp->next;
        count++;
    }

    if(position > count)
        return NULL;

    for(i=1; i<position; i++)
    {
        head = head->next;
    }

    return head;
}

void add_after(Node* head, int pos, char* str)
{
    Node *temp, *position = NULL;

    temp = create_node(str);
    position = search_track(head, pos);

    temp->prev = position;
    temp->next = position->next;
    position->next->prev = temp;
    position->next = temp;
}

void add_before(Node **head, int pos, char *str)
{
    Node *temp, *position = NULL, *current;
    temp = create_node(str);

    if (pos == 1)
    {
        (*head)->prev->next = temp;
        temp->prev = (*head)->prev;
        temp->next = (*head);
        (*head)->prev = temp;
        (*head) = temp;
    }
    else
    {
        position = search_track(*head, pos);

        temp->prev = position->prev;
        temp->next = position;
        position->prev->next = temp;
        position->prev = temp;
    }
}

void traverse(Node* head)
{
    Node* current = head;

    if(head == NULL)
        return;
    do
    {
        printf("%s", current->data);
        current = current->next;
    }while (current != head);
    printf("\n");
}

void delete(Node **head, int pos)
{
    Node *position = NULL, *tmp = NULL, *current;

    if (pos == 1)
    {
        tmp = *head;
        (*head)->next->prev = (*head)->prev;
        (*head) = (*head)->next;
        free(tmp);
    }
    else
    {
        position = search_track(*head, pos);

        tmp = position->prev;
        tmp->next = position->next;
        position->next->prev = tmp;
        free(position);
    }
}

void sort_list(Node **head)
{
    Node *current = *head, *tmp = NULL, *new_head = NULL;

    while (current != *head)
    {
        tmp = current->next;
        insert_sorted(&new_head, create_node(current->data));
        free(current);
        current = tmp;
    }

    *head = new_head;
}

void insert_sorted(Node **head, Node *tmp)
{
    Node *current = *head;

    if (*head == NULL)
    {
        *head = tmp;
        return;
    }

    if (strcmp((*head)->data, tmp->data) > 0)
    {
        tmp->next = *head;
        tmp->prev = (*head)->prev;
        (*head)->prev = tmp;
        *head = tmp;
        return;
    }
    while ((current->next != *head) && (strcmp(current->next->data, tmp->data) < 0))
        current = current->next;

    tmp->next = current->next;
    tmp->prev = current;
    current->next = tmp;
    current->next->prev = tmp;
}