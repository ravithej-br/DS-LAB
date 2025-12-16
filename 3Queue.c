#include <stdio.h>
#define MAX 5   // size of queue

int queue[MAX];
int front = -1, rear = -1;

void insert(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)  // very first element
        front = 0;

    rear++;
    queue[rear] = x;
    printf("%d inserted into queue\n", x);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow (Queue is Empty)!\n");
        return;
    }
    printf("%d deleted from queue\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n---- Queue Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
