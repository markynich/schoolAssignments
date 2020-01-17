#include "lab.h"
LLQUEUE cookQueue;
void cook_cb(void*)
{
    //buff->text(pizza->value());
    
    // temp solution, when it's cooked, put it
    // in the LLQueue; then here 
    // use your new function that displays
    // what is in Q to create a string (with newlines)
    // in it, return it here and siplay that in the buffer
    std::string str;
    str += ord.getInfo() += "\n";
    buffCook->text(str.c_str());
    Fl::add_timeout(10,driver_cb);
}
