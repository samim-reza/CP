#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createDoublyNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertDoublyEnd(struct Node** head, int data) {
    struct Node* newNode = createDoublyNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Print with debug info
void printDoublyList(struct Node* head) {
    struct Node* temp = head;
    printf("\nDoubly Linked List:\n");
    while (temp != NULL) {
        printf("[Address: %p | Prev: %p | Data: %d | Next: %p]\n", 
              (void*)temp, (void*)temp->prev, temp->data, (void*)temp->next);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Demo input
int main() {
    struct Node* head = NULL;
    int input;

    printf("Enter values for Doubly Linked List (-1 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        insertDoublyEnd(&head, input);
    }

    printDoublyList(head);
    return 0;
}
