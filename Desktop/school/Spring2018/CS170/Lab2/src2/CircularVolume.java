/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 2
Submission Date: 10:00pm, Wednesday 2/28/18
Brief Description: This program contains all the methods and functions
needed for the driver class CircularVolumeApp.java to run smoothly.
**********************************************************************/

import java.util.Scanner; //Importing user input ability

public class CircularVolume
{
	/*
	 * Private variables to store data
	 * inside and cannot be accessed unless
	 * through the class and methods. 
	 * Also contains a constant pi
	 * for the equations to get the volume
	 * of the objects
	 */
	private double radius;
	private double height;
	private double axis;
	final double pi = 3.14;
	public String input = "";
public CircularVolume() {} //constructor

//To be able to use and save the user's input
Scanner scanner = new Scanner(System.in);

//Overloaded constructor
public CircularVolume(double radius, double height, double axis)
{
	this.radius = radius;
	this.height = height;
	this.axis = axis;
}
/*
 * Getters and setters to store 
 * and grab data for the
 * program and cannot be accessed
 * except by these methods
 */
public double getRadius() {
	return radius;
}

public void setRadius(double radius) {
	this.radius = radius;
}

public double getHeight() {
	return height;
}

public void setHeight(double height) {
	this.height = height;
}

public double getAxis() {
	return axis;
}

public void setAxis(double axis) {
	this.axis = axis;
}

/*
 * Start of overloading methods for volumes
 * of each object: Sphere, Cylinder,
 * and Ellipsoid. Volume has a single name
 * but different parameters.
 */

//Volume of Sphere
public void Volume(double radius)
{
	System.out.println("Generating Volume of Sphere\n");
	//V=43πr3 equation reference
	double sphere = (((4/3)*pi)*(radius*radius*radius));
	System.out.println("Your Sphere has a volume of " + sphere
						+ "\n With a radius of " +radius);
}

//Volume of Cylinder
public void Volume(double radius, double height)
{
	System.out.println("Generating Volume of Cylinder\n");
	//V=πr2h equation reference
	double cylinder = pi * (radius*radius) * height;
	System.out.println("Your Cylinder has a volume of " + cylinder
						+ "\n With a radius of " + radius
						+ "\n And with a height of " + height);
}

//Volume of Ellipsoid
public void Volume(double radius, double height, double axis)
{
	System.out.println("Generating Volume of Ellipsoid\n");
	//V=(4/3)πabc equation reference
	double ellipsoid = (4/3) * pi * radius * height * axis;
	System.out.println("Your Ellipsoid has a volume of " + ellipsoid
						+ "\n With first axis of " + radius
						+ "\n and second axis of " + height
						+ "\n and third axis of " + axis);
}

} //end of program