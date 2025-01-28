#include <stdio.h>
#include <stdlib.h>
#include "queue.h" // Assume queue operations are defined in queue.h

typedef struct Stack {
    Queue* q1; // Main queue
    Queue* q2; // Temporary queue
} Stack;

// Create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    enqueue(stack->q2, value); // Add new element to q2

    // Transfer all elements from q1 to q2
    while (!isQueueEmpty(stack->q1)) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    // Swap q1 and q2
    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isQueueEmpty(stack->q1)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue(stack->q1);
}

// Peek the top element of the stack
int peek(Stack* stack) {
    if (isQueueEmpty(stack->q1)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return front(stack->q1);
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return isQueueEmpty(stack->q1);
}

// Free the stack
void deleteStack(Stack* stack) {
    deleteQueue(stack->q1); // Free q1
    deleteQueue(stack->q2); // Free q2
    free(stack);            // Free the stack structure
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