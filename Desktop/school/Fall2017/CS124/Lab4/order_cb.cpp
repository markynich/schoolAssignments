#include "lab.h"
LLQUEUE orderQueue;
ORDER ord; // one definition
void order_cb(void*, void*)
{
    ord.info = pizza->value();
    //std::cout << ord.info << std::endl;
    // cook it
    orderQueue.Insert(ord);
    std::string str = "Order: " + ord.getInfo() + " is being processed";
    //fl_alert(pizza->value());
    fl_alert(str.c_str());
    std::string s;
    s += ord.getInfo() += "\n"; 
    buff->text(s.c_str());
    Fl::add_timeout(10,cook_cb);
}
