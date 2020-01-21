
/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 4/20/18
Brief Description: This program is the driver class for the whole
program. It has the main function to run the program. It also
contains the objects to use the classes and threads.
**********************************************************************/


package bankAccount;

public class BankAccountApp {
	public static void main(String[] args)
	{
		/*
		 * Objects to use the classes of the program
		 */
		Account account = new Account();
		BankAccount Chase = new BankAccount(account);
		Thread husband = new Thread(Chase);
		Thread wife = new Thread(Chase);
		/*
		 * sets names of the 2 threads
		 */
		husband.setName("Husband");
		wife.setName("Wife");
		//starts the threads
		husband.start();
		wife.start();
	}
}
