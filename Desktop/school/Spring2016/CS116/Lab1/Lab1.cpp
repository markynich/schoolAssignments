#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>  // used for time function

 
using namespace std;


/** Purpose:
Print out the programmer’s information such as name, class information
and date/time the program is run
@author Ron Sha
@version 1.0 1/27/2017
@param name -  the name of the programmer
@param courseInfo -  the name of the course
 @return - none
*/


void fahrenheitToCelsius(double fahrenheit)
{
	double celsius = ( fahrenheit - 32.0) * 5.0 / 9.0;
	cout << fahrenheit << "°F is equal to " << fixed << setprecision(1)
	<< celsius << "°C" << endl;
}

void celsiusToFahrenheit(double celsius)
{
	double fahrenheit = ( celsius * 9.0 / 5.0) + 32.0;
	cout << celsius << "°C is equal to " << fixed << setprecision(1)
	<< fahrenheit << "°F" << endl;
}

void secondstoHoursMinutesSecond(int seconds)
{
	int hour = seconds/3600;
	int minute = seconds%3600 / 60;
	int second = seconds%60;
			cout << seconds << " equals to " << hour << " hours and equals to "
			<< minute << " minutes and equals to " << second << " seconds" << endl;
}
void printMeFirst(string name, string courseInfo) //function to print out name
{

cout <<" Program written by: "<< name << endl; // Put your name here
cout <<" Course info: "<< courseInfo << endl;
time_t now = time(0); // current date/time based on current system
char* dt = ctime(&now); // convert now to string for
cout << " Date: " << dt << endl;

} // end bracket for PrintMeFirst


int main() //main function starts here
{

printMeFirst("Mark-Nicholas Magsakay", "CS116-02 Thursday - Lab 1"); //prints out my name and information

 int m; //input choice for unit conversion
                

while (true) { // while loop for continuous conversions until you quit

	cout << endl << "Unit Conversion Selection: " << endl;
	cout << " 1. Fahrenheit to Celsius " << endl;
	cout << " 2. Celsuis to Fahreheit" << endl; 
	cout << " 3. Seconds to Minutes, Hours, and Seconds " << endl;
	cout << " 4. - Quit" << endl;
	cin >> m;

		if (m > 4 || cin.fail())
		{
			cout << " Please enter a valid selection " << endl;
			cin.clear();
			cin.ignore(300, '\n');
		}
/**
Fahrenheit to Celsius conversion. It can calculate the conversion of Fahrenheit to Celcius.
Uses a set precision of 1.
*/
		else if (m == 1) // if statement for fahrenheit conversion
		{
			double fahrenheit;
			int input1;
			
			cout << " Please Enter a temperature: " << endl;
				
				while (true) 
				{
					cin >> input1;
						if (cin.fail())
							{
								cout << "Please enter a valid number " << endl;
								cin.clear();
								cin.ignore(300, '\n');
							}
							
						else
							{
							fahrenheitToCelsius(input1);
	 						break;
							} //end bracket for F conversion
				} // end bracket for while statement
		} // end bracket for m == 1
		
/**
Celsius to Fahrenheit conversion. It can calculate the temperature that has been inputed.
It also has a set precision of 1.
*/		
		else if (m == 2)
		{

			int input2;
			
			cout << "Please Enter a temperature: " << endl;
				while (true)
				{
					cin >> input2;
						if (cin.fail())
							{
								cout << "Please enter a valid number " << endl;
								cin.clear();
								cin.ignore(300, '\n');
							}
						else
							{
							celsiusToFahrenheit(input2);
							break;
							} //end for else
				} //end for while
		} //end for m == 2
		
		
/**
Seconds convertor to Hours, Minutes, and Seconds. 
Can only calculate postive numbers which is logical.
*/
		else if (m == 3)
		{
			int input3;
				
			cout << "Enter how many seconds you want converted" << endl;
				
			while (true)
			{
				cin >> input3;
					if (input3<0 || cin.fail())
						{
							cout << "Please enter a positive number " << endl;
							cin.clear();
							cin.ignore(300, '\n');
						}
					else
						{

						secondstoHoursMinutesSecond(input3);
							break;
						} //end else
			} // end while
				
		} // end if
		
/**
Ends the unit convertor code.
*/
		else if (m == 4)
		{
		cout << "Thanks for using this convertor" << endl;
		return 0;
		}
		}// end bracket for 1st while statement
	
		
} // end bracket for main

