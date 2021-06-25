import java.util.*;
class BOOK
{
  String name;
  String author;
  double price;
  int num_pages;
  BOOK()
  {
  }
  public void get_data()
  {
    Scanner in = new Scanner(System.in);
    System.out.print("\nEnter the name of the book: "); 
    name = in.next();
    System.out.print("Enter the author of the book: "); 
    author = in.next();
    System.out.print("Enter the price of the book: "); 
    price = in.nextDouble();
    System.out.print("Enter the number of pages in the book: "); 
    num_pages = in.nextInt();
  }
  public void toString1()
  {
    System.out.println("Name: " + name);
    System.out.println("Author: " + author);
    System.out.println("Price: " + price + " Rs");
    System.out.println("Number of Pages: " + num_pages);
    System.out.println("----------------------------------");
  }
}
class infoBook
{
  public static void main(String args[])
  {
    Scanner in = new Scanner(System.in);
    System.out.print("\nEnter the number of books: ");
    int n = in.nextInt();
    BOOK b[] = new BOOK[10];
    for(int i = 0; i < n; i++)
    {
      b[i] = new BOOK();
      b[i].get_data();
      System.out.println("\n***INFORMATION OF BOOK " + (i+1) +"***");
      b[i].toString1();
    }
  }
}