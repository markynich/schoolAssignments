
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program is the driver class for the program.
It uses methods to use other classes.
**********************************************************************/


public class InheritanceApp 
{
	public static void main(String[] args)
	{
		//Methods to use other classes
		RectangleArea rArea = new RectangleArea();
		RectangleSurfaceArea rsArea = new RectangleSurfaceArea();
		RectangleVolume rVolume = new RectangleVolume();
		CubeVolume cVolume = new CubeVolume();
		
		System.out.println("\nAreas and Volumes of Rectangle and Cube:\n");
		//sets lengths, heights, etc for objects
		rArea.rectArea(4,8);
		rsArea.rectSurfaceArea(12, 10, 8);
		rVolume.rectVolume(3.5,8,4.5);
		cVolume.Volume(7);
		//prints out areas and volumes
		System.out.println("\n" + rArea.toString());
		System.out.println(rsArea.toString());
		System.out.println(rVolume.toString());
		System.out.println(cVolume.toString());
	}
	
}
