#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 5 // Size of the queue

// Function declarations
void initializeQueue();
int is_empty();
int is_full();
void enqueue(int value);
int dequeue();
int peek();

#endif
