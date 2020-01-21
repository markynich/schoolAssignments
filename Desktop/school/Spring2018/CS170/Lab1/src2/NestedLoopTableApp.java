/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 1
Submission Date: 10:00pm Tuesday 2/20/18
Brief Description: This program is the driver class for
NestedLoopTable.java. It asks the user two numbers and it
prints out a table for the user.
**********************************************************************/
import java.util.*;

public class NestedLoopTableApp 
{
	
	public static void main(String[] args)
	{
		//method to use the scanner for program
		Scanner scanner = new Scanner(System.in);
		//To be able to use the nestedloop class
		NestedLoopTable nestedLoop = new NestedLoopTable();
		//start of Menu
		System.out.println("Welcome to Nested Loop Tables");
		System.out.println("Pleae enter a beginning number & ending number \n");
		//Do while loop for constant use for user to use until they quit
		do
		{
			System.out.println("Please Enter a beginning number");
			nestedLoop.setBegin(scanner.nextInt());
			System.out.println("\n Please Enter an ending number");
			nestedLoop.setEnd(scanner.nextInt());
			//method to put numbers in order and print out in a table
			if (nestedLoop.getBegin() < nestedLoop.getEnd())
			{ 
				System.out.println("\n Processing");
				int x,y;
				for(x=nestedLoop.getBegin(); x<=nestedLoop.getEnd(); x++)
				{
					System.out.println();
					for(y=nestedLoop.getBegin(); y<=x; y++)
						System.out.print(y + " ");
				}
				//user choice to continue of not
				System.out.println("\nWould you like to continue?");
				System.out.println("Press any key or 'n' to quit");
				scanner.nextLine();
				nestedLoop.user = scanner.nextLine();
			}
			else
			/*
			 * To catch errors if they do not enter the write input
			 */
			{
				System.out.println("    Error!    ");
				System.out.println("First number must be smaller than the second number");
			}
		}while(!nestedLoop.user.equals(nestedLoop.exit));
		System.out.println("Goodbye");
		scanner.close(); //closes user scanner
		
	}
		
}