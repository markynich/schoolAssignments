/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This abstract class contains doubles and methods needed
to create a grid. Also has a overloaded toString().
**********************************************************************/




public abstract class Shape
{
	//Doubles for a grid
	protected double x1;
	protected double y1;
	protected double x2;
	protected double y2;
	// default constructor
	public Shape() {}
	// overrides the toString method
	public String toString()
	{
		String message = "(" + x1 + "," + y1 + "), (" + x2 + "," + y2 + ")\n";
		return message;
	}
	//abstract methods
	public abstract void computeArea();
	public abstract void computeVolume();
	public abstract double getArea();
	public abstract double getVolume();
}
