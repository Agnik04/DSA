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
void delete_end(Node** tail);
void delete_begin(Node** head);
Node* search_by_pos(Node* head , int position);
void add_in_between_after(Node* pos , int value);
void add_in_between_before(Node* pos , int value);
void delete_in_between_after(Node* pos);
void delete_in_between_before(Node* pos);