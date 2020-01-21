/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 1
Submission Date: 10:00pm, Tuesday 2/20/18
Brief Description: This program contains functions and methods that are
made for the program Conversions. It's functions are for the ConversionApp
driver class to run. Also contains containers to hold information.
**********************************************************************/


import java.util.Scanner;	//enable the use of Scanner function
import java.text.*;

//Start of construction
public class Conversion 
{
	/*	This holds information for temperatures of
	 *  celsius and fahrenheit which can be accessed
	 *  through this class's methods of getters and setters.
	 *  Also contains strings to change the information within
	 *  the program.
	 */
	private double celsius;
	private double fahrenheit;
	
	Scanner scanner = new Scanner(System.in); //To be able to use Scanner function
	String exit = "n"; //to end program
	String user = ""; //to start function
	public int input; //to use input of user
	
	/*
	 * Round the conversion into smaller decimal format
	 */
	DecimalFormat df = new DecimalFormat("#####.#");
	
	public Conversion(){}; //default constructor
	

	public Conversion(double celsius, double fahrenheit)
	{
		this.celsius = celsius;
		this.fahrenheit = fahrenheit;
	} // overload constructor
	/*
	 * Start of functions for Conversion Class
	 *
	 */
	public double getCelsius()
	{
		return celsius;
	}
	public void setCelsius(double celsius)
	{
		this.celsius = celsius;
	}
	public double getFahrenheit()
	{
		return fahrenheit;
	}
	public void setFahrenheit(double fahrenheit)
	{
		this.fahrenheit = fahrenheit;
	}

	/*
	 * These functions are to conversions for Celsius to Fahrenheit
	 * and Fahrenheit to Celsius.
	 */
	public double getCelsiusConversion()
	{
		return ((celsius*1.8) + 32);
	}
	public double getFahrenheitConversion()
	{
		return ((fahrenheit-32)/ 1.8);
	}
	//function to end scanner
	public void quitScanner()
	{
		scanner.close();
	}

} //end bracket of Conversion.java


















