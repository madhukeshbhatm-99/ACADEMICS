class threads implements Runnable
{
	Thread t;
	threads()
	{
		t = new Thread(this, "DemoThread");
		t.start();
	}
	public void run()
	{
		try
		{
			for(int i=0;i<25;i++)
			{
				System.out.println("CSE ");
				Thread.sleep(2000);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Caught " + e);
		}
	}
}

class threading
{
	public static void main(String args[])
	{
		new threads();
		try
		{
			for(int i=0;i<5;i++)
			{
			    System.out.println();
				System.out.println("BMS College of Engineering ");
				Thread.sleep(10000);
			}
		}
		catch(InterruptedException e)
		{
			System.out.println("Caught " + e);
		}
	}
}