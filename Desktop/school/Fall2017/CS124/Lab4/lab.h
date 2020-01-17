#include "config.h"
#include <FL/Fl_Cairo_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <FL/Fl_Output.H>
#include <sstream>
#include <iomanip>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include "llqueue.h"
#include "rbqueue.h"

extern LLQUEUE orderQueue;
extern RBQUEUE driverQueue;
extern Fl_Input* pizza; // declaration of pizza pointer
extern Fl_Output* watch;
extern Fl_Text_Buffer* buff;
extern Fl_Text_Display* orderQ;
extern Fl_Text_Buffer* buffCook;
extern Fl_Text_Display* orderCookQ;
extern Fl_Text_Buffer* buffDriver;
extern Fl_Text_Display* orderDriverQ;

/** 
    \brief This is the callback function to order a pizza
    \param void pointers not used
    \return void
*/
void order_cb(void*, void*);

void cook_cb(void*);

void timer(void*);

void driver_cb(void*);

void deliver(void*);

extern ORDER ord;

