/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 2
Submission Date: 7:00pm, Thursday 7/6/17
Brief Description: This program is the back bone of SumofNumberApp.java
It contains all the information for running the program and stores all
the information in ths program as well.
**********************************************************************/

import java.util.Scanner; //user can add input into the program
public class SumOfNumber {
		//private integers to get retain information for program
		private int number;
		private int sum;
		//method to use the user's input
		Scanner userInput = new Scanner(System.in);



	public SumOfNumber(){};  //default constructor
	/*
	 * It can getters and setters which allows the program to access
	 * the private integers so that it can store and set the information
	 * and then use it for the main program
	 */
	
	public int getNumber() {
		return number;
	}
	public int getSum() {
		return sum;
	}
	public void setSum(int sum) {
		this.sum = sum;
	}
	public void setNumber(int number) {
		this.number = number;
	}
	
	/* a function to get the sum of numbers and
	 * can be called into the main program
	 */
	public int getSumNumbers()
	{
		return sum = sum+getNumber();
	}
	public void quitScanner()
	{
		userInput.close();
	}
} //end of SumofNumber
