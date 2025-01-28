#include <stdio.h>
#include "queue.h"

// Global variables
int queue[MAX_SIZE];   // Queue array
int front = 0;         // Front marker
int rear = 0;          // Rear marker

// Initialize the queue
void initializeQueue() {
    front = 0;
    rear = 0;
}

// Check if the queue is empty
int is_empty() {
    return front == rear;
}

// Check if the queue is full
int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

// Enqueue an element
void enqueue(int value) {
    if (is_full()) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    queue[rear] = value;
    rear = (rear + 1) % MAX_SIZE; // Wrap around if necessary
}

// Dequeue an element
int dequeue() {
    if (is_empty()) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int value = queue[front];
    front = (front + 1) % MAX_SIZE; // Wrap around if necessary
    return value;
}

// Peek at the front element
int peek() {
    if (is_empty()) {
        printf("Queue is empty, cannot peek\n");
        return -1;
    }
    return queue[front];
}
