#include "lab2.h"

void destroyList(NODE* head)
{
    std::cout <<  std::endl; //to space out lists
    NODE* node; //creating node
    for(node = head; node; node = node->next) //loop to delete list
    {       
            std::cout << "Deleting: "
            << node->city << std::endl; // to tell user its deleted
            NODE* tmp = head->next; //assigns head pointer to tmp
            //delete head;
            head = tmp; //head becomes tmp which is deleted

    }
    
}
