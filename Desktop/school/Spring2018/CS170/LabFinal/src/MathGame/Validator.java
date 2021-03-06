
/*********************************************************************
Name: Kerolles, Denna, Patrick, Mark
Course: CS170-01
Lab #: Lab Final
Submission Date: 10:00pm, Wednesday 5/9/18
Brief Description: This class contains the two validation methods
to check if the user's input is valid
**********************************************************************/


package MathGame;

import javax.swing.JOptionPane;

public class Validator 
{
	public static String validName(String n)
	{
		while(!n.matches("[a-zA-Z]+"))
		{
			n = JOptionPane.showInputDialog("Error! Please enter a name: ");
		}
		return n;
	}
	
	public static String validNumber(String n)
	{
		while(!n.matches("[0-9]+"))
		{
			n = JOptionPane.showInputDialog("Error! Please enter a number: ");
		}
		return n;
	}
}
