
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program contains the class that creates the volume
of a rectangle. It contains methods to create the volume and overload toString.
**********************************************************************/

public class RectangleVolume extends Inheritance{

	//constructor that sets the height, width, and length 
	public void rectVolume(double x, double y, double z)
	{
		//Sets the height
		setHeight(x);
		//Sets the width
		setWidth(y);
		//Sets the length
		setLength(z);
		//Creates the volume
		double generator = (getHeight()*getWidth()*getLength());
		setVolume(generator);

	}
	//overloaded toString
	public String toString()
	{
	  String transformation = Double.toString(getVolume());
	  return "Volume of a rectangle is: " + transformation + "\n";
	}
	
	
}












