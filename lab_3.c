//AIM:Design, Develop and Implement a menu driven Program in C for the following //
//operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
//roll no 102
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

// Function to enqueue an element
void enqueue(char element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot add more elements.\n");
        return;
    }
    if (front == -1) front = 0; // Initialize front if queue is empty
    queue[++rear] = element;
    printf("Enqueued '%c' successfully.\n", element);
}

// Function to dequeue an element
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    printf("Dequeued '%c'.\n", queue[front++]);
    if (front > rear) front = rear = -1; // Reset queue if empty
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

// Main function with menu-driven interface
int main() {
    int choice;
    char element;

    while (1) {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to enqueue: ");
                scanf(" %c", &element); // Space before %c to handle newline
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
 