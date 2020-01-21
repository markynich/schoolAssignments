
/*********************************************************************
Name: Patrick, Kerolles, Mark, Denna
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 5/9/18
Brief Description: This class has holds the scores and numbers needed
for the GUI. It randomizes the numbers and sums for the equations
that the user must solve. As user answers equations, their score updates
and stores inside this class.
**********************************************************************/

package MathGame;
import java.util.*;
public class mathGame extends LoadFile
{
	
	private int highScore, a, b, sum;
	private String name;
	Random rnd = new Random(); //to randomize our numbers
	Scanner user = new Scanner(System.in); //user input
	
	/*
	 * Getters and Setters
	 */
	public int getHighScore() {return highScore;}
	public void setHighScore(int highScore) { this.highScore += highScore;}
	public void resetHighScore(int highScore) {this.highScore = highScore;}
	public int getA() {return a;}
	public int getB() {return b;}
	public String getName() {return name;}
	public void setName(String name) {this.name = name;}
	public void setA(int a) 
	{
		a = rnd.nextInt(100);
		this.a = a;
	}
	public void setB(int b) 
	{
		b = rnd.nextInt(100);
		this.b = b;
	}
	public int getSum() {
		return sum;
	}
	public void setSum(int sum) {
		sum = a+b;
		this.sum = sum;
	}
	/*
	 * Method to randomize the numbers for the equation
	 */
	public void randomize()
	{
		setB(1);
		setA(1);
		setSum(1);
	}
}

