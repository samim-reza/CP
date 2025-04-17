#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createCircularNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end (maintains circularity)
void insertCircularEnd(struct Node** head, int data) {
    struct Node* newNode = createCircularNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Points to itself
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head; // Last node points back to head
}

// Print with debug info
void printCircularList(struct Node* head) {
    if (head == NULL) {
        printf("Circular List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\nCircular Linked List:\n");
    do {
        printf("[Address: %p | Data: %d -> Next: %p]\n", 
              (void*)temp, temp->data, (void*)temp->next);
        temp = temp->next;
    } while (temp != head);
    printf("(Loops back to head: %p)\n", (void*)head);
}

// Demo input
int main() {
    struct Node* head = NULL;
    int input;

    printf("Enter values for Circular Linked List (-1 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        insertCircularEnd(&head, input);
    }

    printCircularList(head);
    return 0;
}
