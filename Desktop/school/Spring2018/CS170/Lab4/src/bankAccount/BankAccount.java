
/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 4/20/18
Brief Description: This program contains the class that has methods
for the program to run smoothly. Contains Threading and runnable
**********************************************************************/

package bankAccount;
import java.text.DecimalFormat;
public class BankAccount implements Runnable{
	private Account account;
	//To format the double amounts to 2 decimals
	DecimalFormat dc = new DecimalFormat("#0.00");
	//to use the class account
	public BankAccount(Account account)
	{
		this.account = account;
	}
	/*Runnable method for program to 
	 * deposit and withdraw 2 times
	 * for each Husband and Wife
	 * deposit is random amount
	 */
	public void run()
	{
		for (int i=1; i <=2; i++)
		{
			makeWithdrawal(300);
			makeDeposit(Math.random()*100);
			if (account.getBalance() < 0)
			{
				System.out.println("account is overdrawn!");
			}
		}
	}
	/*
	 * Withdrawal attempt into balance and takes 0.5 seconds
	 */
	private synchronized void makeWithdrawal(double withdrawAmount)
	{
		if (account.getBalance() >= withdrawAmount)
		{
			System.out.println(Thread.currentThread().getName() + " is going to withdraw $" + dc.format(withdrawAmount));
			try
			{
				Thread.sleep(5000);
			} catch (InterruptedException ex){}
			account.withdrawal(withdrawAmount);
			System.out.println(Thread.currentThread().getName() + " completes the withdrawal of $" + dc.format(withdrawAmount));
			System.out.println(Thread.currentThread().getName() + " now has $" + dc.format(account.getBalance()) +"\n");
		}
		else
		{
			System.out.println("Not enough $$ in the balance for " + Thread.currentThread().getName()
						+ "to withdraw $" + dc.format(withdrawAmount) + " and only have $" + dc.format(account.getBalance())) ;
		}
		
	}
	/*
	 * Attempt to deposit into account and takes 0.2 secs
	 */
	private  synchronized void makeDeposit(double depositAmount)
	{
		if (depositAmount > 0)
		{
			System.out.println(Thread.currentThread().getName() + " is going to deposit $" + dc.format(depositAmount));
			try
			{
				Thread.sleep(2000);
			} catch (InterruptedException ex){}
			account.deposit(depositAmount);
			System.out.println(Thread.currentThread().getName() + " completes the deposit of $" + dc.format(depositAmount));
			System.out.println(Thread.currentThread().getName() + " now has $" + dc.format(account.getBalance()) +"\n");
		}
		else
		{
			System.out.println("Cannot depost into " + Thread.currentThread().getName()
						+ "'s account of " + dc.format(depositAmount) + ", must be a positive amount") ;
		}
		
	}
}
