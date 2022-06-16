#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    struct st* next;
    struct st* prev;
    int data;
}Node;

Node* create_node(int value);
void append(Node** tail , int value);
void add_begin(Node** head , int value);
void traverse_next(Node* head);