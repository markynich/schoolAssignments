/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 2
Submission Date: 7:00pm, Thursday 7/6/17
Brief Description: This program runs the with AreaComputing.java.
It asks for measurements of a circle, rectangle, and a cylinder.
It will convert the measurements into the areas of the shapes.
**********************************************************************/

import java.util.Scanner;	//To use user input
public class AreaComputingApp { //beginning of program
	
	public static void main(String[] args) { //start of main 

		//method to use the user's input for program
		Scanner userInput = new Scanner(System.in);
		//method to use class AreaComputing for program
		AreaComputing areaComputing = new AreaComputing();

			/* To get the information needed to get the areas for
			 * circle, cylinder, and rectangle.
			 */
			System.out.println("Please enter the following measurements ");
			System.out.println("Please enter a radius for circle: ");
			areaComputing.setRadius1(userInput.nextDouble());
			System.out.println("Please enter a width for rectangle: ");
			areaComputing.setWidth(userInput.nextInt());
			System.out.println("Please enter a length for rectangle: ");
			areaComputing.setLength(userInput.nextInt());
			System.out.println("Please enter a height for cylinder: ");
			areaComputing.setheight(userInput.nextDouble());
			System.out.println("please enter a radius for cylinder: ");
			areaComputing.setRadius2(userInput.nextDouble());
			
			/*Now we will be printing out all the information
			 * in area of circle, rectangle, and cylinder
			 */
			System.out.println("This is the area of inputted circle: ");
			System.out.println(areaComputing.getAreaOfCircle());
			System.out.println("This is the area of the inputted rectangle: ");
			System.out.println(areaComputing.getAreaOfRectangle());
			System.out.println("This is the area of the inputted cylinder: ");
			System.out.println(areaComputing.getAreaOfCylinder());
			

		System.out.println("End of Program");
		userInput.close(); //to end scanner
		areaComputing.quitScanner(); 
	}//end of main
}//end of program
