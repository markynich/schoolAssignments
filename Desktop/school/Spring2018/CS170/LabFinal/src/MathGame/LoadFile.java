
/*********************************************************************
Name: Denna, Mark, Patrick, Kerolles
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 5/9/18
Brief Description: This class contains the methods to read and write
into highscore.txt. Saves and loads the scores from the game. Also
sorts the scores to top five. Overrides toString to print the scores
into the GUI
**********************************************************************/


package MathGame;

import java.io.*;
import java.util.*;

public class LoadFile
{
	private Scanner read; //obj to read txt file
	private PrintWriter write; //obj to write in txt file
	private int count; //variable to count amount of entries 
	Lists list = new Lists(); //obj to use class List
	/*
	 * To be able to use the highscore.txt and make it readable for other classes
	 * aka GUI
	 */
	public LoadFile() 
	{
		openReadFile();
		readFile();
	};
	/*
	 * makes it able to read the file highscore.txt
	 */
	public void openReadFile()
	{
		try
		{
			read = new Scanner (new File("highscore.txt"));
		}
		catch (Exception e)
		{
			System.out.println("File is not readable");
		}
	}
	/*
	 * readFile reads the file and enters the names
	 * and highscores into the ArrayLists of name and score.
	 * also counts the amount of entries.
	 */
	public void readFile()
	{
		while(read.hasNext())
		{
			String name = read.next();
			list.names.add(name);
			String Sscore = read.next();
			int score = Integer.parseInt(Sscore);
			list.scores.add(score);
			count++;
		}
		read.close();
	}
	/*
	 * Gets count for Bubble sort. 
	 * count is the amount of scores
	 */
	public int getCount()
	{
		return count;
	}
	
	public void setCount (int c)
	{
		this.count = c;
	}
	/*
	 * Sorts the scores in order for top five highscores
	 */
	public void BubbleSort(int size)
	{
		boolean run = false;
		size = size-1;
		while(run == false)
		{
			run = true;
			for (int i=0; i<size; i++)
			{
				if (list.scores.get(i) < list.scores.get(i+1))
				{
					int intTemp = list.scores.get(i);
					list.scores.set(i,list.scores.get(i+1));
					list.scores.set(i+1, intTemp);
					String stringTemp = list.names.get(i);
					list.names.set(i,list.names.get(i+1));
					list.names.set(i+1, stringTemp);
					run = false;
				}
			}
		}
	}
	/*
	 * prints our the top five scores
	 */

	public String toString(int x)
	{
		String score = null;
		for(int i=0;i<5;i++)
		{
			String n = list.names.get(i);
			int s = list.scores.get(i);
			if (i==x)
			{
				score = ((i+1) +". " + n + " " + s);
			}
		}
		return score;
	}
	/*
	 * resets highscore.txt and opens to be able to write
	 * new score into it
	 */
	public void openWriteFile() 
	{
		try 
		{
			write = new PrintWriter("highscore.txt");
		}
		catch (Exception e)
		{
			System.out.println("Cannot Create file");
		}
	}
	/*
	 * Copy List into highscore.txt again
	 */
	public void copyList()
	{
		int size = getCount();
		for(int i=0;i<size;i++)
		{
			String name = list.names.get(i);
			String scores = Integer.toString(list.scores.get(i)); 
			String list = name + " " + scores;
			write.println(list);
		}
		write.close();
	}
	/*
	 * Adds user highscore into ArrayList
	 */
	public void addIntoList(String name, int score)
	{
		list.names.add(name);
		list.scores.add(score);
		count++;
	}

}