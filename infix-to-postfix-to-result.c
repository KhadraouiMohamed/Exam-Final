#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h" // Assume stack operations are defined in stack.h

#define MAX 100 // Maximum size of expression

// Function to determine precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack(); // Initialize stack
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) { 
            // Append operands (numbers) to postfix
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            // Push '(' to stack
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            // Pop until '(' is found
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Pop '('
        } else if (isOperator(infix[i])) {
            // Pop operators with higher or equal precedence
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
        i++;
    }

    // Pop remaining operators in the stack
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
    deleteStack(stack); // Free stack memory
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    Stack* stack = createStack(); // Initialize stack
    int i = 0, op1, op2, result;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            // Push operand to stack
            push(stack, postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            // Pop two operands and apply the operator
            op2 = pop(stack);
            op1 = pop(stack);
            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = 1;
                          for (int j = 0; j < op2; j++) result *= op1;
                          break;
            }
            push(stack, result); // Push result back to stack
        }
        i++;
    }

    result = pop(stack); // Final result is at the top of the stack
    deleteStack(stack); // Free stack memory
    return result;
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];
    int result;

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    // Evaluate the postfix expression
    result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}