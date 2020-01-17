/***********************************************
Name: Mark-Nicholas Magsakay
Course: CS124-01
Lab: Lab 1
*************************************************/


/**
\param[in] ifstream to load the file 'dict.dat'
\param[out] dict.size() which prints out the size of the vector
\return a boolean that indicates if the file is opened successfully
**/

#include "lab.h" //includes everything from lab.h

using namespace std; //to make everything standard

//a function for main that loads the dictionary into the program
bool loadDictionary(string fileName, vector<ENTRY> &dict)
{   //integer needed for counting how many words are in dictionary
    int cnt = 0; 
    ENTRY e; //to access the vector ENTRY which contain word and translation
    ifstream inpFile(fileName.c_str());
    if (!inpFile) return false; //if file does not open, it will return false
    string title; //string to contain title
    getline(inpFile, title); //to get the title from the text file
    cout << title << endl; //to print the title of the program
    cout << "....................................." << endl;
    while (inpFile >> e.word >> e.translation) {
        dict.push_back(e);
        inpFile.ignore(80, '\n'); //skip the rest of the line
        cnt++;
    }//end of while for inpFile
    
    cout << " (" << cnt << " words)\n\n"; //prints out the number of words
    //prints out the number of vectors used
    cout << " (" << dict.size() << " size of vector)\n\n";
    
    return true;
} //end of bool loadDictionary
