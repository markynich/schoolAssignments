#include "morse.h"
//g++ -std=c++11 *.cpp -o ~/cgi-bin/morse

int main()
{
    Telegraph::open();
    Telegraph t;
    std::string str = getenv("QUERY_STRING");
    std::string strOG = str; std::string strInput = str;
    strOG.erase(1,30); // extract first char
    strInput.erase(0,2); // extract the string from the text field 
    if ( strOG == "d") { // Split string where the +'s are instead of converting to spaces
        for (int i = 0; i < strInput.size(); i++) // Convert all +'s to spaces
            if(strInput[i] == '+')
                strInput[i] = ' ';
        strInput += " ..";
        //std::cout << strInput << std::endl;
        char text[strInput.length() + 1];
        strcpy(text, strInput.c_str());
        char eMorse[600];
        t.Decode(text, eMorse);
        std::cout << "<html><h2>ABC:</h2><h3>" << eMorse << "</h3></html>" << std::endl;
    }
    else if ( strOG == "e") {
        char morse[strInput.length() + 1];
        strcpy(morse, strInput.c_str());
        char dText[600];
        t.Encode(morse, dText);
        std::cout << "<html><h2>Morsecode:</h2><h3>" << dText << "</h3></html>" << std::endl;
    }
    Telegraph::close();
}
