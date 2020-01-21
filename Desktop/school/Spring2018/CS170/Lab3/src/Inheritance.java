
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program is a class that contains important
methods and doubles that other classes will use.
**********************************************************************/


public class Inheritance 
{
	//doubles for all classes
	private double width;
	private double length;
	private double height;
	private double volume;
	private double area;
	private double surfaceArea;

	//default constructor
	public Inheritance(){}
	//overloaded constructor
	public Inheritance(double width, double length, double height,
						double volume, double area, double surfaceArea)
	{
		this.width = width;
		this.length = length;
		this.height = height;
		this.volume = volume;
		this.area = area;
		this.surfaceArea = surfaceArea;
	}
	/*
	 * All the setters and getters for
	 * the program to access all information
	 */
	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	public double getHeight() {
		return height;
	}

	public void setHeight(double height) {
		this.height = height;
	}

	public double getVolume() {
		return volume;
	}

	public void setVolume(double volume) {
		this.volume = volume;
	}

	public double getArea() {
		return area;
	}

	public void setArea(double area) {
		this.area = area;
	}

	public double getSurfaceArea() {
		return surfaceArea;
	}

	public void setSurfaceArea(double surfaceArea) {
		this.surfaceArea = surfaceArea;
	}
	
	
	
}
