import java.util.*;
import java.lang.Math.*;
class quadratic
{
  public static void main(String args[])
  {
    Scanner s = new Scanner(System.in);
    System.out.println("Enter the co-efficients of a, b and c");
    int a = nextInt();    
    int b = nextInt();    
    int c = nextInt();    
    double det = Math.sqrt((b * b) - (4 * a * c));
    double base = 2 * a;
    double root1;
    double root2;
    if (det == 0)
    {
      System.out.println("The given roots are EQUAL.");
      root1 = (-b + det)/base;
      root2 = root1;
      System.out.println("And the roots are: " + root1 + ", " + root2);
    }
    else if (det > 0)
    {
      System.out.println("The given roots are REAL and DISTINCT.");
      root1 = (-b + det)/base;
      root2 = (-b - det)/base;
      System.out.println("And the roots are: " + root1 + ", " + root2);
    }
    if (det == 0)
    {
      System.out.println("The given roots are IMAGINARY.");
    }
  }
}
      
