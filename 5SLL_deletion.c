#include <stdio.h>
#include <stdlib.h>

/* Node definition */
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function to create linked list */
void createList(int n) {
    struct node *newnode, *temp;
    int data, i;

    head = NULL;

    printf("Enter %d values:\n", n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

/* Delete first node */
void deleteFirst() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted\n");
}

/* Delete specified node */
void deleteSpecified(int key) {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == key) {
        deleteFirst();
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Specified node deleted\n");
}

/* Delete last node */
void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}

/* Display linked list */
void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    int choice, key,n;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First\n");
        printf("3. Delete Specified\n");
        printf("4. Delete Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
             case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                deleteFirst();
                display();
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                deleteSpecified(key);
                display();
                break;
            case 4:
                deleteLast();
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
