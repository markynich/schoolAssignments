#include "lab2.h"

STATUS BuildListDirectly(NODE* &head, std::string city)
{
    NODE *tail=0, *newnode; // calls the pointers
    head = 0;
    newnode = new NODE; // allocates a new node
    while (head != NULL) //while loop to use link list
    {
        newnode->city = city; //copy list information to newnode
        
    }
        newnode->next = 0; //puts node of next pointer to null
        if (!tail) //if it is not tail then head is null
            head = newnode;
        else
            tail->next = newnode; //else connect tail with newnode
        tail = newnode; //tail equals to newnode
    return OK;
} //end of function

