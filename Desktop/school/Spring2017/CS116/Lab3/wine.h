#ifndef WINE_H
#define WINE_H 

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // used for vector sort
#include <iomanip>  // output format setw
 
using namespace std;
class Address
{
                public:
                                Address(); // set city to empty string
                                Address(string winery_name, string winery_street,
                                        string winery_city, string winery_state, int winery_zip) ; //set info
                                void setInfo(string winery_name, string winery_street,
                                        string winery_city, string winery_state,  int winery_zip) ;     
                                void setWineryName (string winery_name); // sets name 
                                 void setCity (string c); // set city to c
                                string getCity(); // return the value of city
                                string getWineryName(); // retunr value of WineryName
                                string getStreet(); // return vaule of street
                                string getState(); // rteturn sate
                                int getZip();
                                // you may implement any other member functions
                private:
                                string wineryName, street, city, state;
                                int zipCode;
                               
};
 
class Wine
{
                public:
                                Wine() {  paddress=new Address();  }
                                Wine(string wine_name,string wine_type, int wine_year,
                                     int wine_rating, double wine_price);
                                void setInfo(string wine_name,string wine_type, int wine_year,
                                     int wine_rating, double wine_price);
 
                                ~Wine() { if (paddress != NULL)
                                                {delete paddress; paddress = NULL;}  }
                                void setAddress(Address a) ; // copy a to the value of pointer paddress  
                                int getRating(); 
                                double getPrice();
                                string getWineName();
                                string getWineType();
                                int getYear(); // return the value of year
                                void printInfo();
                                friend void printMoreInfo(Wine p);
                               
                                // you may implmenet any other member functions
                               
                                // define operator overload for <
                                // so now you can compare the class object for
                                // less than <
                                // And also can be used in vector sort as well
                                //
                                bool operator< (const Wine& p2) const;
                               
                private:
                                string wineName, wineType;
                                int wineYear, wineRating;
                                double winePrice;
                                Address *paddress;
                               
};
 #endif

 
 
