#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insertEnd(Node **head, int data) {
    Node *n = createNode(data);
    if (*head == NULL) {
        *head = n;
        return;
    }
    Node *temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertLeft(Node **head, int target, int data) {
    if (*head == NULL) return;
    Node *temp = *head;
    while (temp && temp->data != target) temp = temp->next;
    if (temp == NULL) return;
    Node *n = createNode(data);
    if (temp->prev == NULL) {
        n->next = temp;
        temp->prev = n;
        *head = n;
    } else {
        n->next = temp;
        n->prev = temp->prev;
        temp->prev->next = n;
        temp->prev = n;
    }
}

void deleteValue(Node **head, int value) {
    if (*head == NULL) return;
    Node *temp = *head;
    while (temp && temp->data != value) temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

void display(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int choice, val, target;

    while (1) {
        printf("1. Insert at end\n");
        printf("2. Insert to left of node\n");
        printf("3. Delete value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 2:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &val);
                insertLeft(&head, target, val);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteValue(&head, val);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
