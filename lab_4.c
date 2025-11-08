//AIM:This C program creates a linked list to store integer elements. It prompts the user to enter elements and add them to the list until the user enters 0. It then traverses the list and prints each element and "=>" 
//until reaching the null pointer. Finally, it displays the number of nodes in the list.
//roll no:102//
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and display the linked list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total number of nodes: %d\n", count);
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int data;

    printf("Enter integers to add to the linked list (enter 0 to stop):\n");

    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            break;
        }

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode; // First node becomes the head
            tail = newNode;
        } else {
            tail->next = newNode; // Append to the end of the list
            tail = newNode;
        }
    }

    printf("\nThe linked list is:\n");
    traverseList(head);

    return 0;
}
