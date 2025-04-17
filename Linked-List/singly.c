#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createSinglyNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end of the list
void insertSinglyEnd(struct Node** head, int data) {
    struct Node* newNode = createSinglyNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the list with debug info
void printSinglyList(struct Node* head) {
    struct Node* temp = head;
    printf("\nSingly Linked List:\n");
    while (temp != NULL) {
        printf("[Address: %p | Data: %d -> Next: %p]\n", (void*)temp, temp->data, (void*)temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Demo input
int main() {
    struct Node* head = NULL;
    int input;

    printf("Enter values for Singly Linked List (-1 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        insertSinglyEnd(&head, input);
    }

    printSinglyList(head);
    return 0;
}
