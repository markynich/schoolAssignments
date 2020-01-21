/* Kerolles Hermina
   CS170-03
   LAB 4
   4/18/18
*/ 

package Sohu;


import javax.swing.JOptionPane;

public class MySohuApp {
	
	public static void main(String args[])
	{
		MySohu MS = new MySohu();
		String choice = "";
		String fullList = "";
		int counter = 0;
		do
		{
			counter++;
			String nameInput = JOptionPane.showInputDialog("Welcome to Contact Information\n"
					+ "Please enter a contact name");
			//Validation
			Validator.validName(nameInput);
			MS.names.add(nameInput);
			String addressInput = JOptionPane.showInputDialog("Enter Contact's Address");
			//Validation for address
			Validator.validAddress(addressInput);
			MS.address.add(addressInput);
			String emailInput = JOptionPane.showInputDialog("Enter Contact's email");
			//Validation for email
			Validator.validEmail(emailInput);
			MS.emails.add(emailInput);
			String quitInput = JOptionPane.showInputDialog("Any key to continue or 'q' to quit");
			//Validation for Options
			Validator.validQuit(quitInput);
			choice = quitInput;
		} while (!choice.equals("q"));
	
		for(int i=0; i<counter; i++)
		{
			System.out.println(i);
			String namePrint = MS.names.get(i);
			String addressPrint = MS.address.get(i);
			String emailPrint = MS.emails.get(i);
			fullList += "Contact number,"+i+" Name: " + namePrint +
					" Address: " + addressPrint + " Email: " + emailPrint + "\n";
		}
		//Printing out List of Contacts
		JOptionPane.showMessageDialog(null, fullList);
		choice = ""; //resets choice
		//Menu for Program choices
		while (!choice.matches("q"))
		{
			String list = JOptionPane.showInputDialog("List of options you can do:\n"
					+ "1. add contact\n"
					+ "2. delete contact\n"
					+ "3. search contact\n"
					+ "4. print all contacts\n"
					+ "q quit Program");
			Validator.validChoice(list);
		if (list.matches("1"))
		{
			String nameInput = JOptionPane.showInputDialog("Welcome to Contact Information\n"
					+ "Enter a contact name");
			//Validation for name
			Validator.validName(nameInput);
			MS.names.add(nameInput);
			String addressInput = JOptionPane.showInputDialog("Enter Contact's Address");
			//Validation for address
			Validator.validAddress(addressInput);
			MS.address.add(addressInput);
			String emailInput = JOptionPane.showInputDialog("Enter Contact's email");
			//Validation for email
			Validator.validEmail(emailInput);
			MS.emails.add(emailInput);
			String namePrint = MS.names.get(counter);
			String addressPrint = MS.address.get(counter);
			String emailPrint = MS.emails.get(counter);
			fullList += "Contact number"+counter+" Name: " + namePrint +
					" Address: " + addressPrint + " Email: " + emailPrint + "\n";
			counter++;
		}
		if (list.matches("2"))
		{
			int rm = counter - 1;
			String removeInput = JOptionPane.showInputDialog(fullList
					+ "\nEnter the Contact number which you like to delete"
					+ "Example: Contact number 1 (enter 1)");
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
				fullList += "Contact number"+i+" Name: " + namePrint +
						" Address: " + addressPrint + " Email: " + emailPrint + "\n";
			
				//JOptionPane.showMessageDialog(null, fullList);
			}
		}
		if (list.matches("3"))
		{
			int search = counter - 1;
			String searchInput = JOptionPane.showInputDialog("Choose Contact# from 0 " + "to " + search);
			Validator.validRemove(searchInput,0,search);
			System.out.println(searchInput);
			search = Integer.parseInt(searchInput);
			String n = MS.names.get(search);
			String a = MS.address.get(search);
			String e = MS.emails.get(search);
			String sentence =  "Contact #"+search+" Name: " + n +
					" Address: " + a + " Email: " + e + "\n";
			JOptionPane.showMessageDialog(null, sentence);
		}
		if (list.matches("4"))
		{
			JOptionPane.showMessageDialog(null, fullList);
		}
		if (list.matches("q"))
		{
			JOptionPane.showMessageDialog(null, "Exiting Program!");
			choice = list;
		}
			
	}
		System.exit(0);
	}
}