/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description:  This class contains the methods for Sphere class. 
Also contains functions to make the area and volume for Sphere.
**********************************************************************/





public class Sphere extends Circle
{
	// the default constructor
	public Sphere() { super(); }
	// overloaded constructor which sets the radius
	public Sphere(double radius) { super(radius); }
	// computes the area
	public void computeArea()
	{
		super.computeArea();
		area = 4 * area;
	}
	// computes the volume
	public void computeVolume()
	{
		super.computeArea();
		volume = (4 * radius * area) / 3;
	}
}
