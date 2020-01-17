#include "lab2.h"

/**
    main.cpp Displays the linked list in three different
    ways, one way is normal insertion, second is in
    alphabetical order, and third is directly. They all
    build, then get destroyed, and rebuild to make sure
    it is destroyed.
**/

int main(){
std::cout<< "Displaying List with Insert\n\n";
    NODE* head = loadList("cities");
    if(head)
    {   
        displayList(head);
        destroyList(head);
        head =0;
        displayList(head);
    }
std::cout<< "Displaying List with InsertInOrder\n\n";
    head = loadList2("cities");
    if(head)
    {   
        displayList(head);
        destroyList(head);
        head=0;
        displayList(head);
    }
std::cout<< "Displaying List with BuildDirectly\n\n";
    head = loadList3("cities");
    if(head)
    {  
        displayList(head);
        destroyList(head);
        head=0;
        displayList(head);
    }
    return 0;
}
