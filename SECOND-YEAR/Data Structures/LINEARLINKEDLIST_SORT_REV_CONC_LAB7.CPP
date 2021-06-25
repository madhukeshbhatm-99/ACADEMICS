#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}node;

node *head = 0;
node *head1 = 0;
node *temp = 0;

void create_node()
{
    temp = (node*)malloc(sizeof(node));
}

void insert(int ele)
{
    create_node();
    temp->data = ele;
    temp->next = head;
    head = temp;
}

void insert1(int ele)
{
    create_node();
    temp->data = ele;
    temp->next = head1;
    head1 = temp;
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

void display1()
{
    printf("The elements are: ");
    temp = head1;
    while(temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort_the_list()
{
    node *temp1, *temp2;
    int temp;
    if (head == 0)
        printf("No element to sort!\n");
    else if(head->next == 0)
        printf("Only one element in the list!\n");
    else
    {
        temp1 = head;
        while(temp1->next != 0)
        {
            temp2 = head;
            while(temp2->next != 0)
            {
                if ((temp2->data) > (temp2->next->data))
                {
                    temp = temp2->data;
                    temp2->data = temp2->next->data;
                    temp2->next->data = temp;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }
}

void reverse_the_list()
{
    node *curr, *prev, *next;
    if (head == 0)
        printf("No element to reverse the list!\n");
    else if(head->next == 0)
        printf("Only one element in the list!\n");
    else
    {
        curr = head;
        prev = 0;
        while(curr != 0)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
}

void concatenate()
{
    node *temp1 = head;
    if (head == 0 || head1 == 0)
    {
        printf("Empty List!!");
        return;
    }
    else
    {
        while(temp1->next != 0)
           temp1 = temp1->next;
        temp1->next = head1;
    }
}

int main()
{
    int opt, n;
    do
    {
        printf("Option:\n");
        printf("1. Insert to the 1st list\n");
        printf("2. Insert to the 2nd list\n");
        printf("3. Display 1st list\n");
        printf("4. Display 2nd list\n");
        printf("5. Sort the list \n");
        printf("6. Reverse the list\n");
        printf("3. Concatenate the list\n");
        printf("Press 0 to EXIT\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        if (opt == 1 || opt == 2)
        {
           printf("Enter the element: ");
           scanf("%d", &n);
        }
        switch(opt)
        {
            case 0: exit(0);
                    break;
            case 1: insert(n);
                    break;
            case 2: insert1(n);
                    break;
            case 3: display();
                    break;
            case 4: display1();
                    break;
            case 5: sort_the_list();
                    break;
            case 6: reverse_the_list();
                    break;
            case 7: concatenate();
                    break;
            default: printf("Invalid option!\n");
        }
    }while(1);
    return 0;
}
