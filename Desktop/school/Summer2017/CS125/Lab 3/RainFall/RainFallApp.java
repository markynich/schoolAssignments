/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 7/12/17
Brief Description: The driver class for Rainfall class. It executes 
the program for the output of the classes and allows input of the
user to determine which month rain the most and etc.
**********************************************************************/

import java.util.Scanner;
import java.text.DecimalFormat;

public class RainFallApp {
	
	public static void main(String[]args) {
	final int maxMonths = 12;
	double totalRainfall;
	double averageRainfall;
	int monthOfMostRain;
	int monthOfLeastRain;
	
	//array for rainfall
	double[] rainfallInYear = new double[maxMonths];
	
	//array for months in a year
	String months[] = {"January","February","March","April","May",
						"June","July","August","September",
						"October","November","December"};
	/* Get monthly rainfall in a year by calling getRainfallValues method
	 * creating an object for Rainfall class and an object for
	 * DecimalFormat class
	 */
	
	//call getRainfallValues method
	getRainfallValues(rainfallInYear, months);
	//create an object for RainFall class
	
	RainFall rainInYear = new RainFall(rainfallInYear);
	
	//create an object for DecimalFormat class
	DecimalFormat decimals = new DecimalFormat("0.00");
	
	//display the total rainfall in the year
	totalRainfall = rainInYear.getTotalRainfall();
	System.out.println("The total rainfall in the year: " + decimals.format(totalRainfall));
	
	//display the average rainfall in the year
	averageRainfall = rainInYear.getAverageRainfall();
	System.out.println("The average rainfall in the year: " + decimals.format(averageRainfall));
	
	//display the month with most rain
	monthOfMostRain = rainInYear.getMonthOfMostRainfall();
	System.out.println("The month with the most rain: " +rainfallInYear[monthOfMostRain]+ " in "
						+ months[monthOfMostRain]);
	
	//display the month with the least rain
	monthOfLeastRain = rainInYear.getMonthOfLeastRainfall();
	System.out.println("The month with the least rain: " +rainfallInYear[monthOfLeastRain]+ " in "
						+ months[monthOfLeastRain]);
	
		} //end of main
	public static void getRainfallValues(double[] rainfallInEachMonth, String[] monthNames) {
		//create an object for Scanner class
		Scanner userInput = new Scanner(System.in);
		//get the rain in every month
		
		for(int i=0; i< rainfallInEachMonth.length; i++) {
			//prompt the user for rainfall in a month
			System.out.println("Enter the total rainfall in the month of " + monthNames[i]+": ");
			rainfallInEachMonth[i] = userInput.nextDouble();
			
			//verify whether the rain in the month is negative
			
			while(rainfallInEachMonth[i]<0) {
				
					System.out.print("Enter a positive value for rainfall: ");
					rainfallInEachMonth[i] = userInput.nextDouble();
				
				} //end of while
			} //end of for 
			
		System.out.println();
	} //end of static void
	
} //end of program
