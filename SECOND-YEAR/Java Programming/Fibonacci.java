import java.util.*;
class Fibonacci
{
  public static void main(String args[])
  {
    Scanner in = new Scanner(System.in);
    System.out.print("Enter the number of elements in the Fibonacci series: ");
    int n = in.nextInt();
    int t1 = 0;
    int t2 = 1;
    for(int i = 0; i  < n; i++)
    {
      System.out.print(t1 + " ");
      int sum = t1 + t2;
      t1 = t2;
      t2 = sum;
    }
  }
}