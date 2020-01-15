// reading a text file
#include <iostream>
#include <sstream>
#include <vector>
#include <string> 
#include <fstream>
#include <algorithm>  // used for vector sort
#include <iomanip>  // output format setw
#include "wine.h"
#include "printMeFirst.h"

using namespace std;

const char SPLIT_CHAR = ';';

bool comparePrice(Wine *a, Wine *b) //function to help compare prices between the wines
{
    return a->getPrice() > b->getPrice(); //returns the data back into the functions to print out
}

bool compareScore(Wine *a, Wine *b) //function to help compare prices betweeen the wines
{
    return a->getRating() > b->getRating(); //returns the data back into the functions for printint
}

string trim_words(const string & sentence) {
  stringstream ss;
  string s;
  string out;
    
  ss << sentence;
  while (ss >> s) 
  {
    out += (s + ' ');
  }
  return out.substr(0, out.length() - 1);
}


int main(int argc, char* argv[]) //start of the main function
{
  printMeFirst("Mark-Nicholas Magsakay", "CS-116 - 2017 Spring"); //to pring out my name/date/etc.
    string str1, str;
    vector < string > tokens;
	string wine_name /* fname */, wine_type /* lname */, winery_name /*gender*/, winery_address/*state*/,
			winery_city, winery_state;
	int wine_vitage /* month */ , wine_rating /* day */, wine_price /* year */, winery_zipcode;
	string fileName;
	
      vector<Wine *> fptr; //to connect the vector with the Wine class named as fptr

    Wine *f1; //to help use the Wine class more and make it dynamic

    Address addressCity; //to help access the Address class
	
  // use filename if provided in the parameter list

    if (argc < 2)
	{
    /* To test  what is in use for thet txt file that is read
      so that there will be an error test to be sure
    */
		cout <<"Usage: " << argv[0] << " input_file\n"; 
		cout <<"Using default file winelist.txt instead\n";
		fileName = "winelist.txt";

	}
	else 
		fileName = argv[1];
                               
  ifstream myfile (fileName.c_str()); // open the file
 

  if (myfile.is_open()) { //it is the keep the file open and to be able to access the txt file
    while (myfile) {
      if (!getline(myfile, str))
        break; //end of file

      istringstream split(str);
      //  for (string each; getline(split, each, split_char); tokens.push_back(each));
      // OR USE THE WHILE LOOP BELOW
      vector <string> tokens;
      while (split) // parse the line
      {
        string s;
        if (!getline(split, s, SPLIT_CHAR))
          break; // end of line
        else 
        {
          str1 = trim_words(s);
          tokens.push_back(str1);
        }
      }
      // now use `tokens`

      for (unsigned int i = 0; i < tokens.size(); i++)
      {
    /*
    A switch loop to print out the names and etc from the txt file
    */
		switch (i)
		{
			case 0: // field #1 from the line
				wine_name = tokens[0];    // To access and help print the Wine Name
				break;
			case 1: // field #2 from the line
				wine_type = tokens[1];    //To access and help print out the Wine Type
				break;			
			case 2: 
				wine_vitage = stoi(tokens[2]);  //To access and help print out the Wine Vitage
				break;	
			case 3: 
				wine_rating = stoi(tokens[3]); // Stoi helps access the int of Wine Rating
				break;					 // string month to int	month		
			case 4: 
				wine_price = stoi(tokens[4]); // To access the Wine Price
				break;				
			case 5: 
				winery_name = tokens[5]; // To access the Winery Name
				break;				
			case 6:
				winery_address = tokens[6]; // To access the Winery Address
				break;
			case 7:
				winery_city = tokens[7]; // To access the Winery City
				break;
			case 8:
				winery_state = tokens[8]; // To access the Winery State
				break;
			case 9: 
				winery_zipcode = stoi(tokens[i]); // To access the Winery Zipcode
				break;			
		}
      }


     f1 = new Wine(wine_name, wine_type, wine_vitage, wine_rating, wine_price); // an int to make the access of all the names in one term


     addressCity.setCity(winery_city);
     f1->setAddress(addressCity);


     fptr.push_back(f1);

    }
    myfile.close();
  } 
  else 
    cout << "Unable to open file" << endl;
    
  int  options, m=0, scoreOne, scoreTwo, priceOne, priceTwo;
/*
The start of the output function.
The very first part is a menu to help access everything.
The first selection is to see all the wines and everything else
is sorted within the selection. For instance, sorted by a range of price.
*/
while(true)
{

	cout << "Please Choose an option below: " << endl;
	cout << "0. Display all the wines available" << endl;
	cout << "1. Display all the wines that are in between in range of scores" << endl;
	cout << "2. Display all the wines that are within the range of prices" << endl;
	cout << "3. Display all the wines that are sorted by price" << endl;
	cout << "4. Display all the wins that are sorted by scores" << endl;
	cout << "5. Display all the red wines that are sorted by price" << endl;
	cout << "6. Display all the white wins that are sorted by year" << endl;
	cout << "7. End Program" << endl;
	
	cin >> options; // input to have all the menu selections
	
/*
    This is a fail safe to make sure people choose within the selection and try not to ruin the program.
    They cannot leave the program also until they choose the exiting selection
*/

	if (options > 7 || options < 0)
	{
		cout << "Please enter a valid option: " << endl; 
		cin.clear();
		cin.ignore(256, '\n');
	}
	else if (options == 0) //This is to open everything within the txt file
  {

    for (unsigned int i=0; i < fptr.size(); i++)
      {
        fptr[i]->printInfo();

      }
  }
	else if (options == 1) // This is a test for wines within a certain range
	{
	
		cout << endl << "Enter your first range: ";
			cin >> scoreOne;
		cout << endl << "Enter your second range: ";
			cin >> scoreTwo;
			
      /*
      This is a fail safe to make sure people will enter numbers that are appropiate for the menu and ranges, it will cancel on them
      and make them re-enter a new selection that is appropiate for it.
      */
			
			if (scoreOne < 0 || cin.fail() || scoreTwo < 0)
			{
				cout << "Error, invalid input " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			
			for (unsigned int i=0; i < fptr.size(); i++)
			{
				int scoreOverall = fptr[i]->getRating();
        if (scoreOne <= scoreOverall && scoreTwo >= scoreOverall)
        {

            cout << " " << endl;
            cout << scoreOverall << " " << fptr[i]-> getWineName() << endl;
            m++;
        } 

      }
      cout << m << " total wines within the range" << endl;
  }

 else if (options == 2) // This is a test for wines within a certain price
  {
    while (true)
    {
      /*
        This is a beginning input for comparing prices within
        a certain range for both red and white wines.
      */
      cout << endl << "Enter the first price: ";
      cin >> priceOne;
      cout << endl << "Enter the ending price: ";
      cin >> priceTwo;

    if (priceOne < 0 || cin.fail() || priceTwo < 0) // a fail safe to make sure people stay within the ranges.
        {
          cout << "Error, please input a valid price ";
          cin.clear();
          cin.ignore(256, '\n');
          continue;
        } 

    }

    for (unsigned int i= 0; i <fptr.size(); i++) //to access the switch statements
      {
        if(priceOne <=fptr[i]->getPrice() && priceTwo >=fptr[i]->getPrice()) // to access the classes and information
          {
              
             for (unsigned int i=0; i < fptr.size(); i++) //staying within the ranges
                {
                  fptr[i]->printInfo(); //printing out the information
                  m++; //making sure the count is perfect
                 }

          }

      }
      cout << m << " total wines within the prices" << endl;

  }
  
 else if (options == 3) //This is a switch that compares all wine files and puts them in order by price
 {

    sort(fptr.begin(), fptr.end(), comparePrice); // to help sort all the wins in order from least to most expensive

    for (Wine *l : fptr)
    {

      cout << l->getWineName() << " " << l->getPrice() << endl;

    }
 }

 else if (options == 5) // THis is a switch that compares all red wines and puts them in order by rating
 {

  sort(fptr.begin(), fptr.end()), compareScore;
  for (Wine *l : fptr)
  {
    string rwtype = l-> getWineType();
      if (rwtype == "Red") //To make sure it is only red wines and no white wines are within the selection
      {
        cout << l->getWineName() << " " << l->getRating() << endl;
      }
  }
 }
 else if (options == 6) //This is a switch that compares all the white wines and puts them in order by rating
 {
  sort(fptr.begin(), fptr.end(), compareScore);
    for (Wine *l : fptr)
    {
      string rwtype = l-> getWineType();
      if (rwtype == "White") // To make sure it is only white wines and no red wines are within the selection
      {
        cout << l->getWineName() << " " << l->getRating() << endl;
      }
 }
}
 else if (options == 7) //This is a switch that ends the program when needed
 {
  return 0;
 }
}
  return 0; // end of program
}

