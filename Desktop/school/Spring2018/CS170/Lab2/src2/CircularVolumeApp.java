
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 2
Submission Date: 10:00pm, Wednesday 2/28/18
Brief Description: This program is the driver class
for CircularVolume.java. It contains the main function
for the program to run. Also has options for the user to choose
to get volumes for certain objects. Program has the ability to 
quit or continue. Must be real numbers and no
negative numbers. 
**********************************************************************/

import java.util.Scanner;


public class CircularVolumeApp {
	
	//start of main
	public static void main(String[] args)
	{
		//Scanner for user input
	Scanner scanner = new Scanner(System.in);
		
	CircularVolume CircleVolume = new CircularVolume(); //To be able to use the functions and methods of CircularVolume
	System.out.println("Welcome to Volume Creator for Circular Objects\n");
	while (!CircleVolume.input.equals("n")) {
	System.out.println("--Please select an option--\n"+"1 - Sphere\n"+"2 - Cylinder\n"
						+"3 - Ellipsoid\n"+"n - Quit Program\n\n");
	CircleVolume.input = scanner.nextLine();
	//User enters 1, they are getting volume of Sphere
	if (CircleVolume.input.equals("1"))
		{
		System.out.println("Please enter a radius amount for a Sphere");
		double num = scanner.nextDouble();
		while(num < 1 || num > 1000000) {
			System.out.println("Error! Please enter a correct radius amount");
			num = scanner.nextDouble();
			}
		CircleVolume.setRadius(num);
		CircleVolume.Volume(CircleVolume.getRadius());
		System.out.println("\n");
		}
	//User enters 2, they are getting volume of Cylinder
	if (CircleVolume.input.equals("2"))
		{
		System.out.println("Please enter a radius amount for a Cylinder");
		double num = scanner.nextDouble();
		while(num < 1 || num > 1000000) {
			System.out.println("Error! Please enter a correct radius amount");
			num = scanner.nextDouble();
			}
		CircleVolume.setRadius(num);
		System.out.println("Please enter a height amount for a Cylinder");
		double num2 = scanner.nextDouble();
		while(num2 < 1 || num2 > 1000000) {
			System.out.println("Error! Please enter a correct height amount");
			num2 = scanner.nextDouble();
			}
		CircleVolume.setHeight(num2);
		CircleVolume.Volume(num,num2);
		System.out.println("\n");
		}
	//User enters 3, they are getting volume of Ellipsoid
	if (CircleVolume.input.equals("3"))
		{
		System.out.println("Please enter first axis amount for a Ellipsoid");
		double num = scanner.nextDouble();
		while(num < 1 || num > 1000000) {
			System.out.println("Error! Please enter a correct axis amount");
			num = scanner.nextDouble();
			}
		CircleVolume.setRadius(num);
		System.out.println("Please enter second axis amount for a Ellipsoid");
		double num2 = scanner.nextDouble();
		while(num2 < 1 || num2 > 1000000) {
			System.out.println("Error! Please enter a correct axis amount");
			num2 = scanner.nextDouble();
			}
		CircleVolume.setHeight(num2);
		System.out.println("Please enter second axis amount for a Ellipsoid");
		double num3 = scanner.nextDouble();
		while(num3 < 1 || num3 > 1000000) {
			System.out.println("Error! Please enter a correct axis amount");
			num3 = scanner.nextDouble();
			}
		CircleVolume.setAxis(num3);
		CircleVolume.Volume(num,num2,num3);
		System.out.println("\n");
		}
	//If user enter n, they quit the program
	if (CircleVolume.input.equals("n")) {
		System.out.println("Hope you had a good time");
		break;
		}
	//If user enters anything else, the program catches it and prints out this line
	  else  {
		System.out.println("Oh no, Error! \n Please Enter the correct choices\n");
		}
		
		}


	}
}

