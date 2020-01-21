/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This abstract class contains functions for radius
that sets and gets radius for the objects. Also computes radius if it
is creating a grid. Program has overloaded toString().
**********************************************************************/




public abstract class CircleShape2 extends Shape
{
	
	protected double radius;

	//default constructor which sets the radius to 0
	public CircleShape2()
	{
		this.radius = 0;
	}
	//overloaded constructor to set the radius
	public CircleShape2(double radius) 
	{
		this.radius = radius;
	}
	//sets radius for other objects
	public void setRadius(double radius)
	{
		this.radius = radius;	
	}
	//gets the radius for other objects
	public double getRadius() { return radius; }
	// computes radius for grids
	public void computeRadius()
	{
		radius = Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	}
	// overrides the toString method
	public String toString()
	{
		return super.toString() + "Radius: " + radius + "\n";
	}
}
