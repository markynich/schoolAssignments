#include "HEAP.H"
/**
    \brief This is a class Stock that creates minHeap and maxHeap which are able to be called throughout the program
*/
class Stock
{
    enum {MAXHEAPSIZE = 100};
public:
    Stock() : minH(MAXHEAPSIZE,HEAP<double>::MIN),
              maxH(MAXHEAPSIZE,HEAP<double>::MAX) {}
    HEAP<double> minH;
    HEAP<double> maxH;
    std::string name;
private:
    
};
/**
    \brief This is a function that loads a text file with information of the heap trees
    \param string to write in the file and a vector to reference the info that will be loaded from the file
    \return return information
*/
void loadFile(std::string f, std::vector<double> &v);
/**
    \brief This is a function that saves into a text file with the user's information
    \param string to write in the file and a vector to reference the info that will be saved into the file
 
*/
void saveFile(std::string f, std::vector<double> &v);
