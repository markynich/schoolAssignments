/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 7/12/17
Brief Description:
**********************************************************************/

public class ProductionWorker extends Employee {
	//constant declarations
	public final int noShift = 0;
	public final int dayShift = 1;
	public final int nightShift = 2;
	
	//data fields
	private int shift;
	private double hourlyPayRate;
	
	//default constructor implementation
	public ProductionWorker()
	{
		super();
		shift = noShift;
		hourlyPayRate = 0.0;
	} //end of default constructor
	
	//parameter constructor implementation
	public ProductionWorker(String employName, String employNumber, String date,
							int sh, double rate)
	{
		super(employName, employNumber, date);
		setShift(sh);
		setHourlyPayRate(rate);
	} //end of parameter Production Worker constructor
	
	//accessor methods
	//getShift method implementation
	public int getShift()
	{
		return shift;
	} // end of getShift
	//getHourlyPayRate method implementation
	public double getHourlyPayRate()
	{
		return hourlyPayRate;
	} //end of getHourlyPayRate
	//mutator methods
	//setShift method implementation
	public void setShift(int sh)
	{
		if(sh == dayShift || sh == nightShift)
			shift = sh;
		else
			shift = noShift;
	} //end of setShift
	//setHourlyPayRate method implementation
	public void setHourlyPayRate(double rate)
	{
		hourlyPayRate = rate;
	} //end of setHourlyPayRate
	//toString method implementation
	public String toString()
	{
		String result = "";
		result = super.toString() + "\n";
		if (shift == dayShift)
			result += "Shift: Day\n";
		else if (shift == nightShift)
			result += "Shift: Night\n";
		else
			result += "Shift: Invalid\n";
			result += "Hourly pay rate: " + String.format("$%.2f", hourlyPayRate);
			return result;
	} //end of toString()
} //end of ProductionWorker Program
