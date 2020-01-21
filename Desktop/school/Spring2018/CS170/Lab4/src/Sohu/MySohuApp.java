
/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 4/20/18
Brief Description: This program contains the class that all the 
methods, even the main method to run the program.
**********************************************************************/


package Sohu;
import javax.swing.JOptionPane;

public class MySohuApp {
	//start of main
	public static void main(String args[])
	{
		MySohu MS = new MySohu();
		String choice = "";
		String fullList = "";
		int counter = 0; //counter to count how many contacts to user adds
		/*
		 * Do while loop to inserts the information the user puts into
		 * Cannot quit unless entered n to quit
		 */
		do
		{
			counter++;
			String nameInput = JOptionPane.showInputDialog("Welcome to Contact Information\n"
					+ "Please enter a contact name");
			//Validation for name
			Validator.validName(nameInput);
			MS.names.add(nameInput);
			String addressInput = JOptionPane.showInputDialog("Please Enter Contact's Address");
			//Validation for address
			Validator.validAddress(addressInput);
			MS.address.add(addressInput);
			String emailInput = JOptionPane.showInputDialog("Please Enter Contact's email");
			//Validation for email
			Validator.validEmail(emailInput);
			MS.emails.add(emailInput);
			String quitInput = JOptionPane.showInputDialog("Enter any key to continue or 'n' to quit");
			//Validation for Options
			Validator.validQuit(quitInput);
			choice = quitInput;
		} while (!choice.equals("n"));
		//Add List of Contacts into ArrayList
		for(int i=0; i<counter; i++)
		{
			System.out.println(i);
			String namePrint = MS.names.get(i);
			String addressPrint = MS.address.get(i);
			String emailPrint = MS.emails.get(i);
			fullList += "Contact #"+i+" Name: " + namePrint +
					" Address: " + addressPrint + " Email: " + emailPrint + "\n";
		}
		//Printing out List of Contacts
		JOptionPane.showMessageDialog(null, fullList);
		choice = ""; //resets choice
		//Menu for Program choices
		while (!choice.matches("n"))
		{
			String list = JOptionPane.showInputDialog("List of options you can do:\n"
					+ "1. add contact\n"
					+ "2. delete contact\n"
					+ "3. search contact\n"
					+ "4. print all contacts\n"
					+ "n quit Program");
			Validator.validChoice(list);
		//first option
		if (list.matches("1"))
		{
			String nameInput = JOptionPane.showInputDialog("Welcome to Contact Information\n"
					+ "Please enter a contact name");
			//Validation for name
			Validator.validName(nameInput);
			MS.names.add(nameInput);
			String addressInput = JOptionPane.showInputDialog("Please Enter Contact's Address");
			//Validation for address
			Validator.validAddress(addressInput);
			MS.address.add(addressInput);
			String emailInput = JOptionPane.showInputDialog("Please Enter Contact's email");
			//Validation for email
			Validator.validEmail(emailInput);
			MS.emails.add(emailInput);
			String namePrint = MS.names.get(counter);
			String addressPrint = MS.address.get(counter);
			String emailPrint = MS.emails.get(counter);
			fullList += "Contact #"+counter+" Name: " + namePrint +
					" Address: " + addressPrint + " Email: " + emailPrint + "\n";
			counter++;
		}
		//second option
		if (list.matches("2"))
		{
			int rm = counter - 1;
			String removeInput = JOptionPane.showInputDialog(fullList
					+ "\nEnter the Contact number which you like to delete"
					+ "Example: Contact #1 (enter 1)");
			Validator.validRemove(removeInput,0,rm);
			Validator.validRemove(removeInput,0,rm);
			rm = Integer.parseInt(removeInput);
			MS.names.remove(rm);
			MS.address.remove(rm);
			MS.emails.remove(rm);
			counter --;
			fullList = "";
			for(int i=0; i<counter; i++)
			{
				System.out.println(i);
				String namePrint = MS.names.get(i);
				String addressPrint = MS.address.get(i);
				String emailPrint = MS.emails.get(i);
				fullList += "Contact #"+i+" Name: " + namePrint +
						" Address: " + addressPrint + " Email: " + emailPrint + "\n";
			
				//JOptionPane.showMessageDialog(null, fullList);
			}
		}
		//third option
		if (list.matches("3"))
		{
			int sh = counter - 1;
			String searchInput = JOptionPane.showInputDialog("Choose Contact# from 0 " + "to " + sh);
			Validator.validRemove(searchInput,0,sh);
			System.out.println(searchInput);
			sh = Integer.parseInt(searchInput);
			String n = MS.names.get(sh);
			String a = MS.address.get(sh);
			String e = MS.emails.get(sh);
			String sentence =  "Contact #"+sh+" Name: " + n +
					" Address: " + a + " Email: " + e + "\n";
			JOptionPane.showMessageDialog(null, sentence);
		}
		//fourth option
		if (list.matches("4"))
		{
			JOptionPane.showMessageDialog(null, fullList);
		}
		//fifth option
		if (list.matches("n"))
		{
			JOptionPane.showMessageDialog(null, "Exiting Program Goodbye!");
			choice = list;
		}
			
	}//while loop for list
		System.exit(0);
	}//main program
}//final closing bracket
