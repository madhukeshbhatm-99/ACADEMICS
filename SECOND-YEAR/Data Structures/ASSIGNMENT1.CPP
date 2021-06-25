#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int entry = -1;
int i;
struct student
{
  char name[20];
  int id;
  char email[10];
}s[100];
void push();
void pop();
int isEmpty();
int isFull();
void peek();
void print();
void main()
{
  int opt;
  clrscr();
  do
  {
    printf("\n\nSelect a suitable option from the following \n");
    printf("1. Push a student to the auditorium \n");
    printf("2. Pop a student from the auditorium \n");
    printf("3. Display the last student's information in the auditorium \n");
    printf("4. Display the students' information present in the auditorium \n");
    printf("5. EXIT \n");
    printf("The option is: ");
    scanf("%d", &opt);
    switch(opt)
    {
      case 1: push();
	      break;
      case 2: pop();
	      break;
      case 3: peek();
	      break;
      case 4: print();
	      break;
      case 5: exit(0);
	      break;
      default: printf("Invalid option");
    }
  }while(1);
  getch();
}
int isEmpty()
{
  if (entry==-1)
    return 1;
  else
    return 0;
}
int isFull()
{
  if (entry==99)
    return 1;
  else
    return 0;
}
void push()
{
  if(isFull()==1)
    printf("The auditorium is full! ");
  else
  {
    entry++;
    printf("Enter the student's details \n");
    printf("Name: ");
    scanf("%s", &s[entry].name);
    printf("ID: ");
    scanf("%d", &s[entry].id);
    printf("Email: ");
    scanf("%s", &s[entry].email);
  }
}
void pop()
{
  if(isEmpty()==1)
    printf("The auditorium is empty! ");
  else
  {
    printf("The popped student's details: \n");
    printf("Name: ");
    printf("%s", s[entry].name);
    printf("\nID: ");
    printf("%d", s[entry].id);
    printf("\nEmail: ");
    printf("%s", s[entry].email);
    entry--;
  }
}
void print()
{
  for(i=0; i<=entry; i++)
  {
    printf("\nThe student's details \n");
    printf("Name: ");
    printf("%s", s[i].name);
    printf("\nID: ");
    printf("%d", s[i].id);
    printf("\nEmail: ");
    printf("%s", s[i].email);
  }
}
void peek()
{
  printf("Name: ");
  printf("%s", s[entry].name);
  printf("\nID: ");
  printf("%d", s[entry].id);
  printf("\nEmail: ");
  printf("%s", s[entry].email);
}
