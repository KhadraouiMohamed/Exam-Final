#ifndef STACK_H
#define STACK_H

// Define the maximum size of the stack (you can modify this as needed)
#define MAX_SIZE 100

// Function prototypes
void initStack();
int is_empty();
int is_full();
void push(int item);
int pop();
int peek();
void clear();

#endif
