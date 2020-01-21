/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 7/19/17
Brief Description: The class for printing out the output for Testscores.java
and it is the driver class for both TestScores and InvalidTestScore.
**********************************************************************/


import java.util.Scanner;


public class TestScoreApp {

	public static void main(String[] args) throws Exception { //start of main 

		int x=0;   
	    TestScores score = new TestScores(); //function to call class TestScores
	    
	    // Create a scanner for keyboard input.
	    Scanner userInput = new Scanner(System.in); //allows to start up scanner
	    do {
	    try {
	    System.out.println("Enter test score one: ");
	    score.setScore1(userInput.nextDouble()); //to put user input into score1
	    score.failTest1();
	    
	    System.out.println("Enter test score two: ");
	    score.setScore2(userInput.nextDouble());	//to put user input into score2
	    score.failTest2();
	    
	    System.out.println("Enter test score three: ");
	    score.setScore3(userInput.nextDouble());	//to put user input into score3
	    score.failTest3();
	    score.gradeFunction();
	    System.out.println("Would you like to continue the program?\n" 
	                       + " (yes = 0)/(no = 1)");
	    x=userInput.nextInt();
	    }
	    catch (InvalidTestScore e) {
	    	System.out.println(e.getMessage());
	    }
	    } while (x==0);
	    System.exit(0);

		} //end of main
}
