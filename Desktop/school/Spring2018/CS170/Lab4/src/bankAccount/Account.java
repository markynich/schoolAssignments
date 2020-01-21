
/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 4/20/18
Brief Description: This program contains the class that has the methods
and variables to store and get information for the balance of the
account in this program.
**********************************************************************/


package bankAccount;

public class Account
{
	//variable for the account balance
	private double balance;
	//sets balance to $1000
	public Account()
	{
		balance = 1000.0;
	}
	//method to deposit amount into balance
	public void deposit(double amount)
	{
		balance = balance + amount;
	}
	//method to withdraw amount from balance
	public void withdrawal(double amount)
	{
		balance = balance - amount;
	}
	//gets Balance amount
	public double getBalance()
	{
		return balance;
	}
	
	
	
}
