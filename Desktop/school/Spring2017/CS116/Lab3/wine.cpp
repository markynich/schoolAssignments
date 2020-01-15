#include "wine.h"


Address::Address() // set city to empty string
{
	wineryName = "";
	street = "";
	city = "";
	state = "";
	zipCode = 0;
}
Address::Address(string winery_name, string winery_street, string winery_city, string winery_state, int winery_zipcode) // asigned varibles 
{
	wineryName = winery_name;
	street = winery_street;
	city = winery_city;
	state = winery_state;
	zipCode = winery_zipcode;
}
void Address::setInfo(string winery_name, string winery_street,string winery_city, string winery_state, int winery_zipcode ) // sets info 
{
	wineryName = winery_name;
	street = winery_street;
	city = winery_city;
	state = winery_state;
	zipCode = winery_zipcode;
}
void Address::setWineryName(string winery_name) // sets winert name 
{
	wineryName = winery_name;
}
void Address::setCity(string c) // set city name
{
	city = c;

}
string Address::getCity() // calles city
{
	return city;
} 
string Address::getWineryName() // calles winerny name
{
	return wineryName;
}
string Address::getState() // calles state 
{
	return state;
}
string Address::getStreet() //calles street
{
	return street;
}
int Address::getZip() //calles zipcode
{
	return zipCode;
}
Wine::Wine(string wine_name, string wine_type, int wine_year, // asigned varibles 
	int wine_rating, double wine_price)
{
	wineName = wine_name;
	wineType = wine_type;
	wineYear = wine_year;
	winePrice = wine_price;
	wineRating = wine_rating;
	paddress = new Address();
}
void Wine::setInfo(string wine_name, string wine_type, int wine_year, 
	int wine_rating, double wine_price) // sets info
{
	wineName = wine_name;
	wineType = wine_type;
	wineYear = wine_year;
	wineRating = wine_rating;
	winePrice = wine_price;
}

void Wine::setAddress(Address a) // points to address to set address
{
	//paddress->setInfo(a.getWineryName(), a.getStreet(), a.getCity(), a.getState(), a.getZip());
	*paddress = a;
}

int Wine::getRating() //get ratings 
{
	return wineRating;
}
double Wine::getPrice()  // gets price
{
	return winePrice;
}
string Wine::getWineName()  // gets wine name 
{
	return wineName;
}

string Wine::getWineType() // gets wine type 
{
	return wineType;
}
int Wine::getYear() // gets wine year
{
	return wineYear;
}


// Operator function.  Will discuss this in class
//
bool Wine::operator< (const Wine& p2) const
                                  { return this->wineYear < p2.wineYear; }
 
 
void printMoreInfo(Wine p)
{

cout << p.wineName << " " << p.wineType << " "<<p.wineRating << " " << p.winePrice 
<< " "<< p.wineYear <<
 " " << p.paddress -> getWineryName() << " " <<  p.paddress -> getCity() << endl;
// write a function to print out the following:
//  wineName, wineType, wineRating, winePrice, wineYear, wineryName, wineryCity
//
}