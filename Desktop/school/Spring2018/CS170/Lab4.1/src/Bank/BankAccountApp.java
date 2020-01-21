/* Kerolles Hermina
   CS170-03
   LAB 4
   4/18/18
*/ 

package Bank;

public class BankAccountApp {
	public static void main(String[] args)
	{
		Account account = new Account();
		BankAccount Citi = new BankAccount(account);
		Thread husband = new Thread(Citi);
		Thread wife = new Thread(Citi);
		husband.setName("Husband");
		wife.setName("Wife");
		
		husband.start();
		wife.start();
	}
}
