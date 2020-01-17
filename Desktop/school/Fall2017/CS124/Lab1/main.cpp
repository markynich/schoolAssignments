/***********************************************
Name: Mark-Nicholas Magsakay
Course: CS124-01
Lab: Lab 1
*************************************************/

/**
\param[in,out] word that are input to the file dictionary
\param[in,out] translation is an input/output for translating a word in dictionary
\param[out] q exits out the program
\return a boolean that indicates if the file is opened successfully
**/

#include "lab.h" //includes everything from lab.h

using namespace std; //to make everything standard

int main() {
    vector<ENTRY> dict; //vector object to be able to use ENTRY
    string word, translation; //strings needed for user input and output
    bool ok, quit; //loads dictionary file
    
    ok = loadDictionary("dict.dat", dict); //object that uses function loadDictionary
    //if loop that is an error catcher to tell user the dictionary cannot be loaded
    if (!ok){
        cout << "*** Cannot load dictionary ***\n";
        return 1;
    }//end of if
    quit = false;
    while (!quit) {
        cout << "Enter a word or 'q' to quit ==> ";
        cin >> word;            //Read one word
        cin.ignore(80, '\n');   //skip the rest of the line
        //if loop that ends the program if user enters 'q'
        if (word== "q")            
            quit = true;
        /*enters user input into foundWord which prints out the
         word's translation if it is in the dictionary*/
        else if (foundWord(dict, word, translation))
            cout << translation << "\n\n";
        /*allows the user to enter a word and it's translation
         in the dictionary if the word is not in the dictionary */
        else{
                saveDictionary("dict.dat",dict);

            } //end of else
    }//end of while
    return 0;
    
}// end main
