
/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 3/28/18
Brief Description: This class contains interfaces for other classes
to use which are needed for the 3 different quizzes the user
can take in the program.
**********************************************************************/
/*
 * Contains interfaces for the classes to user.
 * mainly methods that will be used for each quiz/
 */

//Interface for Fish
public interface CanSwim {
  void swim();
  void looks();
  void breathe();
}

//Interface for Airplane
interface CanFly {
  void fly();
  void gas();
  void transportation();
}

//Interface for Wolf
interface CanWalk {
  void walk();
  void hunt();
  void pack();
}
