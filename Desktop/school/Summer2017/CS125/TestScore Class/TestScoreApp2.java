/**********************************************************
Name: Mark-Nicholas Magsakay
Course: CS 125-01
Lab #: Lab 1 part 2
Submission Date: 10:00pm, Wed (6/28)
Brief Description: The code is made to run TestScore class and use
classes to get inputs of 3 tests and create an average of the 
three tests, but this time it gives a letter grade of the
average of whichever grade it lands on.
***********************************************************/



import java.util.Scanner; //to allow the use of user input

class TestScores2 //start of class TestScores2
{
	public static void main(String[] args) //start of main
	{
		int testscore1; //integar of test1 score
		int testscore2; //integar of test2 score
		int testscore3; //integar of test3 score
		double average; //double integar of average scores
		String input;   // a string to use for user inputs
		
		//to start up user input with access of keyboard
		Scanner keyboard = new Scanner(System.in); 
		
		System.out.println("Enter first test score: ");
		input = keyboard.nextLine(); //to add input of user to nextline
		testscore1 = Integer.parseInt(input);
		
		System.out.println("Enter second test score: ");
		input = keyboard.nextLine(); //to add input of user to nextline
		testscore2 = Integer.parseInt(input);
		
		System.out.println("Enter third test score: ");
		input = keyboard.nextLine(); //to add input of user to nextline
		testscore3 = Integer.parseInt(input);
		
		//function for average of all three test scores
		average = ((testscore1 + testscore2 + testscore3)/3);
		
		//if functions to determine which grade the average belongs to
		if (average >=90 && average <=100) {
			System.out.println("Average of the test scores is ");
			System.out.print(average); //to print out average score
			System.out.println(" In Which the Grade is an A");
		}
		else if (average >=80 && average <=90)	{
			System.out.println("Average of the test scores is ");
			System.out.print(average); //to print out average score
			System.out.println(" In Which the Grade is a B");
		}
		else if (average >=70 && average <=80)	{
			System.out.println("Average of the test scores is ");
			System.out.print(average); //to print out average score
			System.out.println(" In Which the Grade is a C");
		}
		else if (average >=60 && average <=70)	{
			System.out.println("Average of the test scores is ");
			System.out.print(average); //to print out average score
			System.out.println(" In Which the Grade is a D");
		}
		else if  (average >=50 && average <=60)	{
			System.out.println("Average of the test scores is ");
			System.out.print(average); //to print out average score
			System.out.println(" In Which the Grade is a F");
		}
		//If the grade is below 50%, it will just print out the average.
		else	{
			
			System.out.println("Average of the test scores is ");
			System.out.print(average); //to print out average score
		}
			System.exit(0); //ends the program
	} //end of main
} //end of program