import java.util.*;
import java.lang.Math;

class account
{
  double principal;
  double rate;
  int time;
  double amount;
  public void balance()
  {
    Scanner s = new Scanner(System.in);  
    System.out.print("\nEnter the account balance: ");
    amount = s.nextDouble();    
  }
}

class savings extends account
{
  savings()
  {
  }
  public void display()
  {
    Scanner s = new Scanner(System.in);
    System.out.print("Enter the amount to be withdrawn: ");
    double withdraw = s.nextDouble();
    double updatBal = amount - withdraw;    
    System.out.println("Updated balance: " + updatBal);
    System.out.print("\nEnter the principle amount: ");
    principal = s.nextDouble();    
    System.out.print("Enter the rate of interest: ");
    rate = s.nextDouble();    
    System.out.print("Enter the time in years: ");
    time = s.nextInt();    
    double  CI = principal * Math.pow((1 + rate), time) - (principal - withdraw);
    System.out.println("The Coumpound Interest is: " + CI);
    System.out.println("The savings account does not provide cheque book facility!");
  }
}

class current extends account
{
  public void display()
  {
    if(amount < 1000.00)
     System.out.println("Your account balance is too low! Certain service charges are imposed on you");       
    else
    System.out.println("Cheque book facility is available!");
  }
}

class bank
{
  public static void main(String arg[])
  {
    Scanner s = new Scanner(System.in);  
    System.out.print("\nSelect a account: \n1. Savings account \n2. Current Account \nOption: ");
    int opt = s.nextInt();    
    savings s1 = new savings();
    current c = new current();
    switch(opt)
    {
      case 1: s1.balance();
              s1.display();
              break;
      case 2: c.balance();
              c.display();
              break;
      default: System.out.print("Invalid option");
    }
  }
}    
