
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program is the driver class
for the 3 quizzes the user can take. This class uses all the information
from other classes to run.
**********************************************************************/

//To be able to use the input of users
import java.util.Scanner;
public class CanSwimApp 
{
	
	public static void main(String args[])
	{
		//Methods to use the input of the users.
		Scanner scanner = new Scanner(System.in);
		Scanner scanner2 = new Scanner(System.in);
		int choice = 0;
		String guess = "";
		//count how many tries the user takes
		int counter = 0;
		//method to use the SomeOne class
		SomeOne guessWho = new SomeOne();
		guessWho.Start();
		guessWho.menu();
		choice = scanner.nextInt();
		/*
		 * While loop to correct user if he/she does not choose
		 * a correct option
		 */
		while (choice > 3 || choice < 1)
		{
			System.out.println("Error, must choose a correct option");
			guessWho.menu();
			choice = scanner.nextInt();
		}
			/*
			 * Start of Quiz #1
			 * Quiz uses if and else statements for when the user
			 * is correct or wrong. They have four tries to guess
			 * correctly, they will get 3 clues within the quiz.
			 * a new clue each time they get it wrong. After four tries,
			 * they lose and get to find out the correct answer.
			 */
		
			if(choice == 1)
			{
				System.out.println("Welcome to Quiz #1\n"
						+ "First clue:");
				guessWho.swim();
				guess = scanner2.nextLine();
				counter++;
				if (guess.equals("fish"))
					System.out.println("Correct!\n"
							+ "It took " + counter +" tries");
				else
				{
					System.out.println("Wrong, next clue:");
					guessWho.breathe();
					guess = scanner2.nextLine();
					counter++;
					if (guess.equals("fish"))
						System.out.println("Correct!\n"
								+ "It took " + counter +" tries");
					else
					{
						System.out.println("Wrong, final clue:");
						guessWho.looks();
						guess = scanner2.nextLine();
						counter++;
						if (guess.equals("fish"))
							System.out.println("Correct!\n"
									+ "It took " + counter +" tries");
						else
						{
							System.out.println("Wrong, final try: \n");
							guess = scanner2.nextLine();
							counter++;
							if (guess.equals("fish"))
								System.out.println("Correct!\n"
										+ "It took " + counter +" tries");
							else
							{
								System.out.println("Wrong! Correct Answer was fish.\n"
										+ "you had " + counter + " tries.");
							}
						}
					}
				}
			}
			/*
			 * Start of Quiz #2
			 * Quiz uses if and else statements for when the user
			 * is correct or wrong. They have four tries to guess
			 * correctly, they will get 3 clues within the quiz.
			 * a new clue each time they get it wrong. After four tries,
			 * they lose and get to find out the correct answer.
			 */
			if (choice == 2)
			{
				System.out.println("Welcome to Quiz #2\n"
						+ "First clue:");
				guessWho.fly();
				guess = scanner2.nextLine();
				counter++;
				if (guess.equals("airplane"))
					System.out.println("Correct!\n"
							+ "It took " + counter +" tries");
				else
				{
					System.out.println("Wrong, next clue:");
					guessWho.gas();
					guess = scanner2.nextLine();
					counter++;
					if (guess.equals("airplane"))
						System.out.println("Correct!\n"
								+ "It took " + counter +" tries");
					else
					{
						System.out.println("Wrong, final clue:");
						guessWho.transportation();
						guess = scanner2.nextLine();
						counter++;
						if (guess.equals("airplane"))
							System.out.println("Correct!\n"
									+ "It took " + counter +" tries");
						else
						{
							System.out.println("Wrong, final try: \n");
							guess = scanner2.nextLine();
							counter++;
							if (guess.equals("airplane"))
								System.out.println("Correct!\n"
										+ "It took " + counter +" tries");
							else
							{
								System.out.println("Wrong! Correct Answer was airplane.\n"
										+ "you had " + counter + " tries.");
							}
						}
					}
				}
			}
			/*
			 * Start of Quiz #3
			 * Quiz uses if and else statements for when the user
			 * is correct or wrong. They have four tries to guess
			 * correctly, they will get 3 clues within the quiz.
			 * a new clue each time they get it wrong. After four tries,
			 * they lose and get to find out the correct answer.
			 */
			if (choice == 3)
			{
				System.out.println("Welcome to Quiz #3, Let's Begin\n"
						+ "First clue:");
				guessWho.walk();
				guess = scanner2.nextLine();
				counter++;
				if (guess.equals("wolf"))
					System.out.println("Correct!\n"
							+ "It took " + counter +" tries");
				else
				{
					System.out.println("Wrong, next clue:");
					guessWho.hunt();
					guess = scanner2.nextLine();
					counter++;
					if (guess.equals("wolf"))
						System.out.println("Correct!\n"
								+ "It took " + counter +" tries");
					else
					{
						System.out.println("Wrong, final clue:");
						guessWho.pack();
						guess = scanner2.nextLine();
						counter++;
						if (guess.equals("wolf"))
							System.out.println("Correct!\n"
									+ "It took " + counter +" tries");
						else
						{
							System.out.println("Wrong, final try: \n");
							guess = scanner2.nextLine();
							counter++;
							if (guess.equals("wolf"))
								System.out.println("Correct!\n"
										+ "It took " + counter +" tries");
							else
							{
								System.out.println("Wrong! Correct Answer was wolf.\n"
										+ "you had " + counter + " tries.");
							}
						}
					}
				}
			}
		//to close user input methods
		scanner.close();
		scanner2.close();
	}
}
