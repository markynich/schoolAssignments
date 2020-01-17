/***********************************************
Name: Mark-Nicholas Magsakay
Course: CS124-01
Lab: Lab 1
*************************************************/


/**
\param[in] input, which is used to get user input
\param[in] saveFile, which saves user's input such as word and translation
\param[out] saveFile, it will print out the word and translation into dictionary
**/

#include "lab.h" //includes everything from lab.h

using namespace std; //to make everything standard

bool saveDictionary(string fileName, vector<ENTRY> &dict)

{   
    string input; //to get user's input
    ENTRY e; //to access the vector ENTRY
    fstream saveFile; //object to access text file 'dict.dat'
    saveFile.open(fileName.c_str(), ios::app); //to open text file
    //to tell the user the word is not in the dictionary
    cout << e.word << " -- not in the dictionary.\n\n";
    cout << "Would you like to add translation? (y/n) ";
    cin >> input; //taking in user's input
    /*if loop that if the user wants to add their word and translation
      into the dictionary, they must type 'y', if not, anything else
      to continue the code.
    */
            if(input == "y")
                {   
                    ENTRY e;
                    cout << "Enter the word you want to put in the dictionary " << endl;
                    cin >> e.word; //take in user input for word
                    cout << "Enter the translation: " << endl;
                    cin >> e.translation; //take in user input for translation
                    dict.push_back(e); // enters user input to last element of vector
                    //saves user's input into the text file
                    saveFile << e.word << " " << e.translation << endl;

                }
}
