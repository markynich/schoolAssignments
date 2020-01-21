/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 7/12/17
Brief Description: The class for making storing the information and giving
the information that the driver class will be calling. It also demonstrates
the use of arrays.
**********************************************************************/



public class RainFall {
	//variable declarations
	private double[] rainInYear;
	/* The following parameterized constructor creates an array to store rainfall
	 * in each month and store the specified rainfall
	 */
	public RainFall(double[] rainfallInEachMonth) {
		//creates an array to store rainfall in each month
		rainInYear = new double[rainfallInEachMonth.length];
		
		//store the rainfall
		for(int i=0; i< rainfallInEachMonth.length; i++)
			rainInYear[i] = rainfallInEachMonth[i];
	} //end of 	public RainFall(double[] rainfallInEachMonth) {
	public double getTotalRainfall() {
		//local variable
		double totalRainfall = 0.0;
		
		//calculate the total rainfall in the year
		for(int i=0; i< rainInYear.length; i++)
		totalRainfall += rainInYear[i];
		//return the total rainfall
		return totalRainfall;
	} // end of 	public double getTotalRainfall()
	public double getAverageRainfall() {
		//local variable
		double averageRainfall = 0.0;
		//calculate the average rainfall in the year
		averageRainfall = getTotalRainfall() / rainInYear.length;
		//return the average rainfall;
		return averageRainfall;
		
	}//end of public double getAverageRainfall()
	public int getMonthOfMostRainfall() {
		//local variable
		double most;
		int monthNumber;
		//initialize the variables
		most = rainInYear[0];
		monthNumber = 0;
		//repeat the loop to find the month of the most rainfall
		for (int i=1; i< rainInYear.length; i++) {
			//find the most rainfall
			if (rainInYear[i] > most) {
				most = rainInYear[i];
				monthNumber =i;
				} //end of if
			} // end of for
		return monthNumber;
		} //end of public int getMonthOfMostRainfall()
	public int getMonthOfLeastRainfall() {
		double least;
		int monthNumber;
		least = rainInYear[0];
		monthNumber = 0;
		//repeat the loop to find the month of the least rainfall
		for (int i=1; i< rainInYear.length; i++) {
				//find the least rainfall
				if (rainInYear[i] < least) {
					least = rainInYear[i];
					monthNumber =i;
			} //end of if
		} // end of for
		return monthNumber;
	} // end of public int getMonthOfLeastRainfall()
	
} //end of program
