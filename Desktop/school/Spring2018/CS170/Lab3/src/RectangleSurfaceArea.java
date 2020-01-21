
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program contains the class that creates the surface
area of a rectangle. It contains methods to create the surface area
and overload toString.
**********************************************************************/

public class RectangleSurfaceArea extends Inheritance
{
	//constructor that sets the length, width, and height
	public void rectSurfaceArea(double x, double y, double z)
	{
		
		//Sets length 
		setLength(x);
		//Sets width 
		setWidth(y);
		//Sets height 
		setHeight(z);

		//creates the surface area
		double generator = (2*((getWidth()*getLength())+
							(getHeight()*getLength())+
							(getHeight()*getWidth())));
		setSurfaceArea(generator);

	}
	//overloaded toString
	public String toString()
	{
	  String transformation = Double.toString(getSurfaceArea());
	  return "Surface area of rectangle is: " + transformation + "\n";
	}
}
