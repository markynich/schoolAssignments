/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 2
Submission Date: 10:00pm, Wednesday 2/28/18
Brief Description: This program is the driver class for
FutureValueBigDecimal.java. It uses JOPtionPane and asks the user for 
their name and an amount to invest.
Also asks for a percentage, and how many years. 
It contains the main function for the program to run.
It asks the user if they want to continue or not.
Able to quit when asked.
**********************************************************************/

import javax.swing.JOptionPane;

public class FutureValueBigDecimalApp
{
	//start of main function
	public static void main(String[] args)
	{
	//method to use the main class for the driver
	FutureValueBigDecimal fvBd = new FutureValueBigDecimal();
	//strings to access through program
	String choice = "y", investStr, futureValueStr, rateStr;
	JOptionPane.showMessageDialog(null,"Welcome to Investments!");
	do
	{
	String nameInput = JOptionPane.showInputDialog("Please enter your name");
	//Validatation for name
	while(!nameInput.matches("[a-zA-Z ]+"))
		nameInput = JOptionPane.showInputDialog("Error! Please enter first name only: ");
	fvBd.setName(nameInput);
	String monthInput = JOptionPane.showInputDialog("Enter Your monthly investment amount: ");
	double number = Double.parseDouble(monthInput);
	//validation for input
	while(number < 1 || number > 1000000)  {
			monthInput = JOptionPane.showInputDialog("Error! Please enter investments from $1 - $1,000,000");
			number = Double.parseDouble(monthInput);
		}
	monthInput = Double.toString(number);
	fvBd.setMonthlyInvest(monthInput);
	String yearRateInput = JOptionPane.showInputDialog("Enter Your interest rate from 0.1% - 35%");
	double percent = Double.parseDouble(yearRateInput);
	//validation for input
	while(percent < 0.1 || percent > 35)  {
			yearRateInput = JOptionPane.showInputDialog("Error! Please enter rate from 0.1% - 35%");
			percent = Double.parseDouble(yearRateInput);
		}
	yearRateInput = Double.toString(percent);
	fvBd.setYearlyRate(yearRateInput);
	String yearInput = JOptionPane.showInputDialog("Enter how many years to invest: ");
	double yearAmount = Double.parseDouble(yearInput);
	//validation for input
	while(yearAmount < 1 || yearAmount > 120)  {
		yearInput = JOptionPane.showInputDialog("Error! Please enter years from 1 - 120");
			yearAmount = Double.parseDouble(yearInput);
		}
	yearInput = Double.toString(yearAmount);
	fvBd.setYears(yearInput);
	
	fvBd.InvestmentCalc();
	
	investStr = "$"+fvBd.getMonthlyInvest();
	futureValueStr = "$"+ fvBd.getFutureValue();
	rateStr = fvBd.getYearlyRate()+"%";
	
	//Prints out the investments
	JOptionPane.showMessageDialog(null, "Your name: " + fvBd.getName() + "\n" + "Invested amount: "
									+ investStr + "\n" + "Interest rate: " + rateStr
									+ "\n" + "Invested Years: " + fvBd.getYears() + "\n"
									+ "Future Value: " + futureValueStr + "\n");

	// User is able to exit or continue program
		String exit = JOptionPane.showInputDialog("Would you like to continue? (y/n) ");
		choice = exit;
			if(choice.equals("y"))
				choice = exit;
			else if (choice.equals("n")) 
					choice = exit;
			else {
				exit = JOptionPane.showInputDialog("Error, please choose the two option\n" +
						"y - To continue\n" + "n - To exit program");
				choice = exit;
				System.out.println(choice);
				}
	} while(!choice.equals("n"));
	JOptionPane.showMessageDialog(null,"Goodbye");
}
}

