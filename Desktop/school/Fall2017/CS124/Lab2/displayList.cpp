#include "lab2.h"

void displayList(NODE* head)
{   
    std::cout << "\nList: " << std::endl; //tells user the list is built
    NODE* node;
    if(head)
    /** for Node equals head, and node equals node pointing
        to next, it will print out the city and will continue
        until it prints out all the list
    **/
        for(NODE* node = head; node; node = node->next)
        {    
            std::cout << node->city << std::endl;
        }
        else
            std::cout << "List is empty\n" << std::endl;
            // if there is nothing in the list, then it will
            //print out this statement

}
