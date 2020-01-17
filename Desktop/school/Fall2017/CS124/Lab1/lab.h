/*
Name: Mark-Nicholas Magsakay
Course: CS124-01
Lab: Lab 1
*/

/**
\param[in] fileName the file of the dictionary
\param[out] dict a reference to a vector of Entries
\return a boolean that indicates if the file is opened successfully
**/
//includes needed to run the dictionary program
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
//default structure for two key strings: word, translation
struct ENTRY {
    string word;
    string translation;
}; //end of ENTRY
//defining all the functions needed for the program
bool loadDictionary(string fileName, vector<ENTRY> &dict);
bool saveDictionary(string fileName, vector<ENTRY> &dict);
ostream & operator<<(ostream &o, const ENTRY &e);
istream & operator>>(istream &i, const ENTRY &e);
bool foundWord(const vector<ENTRY> &dict, const string &word,
 string &stranslation);
 
