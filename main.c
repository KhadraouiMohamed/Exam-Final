#include <stdio.h>
#include "list.h" // Include the static library header

// Function to append a node to the list
void appendNode(Node **head, int value, int position) {
    Node *newNode = createNode(value); // Create a new node

    // Case 1: Insert at the head
    if (position == 0) {
        setNext(newNode, *head);
        *head = newNode;
        return;
    }

    // Case 2: Insert at a specific position
    Node *current = *head;
    int currentPosition = 0;

    while (current != NULL && currentPosition < position - 1) {
        current = getNext(current);
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position out of bounds! Node will be appended at the end.\n");
    }

    // Case 3: Append at the end
    setNext(newNode, getNext(current));
    setNext(current, newNode);
}

// Function to print the linked list
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node *head = NULL;

    // Append nodes at different positions
    appendNode(&head, 10, 0);  // Insert at head
    appendNode(&head, 20, 1);  // Insert at the end
    appendNode(&head, 30, 1);  // Insert at position 1 (middle)
    appendNode(&head, 40, 10); // Position out of bounds, append at the end

    // Print the linked list
    printList(head);

    return 0;
}