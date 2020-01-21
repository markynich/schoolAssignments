
/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 7/19/17
Brief Description: The class for making the exception when errors occur
which this class is used to print out the errors that occured.
**********************************************************************/

public class InvalidTestScore extends Exception{
	public InvalidTestScore(double n)
	{
		super ("Error: Test Scores cannot be less than 0 and greater than 100 like: " +n);
	}
}
