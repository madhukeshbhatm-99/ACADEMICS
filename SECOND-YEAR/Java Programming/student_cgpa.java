import java.util.*;
class student
{
  public static void main(String[] args)
  {
    info i = new info();
    i.accept();
    i.display();
    i.calc_cgpa();
  }
}
class info
{
  int marks[] = new int[10];
  int n;
  String name;
  String usn;
  int i;
  int grades[] = new int[10];
  int credits[] = new int[10];
  int totalCredits;
  int sum = 0;
  public void accept()
  {
    Scanner s = new Scanner(System.in);
    System.out.print("Enter the student's name: ");
    name = s.next();
    System.out.print("Enter the student's USN: ");
    usn = s.next();
    System.out.print("Enter the number of subjects: ");
    n = s.nextInt();
    System.out.println("Enter the student's marks: ");
    for(int i=0; i<n; i++)
    {
      System.out.print("Subject " + (i+1) + ": ");
      marks[i] = s.nextInt();
    }
  }
  public void display()
  {
    System.out.println("\n***Student Info***");
    System.out.println("Student's name: " + name);
    System.out.println("Student's USN: " + usn);
    System.out.println("Student's marks");
    for(int i=0; i<n; i++)
     System.out.println("Subject " + (i+1) + ":  " + marks[i]);
  }
  public void calc_cgpa()
  {
    Scanner in = new Scanner(System.in);
    System.out.println("\n***Calculation of CGPA***");
    for (int i=0; i<n; i++)
    {
       if ((marks[i]>=90)&&(marks[i]<=100))
        grades[i]=10;
      else if ((marks[i]>=75)&&(marks[i]<90))
        grades[i]=9;
      else if ((marks[i]>=60)&&(marks[i]<75))
        grades[i]=8;
      else if ((marks[i]>=50)&&(marks[i]<60))
        grades[i]=7;
      else if ((marks[i]>=45)&&(marks[i]<50))
        grades[i]=6;
      else if ((marks[i]>=40)&&(marks[i]<45))
        grades[i]=5;
      else
        grades[i]=0;
    }
    System.out.println("GRADES : ");
    for (i=0; i<n; i++)
      System.out.println("The grade in subject " + (i+1) + ": " + grades[i]);
    System.out.println("CREDITS: ");
    for (i=0; i<n; i++)
    {
      System.out.print("Enter the Credits of subject " + (i+1) + ": ");
      credits[i] = in.nextInt();
    }
    for (i=0; i<n; i++)
    {
      totalCredits = totalCredits+credits[i];
    }
    System.out.println("\nThe total credits of all the subjects is: " + totalCredits);
    for (i=0; i<n; i++)
    {
       int product = grades[i] * credits[i];
       sum = sum + product;
    }
    double sgpa = (double)sum / totalCredits;
    System.out.println("The SGPA of the student is " + sgpa);
    System.out.print("The previous SGPA of the student is ");
    double sgpa2 = in.nextDouble();
    double cgpa = (sgpa + sgpa2) / 2.0;
    System.out.println("The CGPA of the student is " + cgpa);  
  }
}  
