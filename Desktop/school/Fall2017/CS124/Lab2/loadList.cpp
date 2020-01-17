#include "lab2.h"
/**
\image latex ../lab2fig1.eps "Linked List"
*/
/**
    loads the linked list into the program which lets the
    function DisplayList print it out for the user
**/
NODE* loadList(std::string filename)
{
    NODE* head = 0; //puts head to null
    std::ifstream inputFile(filename.c_str()); //taking input
    std::string city; //to use string city for list
    while (inputFile >> city) // loop to grab information
        if (Insert(head, city) == FAILED)
            std::cerr << "Error on Insert\n";
        //if statements that catches error if it cannot
        //get linked list information
    return head; //returns head
}
