/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 5
Submission Date: 10:00pm, Wednesday 8/2/17
Brief Description: The class for showing an exception if an input of gallons
and miles are less and zero which throws in an exception and restarts program.
**********************************************************************/


@SuppressWarnings("serial")
public class InvalidMPGApplet extends Exception{ //makes sure it catches exceptions
	public InvalidMPGApplet(double n)
	{
		super ("Error: Input must be higher than 0 " +n); //error message
	}
}