#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Insert at end */
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Display */
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Sort */
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

/* Reverse */
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Concatenate */
struct Node* concatenate(struct Node *head1, struct Node *head2) {
    struct Node *temp = head1;

    if (head1 == NULL)
        return head2;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, data, choice;

    /* Input List 1 */
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head1, data);
    }

    /* Input List 2 */
    printf("\nEnter number of elements in List 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head2, data);
    }

    /* Sort choice */
    printf("\nWhich list do you want to SORT?\n");
    printf("1. List 1\n2. List 2\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        sortList(head1);
    else if (choice == 2)
        sortList(head2);

    printf("\nAfter Sorting:\nList 1: ");
    display(head1);
    printf("List 2: ");
    display(head2);

    /* Reverse choice */
    printf("\nWhich list do you want to REVERSE?\n");
    printf("1. List 1\n2. List 2\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        head1 = reverseList(head1);
    else if (choice == 2)
        head2 = reverseList(head2);

    printf("\nAfter Reversing:\nList 1: ");
    display(head1);
    printf("List 2: ");
    display(head2);

    /* Concatenate */
    head1 = concatenate(head1, head2);
    printf("\nAfter Concatenation (List1 + List2):\n");
    display(head1);

    return 0;
}
