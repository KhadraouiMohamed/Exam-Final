#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(Node* node)
{
    free(node);
}

int getValue(Node* node)
{
    return node ? node->value : -1; // Return -1 if node is NULL
}

void setValue(Node* node, int value)
{
    if (node)
    {
        node->value = value;
    }
}

Node* getNext(Node* node)
{
    return node ? node->next : NULL;
}

void setNext(Node* node, Node* nextNode)
{
    if (node)
    {
        node->next = nextNode;
    }
}

int isListEmpty(Node* head)
{
    return head == NULL;  // Return 1 if the list is empty, 0 otherwise
}
