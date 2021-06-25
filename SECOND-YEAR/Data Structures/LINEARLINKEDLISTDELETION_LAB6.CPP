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

void delete_from_front()
{
    if (head == 0)
        printf("List is empty\n");
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("The element in the beginning of the list has been deleted!\n");
    }
}

void delete_from_rear()
{
    if (head == 0)
        printf("List is empty\n");
    else
    {
        temp = head;
        node *prev;
        while(temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = 0;
        free(temp);
        printf("The element in the end of the list has been deleted!\n");
    }
}

void delete_from_pos(pos)
{
    node *prev;
    if (head == 0)
        printf("List is empty\n");
    else if (pos == 1)
        delete_from_front();
    else if (pos > number_of_nodes())
        printf("This position doesn't exist!\n");
    else
    {
        node *temp1 = head;
        for(int i = 0; i < pos-1; i++)
        {
            prev = temp1;
            temp1 = temp1->next;
        }
        prev->next = temp1->next;
        free(temp1);
        printf("The element in the %d position of the list has been deleted!\n", pos);
    }
}

void display()
{
    if (number_of_nodes() == 0)
    {
        printf("Empty list!!\n");
        return;
    }
    printf("The elements are: ");
    node *temp = head;
    while(temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int number_of_nodes()
{
    int count = 0;
    temp = head;
    while(temp != 0)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int main()
{
    int opt, n, pos, count;
    int subopt;
    do
    {
        printf("\nEnter a suitable option:\n");
        printf("1.  Insert the element at the beginning\n");
        printf("2.  Delete the element at the beginning\n");
        printf("3.  Delete the element at the end\n");
        printf("4.  Delete the element at a particular position\n");
        printf("5.  Display the elements in the list\n");
        printf("Press 0 to EXIT\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        if (opt == 1)
        {
           printf("Enter the element to be added: ");
           scanf("%d", &n);
        }
        switch(opt)
        {
            case 0: printf("The program is terminating....\n");
                    exit(0);
                    break;
            case 1: insert_at_front(n);
                    break;
            case 2: delete_from_front();
                    break;
            case 3: delete_from_rear();
                    break;
            case 4: printf("Enter the position where the element has to be deleted: ");
                    scanf("%d", &pos);
                    delete_from_pos(pos);
                    break;
            case 5: display();
                    break;
            default: printf("Invalid option!\n");
        }
    }while(1);
    return 0;
}
