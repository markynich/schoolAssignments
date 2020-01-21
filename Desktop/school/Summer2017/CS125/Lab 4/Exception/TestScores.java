/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 4
Submission Date: 10:00pm, Wednesday 7/19/17
Brief Description: The class for making storing the information and giving
the information that the driver class will be calling. It also contains
all the functions used for the driver class TestScoreApp.
**********************************************************************/


public class TestScores { //beginning of class TestScores

    private double score1; //the private locations of scores 1-3
    private double score2;
    private double score3;

    public TestScores()	{  //default constructor to call class
    
    }
    
    public TestScores(double score1, double score2, double score3){
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
    
    public void failTest1() throws InvalidTestScore {
    	if (score1 < 0 || score1 > 100)
    		throw new InvalidTestScore(score1);
    	else
    		score1 = getScore1();
    }
    
    public void failTest2() throws InvalidTestScore {
    	if (score2 < 0 || score2 > 100)
    		throw new InvalidTestScore(score2);
    	else
    		score2 = getScore2();
    }
    
    public void failTest3() throws InvalidTestScore {
    	if (score3 < 0 || score3 > 100)
    		throw new InvalidTestScore(score3);
    	else
    		score3 = getScore3();
    }
    public void gradeFunction(){
    	if (getAverageScore() >=90 && getAverageScore() <= 100)
	    	System.out.println("The average test score is: " + getAverageScore()
	    						+ "\n The Grade is A");
	    else if (getAverageScore() >=80 && getAverageScore() <= 89)
	    	System.out.println("The average test score is: " + getAverageScore()
	    						+ "\n The Grade is B");
	    else if (getAverageScore() >=70 && getAverageScore() <= 79)
	    	System.out.println("The average test score is: " + getAverageScore()
	    						+ "\n The Grade is C");
	    else if (getAverageScore() >=60 && getAverageScore() <= 69)
	    	System.out.println("The average test score is: " + getAverageScore()
	    						+ "\n The Grade is D");
	    else
	    	System.out.println("The average test score is: "+ getAverageScore());
	    
    }

} //end of program
