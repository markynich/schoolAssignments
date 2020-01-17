#include "lab2.h"
/**
\image latex ../lab2fig3.eps "Linked List"
*/
NODE* loadList3(std::string filename)
{
    NODE* head = 0;  //puts head to null
    std::ifstream inputFile(filename.c_str()); //taking input
    std::string city; //to use string city for list
    while (inputFile >> city) // loop to grab information
        if (BuildListDirectly(head, city) == FAILED)
            std::cerr << "Error on Insert\n";
            //if statements that catches error if it cannot
        //get linked list information
    return head; //returns head
}
