#include <stdio.h>
#include "stack.h"

// Array to store stack elements
int stack[MAX_SIZE];

// Variable to track the top of the stack
int top = -1;  // Initially the stack is empty

// Function to initialize the stack (not strictly needed, but for clarity)
void initStack() {
    top = -1;  // Stack is initially empty
}

// Function to check if the stack is empty
int is_empty() {
    return top == -1;  // Return true if stack is empty
}

// Function to check if the stack is full
int is_full() {
    return top == MAX_SIZE - 1;  // Return true if stack is full
}

// Function to push an item onto the stack
void push(int item) {
    if (is_full()) {
        printf("Stack Overflow! Unable to push %d.\n", item);
    } else {
        stack[++top] = item;  // Increment top and add the item
        printf("Pushed %d onto the stack.\n", item);
    }
}

// Function to pop an item from the stack
int pop() {
    if (is_empty()) {
        printf("Stack Underflow! Unable to pop.\n");
        return -1;  // Return an error value if stack is empty
    } else {
        return stack[top--];  // Return the top item and decrement top
    }
}

// Function to peek at the top item of the stack
int peek() {
    if (is_empty()) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;  // Return an error value if stack is empty
    } else {
        return stack[top];  // Return the top item without removing it
    }
}

// Function to clear the stack
void clear() {
    top = -1;  // Reset the top to -1 to indicate the stack is empty
    printf("Stack cleared.\n");
}
