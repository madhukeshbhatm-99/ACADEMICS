#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int top = -1;
int num[10];
int ele;
void push(int num[], int x);
void pop(int num[]);
void isFull();
void isEmpty();
void print(int num[]);
void main()
{
  int i,opt;
  clrscr();
  printf("****** BASIC OPERATIONS ON STACK ******");
  do
  {
    printf("\n\nSelect an operation to perform: \n");
    printf("1. Insert an element to the stack \n");
    printf("2. Delete an element from the stack \n");
    printf("3. Check weather the stack is overflow \n");
    printf("4. Check weather the stack is underflow \n");
    printf("5. EXIT \n");
    printf("Enter the option: ");
    scanf("%d", &opt);
    switch(opt)
    {
      case 1: printf("Enter the element which needs to be inserted: ");
	      scanf("%d", &ele);
	      push(num, ele);
	      break;
      case 2: pop(num);
	      break;
      case 3: isFull();
	      break;
      case 4: isEmpty();
	      break;
      case 5: exit(0);
      default: printf("Invalid option. ");
    }
  }while(opt!=5);
  getch();
}
void push(int num[], int ele)
{
  if(top>=10)
    printf("Element cannot be added as the stack is full.");
  else
  {
    top++;
    num[top] = ele;
    printf("The element has been inserted! ");
    print(num);
  }
}
void pop(int num[])
{
  if(top==-1)
    printf("Element cannot be deleted as the stack is empty.");
  else
  {
    top--;
    printf("The element has been deleted! ");
    print(num);
  }
}
void print(int num[])
{
  int i;
  printf("\nThe elements in the stack are: ");
  for(i=0; i<=top; i++)
    printf("%d ", num[i]);
}
void isFull()
{
  if(top>=10)
    printf("Stack is full.");
  else
    printf("Stack is not full.");
}
void isEmpty()
{
  if(top==-1)
    printf("Stack is empty.");
  else
    printf("Stack is not empty.");
}
