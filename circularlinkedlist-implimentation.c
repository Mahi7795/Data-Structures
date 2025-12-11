#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = n;
    return n;
}

void insertEnd(Node **head, int data) {
    Node *n = createNode(data);
    if (*head == NULL) {
        *head = n;
        return;
    }
    Node *temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = n;
    n->next = *head;
}

void insertBegin(Node **head, int data) {
    Node *n = createNode(data);
    if (*head == NULL) {
        *head = n;
        return;
    }
    Node *temp = *head;
    while (temp->next != *head) temp = temp->next;
    n->next = *head;
    temp->next = n;
    *head = n;
}

void deleteValue(Node **head, int value) {
    if (*head == NULL) return;

    Node *curr = *head, *prev = NULL;

    if (curr->data == value && curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }

    while (curr->data != value) {
        prev = curr;
        curr = curr->next;
        if (curr == *head) return;
    }

    if (curr == *head) {
        Node *temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = (*head)->next;
        *head = (*head)->next;
        free(curr);
        return;
    }

    prev->next = curr->next;
    free(curr);
}

void display(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node *head = NULL;
    int choice, val;

    while (1) {
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
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
                printf("Enter value: ");
                scanf("%d", &val);
                insertBegin(&head, val);
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
