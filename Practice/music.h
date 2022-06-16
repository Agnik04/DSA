#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
{
    struct st *next;
    struct st *prev;
    char* data;
}Node;

Node* create_node(char* str);
void add_end(Node** head, char* str);
void play(Node* current);
Node* search_track(Node* head , int position);
void add_after(Node* head, int pos, char* str, FILE* fp);
void add_before(Node **head, int pos, char *str, FILE *fp);
void traverse(Node* head);
void delete (Node **head, int psition, FILE *fp);
void sort_list(Node **head, FILE *fp);
void insert_sorted(Node **head, Node *tmp);