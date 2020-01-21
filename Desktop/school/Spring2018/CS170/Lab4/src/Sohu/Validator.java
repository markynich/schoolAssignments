
/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 4/20/18
Brief Description: This program contains the class that has methods
to validate all the information inside the program. Each method
validates a specific part of the program
**********************************************************************/


package Sohu;

import javax.swing.JOptionPane;

public class Validator {
	
	//Name validation
	public static String validName(String n)
	{
		while(!n.matches("[a-zA-Z]+"))
		{
			n = JOptionPane.showInputDialog("Error! Please enter a first name: ");
		}
		return n;
	}
	//Address validation
	public static String validAddress(String a)
	{
		while(!a.matches("[a-zA-Z0-9 ]+"))
		{
			a = JOptionPane.showInputDialog("Error! Please enter an address: "
					+ "Ex: 1234 Java Street");
		}
		return a;
	}
	//email validation
	public static String validEmail(String em)
	{
		while(!em.matches("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}"))
		{
			em = JOptionPane.showInputDialog("Error! Please enter an address: "
					+ "Ex: java14@sbcglobal.net");
		}
		return em;
	}
	//validation to quit
	public static String validQuit(String q)
	{
		while(!q.matches("[a-zA-Z0-9 ]+"))
		{
			q = JOptionPane.showInputDialog("Error! Please enter a key to continue or 'n' to quit");
		}
		return q;
	}
	//validating the choice of user
	public static String validChoice(String c)
	{
		while(!c.matches("[1-5n]+"))
		{
			c = JOptionPane.showInputDialog("Error! Please choose a correct option:\n"
					+ "1. add contact\n"
					+ "2. delete contact\n"
					+ "3. search contact\n"
					+ "4. print all contacts\n"
					+ "n. quit program");
		}
		return c;
	}
	//validation for removing contacts or searching contacts
	public static String validRemove(String r, int min, int max)
	{
		String returnString = "";
		while(!r.matches("[0-9]+"))
		{
			r = JOptionPane.showInputDialog("Error! Please correct Contact # within 0 to "
					+ max
					+ "\nExample: Contact #0 (enter 0)");
			returnString = r;
		}
		if (r.matches("[0-9]+"))
		{
			int num = Integer.parseInt(r);
			while (num < min || num > max)
			{
				r = JOptionPane.showInputDialog("Error! Please correct Contact # within 0 to "
						+ max
						+ "\nExample: Contact #0 (enter 0)");
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



