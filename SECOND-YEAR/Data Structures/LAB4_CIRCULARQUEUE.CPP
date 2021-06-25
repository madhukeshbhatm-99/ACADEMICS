#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void enqueue(int item[], int ele, int *front, int *rear)
{
    if((*front == *rear + 1) || (*front == 0 && *rear == (SIZE - 1)))
        printf("Queue OVERFLOW!\n");
    else
    {
        if (*front == -1)
           *front = 0;
        *rear = (*rear + 1) % SIZE;
        item[*rear] = ele;
        printf("%d has been added\n", ele);
    }
}

void dequeue(int item[], int *front, int *rear)
{
    if(*front == -1 && *rear == -1)
        printf("Queue UNDERFLOW!\n");
    else if (*front == *rear )
    {
        *front = -1;
        *rear = -1;
    }
    else
        printf("%d has been deleted\n", item[*front]);
        *front = (*front + 1) % SIZE;
}

void display(int *front, int *rear, int item[])
{
    int i;
    if(*front == -1 && *rear == -1)
        printf("EMPTY Queue!\n");
    else
    {
        printf("The elements in the queue are: ");
        for (int i = *front; i != *rear; i = (i+1) % SIZE)
            printf("%d ", item[i]);
        printf("%d ", item[*rear]);
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
        printf("\n3. Display the queue elements ");
        printf("\n4. EXIT ");
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
            case 3: display(&front, &rear, item);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid option");
        }
    }while(1);
    return 0;
}
