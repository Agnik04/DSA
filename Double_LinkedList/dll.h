#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    struct st* next;
    struct st* prev;
    int data;
}Node;

Node* create_node(int value);
void add_end(Node** head, Node** tail, int value);
void add_begin(Node** head, Node** tail, int value);
void traverse_next(Node* head);
void traverse_prev(Node* tail);