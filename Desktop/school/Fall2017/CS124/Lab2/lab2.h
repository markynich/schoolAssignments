#include <string>
#include <iostream>
#include <fstream>
/**
    \brief City Structure
    
    This is a structue used to create each node
    of the linked list of cities
    
**/

/**enumerate something, number it
statuses of new type(string, int, double)

**/
enum STATUS {FAILED, OK};
struct NODE {
    std::string city;
    NODE *next;
    NODE *prev;
};


/**
    \brief Insert puts a new node at the beginning of the list
    
    \param[in,out] head, Inserting the head of linked list, but also called the header //they the same
    @param[in] city, The data of the NODE is inserted
    \return A STATUS indicating if Insert was successful or not
*/

STATUS Insert(NODE* &head, std::string city);

/**
    \brief This function loads the data from a file
    
    The file contains a list of cities, each on a seperate line.
    \param filename Name of file
    \return a pointer 'head' to the link list
*/
NODE* loadList(std:: string filename);

/**
    \bried This function display th link list
    \param head is a pointer to beginning node of linklist
*/

void displayList(NODE* head);

/**
    \brief Destroys the list
    
    \param filename Name of the file
    \return a pointer 'head; to the link list
*/

void destroyList(NODE* head);

/**
    \brief This function loads the list in alphabetical order
    
    The file contains a list of cities, each on a seperate line.
    \param filename Name of file
    \return a pointer 'head' to the link list
*/
NODE* loadList2(std:: string filename);

/**
    \brief Insert the list in order
    
    \param[in,out] head, Inserting the head of linked list, but also called the header //they the same
    @param[in] city, The data of the NODE is inserted
    \return A STATUS indicating if Insert was successful or not
*/

STATUS InsertInOrder(NODE* &head, std::string city);

/**
    \brief This function builds the list directly
    
    The file contains a list of cities, each on a seperate line.
    \param filename Name of file
    \return a pointer 'head' and also a pointer 'tail' to the link list
*/
NODE* loadList3(std:: string filename);

/**
    \brief Insert the list directly
    
    \param[in,out] head, Inserting the head of linked list, but also called the header //they the same
    @param[in] city, The data of the NODE is inserted
    \return A STATUS indicating if BuildListDirectly was successful or not
*/
STATUS BuildListDirectly(NODE* &head, std::string city);

