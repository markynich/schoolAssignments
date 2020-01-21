/*********************************************************************
Name:Denna Mae Basto
Course: CS170-01
Lab #: Lab 1
Submission Date: 10:00pm Tuesday 2/20/18
Brief Description: NestedLoopTable.java contains methods and
functions which runs and executes for NestedLoopTableApp.java
**********************************************************************/


import java.util.*;

public class NestedLoopTable 
{
	/*	This is a container of
	 *  ints and strings for the class to use
	 *  They are to store and access through the program
	 */
	private int begin;
	private int end;
	 
	Scanner scanner = new Scanner(System.in); //To be able to use scanner
	String exit = "n"; //To end the program
	String user = ""; 

	
	public NestedLoopTable(){}; //default constructor
	/*
	 * Overload constructor to use the private information and store inside
	 */
	public NestedLoopTable(int begin, int end)
	{
		this.begin = begin;
		this.end = end;
	}
	/*
	 * These are needed to use the private information and
	 * store inside the private ints.
	 */
	public int getBegin()
	{
		return begin;
	}
	public void setBegin(int begin)
	{
		this.begin = begin;
	}
	public int getEnd()
	{
		return end;
	}
	public void setEnd(int end)
	{
		this.end = end;
	}
	
	public void quitScanner()
	{
		scanner.close();
	}

} //end of program
