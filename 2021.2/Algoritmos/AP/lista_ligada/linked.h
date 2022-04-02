#ifndef _LINKED_H
#define _LINKED_H

struct node {
    int data;
    struct node* next;
};
typedef struct node Node;

Node* insert(Node *curr, Node *tail, int data);
Node* delete(Node *curr);
void count(Node *head, int data);
Node* prev(Node *curr, Node *head);
Node* next(Node *curr);
void clear(Node *head);

#endif