
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program contains the class that creates the area
of a rectangle. It contains methods to create the area and overload toString.
**********************************************************************/

public class RectangleArea extends Inheritance
{
	//constructor that sets the length and width of the rectangle
	public void rectArea(double x, double y)
	{
		//Sets the length
		setLength(x);
		//Sets the width
		setWidth(y);
		//creates the area
		double generator = (getLength()*getWidth());
		setArea(generator);
	}
	//overloaded toString
	public String toString()
	{
	  String transformation = Double.toString(getArea());
	  return "Area of a rectangle is: " + transformation + "\n";
	}
	
}
