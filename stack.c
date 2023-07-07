#include <stdbool.h>
#include <stdio.h>

// Size of the stack
int size = 8;

// Stack storage
int intArray[8];

// Top of the stack
int top = -1;

// Operation: Pop
// Pop item from the top of the stack
int pop() {
    // Retrieve data and decrement the top by 1
    return intArray[top--];
}

// Operation: Peek
// View the data at the top of the stack
int peek() {
    // Retrieve data from the top
    return intArray[top];
}

// Operation: isFull
// Return true if stack is full
bool isFull() { return (top == size - 1); }

// Operation: isEmpty
// Return true if stack is empty
bool isEmpty() { return (top == -1); }

// Operation: Push
// Push item on the top of the stack
void push(int data) {
    if (!isFull()) {
        // Increment top by 1 and insert data
        intArray[++top] = data;
    } else {
        printf("Cannot add data. Stack is full.\n");
    }
}

int main() {
    // Push items on the stack
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);

    printf("Element at the top of the stack: %d\n", peek());
    printf("Elements: \n");

    // Print stack data
    while (!isEmpty()) {
        int data = pop();
        printf("%d\n", data);
    }

    printf("Stack full: %s\n", isFull() ? "true" : "false");
    printf("Stack empty: %s\n", isEmpty() ? "true" : "false");
}
