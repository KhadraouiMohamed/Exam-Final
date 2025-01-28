#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int value);
void deleteNode(Node* node);
int getValue(Node* node);
void setValue(Node* node, int value);
Node* getNext(Node* node);
void setNext(Node* node, Node* nextNode);
int isListEmpty(Node* head);
#endif // LIST_H
