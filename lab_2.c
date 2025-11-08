//AIM:Design, Develop and Implement a menu driven Program in C for the following
// operations on STACK of Integers (Array Implementation of Stack with maximum size MAX) 
//roll no 102
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the stack

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function prototypes
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

int main() {
    Stack stack;
    stack.top = -1; // Initialize stack as empty
    int choice, value;

    while (1) {
        printf("\n*** Stack Operations Menu ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        s->data[++(s->top)] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    } else {
        return s->data[(s->top)--];
    }
}

// Function to peek at the top element of the stack
int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty! No top element.\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}

// Function to display all elements of the stack
void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}