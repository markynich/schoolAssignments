/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 5
Submission Date: 10:00pm, Wednesday 8/2/17
Brief Description: The class works similarly to MPGCalculator but with 
the exception of using JApplet. It prints out what outcome in JApplet.
**********************************************************************/


import java.awt.*;

import javax.swing.*;


public class MPGCalculatorApplet extends JApplet{ //to be able to use japplet
	MPGCalculator mpgCal = new MPGCalculator();
	public void init(){ //initializes what happens first

			mpgCal.insertInput(); // input for miles
			//mpgCal.printGallons(); //input for gallons
		
		}
	
public void paint (Graphics g){ //access the graphics of japplet
	super.paint(g);

	g.drawString("The miles per gallon is ", 30, 50); //prints out sentence in japplet
	g.drawString(String.valueOf(mpgCal.getMPG()), 50, 70);  //prints out mpg in japplet

}//end of main
}//end of program