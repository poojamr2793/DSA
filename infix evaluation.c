#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

// Stack for integers
typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Stack for operators (strings)
typedef struct {
    int top;
    unsigned capacity;
    char* array;
} StringStack;

// Function to perform calculation on two numbers
int applyOperation(int a, int b, char* op) {
    if (strcmp(op, "+") == 0) return a + b;
    if (strcmp(op, "-") == 0) return a - b;
    if (strcmp(op, "*") == 0) return a * b;
    
    // Floor Division
    if (strcmp(op, "/") == 0) {
        if (a * b < 0 && a % b != 0)
            return (a / b) - 1;
        return a / b;
    }
    
    if (strcmp(op, "^") == 0) return (int)pow(a, b);
    return 0;
}

// Function to return precedence of operators
int precedence(char* op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
    if (strcmp(op, "^") == 0) return 3;
    return 0;
}

// Function to check if operator is right-associative
bool isRightAssociative(char* op) {
    return (strcmp(op, "^") == 0);
}

// Function to check if token is a number
bool isNumber(char* token) {
    if (token == NULL || *token == '\0') return false;
    int start = (token[0] == '-') ? 1 : 0;
    if (start == 1 && strlen(token) == 1) return false;
    for (int i = start; token[i] != '\0'; i++) {
        if (!isdigit((unsigned char)token[i])) return false;
    }
    return true;
}

// Create stack for values
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Create stack for operators
StringStack* createStringStack(unsigned capacity) {
    StringStack* stack = (StringStack*)malloc(sizeof(StringStack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char) * MAX);
    return stack;
}

// Push integer to stack
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Push operator string to stack
void pushString(StringStack* stack, char* item) {
    strcpy(stack->array + (stack->top + 1) * MAX, item);
    stack->top++;
}

// Pop integer from stack
int pop(Stack* stack) {
    return stack->array[stack->top--];
}

// Pop operator string from stack
char* popString(StringStack* stack) {
    char* item = (char*)malloc(MAX * sizeof(char));
    strcpy(item, stack->array + stack->top * MAX);
    stack->top--;
    return item;
}

// Peek top integer from stack
int peek(Stack* stack) {
    return stack->array[stack->top];
}

// Peek top operator string from stack
char* peekString(StringStack* stack) {
    char* item = (char*)malloc(MAX * sizeof(char));
    strcpy(item, stack->array + stack->top * MAX);
    return item;
}

// Check if integer stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if operator stack is empty
bool isEmptyString(StringStack* stack) {
    return stack->top == -1;
}

// Function to evaluate infix expression
int evaluateInfix(char** arr, int n) {
    Stack* values = createStack(n);
    StringStack* ops = createStringStack(n);

    for (int i = 0; i < n; i++) {

        // If it's a number, push to values stack
        if (isNumber(arr[i])) {
            push(values, atoi(arr[i]));
        } 

        // If it's an operator
        else {
            while (!isEmptyString(ops) &&
                   (precedence(peekString(ops)) > precedence(arr[i]) ||
                    (precedence(peekString(ops)) == precedence(arr[i])
                                        && !isRightAssociative(arr[i])))) {
                int val2 = pop(values);
                int val1 = pop(values);
                char* op = popString(ops);
                push(values, applyOperation(val1, val2, op));
            }
            pushString(ops, arr[i]);
        }
    }

    // Process remaining operators
    while (!isEmptyString(ops)) {
        int val2 = pop(values);
        int val1 = pop(values);
        char* op = popString(ops);
        push(values, applyOperation(val1, val2, op));
    }

    return peek(values);
}

int main() {
    char* arr[] = {"100", "+", "200", "/", "2", "*", "5", "+", "7"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", evaluateInfix(arr, n));
    return 0;
}
