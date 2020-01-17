#include "lab.h"

void deliver(void*)
{
    //Fl::repeat_timeout(10, deliver);
    std::string driverName;
    if (!orderQueue.isEmpty() && !driverQueue.isEmpty()) {
        orderQueue.Remove(ord);
        driverQueue.Remove(driverName);
        std::string str = driverName + " Delivered: " + ord.getInfo() + " pizza";
        fl_alert(str.c_str());
        std::string s = "";
        s = s.substr(s.find_first_of(" \n")+1);
        buff->text(s.c_str());
        buffCook->text(s.c_str());
        buffDriver->text(s.c_str());
        //Fl::remove_timeout(deliver);
    }
    else {
        std::string str = "Order pending...";
        fl_alert(str.c_str());
    }
}
