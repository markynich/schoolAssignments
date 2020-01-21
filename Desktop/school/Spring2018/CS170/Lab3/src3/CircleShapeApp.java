/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This class is the driver class for the program.
It contains print out lines and functions to run the program properly.
**********************************************************************/


public class CircleShapeApp
{
	/*
	 * main function
	 */
	public static void main(String[] args)
	{
		System.out.println("This is a Generator for Area and Volume.\n"
				+ "of a Circle, Sphere, and Cone.\n"
				+ "Below will be all the Areas and Volumes.\n");
		
		
		//Methods for Circle, Sphere, and Cone
		Circle circle = new Circle(7.25);
		Sphere sphere = new Sphere(9.12);
		Cone cone = new Cone(5.24,12.5);

		//Circle, prints out the area and volume
		Shape shape = circle;
		shape.computeArea();
		System.out.println("Area of Circle: " + shape.getArea());
		shape.computeVolume();
		System.out.println("Volume of Circle: " + shape.getVolume());
		
		//Sphere, prints out the area and volume
		shape = sphere;
		shape.computeArea();
		System.out.println("\nArea of Sphere: " + shape.getArea());
		shape.computeVolume();
		System.out.println("Volume of Sphere: " + shape.getVolume());
		
		
		//Cone, prints out the area and volume
		shape = cone;
		shape.computeArea();
		System.out.println("\nArea of Cone: " + shape.getArea());
		shape.computeVolume();
		System.out.println("Volume of Cone: " + shape.getVolume());
	}
}
