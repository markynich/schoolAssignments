/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description:  This class contains the methods for Cone class
 and overload for toString(). Also contains functions to make the
 area and volume for cone.
**********************************************************************/




public class Cone extends Circle
{
	protected double height;
	//default constructor
	public Cone()
	{
		super();
		height = 0;
	}
	// overloaded constructor that sets the height and radius
	public Cone(double radius, double h)
	{
		super(radius);
		height = h;
	}
	// computes the area
	public void computeArea()
	{
		area = Math.PI * getRadius() * (getRadius() + Math.sqrt((height * height) + (getRadius() * getRadius())));
	}
	// computes the volume
	public void computeVolume()
	{
		volume = Math.PI * (radius * radius) * (height / 3);
	}
	// overrides the toString
	public String toString()
	{
		return super.toString() + "Area: " + area + "\n Volume: " + volume;
	}
}
