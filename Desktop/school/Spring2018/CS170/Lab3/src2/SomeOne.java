
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This program contains two classes. One abstract class
and another class that has methods for the driver class.
**********************************************************************/

abstract class Action {
	//This method is for the introduction in the beginning of the program
	public void Start()
	{
		System.out.println("You get to choose from 3 different quizzes\n"
				+ "And you get 4 guesses before you lose");
	}
	//This method is for the options the user can choose from
	public void menu()
	{
	  System.out.println(" 1. Quiz #1\n"
	  					+" 2. Quiz #2\n"
	  					+" 3. Quiz #3");
	}
}
/*
 * this class Action and implements
 * the interfaces so that it can define
 * all the methods within the interfaces.
 */
public class SomeOne extends Action implements CanSwim, CanFly, CanWalk {
  //Clues for Fish
  public void swim() {
  	System.out.println("I like to swim, who am I?");
  }

  public void looks() {
	  System.out.println("I am in ocean, who am I?");
  }
  
  public void breathe() {
	  System.out.println("I cannot breathe air, who am I?");
  }
  
  //Clues for Airplane
  public void fly() {
  	System.out.println("I like to fly, what am I?");
  }
  
  public void gas() {
	  System.out.println("I use a lot of gas, what am I?");
  }
  
  public void transportation() {
	  System.out.println("A lot of people use me as transportation, what am I?");
  }
  
  //Clues for Wolf
  public void walk() {
  	System.out.println("I can walk on four feet, who am I?");
  }
  
  public void hunt() {
	  System.out.println("I like to hunt, who am I?");
  }
  
  public void pack() {
	  System.out.println("I travel in packs, who am I?");
  }
}