/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 2
Submission Date: 7:00pm, Thursday 7/6/17
Brief Description: This program is the back bone of AreaComputingApp.java.
It contains all the information needed to run the program and holds all
the information for the program.
**********************************************************************/

import java.util.Scanner;	//user's input and to use a method
public class AreaComputing { //start of program
	/*	This is a private container for units of all
	 *  the shapes which can only be accessed through
	 *  this class.
	 */
	private double circle;
	private double cylinder;
	private int rectangle;
	private int length;
	private int width;
	private double radius1;
	private double radius2;
	private double height;
	private double pie = 3.14;
	//method for using the user's input
	Scanner userInput = new Scanner(System.in);
	
	//default constructor for using the class in the main program
	public  AreaComputing(){}; //default constructor
	//overload constructor for accessing private
	public AreaComputing(double cylinder, double circle, int rectangle,
						 double radius1, double height, double pie,
						 int length, int width, double radius2)
	{
		this.circle = circle;
		this.cylinder = cylinder;
		this.rectangle = rectangle;
		this.radius1 = radius1;
		this.height = height;
		this.pie = pie;
		this.length = length;
		this.width = width;
		this.radius2 = radius2;
	}//end of AreaComputing Overload
	/*
	 * This is where all the setters and getters are
	 * for all units and be able to be used in 
	 * the main program. It can set the measurement
	 * and also grab the measurement that was set.
	 */
	public double getCircle() {
		return circle;
	}

	public void setCircle(double circle) {
		this.circle = circle;
	}

	public double getCylinder() {
		return cylinder;
	}

	public void setcylinder(double cylinder) {
		this.cylinder = cylinder;
	}

	public int getRectangle() {
		return rectangle;
	}

	public void setRectangle(int rectangle) {
		this.rectangle = rectangle;
	}

	public double getRadius1() {
		return radius1;
	}

	public void setRadius1(double radius1) {
		this.radius1 = radius1;
	}
	
	public double getHeight() {
		return height;
	}

	public void setheight(double height) {
		this.height = height;
	}

	public double getPie() {
		return pie;
	}

	public void setPie(double pie) {
		this.pie = pie;
	}

	public int getLength() {
		return length;
	}

	public void setLength(int length) {
		this.length = length;
	}

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public double getRadius2() {
		return radius2;
	}

	public void setRadius2(double radius2) {
		this.radius2 = radius2;
	}
	/*
	 * Functions for getting the area of the shapes.
	 * It uses the measurements that are stored in this
	 * program and uses it to get the areas.
	 */
	public double getAreaOfCircle(){
		return circle = pie*radius1*radius1;
	}
	
	public double getAreaOfCylinder(){
		return cylinder = pie*radius2*radius2*height;
	}
	
	public int getAreaOfRectangle(){
		return rectangle = width*length;
	}
	//to end the scanner program.
	public void quitScanner()
	{
		userInput.close();
	}
	
}//end of program
