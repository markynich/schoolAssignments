#include "lab2.h"
/**
    \brief Insert puts a new node at the beginning of the list
    
    \param[in,out] head, Inserting the head of linked list, but also called the header //they the same
    @param[in] city, The data of the NODE is inserted
    \return A STATUS indicating if Insert was successful or not
*/

/**
    A function to insert the linked list into the program
    which is then printed out for the user
**/
STATUS Insert(NODE* &head, std::string city)
{
    NODE* newnode = new NODE; //allocating new node
    newnode->city = city; //copying information into node
    newnode->next = head; //pointing to head
    head = newnode; //node equals head
    return OK;
}
