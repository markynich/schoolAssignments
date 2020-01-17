#include "lab.h"
RBQUEUE driverQueue;
void driver_cb(void*)
{
    std::string str;
    if(driverQueue.isFull()) {
        str = "Driver Queue is full";
        fl_alert(str.c_str());
    }
    else if(!driverQueue.isFull()) {
        driverQueue.setDriverName("Dave");
        driverQueue.Insert(driverQueue.getDriverName());
        str += driverQueue.getDriverName() += "\n";
        buffDriver->text(str.c_str());
        
    }
    Fl::add_timeout(10,deliver);
}
