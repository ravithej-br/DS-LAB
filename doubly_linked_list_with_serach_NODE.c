#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    printf("\nDoubly Linked List Structure:\n");
    printf("-------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-5s | %-10s |\n", "Node Addr", "Prev Addr", "Data", "Next Addr");
    printf("-------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("| %-10p | %-10p | %-5d | %-10p |\n",
               (void*)temp,
               (void*)temp->prev,
               temp->data,
               (void*)temp->next);
        temp = temp->next;
    }
    printf("-------------------------------------------------------------\n");
}

Node* searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;  // Found
        }
        temp = temp->next;
    }
    return NULL;  // Not found
}

int main() {
    // Create nodes
    Node* N1 = createNode(1);
    Node* N2 = createNode(2);
    Node* N3 = createNode(3);
    Node* N4 = createNode(4);
    Node* N5 = createNode(5);

    // Link nodes
    N1->next = N2;
    N2->prev = N1;
    N2->next = N3;
    N3->prev = N2;
    N3->next = N4;
    N4->prev = N3;
    N4->next = N5;
    N5->prev = N4;

    // Display the list
    displayList(N1);

    // Search for a node
    int key;
    printf("\nEnter a value to search: ");
    scanf("%d", &key);

    Node* found = searchNode(N1, key);
    if (found != NULL) {
        printf("Node with data %d found at address: %p\n", key, (void*)found);
    } else {
        printf("Node with data %d not found in the list.\n", key);
    }

    // Free memory
    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}
