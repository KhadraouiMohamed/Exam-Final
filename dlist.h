#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// Function prototypes for doubly linked list
Node* createNode(int value);
void deleteNode(Node* node);
int getValue(Node* node);
void setValue(Node* node, int value);
Node* getNext(Node* node);
void setNext(Node* node, Node* nextNode);
Node* getPrev(Node* node);
void setPrev(Node* node, Node* prevNode);
int isListEmpty(Node* head);

#endif // DOUBLE_LIST_H
