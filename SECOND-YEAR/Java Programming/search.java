import java.util.*;
import java.lang.*;
class search
{ 
  public static void main(String args[])
  {
    tech t = new tech();
    int a[] = new int[20];
    int n;
    int ele;
    Scanner s = new Scanner(System.in);
    System.out.print("Enter the number of array elements: ");
    n = s.nextInt();
    System.out.print("Enter the array elements: ");
    for(int i=0; i<n; i++)
      a[i] = s.nextInt();
    System.out.print("Enter the element to be searched: ");
    ele = s.nextInt();
    System.out.println("Binary search: ");
    t.binary(n, a, ele);
    System.out.println("Linear search: ");
    t.linear(n, a, ele);
  }
}
class tech
{
  int a[] = new int[20];
  int n; 
  int ele;
  public void binary(int n, int a[], int ele)
  {
    int mid;
    int beg = 0;
    int end = n-1;
    int loc = -1;
    while(beg<=end)
    {
      mid = (beg + end)/2;
      if(a[mid]==ele)
      {
        loc = mid;
        break;
      }
      else if(a[mid]<ele)
        beg = mid + 1;
      else 
        end = mid - 1;
    }
    if (loc==-1)
      System.out.println("Element not found!");
    else
      System.out.println("Element found in the location " + (loc+1));
  }
  public void linear(int n, int a[], int ele)
  {
    int loc = -1;
    for(int i=0; i<n; i++)
    {
      if(a[i]==ele)
      {
        loc = i;
        break;
      }
    }
    if (loc==-1)
      System.out.println("Element not found!");
    else
      System.out.println("Element found in the location " + (loc+1));
  }
 
}


