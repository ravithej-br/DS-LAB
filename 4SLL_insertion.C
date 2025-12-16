 #include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

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

void insertAtFirst(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insertAtPosition(int x, int pos) {
    int i;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;

    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return;
    }

    struct node *temp = head;

    for(i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL){
        printf("Position not found!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void display() {
    struct node *temp = head;

    if(head == NULL){
        printf("List is Empty!\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL){
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

int main() {
    int choice, n, value, pos;

    while(1){
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert at First\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("How many nodes? ");
            scanf("%d", &n);
            createList(n);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtFirst(value);
            display();
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(value, pos);
            display();
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            display();
            break;

        case 5:
            display();
            break;

        case 6:
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }
}
