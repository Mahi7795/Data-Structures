#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int priority[MAX];
    int size;
} PQueue;

void insert(PQueue *pq, int val, int p) {
    if (pq->size == MAX) {
        printf("Queue is full\n");
        return;
    }
    int i = pq->size;
    pq->data[i] = val;
    pq->priority[i] = p;
    pq->size++;
}

int delete(PQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int i, min = pq->priority[0], index = 0;
    for (i = 1; i < pq->size; i++) {
        if (pq->priority[i] < min) {
            min = pq->priority[i];
            index = i;
        }
    }

    int deleted = pq->data[index];

    for (i = index; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;

    return deleted;
}

void display(PQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < pq->size; i++) {
        printf("%d(%d) ", pq->data[i], pq->priority[i]);
    }
    printf("\n");
}

int main() {
    PQueue pq;
    pq.size = 0;

    int choice, val, p;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete highest priority\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter priority (lower number = higher priority): ");
                scanf("%d", &p);
                insert(&pq, val, p);
                break;
            case 2:
                printf("Deleted: %d\n", delete(&pq));
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
