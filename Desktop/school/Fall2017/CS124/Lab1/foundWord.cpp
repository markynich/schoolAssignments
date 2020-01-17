/***********************************************
Name: Mark-Nicholas Magsakay
Course: CS124-01
Lab: Lab 1
*************************************************/


/**
\param[in] word and dict[i].word finds the user's word from the text file
\param[out] translation and dict[i].translation is printed out if word is found
\return a boolean that indicates if the file is opened successfully
**/

#include "lab.h" //includes everything from lab.h

using namespace std; //to make everything standard

bool foundWord(const vector<ENTRY> &dict, const string &word, string &translation)
{
    bool found = false; //if the word is not found, it will return false
    //integer for the for loop and len is for the length of the vector
    int i, len = dict.size();
    /*for loop which is needed to find the word in dictionary
     which in turn gives the translation of the word*/
    for (i = 0; !found && i < len; i++) {
        if (dict[i].word == word){
            translation = dict[i].translation;
            found = true;
        }//end of if
    } //end of for
    return found; //returns the translation to user for it to be output
} //end of bool
