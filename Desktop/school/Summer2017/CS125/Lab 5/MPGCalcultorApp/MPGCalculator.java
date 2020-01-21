/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 5
Submission Date: 10:00pm, Wednesday 8/2/17
Brief Description: The class for storing all the information and methods
needed to run the driver class MPGCalculatorApp.
**********************************************************************/


import javax.swing.JOptionPane; //importing GUI
public class MPGCalculator {
	
	/*
	 *  private variables and non private variables to contain information
	 *  such as miles and gallons and the input of the user. Also the 
	 *  integer x is for looping the program.
	 */
	private double miles;
	private double gallons;
	String input;
	int x = 1;
	
public MPGCalculator(){};

public MPGCalculator(double miles, double gallons){
	
	this.miles = miles;
	this.gallons = gallons;
	
}

// the start of mutators
public double getMiles() { //to get the Miles
	return miles;
}

public void setMiles(double miles) { //to set the Miles
	this.miles = miles;
}

public double getGallons() { //to get the Gallons
	return gallons;
}

public void setGallons(double gallons) { //to set the Gallons
	this.gallons = gallons;
};

public double getMPG() { //method to get the miles per gallon
	
	return (miles/gallons);
	
};

public void failMiles() throws InvalidMPG{ //exception for numbers less than 0
	if (miles < 0)
		throw new InvalidMPG(miles);
	else
		;
};

public void failGallons() throws InvalidMPG{ //exception for numbers less than 0
	if (gallons < 0)
		throw new InvalidMPG(miles);
	else
		;
}

//main method for the program
public void MPGMethod() {
	
	do{
		try{
			input = JOptionPane.showInputDialog("Enter the miles driven: ");
			setMiles(Double.parseDouble(input)); //sets input
			failMiles();
			
			input = JOptionPane.showInputDialog("Enter the gallons used: ");
			setGallons(Double.parseDouble(input)); //sets input
			failGallons();
			
			JOptionPane.showMessageDialog(null, "The miles per gallon is " + getMPG());
			x=2; //to make sure the program ends
		}
		catch(Exception e) { //catches exception such as letters
			JOptionPane.showConfirmDialog(null, "Enter a correct number");
		};// do while end
	}while(x==1); //to continue if any exception occurs
};

}
