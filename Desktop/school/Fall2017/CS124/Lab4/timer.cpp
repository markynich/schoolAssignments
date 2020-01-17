#include "lab.h"
void timer(void*)
{
    //std::cout << "1 sec" << std::endl;
    static int s= 0; static int m = 0;
    std::ostringstream oss; // don't discard the memory. 
                                              // keep it so we can update t to the window
    s++;    if(s == 59) {s = 0; m++; }
    oss << std::setfill('0');
    oss << std::setw(2) << m << ":" << std::setw(2) << s;
    //oss << s;
    watch->value(oss.str().c_str());
    
    // Here we could check if the Q's have pizza and drivers
    // ready for delivery every 10 seconds so we can see order
    // in Q     if (s % 10 == 0)
    static std::string str;
    std::string pizzas[] = {"veggie","pepperoni","sausage","hawaiian"};
    /*
    if(s % 10 == 0) // After 10 seconds. Add Order to Queue. 
    {
        str += pizzas[s%4] += "\n";
        buff->text(str.c_str());
    }
    if(s % 20 == 0) // After 20 seconds. Add Order to Cook Queue. 
    {
    }
    if(s % 30 == 0 ) // After 30 seconds. Add Cooked order to Driver Queue. 
    {
    }
    */
    Fl::repeat_timeout(1,timer);
}
