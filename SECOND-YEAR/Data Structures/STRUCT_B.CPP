#include <stdio.h>
#include <conio.h>
struct STUDENT
{
  int marks[10];
  char name[20];
  char usn[15];
}st;
void main()
{
  int i;
  clrscr();
  printf("Enter the name of the student: ");
  scanf("%s", &st.name);
  printf("Enter the USN of the student: ");
  scanf("%s", &st.usn);
  printf("Enter the marks: \n");
  for(i=0; i<6; i++)
  {
    printf("Subject %d: ", i+1);
    scanf("%d", &st.marks[i]);
  }
  printf("The name of the student: ");
  printf("%s \n", st.name);
  printf("The USN of the student: ");
  printf("%s \n", st.usn);
  printf("Marks: \n");
  for(i=0; i<6; i++)
  {
    printf("Subject %d: ", i+1);
    printf("%d \n", st.marks[i]);
  }
  getch();
}