#include "lab.h"
/*
g++ -I ~/fltk-1.3.3 *.cpp `fltk-config --cxxflags --ldflags --use-cairo` -o lab4
*/
Fl_Input* pizza; // definition 
Fl_Output* watch;
Fl_Text_Buffer* buff;
Fl_Text_Display* orderQ;
Fl_Text_Buffer* buffCook;
Fl_Text_Display* orderCookQ;
Fl_Text_Buffer* buffDriver;
Fl_Text_Display* orderDriverQ;
int main()
{
    /*
    Code third queue in main....
    */
    Fl_Cairo_Window cw(400,300); // width & height of window
    cw.label("Pizza Deliveries Extravaganja"); // title of your cairo window
    //cw.color(FL_GREEN);
    
    pizza = new Fl_Input(190, 20, 100, 20, "pizza:");
    pizza->labelcolor(FL_BLUE);
    
    buff = new Fl_Text_Buffer();
    orderQ = new Fl_Text_Display(50,100,100,100,"Order Q");
    orderQ->buffer(buff);
    
    buffCook = new Fl_Text_Buffer();
    orderCookQ = new Fl_Text_Display(150,100,100,100,"Cooked Q");
    orderCookQ->buffer(buffCook);
    
    buffDriver = new Fl_Text_Buffer();
    orderDriverQ = new Fl_Text_Display(250,100,100,100,"Driver Q");
    orderDriverQ->buffer(buffDriver);
    
    watch = new Fl_Output(70,20,50,20,"seconds:");
    
    Fl_Button b(330, 60, 50, 20, "Order:");
    b.callback((Fl_Callback*)order_cb);
    
    cw.show();
    Fl::add_timeout(1,timer);
    return Fl::run();
}
