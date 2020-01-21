/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 7/12/17
Brief Description:
**********************************************************************/
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class InheritanceApp {
	
	final static String dateFormat = "mm/dd/yyyy";
	//start of main program
	public static void main(String[] args) throws ParseException
	{
		Scanner userInput = new Scanner(System.in);

			System.out.println("Enter the employee name: ");
			String employName = userInput.nextLine();
			//prompt the user to enter the employee number
			System.out.println("Enter the employee number in the " +
			"format XXX-L (Each X is a digit " + "within the range 0-9 and the L "
			+ "is a letter within the range A-M: ");
			String employNumber = userInput.nextLine();
			//prompt the user to enter the employee hire date
			System.out.println("Enter the employee hire date in format mm/dd/yyyy: ");
			String date = userInput.nextLine();
			SimpleDateFormat date_obj = new SimpleDateFormat("mm/dd/yyyy");
			/*boolean b=isDateValid(date);
			if(b==true)
			{
				date=date;
			} //end of if loop
			else
				return;
			*/	
			//prompt the user to enter the employee shift
			System.out.println("Enter the employee shift (1 for day shift"
								+ " and 2 for night shift): ");
			int sh = Integer.parseInt(userInput.nextLine());
			//prompt the user to enter the employee hourly pay rate
			System.out.println("Enter the hourly pay rate: $");
			double rate = Double.parseDouble(userInput.nextLine());
			//create an object for ProductionWorker class
			ProductionWorker prodWorker = new ProductionWorker(employName, employNumber,
															date, sh, rate);
			//display the details of the employee
			System.out.println("\nDetails of the employee: ");
			System.out.println(prodWorker);


			System.out.println("End of Program");
			userInput.close();
		
		
	} //end of main program

	
} //end of InheritanceApp Program
