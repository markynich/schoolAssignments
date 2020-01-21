/* Kerolles Hermina
   CS170-03
   LAB 4
   4/18/18
*/ 

package Sohu;

import javax.swing.JOptionPane;

public class Validator {
	

	public static String validName(String name)
	{
		while(!name.matches("[a-zA-Z ]+"))
		{
			name = JOptionPane.showInputDialog("Error! Enter a name: ");
		}
		return name;
	}
	public static String validAddress(String address)
	{
		while(!address.matches("[a-zA-Z0-9 ]+"))
		{
			address = JOptionPane.showInputDialog("Error! Enter an address: "
					+ "Ex: 36880 Newark blvd");
		}
		return address;
	}
	public static String validEmail(String email)
	{
		while(!email.matches("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}"))
		{
			email = JOptionPane.showInputDialog("Error! Enter an address: "
					+ "Ex: Khermina@aol.com");
		}
		return email;
	}
	public static String validQuit(String q)
	{
		while(!q.matches("[a-zA-Z0-9 ]+"))
		{
			q = JOptionPane.showInputDialog("Error! Enter a key to continue or 'q' to quit");
		}
		return q;
	}
	public static String validChoice(String choice)
	{
		while(!choice.matches("[1-5n]+"))
		{
			choice = JOptionPane.showInputDialog("Error! Please choose a correct option:\n"
					+ "1. add contact\n"
					+ "2. delete contact\n"
					+ "3. search contact\n"
					+ "4. print all contacts\n"
					+ "q. quit program");
		}
		return choice;
	}
	public static String validRemove(String r, int min, int max)
	{
		String returnString = "";
		while(!r.matches("[0-9]+"))
		{
			r = JOptionPane.showInputDialog("Error! Enter correct Contact # within 0 to "
					+ max
					+ "\nExample: Contact #5 (enter 5)");
			returnString = r;
		}
		if (r.matches("[0-9]+"))
		{
			int num = Integer.parseInt(r);
			while (num < min || num > max)
			{
				r = JOptionPane.showInputDialog("Error! Enter correct Contact # within 0 to "
						+ max
						+ "\nExample: Contact #5 (enter 5)");
				num = Integer.parseInt(r);
				r = Integer.toString(num);
			}
			r = Integer.toString(num);
			returnString = r;
			return returnString;
		}
		return returnString;
	}
}




