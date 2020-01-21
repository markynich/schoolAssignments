/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This class contains the methods for Circle class
 and overload for toString(). Also contains functions to make the
 area for circle.
**********************************************************************/



public class Circle extends CircleShape2
{
	protected double area, volume;
	//default constructor
	public Circle()
	{
		super();
		area = 0;
		volume = 0;
	}
	// overloaded constructor which sets the radius for circle
	public Circle(double radius) { super(radius); }
	// computes the area for Circle
	public void computeArea()
	{
		area = Math.PI * radius * radius;
	}
	// returns the area of circle
	public double getArea() { return area; }
	// Circle cannot have a volume so it will return 0
	public void computeVolume() {}
	
	public double getVolume() { return volume; }
	// overrides the toString method
	public String toString()
	{
		return super.toString() + "Area: " + area + "\n";
	}
}
