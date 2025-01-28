#include <stdio.h>
#include "dlist.h"

// Function to append a node to the end of a doubly linked list
void appendNode(Node** head, int value) {
    Node* newNode = createNode(value); // Create a new node

    // Case 1: If the list is empty, make the new node the head
    if (*head == NULL || isListEmpty(*head)) {
        *head = newNode;
        return;
    }

    // Case 2: Traverse to the last node
    Node* current = *head;
    while (getNext(current) != NULL) {
        current = getNext(current);
    }

    // Link the new node to the current last node
    setNext(current, newNode);
    setPrev(newNode, current);
}

// Function to reverse a doubly linked list
void reverseList(Node** head) {
    if (*head == NULL || isListEmpty(*head)) {
        printf("The list is empty. Nothing to reverse.\n");
        return;
    }

    Node* current = *head;
    Node* temp = NULL;

    // Traverse the list and swap next and prev pointers
    while (current != NULL) {
        temp = getNext(current);             // Store the next node temporarily
        setNext(current, getPrev(current)); // Swap next and prev
        setPrev(current, temp);
        current = temp;                      // Move to the next node in the original list
    }

    // After the loop, the previous tail is now the head
    *head = getPrev(*head);
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Append nodes to the list
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    printf("Original List:\n");
    printList(head);

    // Reverse the list
    reverseList(&head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}