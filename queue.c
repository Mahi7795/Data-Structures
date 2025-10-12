#include <stdio.h>
#define size 2
int queue[size];
int front = -1, rear = -1;
void add(int num)
{
    if (rear == size - 1)
    {
        printf("Queue overflow");
    }
    else
    {
        if (front == -1)
            front = 0;
        // rear = (rear + 1) % 5;
        queue[++rear] = num;
    }
}
void deleteItem()
{
    // front = (front + 1) % 5;
    if (front > rear)
    {
        printf("Queue underflow");
    }
    else
    {
        front++;
    }
}
void display()
{
    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}
int main()
{
    while (1)
    {
        int choice;
        int num;
        printf("\n----------queue menu-----------\n");
        printf("1.add\t2.delete\t3.display\t4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the number: ");
            scanf("%d", &num);
            add(num);
            break;
        case 2:
            deleteItem();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;

        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
}