#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

// Function to create a new node with a given value
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to delete a node (free its memory)
void deleteNode(Node* node) {
    if (node != NULL) {
        free(node);
    }
}

// Function to get the value stored in a node
int getValue(Node* node) {
    return node ? node->value : -1;
}

// Function to set the value of a node
void setValue(Node* node, int value) {
    if (node != NULL) {
        node->value = value;
    }
}

// Function to get the next node in the list
Node* getNext(Node* node) {
    return node ? node->next : NULL;
}

// Function to set the next node for a given node
void setNext(Node* node, Node* nextNode) {
    if (node != NULL) {
        node->next = nextNode;
    }
}

// Function to get the previous node in the list
Node* getPrev(Node* node) {
    return node ? node->prev : NULL;
}

// Function to set the previous node for a given node
void setPrev(Node* node, Node* prevNode) {
    if (node != NULL) {
        node->prev = prevNode;
    }
}

// Function to check if the list is empty
int isListEmpty(Node* head) {
    return head == NULL;
}
