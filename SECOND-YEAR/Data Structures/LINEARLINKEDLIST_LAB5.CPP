#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}node;

node *head = 0;
node *temp = 0;

void create_node()
{
    temp = (node*)malloc(sizeof(node));
}

void insert_at_front(int ele)
{
    create_node();
    temp->data = ele;
    temp->next = head;
    head = temp;
    printf("%d has been added in the beginning!\n", ele);
}

void insert_at_rear(int ele)
{
    create_node();
    temp->data = ele;
    temp->next = 0;
    if (head == 0)
        head = temp;
    else
    {
        node *temp1 = head;
        while(temp1->next != 0)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    printf("%d has been added in the end!\n", ele);
}

void display()
{
    printf("The elements are: ");
    temp = head;
    while(temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int opt, n;
    do
    {
        printf("\nEnter a suitable option:\n");
        printf("1. Insert the element at the beginning\n");
        printf("2. Insert the element at the end\n");
        printf("3. Display the elements \n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        if (opt == 1 || opt == 2)
        {
           printf("Enter the element to be added: ");
           scanf("%d", &n);
        }
        switch(opt)
        {
            case 1: insert_at_front(n);
                    break;
            case 2: insert_at_rear(n);
                    break;
            case 3: display();
                    break;
            default: printf("The program is terminating");
                     exit(0);
        }
    }while(1);
    return 0;
}
