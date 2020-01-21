
/*********************************************************************
Name: Mark, Denna, Patrick, Kerolles
Course: CS170-01
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 5/9/18
Brief Description: This class is the GUI class that uses all the methods
to make the game run smoothly. It stores the user's name and score
into the list and sorts the score to a Top Five List. List updates as
the user gets the answer wrong. User also games 100 points for every
answer correct.
**********************************************************************/

package MathGame;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Font;
import java.awt.*;

import javax.swing.*;

import java.awt.Color;

public class GUI extends Lists{

	private JFrame frame;
	private JButton submit;
	private JTextField wordQuestion, answer, txtScore,equation;
	private JTextField Score1, Score2, Score3, Score4, Score5;
	mathGame game = new mathGame();
	LoadFile lf = new LoadFile();
	/**
	 * Create the application.
	 */
	public GUI() {initialize();}
	/**
	 * Launches the application
	 */
	public void run()
	{
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI window = new GUI();
					window.randomNumber();
					window.topFiveScoreGUI();
					window.userAnswer();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	/*
	 * Randomizes the numbers
	 */
	public void randomNumber()
	{
	game.randomize();
	equation.setText(game.getA() + "+" + game.getB());
	}
	/*
	 * Prints out topFive for GUI
	 */
	public void topFiveScoreGUI()
	{
			lf.BubbleSort(lf.getCount());
			Score1.setText(lf.toString(0));
			Score2.setText(lf.toString(1));
			Score3.setText(lf.toString(2));
			Score4.setText(lf.toString(3));
			Score5.setText(lf.toString(4));
	}
	/*
	 * To get the user's answer when you click on the button
	 */
	public void userAnswer()
	{
		submit.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				String input = answer.getText();
				int number = Integer.parseInt(Validator.validNumber(input));
				compareAnswer(number);
				
			}
		});
	}
	/*
	 * compares the answer of the user
	 */
	public void compareAnswer(int num)
	{
		if (num == game.getSum())
		{
			JOptionPane.showMessageDialog(null, "Correct!");
			game.setHighScore(100);
			txtScore.setText("Score:            " + game.getHighScore());
			randomNumber();
			answer.setText("");
		}
		else
		{
			JOptionPane.showMessageDialog(null, "Wrong.");
			String nameInput = JOptionPane.showInputDialog("Please enter your first name");
			lf.addIntoList(Validator.validName(nameInput), game.getHighScore());
			lf.openWriteFile();
			lf.copyList();
			topFiveScoreGUI();
			game.resetHighScore(0);
			txtScore.setText("Score:            " + game.getHighScore());
			answer.setText("");
			randomNumber();
			
		}
	}
	
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(new Color(51, 153, 204));
		frame.setBackground(new Color(153, 153, 153));
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		/*
		 * Title
		 */
		JLabel title = new JLabel("Math Addition");
		title.setFont(new Font("Lucida Grande", Font.PLAIN, 20));
		title.setBounds(41, 15, 148, 40);
		frame.getContentPane().add(title);
		/*
		 * Introduction
		 */
		JTextArea Introduction = new JTextArea();
		Introduction.setEditable(false);
		Introduction.setBackground(new Color(51, 153, 204));
		Introduction.setText("Welcome to Math Addition!\nYou get 100 points for\nevery correct answer!");
		Introduction.setBounds(26, 54, 176, 58);
		frame.getContentPane().add(Introduction);
		/*
		 * Question
		 */
		wordQuestion = new JTextField();
		wordQuestion.setEditable(false);
		wordQuestion.setBackground(new Color(51, 153, 204));
		wordQuestion.setFont(new Font("Lucida Grande", Font.PLAIN, 17));
		wordQuestion.setText("What is the answer?");
		wordQuestion.setBounds(6, 156, 176, 33);
		frame.getContentPane().add(wordQuestion);
		wordQuestion.setColumns(10);
		/*
		 * Answer input
		 */
		answer = new JTextField();
		answer.setText("");
		answer.setFont(new Font("Lucida Grande", Font.PLAIN, 27));
		answer.setBounds(200, 195, 120, 50);
		frame.getContentPane().add(answer);
		answer.setColumns(10);

		/*
		 * submit button
		 */
		submit = new JButton("Submit");
		submit.setIcon(new ImageIcon("/Volumes/Apple HDD/Code/Java/LabFinal/images/pencil.png"));
		submit.setBounds(332, 195, 112, 50);
		frame.getContentPane().add(submit);
		/*
		 * Score listing
		 */
		txtScore = new JTextField();
		//Image img = new ImageIcon(this.getClass().getResource("/pencil.png")).getImage();
		//txtScore.setIcon(new ImageIcon(img));
		txtScore.setEditable(false);
		txtScore.setBackground(new Color(51, 153, 204));
		txtScore.setFont(new Font("Lucida Grande", Font.PLAIN, 18));
		txtScore.setText("Score:            0");
		txtScore.setBounds(194, 159, 176, 26);
		frame.getContentPane().add(txtScore);
		txtScore.setColumns(10);
		/*
		 * Equation
		 */
		equation = new JTextField();
		equation.setBackground(new Color(51, 153, 204));
		equation.setEditable(false);
		equation.setFont(new Font("Lucida Grande", Font.PLAIN, 27));
		equation.setBounds(6, 196, 191, 49);
		frame.getContentPane().add(equation);
		equation.setColumns(10);
		/*
		 * Top 5 list Title
		 */
		JLabel topFive = new JLabel("Top 5 Highscores");
		topFive.setBounds(226, 6, 144, 16);
		frame.getContentPane().add(topFive);
		
		Score1 = new JTextField();
		Score1.setBackground(new Color(51, 153, 204));
		Score1.setText("1.");
		Score1.setBounds(225, 25, 219, 26);
		frame.getContentPane().add(Score1);
		Score1.setColumns(10);
		
		Score2 = new JTextField();
		Score2.setText("2.");
		Score2.setBackground(new Color(51, 153, 204));
		Score2.setBounds(226, 49, 218, 26);
		frame.getContentPane().add(Score2);
		Score2.setColumns(10);
		
		Score3 = new JTextField();
		Score3.setText("3.");
		Score3.setBackground(new Color(51, 153, 204));
		Score3.setBounds(226, 74, 218, 26);
		frame.getContentPane().add(Score3);
		Score3.setColumns(10);
		
		Score4 = new JTextField();
		Score4.setText("4.");
		Score4.setBackground(new Color(51, 153, 204));
		Score4.setBounds(226, 98, 218, 26);
		frame.getContentPane().add(Score4);
		Score4.setColumns(10);
		
		Score5 = new JTextField();
		Score5.setText("5.");
		Score5.setBackground(new Color(51, 153, 204));
		Score5.setBounds(226, 121, 218, 26);
		frame.getContentPane().add(Score5);
		Score5.setColumns(10);
	}
}
