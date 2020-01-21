/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 2
Submission Date: 10:00pm, Wednesday 2/28/18
Brief Description: This program is the regular class for
the driver class FutureValueBigDecimalApp.Java
It contains functions and methods needed for the driver class to run
**********************************************************************/

//Libraries needed for the program
import java.util.*;
import java.text.*;
import java.math.BigDecimal;
import javax.swing.*;
//start of class
public class FutureValueBigDecimal 
{
	/*
	 * Holds string data that can only
	 * be accessed through methods and
	 * functions from within the class
	 */
	private String name, years,
			monthlyInvest, yearlyRate,
			futureValue;
	//variable called scanner to use user's input
	Scanner scanner = new Scanner(System.in);
	
	//default constructor and overload constructor
	public FutureValueBigDecimal(){};
	public FutureValueBigDecimal(String name, String years, String monthlyInvest, String yearlyRate, String futureValue)
	{
		this.name = name;
		this.years = years;
		this.monthlyInvest = monthlyInvest;
		this.yearlyRate = yearlyRate;
		this.futureValue = futureValue;
	}
	/*
	 * Getters and setters methods to store
	 * user's data and grab to use the data
	 * when needed. Only accessible through
	 * these methods
	 */
	public void setName(String name)
	{
		this.name = name;
	}
	public String getName()
	{
		return name;
	}
	public void setMonthlyInvest(String monthlyInvest)
	{
		this.monthlyInvest = monthlyInvest;
	}
	public String getMonthlyInvest()
	{
		return monthlyInvest;
	}
	public void setYears(String years)
	{
		this.years = years;
	}
	public String getYears()
	{
		return years;
	}
	public void setYearlyRate(String yearlyRate)
	{
		this.yearlyRate = yearlyRate;
	}
	public String getYearlyRate()
	{
		return yearlyRate;
	}
	public void setFutureValue(String futureValue)
	{
		this.futureValue = futureValue;
	}
	public String getFutureValue()
	{
		return futureValue;
	}
/*
 * Calculates the investment that the user will be
 * receiving. However, it is in Big Decimal instead
 * of regular Double code. It is in a for loop to calculate
 * the amount and store inside a private container
 */
	public void InvestmentCalc()
	{
		BigDecimal one = new BigDecimal("1");
		BigDecimal twelve = new BigDecimal("12");
		BigDecimal hundred = new BigDecimal("100");
		BigDecimal yearRate = new BigDecimal(yearlyRate);
		BigDecimal months = new BigDecimal(years);
		BigDecimal futureInvest = BigDecimal.ZERO;
		BigDecimal monthInvest = new BigDecimal(monthlyInvest);
		
		
		BigDecimal monthlyRate = yearRate.divide(twelve,1);
		monthlyRate = monthlyRate.divide(hundred,1);
		monthlyRate = monthlyRate.add(one);

		months = months.multiply(twelve);
		for (BigDecimal i = BigDecimal.ONE; i.compareTo(months) < 0; i = i.add(BigDecimal.ONE))
		{
			futureInvest = futureInvest.add(monthInvest);

			futureInvest = futureInvest.multiply(monthlyRate);

		}
		//Method to format the investment to three decimal places
		DecimalFormat df3 = new DecimalFormat("#.###");
		df3.format(futureInvest);
		setFutureValue(futureInvest.toString());
	}
	/*
	 * Menu function for the main driver class.
	 * It uses JOptionPane for the user to go through.
	 * It asked the user a few questions then calculates
	 * the investment for the user and asks the user
	 * if he/she wants to continue. 
	 */

}
	
	
	
