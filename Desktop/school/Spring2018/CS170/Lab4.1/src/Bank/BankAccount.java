/* Kerolles Hermina
   CS170-03
   LAB 4
   4/18/18
*/ 

package Bank;
import java.text.DecimalFormat;
public class BankAccount implements Runnable{
	private Account account;
	//format amounts to 2 decimals
	DecimalFormat dc = new DecimalFormat("#0.00");
	//class account
	public BankAccount(Account account)
	{
		this.account = account;
	}
	
	public void run()
	{
		for (int i=1; i <=2; i++)
		{
			makeWithdrawal(300);
			makeDeposit(Math.random()*100);
			if (account.getBalance() < 0)
			{
				System.out.println("Overdrawn!");
			}
		}
	}
	
	private synchronized void makeWithdrawal(double withdrawAmount)
	{
		if (account.getBalance() >= withdrawAmount)
		{
			System.out.println(Thread.currentThread().getName() + " is withdrawing money" + dc.format(withdrawAmount));
			try
			{
				Thread.sleep(5000);
			} catch (InterruptedException ex){}
			account.withdrawal(withdrawAmount);
			System.out.println(Thread.currentThread().getName() + " completes the withdrawal of money" + dc.format(withdrawAmount));
			System.out.println(Thread.currentThread().getName() + " now has received the money" + dc.format(account.getBalance()) +"\n");
		}
		else
		{
			System.out.println("Not enough money in the account for " + Thread.currentThread().getName()
						+ "to withdraw money" + dc.format(withdrawAmount) + " and only have money" + dc.format(account.getBalance())) ;
		}
		
	}
	
	private  synchronized void makeDeposit(double depositAmount)
	{
		if (depositAmount > 0)
		{
			System.out.println(Thread.currentThread().getName() + " is depositing money" + dc.format(depositAmount));
			try
			{
				Thread.sleep(2000);
			} catch (InterruptedException ex){}
			account.deposit(depositAmount);
			System.out.println(Thread.currentThread().getName() + " completed the deposit of money" + dc.format(depositAmount));
			System.out.println(Thread.currentThread().getName() + " now has money" + dc.format(account.getBalance()) +"\n");
		}
		else
		{
			System.out.println("Can't depost into " + Thread.currentThread().getName()
						+ "'s account of " + dc.format(depositAmount) + ", must be a positive amount") ;
		}
		
	}
}

	
	
	
	