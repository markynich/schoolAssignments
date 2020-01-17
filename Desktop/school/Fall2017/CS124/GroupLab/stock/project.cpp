#include "Stock.h"
int main()
{    
    Stock s;
    std::vector<double> v;
    std::vector<double> z;
    std::string test = getenv("QUERY_STRING");
    std::string delimiter = "&";
    std::string stockName = test.substr(0, test.find(delimiter)); // extract StockName
    test.erase(0, stockName.length()+1); // Remove Stock Info from string
    stockName.erase(0,6);
    std::string typeInput = test.substr(0, test.find(delimiter));
    test.erase(0, typeInput.length()+1);
    typeInput.erase(0,2);
    std::string nameInput = test.substr(0, test.find(delimiter));
    test.erase(0, nameInput.length()+1);
    nameInput.erase(0,2);
    std::string sharesInput = test.substr(0, test.find(delimiter));
    test.erase(0, sharesInput.length());
    sharesInput.erase(0,2);
    std::string priceInput = test;
    priceInput.erase(0,3);
    /*
    std::cout << priceInput << std::endl;
    std::cout << "*****************" << std::endl;
    std::cout << stockName << std::endl;
    std::cout << typeInput << std::endl;
    std::cout << nameInput << std::endl;
    std::cout << sharesInput << std::endl;
    std::cout << priceInput << std::endl;
    std::cout << "**************" << std::endl;
    */
    if (typeInput == "Buy") {
        double priceDouble = std::stod(priceInput);
        s.maxH.Insert(priceDouble);
        s.maxH.Insert(priceDouble);
        //s.maxH.printHeap();
        double shareDouble = std::stod(sharesInput);
        //std::cout << "priceDouble: " << priceDouble << std::endl;
        //std::cout << "shareDouble: " <<  shareDouble << std::endl;
        loadFile("/home/debian/cs124/stock/shares.json", z); 
        loadFile("/home/debian/cs124/stock/min.json", v);
        //std::cout << v[0] << std::endl;
        if (v.size() == 0 )
            std::cout << "<html><h1>No seller found. Request pending...</h1></html>" << std::endl;
        else if(v.size() != 0 ) {
            int i;
            for(i = 0; i < v.size(); i++) {
                if (priceDouble == v[i]) {
                    std::cout << "<html><h1>Match found!</h1></html>" << std::endl;
                    shareDouble = shareDouble;
                    std::cout << "<html><h2>Stock: Nvidia<h2></html>" << std::endl;
                    std::cout << "<html><h3>Name: Market</h3></html>" << std::endl;
                    std::cout << "<html><h4>Shares:" << shareDouble << "</h4></html>" << std::endl;
                    std::cout << "<html><h5>Type: Sell </h5></html>" << std::endl;
                    std::cout << "<html><h6>Prices:" << priceDouble << "</h6></html>" << std::endl;
                }
                if(i == v.size()-1 && priceDouble != v[i])
                    std::cout << "<html><h1>No seller found. Request pending...</h1></html" << std::endl;
                }
        }
        v.clear();
        v.push_back(priceDouble);
        z.clear();
        z.push_back(shareDouble);
        saveFile("/home/debian/cs124/stock/info.json", v);
        saveFile("/home/debian/cs124/stock/shares.json", z);  
    }
    else if (typeInput == "Sell") {
        double priceDouble = std::stod(priceInput);
        s.minH.Insert(priceDouble);
        s.minH.Insert(priceDouble);
        //s.minH.printHeap();
        double shareDouble = std::stod(sharesInput);
        //std::cout << "sharesInput: " << sharesInput << std::endl;
        //std::cout << "priceDouble: " << priceDouble << std::endl;
        loadFile("/home/debian/cs124/stock/shares.json", z);
        loadFile("/home/debian/cs124/stock/info.json", v);
        if (v.size() == 0 )
            std::cout << "<html><h1>No seller found. Request pending...</h1></html>" << std::endl;
        else if(v.size() != 0 ) {
            int i;
            for(i = 0; i < v.size(); i++) {
                if (priceDouble == v[i]) {
                    shareDouble = shareDouble;
                    if( shareDouble < 0) 
                        shareDouble = shareDouble * -1;
                    std::cout << "<html><h1>Match found!</h1></html>" << std::endl;
                    std::cout << "<html><h2>Stock: Nvidia<h2></html>" << std::endl;
                    std::cout << "<html><h3>Name: Market</h3></html>" << std::endl;
                    std::cout << "<html><h4>Shares:" << shareDouble << "</h4></html>" << std::endl;
                    std::cout << "<html><h5>Type: Buy </h5></html>" << std::endl;
                    std::cout << "<html><h6>Prices:" << priceDouble << "</h6></html>" << std::endl;
                }
                if(i == v.size()-1 && priceDouble != v[i])
                    std::cout << "<html><h1>No buyer found. Request pending...</h1></html>" << std::endl;
                }
        }
        v.clear();
        v.push_back(priceDouble);
        z.clear();
        z.push_back(shareDouble);
        saveFile("/home/debian/cs124/stock/min.json", v);
        saveFile("/home/debian/cs124/stock/shares.json", z);    
        }
}
