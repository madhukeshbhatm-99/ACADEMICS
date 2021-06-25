#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int isEmpty(int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
        return 1;
    else
        return 0;
}

int isFull(int *rear)
{
    if(*rear == (SIZE - 1))
        return 1;
    else
        return 0;
}

void enqueue(int item[], int ele, int *front, int *rear)
{
    if(isFull(&rear) == 1)
        printf("Queue OVERFLOW!");
    else if (*rear == -1)
    {
        *front = 0;
        *rear = 0;
        item[*rear] = ele;
    }
    else
    {
        *rear = *rear + 1;
        item[*rear] = ele;
    }
}

void dequeue(int item[], int *front, int *rear)
{
    if(isEmpty(&front, &rear) == 1)
        printf("Queue UNDERFLOW!");
    else if (*front == *rear )
    {
        *front = -1;
        *rear = -1;
    }
    else
        *front = *front + 1;
}

void show(int item[], int *front)
{
    printf("The first element of the queue is: %d\n", item[*front]);
}

void display(int *front, int *rear, int item[])
{
    if(isEmpty(&front, &rear) == 1)
        printf("Queue UNDERFLOW!");
    else
    {
        printf("The elements in the queue are: ");
        for (int i = *front; i <= *rear; i = i+1)
            printf("%d ", item[i]);
        printf("\n");
    }
}

int main()
{
    int item[20], opt, peek = 0, front = -1, rear = -1, ele;
    do
    {
        printf("\nSelect a suitable option: ");
        printf("\n1. Enqueue ");
        printf("\n2. Dequeue ");
        printf("\n3. Show the first element in the queue ");
        printf("\n4. Display the queue elements ");
        printf("\n5. EXIT ");
        printf("\nEnter the option: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d", &ele);
                    enqueue(item, ele, &front, &rear);
                    break;
            case 2: dequeue(item, &front, &rear);
                    break;
            case 3: show(item, &front);
                    break;
            case 4: display(&front, &rear, item);
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid option");
        }
    }while(1);
    return 0;
}
