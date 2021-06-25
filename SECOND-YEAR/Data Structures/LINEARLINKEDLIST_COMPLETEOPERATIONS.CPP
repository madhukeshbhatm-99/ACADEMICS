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

void insert_at_pos(int pos, int ele)
{
    create_node();
    temp->data = ele;
    temp->next = 0;
    if (pos == 1)
    {
        insert_at_front(ele);
        printf("%d has been added at the 1st position!\n", ele);
    }
    else if (pos > (number_of_nodes() + 1))
        printf("This position doesn't exist!\n");
    else
    {
        node *temp1 = head;
        for(int i = 1; i < pos-1; i++)
            temp1 = temp1->next;
        temp->next = temp1->next;
        temp1->next = temp;
        printf("%d has been added at the %d position!\n", ele, pos);
    }
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

void sort_the_list_asscending()
{
    node *temp1, *temp2;
    int temp;
    if (head == 0)
        printf("No element to sort!\n");
    else if(number_of_nodes() == 1)
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
        printf("The elements in the list are successfully sorted in ascending order!\n");
    }
}

void sort_the_list_descending()
{
    node *temp1, *temp2;
    int temp;
    if (head == 0)
        printf("No element to sort!\n");
    else if(number_of_nodes() == 1)
        printf("Only one element in the list!\n");
    else
    {
        temp1 = head;
        while(temp1->next != 0)
        {
            temp2 = head;
            while(temp2->next != 0)
            {
                if ((temp2->data) < (temp2->next->data))
                {
                    temp = temp2->data;
                    temp2->data = temp2->next->data;
                    temp2->next->data = temp;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        printf("The elements in the list are successfully sorted in descending order!\n");
    }
}

void sort_the_list_during_insertion_asscending(int ele)
{
    sort_the_list_asscending();
    create_node();
    temp->data = ele;
    temp->next = 0;
    node *temp1, *temp2;
    if (head == 0)
        head = temp;
    else
    {
        temp1 = head;
        if ((temp1->data) > ele)
        {
            head = temp;
            temp = temp->next;
        }
        else
        {
            while((temp1->data) < ele)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = temp;
            temp->next = temp1;
        }
    }
}

void sort_the_list_during_insertion_descending(int ele)
{
    if (number_of_nodes() > 1)
        sort_the_list_descending();
    create_node();
    temp->data = ele;
    temp->next = 0;
    node *temp1, *temp2;
    if (head == 0)
        head = temp;
    else
    {
        temp1 = head;
        if ((temp1->data) < ele)
        {
            head = temp;
            temp = temp->next;
        }
        else
        {
            while((temp1->data) > ele)
            {
                temp2 = temp1;
                temp1 = temp1->next;
                if (temp == 0)
                    break;
            }
            temp2->next = temp;
            temp->next = temp1;
        }
    }
}

void reverse_the_list()
{
    node *curr, *prev, *next;
    if (head == 0)
        printf("No element to reverse the list!\n");
    else if(number_of_nodes() == 1)
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
        printf("The list has been successfully reversed!\n");
    }
}

void display_using_recursion(node *ptr)
{
    if (ptr == 0)
        return;
    printf("%d ", ptr->data);
    display_using_recursion(ptr->next);
}

void display_reverse_using_recursion(node *ptr)
{
    if (ptr == 0)
        return;
    display_reverse_using_recursion(ptr->next);
    printf("%d ", ptr->data);
}

void reverse_the_list_using_recursion(node *prev)
{
    if (prev->next == 0)
    {
        head = prev;
        return;
    }
    reverse_the_list_using_recursion(prev->next);
    node *curr = prev->next;
    curr->next = prev;
    prev->next = 0;
}

int main()
{
    int opt, n, pos, count;
    int subopt;
    do
    {
        printf("\n*** BASIC OPERATIONS ON SINGLY LINKED LIST ***\n");
        printf("Enter a suitable option:\n");
        printf("1.  Insert the element at the beginning\n");
        printf("2.  Insert the element at the end\n");
        printf("3.  Insert the element at a particular position\n");
        printf("4.  Delete the element at the beginning\n");
        printf("5.  Delete the element at the end\n");
        printf("6.  Delete the element at a particular position\n");
        printf("7.  Display the elements in the list\n");
        printf("8.  Display the number of elements in the list\n");
        printf("9.  Sort the list after insertion\n");
        printf("    1. In ascending order \n");
        printf("    2. In descending order \n");
        printf("10. Sort the list during insertion\n");
        printf("    1. In ascending order \n");
        printf("    2. In descending order \n");
        printf("11. Reverse the list\n");
        printf("12. Using Recursive functions:\n");
        printf("    1. Display the elements of the list\n");
        printf("    2. Display the elements of the list in the reverse order\n");
        printf("    3. Reverse the list\n");
        printf("Press 0 to EXIT\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        if (opt == 9 || opt == 10 || opt == 12)
        {
            printf("Your sub option is: ");
            scanf("%d", &subopt);
        }
        if (opt == 1 || opt == 2 || opt == 3 || opt == 10)
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
            case 2: insert_at_rear(n);
                    break;
            case 3: printf("Enter the position where the element has to be inserted: ");
                    scanf("%d", &pos);
                    insert_at_pos(pos, n);
                    break;
            case 4: delete_from_front();
                    break;
            case 5: delete_from_rear();
                    break;
            case 6: printf("Enter the position where the element has to be deleted: ");
                    scanf("%d", &pos);
                    delete_from_pos(pos);
                    break;
            case 7: display();
                    break;
            case 8: count = number_of_nodes();
                    printf("The number of elements in the node are: %d\n", count);
                    break;
            case 9: switch(subopt)
                    {
                        case 1: sort_the_list_asscending();
                                break;
                        case 2: sort_the_list_descending();
                                break;
                        default: printf("Invalid option\n");
                    }
                    break;
            case 10: switch(subopt)
                     {
                         case 1: sort_the_list_during_insertion_asscending(n);
                                 break;
                         case 2: sort_the_list_during_insertion_descending(n);
                                 break;
                         default: printf("Invalid option\n");
                     }
                     break;
            case 11: reverse_the_list();
                     break;
            case 12: switch(subopt)
                     {
                         case 1: if (number_of_nodes() == 0)
                                    printf("EMPTY list\n");
                                 else
                                 {   printf("The elements are: ");
                                     display_using_recursion(head);
                                     printf("\n");
                                 }
                                 break;
                         case 2: if (number_of_nodes() == 0)
                                    printf("EMPTY list\n");
                                 else
                                 {   printf("The elements are: ");
                                     display_reverse_using_recursion(head);
                                     printf("\n");
                                 }
                                 break;
                         case 3: if (number_of_nodes() == 0)
                                    printf("EMPTY list\n");
                                 else if (number_of_nodes() == 1)
                                    printf("Only one element in the list\n");
                                 else
                                 {
                                     reverse_the_list_using_recursion(head);
                                     printf("The list has been successfully reversed!\n");
                                 }
                                 break;
                         default: printf("Invalid option\n");
                     }
                     break;
            default: printf("Invalid option!\n");
        }
    }while(1);
    return 0;
}
