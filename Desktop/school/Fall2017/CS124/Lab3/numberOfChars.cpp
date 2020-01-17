#include "lab3.h"

int numberOfChars(std::ifstream &f)
{

    int n = 0;
    char c;
    while(f >> c)
        n++;
    //count characters
    return n;

}
