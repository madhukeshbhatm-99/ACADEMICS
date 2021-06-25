#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *head=0;
void insert_left(int x)
{
   node *temp;
   temp=(node *)malloc(sizeof(node));
   temp->data=x;
   temp->prev=0;
   temp->next=0;
   if(head==0)
    head=temp;
   else
   {
       temp->next=head;
       head->prev=temp;
       head=temp;
   }
}

void delete_pos(int x)
{
  node *temp=head;
  if(temp==0)
    return;
  else if(temp->next==0)
  {
      head=0;
      free(temp);
      return;
  }
  else
 {
  for(int i=1;i<x;i++)
  {
      temp=temp->next;
  }
  if(temp->next==0)
    {temp->prev=0; free(temp);}
  else
  {
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
 }
 }
}

void display()
{
    node *temp=head;
    printf("The list : ");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    int n=1,x;
    while(n!=0)
    {
        printf("\nOptions\n 1.Inserting the element at the left of list\n2. Deleting the element position\nPress 0 to EXIT\n");
        printf("Option: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :printf("Enter the element: ");
                    scanf("%d",&x);
                    insert_left(x);
                    display();break;
            case 2 :printf("Enter the position to be deleted: ");
                    scanf("%d",&x);
                    delete_pos(x);
                    display();break;
            case 0 :return;
            default :printf("Invalid input!!!");
        }
    }
}
