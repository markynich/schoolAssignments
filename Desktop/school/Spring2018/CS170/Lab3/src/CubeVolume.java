
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program contains the class that creates the volume
of a cube. It contains methods to create the volume and overload toString.
**********************************************************************/

public class CubeVolume extends Inheritance{

	//constructor which sets the length
	public void Volume(double x) 
	{
		//Set length
		setLength(x);
		//create the volume for cube.
		double generator = (getLength()*getLength()*getLength());
		//Set the volume of cube to be printed out later
		setVolume(generator);
		
	}
	//overloaded toString Method
	public String toString()
	{
	  String transformation = Double.toString(getVolume());
	  return "Volume of a cube is: " + transformation + "\n";
	}
}
