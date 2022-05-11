#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int data;
    struct st* next;
}Node;

Node* create_node(int value);
void append(Node** head , int value);
void traverse(Node* head);
void insert_at_begin(Node** head , int value);
void insert_at_end(Node** head , int value);
void insert_at_npos(Node** head , int value , int n);
void delete(Node** head , int value);
//void reverse(Node* head , int n);
void reverse_rec(Node* head);
void circular_list(Node** head);
int middle_node(Node* head , int n);