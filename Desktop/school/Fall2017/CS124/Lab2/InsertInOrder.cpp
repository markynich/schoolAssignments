#include "lab2.h"
/**
    Code that inserts the information of the linked list,
    but in alphabetical order.
**/
STATUS InsertInOrder(NODE* &head, std::string city)
{

    NODE *newnode; //creating a new node called newnode
    
    newnode = new NODE; //allocating a new node
    if(!newnode)
        return FAILED; //debugger if it fails
        
    newnode->city=city; //to copy information into list
    
    NODE *node = head, *prev = 0;
    //While node and nodepointing to city is less than
    //or equal to city, prev equals node and node equals
    // node points to next
    while (node && node->city <=city)
    {
            prev = node;
            node = node->next;
    }
    
    newnode->next = node;
    if(prev)
    prev->next = newnode;
    else
        head = newnode;
        
    return OK;
        
}
