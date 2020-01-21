/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 2
Submission Date: 7:00pm, Thursday 7/6/17
Brief Description: This program is made to count the summation of
positive numbers and makes sure the number that the user inputed 
is definitely positive. Or else it will ask the user again.
**********************************************************************/
import java.util.Scanner; //To use user input
public class SumOfNumberApp { //start of program

	public static void main(String[] args){ //start of main program

		//method to use the user's input
		Scanner userInput = new Scanner(System.in);
		
		//to access the class SumOfNumber
		SumOfNumber sumOfNumber = new SumOfNumber();
		
		
			
			System.out.println("Please enter a positive integer:");
			//user's input of a positive integer to be used
			sumOfNumber.setNumber(userInput.nextInt());
			// To make sure it is a positive input
			if (sumOfNumber.getNumber() < 0)
			{	
				System.out.println("Error, please enter a positive integer:");
				sumOfNumber.setNumber(userInput.nextInt());

			}
			/* A for loop to make sure it is a positive number
			 * so that it can run in the program
			 */
			for (int n = 0; n <= sumOfNumber.getNumber(); n++ )
			{
				sumOfNumber.getSumNumbers();
			}
		//The final result of the program
	System.out.println( "The sum of numbers from 1 to " + sumOfNumber.getNumber() + " is " + ((sumOfNumber.getSum())/2));

	System.out.println("End of Program");
	userInput.close(); //to close the scanner
	sumOfNumber.quitScanner();
		} //End of Main Program
	 
} //End of SumofNumberApp
