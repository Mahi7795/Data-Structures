#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main(void) {
    Stack s;
    init(&s);

    int choice, value;

    while (1) {
        printf("1. Push
");
        printf("2. Pop
");
        printf("3. Display
");
        printf("4. Exit
");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                printf("Popped: %d
", pop(&s));
                break;
            case 3:
                if (isEmpty(&s)) {
                    printf("Stack is empty
");
                } else {
                    for (int i = s.top; i >= 0; i--) {
                        printf("%d ", s.arr[i]);
                    }
                    printf("
");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice
");
        }
    }
}
