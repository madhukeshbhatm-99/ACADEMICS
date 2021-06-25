#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}node;

node *front = 0;
node *rear = 0;
node *top = 0;
node *ptr = 0;
node *temp = 0;

void create_node_stk()
{
    temp = (node*)malloc(sizeof(node));
}

void create_node_que()
{
    ptr = (node*)malloc(sizeof(node));
}

void push(int ele)
{
    create_node_stk();
    temp->data = ele;
    temp->next = 0;
    if (top == 0)
        top = temp;
    else
    {
        node *temp1 = top;
        while(temp1->next != 0)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}

void enqueue(int ele)
{
    create_node_que();
    ptr->data = ele;
    ptr->next = 0;
    if (front == 0)
    {
         front = ptr;
         rear = ptr;
    }
    else
    {
        node *ptr1 = rear;
        while(ptr1->next != 0)
            ptr1 = ptr1->next;
        ptr1->next = ptr;
    }
}

void dequeue()
{
    if (front == 0)
        printf("Queue is empty\n");
    else if(ptr->next == 0)
        dequeue();
    else
    {
        ptr = rear;
        rear = rear->next;
        free(ptr);
    }
}

void pop()
{
    if (top == 0)
        printf("Stack is empty\n");
    else if(temp->next == 0)
    {
        temp = top;
        top->next = 0;
        free(temp);
    }
    else
    {
        temp = top;
        node *prev;
        while(temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = 0;
        free(temp);
    }
}

void display_stk()
{
    if (top == 0)
    {
        printf("Empty Stack!!\n");
        return;
    }
    printf("The elements are: ");
    temp = top;
    while(temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_que()
{
    if (front == 0)
    {
        printf("Empty Queue!!\n");
        return;
    }
    printf("The elements are: ");
    ptr = rear;
    while(ptr != 0)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int opt, n, pos, count;
    int subopt;
    do
    {
        printf("\nEnter a suitable option:\n");
        printf("1. Implementing Stack:\n");
        printf("    1. Push\n");
        printf("    2. Pop\n");
        printf("    3. Display\n");
        printf("2. Implementing Queue:\n");
        printf("    1. Enqueue\n");
        printf("    2. Dequeue\n");
        printf("    3. Display\n");
        printf("Press 0 to EXIT\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        if (opt == 1 || opt == 2)
        {
            printf("Your sub option is: ");
            scanf("%d", &subopt);
        }
        if (subopt == 1)
        {
           printf("Enter the element to be added: ");
           scanf("%d", &n);
        }
        switch(opt)
        {
            case 0: exit(0);
                    break;
            case 1: switch(subopt)
                    {
                        case 1: push(n);
                                break;
                        case 2: pop();
                                break;
                        case 3: display_stk();
                                break;
                        default: printf("Invalid option\n");
                    }
                    break;
            case 2: switch(subopt)
                     {
                         case 1: enqueue(n);
                                 break;
                         case 2: dequeue();
                                 break;
                        case 3: display_que();
                                break;
                         default: printf("Invalid option\n");
                     }
                     break;
            default: printf("Invalid option!\n");
        }
    }while(1);
    return 0;
}
