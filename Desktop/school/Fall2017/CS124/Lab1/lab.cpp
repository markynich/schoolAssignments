/***********************************************
Name: Mark-Nicholas Magsakay
Course: CS124-01
Lab: Lab 1
*************************************************/


/**
\param[in] istream is a overloader for the input of ">>"
\param[out] ostream is a overloader for the output of "<<"
\return a boolean that indicates if the file is opened successfully
**/

#include "lab.h" //includes everything from lab.h

using namespace std; //to make everything standard
//overloads the function of <<
ostream & operator <<(ostream & o, ENTRY &e)
{
    o << e.word << "\t";
    o << e.translation << endl;
    return o;
}
//overloads the function of >>
istream & operator >>(istream & i, ENTRY &e)
{
    i >> e.word >> e.translation;
}

