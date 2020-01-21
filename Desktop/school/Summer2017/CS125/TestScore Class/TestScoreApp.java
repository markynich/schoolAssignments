/**********************************************************
Name: Mark-Nicholas Magsakay
Course: CS 125-01
Lab #: Lab 1
Submission Date: 10:00pm, Wed (6/28)
Brief Description: The code is made to run TestScore class and use
classes to get inputs of 3 tests and create an average of the 
three tests.
***********************************************************/

import java.util.Scanner; //allows the use of user input
public class TestScores { //beginning of class TestScores

    private double score1; //the private locations of scores 1-3
    private double score2;
    private double score3;

    public TestScores()	{  //default constructor to call class
    
    }
    
    public TestScores(double score1, double score2, double score3) {
        this.score1 = score1;
        this.score2 = score2;
        this.score3 = score3;
    }

    public void setScore1(double score) { //To set score input into score1
        score1 = score;
    }

    public void setScore2(double score) { //To set score input into score2
        score2 = score;
    }

    public void setScore3(double score) { //To set score input into score3
        score3 = score;
    }

    public double getScore1() { //to get and access score 1
        return score1;
    }

    public double getScore2() { //to get and access score 2
        return score2;
    }

    public double getScore3() { //to get and access score 3
        return score3;
    }

    public double getAverageScore() { //function to get average of the 3 scores
        return (score1 + score2 + score3) / 3;
    }
    //Main method
public static void main(String[] args) { //start of main 

   
    TestScores score = new TestScores(); //function to call class TestScores

    // Create a scanner for keyboard input.
    Scanner keyboard = new Scanner(System.in); //allows to start up scanner

    System.out.println("Enter test score one: ");
    score.score1 = keyboard.nextDouble(); //to put user input into score1
 
    System.out.println("Enter test score two: ");
    score.score2 = keyboard.nextDouble();	//to put user input into score2
  
    System.out.println("Enter test score three: ");
    score.score3 = keyboard.nextDouble();	//to put user input into score3
    // Display average
    System.out.println("The average test score is: ");
    System.out.print(score.getAverageScore()); //output of average

	} //end of main
} //end of program
