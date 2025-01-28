#include <stdio.h>
#include <stdlib.h>
#include "queue.h" // Assume queue operations are defined in queue.h

typedef struct Stack {
    Queue* q; // Single queue to simulate stack
} Stack;

// Create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q = createQueue();
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    int size = queueSize(stack->q); // Get the current size of the queue

    // Enqueue the new value
    enqueue(stack->q, value);

    // Rotate the queue to make the last added element the front
    for (int i = 0; i < size; i++) {
        enqueue(stack->q, dequeue(stack->q));
    }
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isQueueEmpty(stack->q)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue(stack->q);
}

// Peek the top element of the stack
int peek(Stack* stack) {
    if (isQueueEmpty(stack->q)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return front(stack->q);
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return isQueueEmpty(stack->q);
}

// Free the stack
void deleteStack(Stack* stack) {
    deleteQueue(stack->q); // Free the queue
    free(stack);           // Free the stack structure
}

// Main function
int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack)); // Output: 30

    printf("Popped element: %d\n", pop(stack)); // Output: 30
    printf("Popped element: %d\n", pop(stack)); // Output: 20

    printf("Stack is empty: %s\n", isEmpty(stack) ? "Yes" : "No");

    deleteStack(stack);
    return 0;
}