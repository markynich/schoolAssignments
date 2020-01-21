/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 1
Submission Date: 10:00pm, Tuesday 2/20/18
Brief Description: This program is the driver class for Conversion.java.
It uses all the functions and methods within the class to run the program.
It uses the main function to start the program and enter a menu for the
user to use to convert temperatures.
**********************************************************************/
import java.util.*;

public class ConversionApp //start of program
{
	public static void main(String[] args)
	{
		//method to use the user's input for program
		Scanner scanner = new Scanner(System.in);
		//method to use class Conversion for program
		Conversion change = new Conversion();
		/*
		 * Start of menu
		 */
		System.out.println ("\n Celcius and Fahrenheit Conversion \n");
		System.out.println("Please choose a Conversion");
		System.out.println("----Enter a 1 or 2 for----\n");
		/*
		 * Do while loop for user to continuously use the menu and conversions
		 */
		do
		{
			System.out.println("1. Celsius to Fahrenheit");
			System.out.println("2. Fahrenheit to Celsius");
			change.input = scanner.nextInt();
			// Conversion from Celsius to Fahrenheit
			if(change.input == 1)
			{
				System.out.println("Enter a Celsius amount for conversion");
				change.setCelsius(scanner.nextDouble());
				System.out.println("Here is the conversion \n");
				System.out.print(change.getCelsius() + " C and " + change.df.format(change.getCelsiusConversion()) + " F \n");
				System.out.println("Any key to continue or 'n' to quit");
				scanner.nextLine();
				change.user = scanner.nextLine();
			}//end of Celsius conversion
			//Conversion from Fahrenheit to Celsius
			else if (change.input == 2)
			{
				System.out.println("Enter a Fahrenheit amount to convert");
				change.setFahrenheit(scanner.nextDouble());
				System.out.println("Here is the conversion \n");
				System.out.print(change.getFahrenheit() + " F and " + change.df.format(change.getFahrenheitConversion()) + " C \n");
				System.out.println("Any key to continue or 'n' to quit");
				scanner.nextLine();
				change.user = scanner.nextLine();
			}//end of Fahrenheit conversion
			//To catch error if user does not choose correct selection
			else
			{
				System.out.println("Error, wrong input.");
				System.out.println("Please choose a correct option");
			}
		}while(!change.user.equals(change.exit));
		System.out.println("\n GoodBye!");
		scanner.close(); //closes scanner
		change.quitScanner(); //closes scanner of Conversion.java
	}
	
} //end bracket of driver class ConversionApp.java
