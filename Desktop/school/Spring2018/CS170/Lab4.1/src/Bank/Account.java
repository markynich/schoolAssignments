/* Kerolles Hermina
   CS170-03
   LAB 4
   4/18/18
*/ 

package Bank;

public class Account
{
	private double balance;
	
	public Account()
	{
		balance = 1000.0;
	}
	
	public void deposit(double amount)
	{
		balance = balance + amount;
	}
	
	public void withdrawal(double amount)
	{
		balance = balance - amount;
	}
	
	public double getBalance()
	{
		return balance;
	}
	
	
	
}
