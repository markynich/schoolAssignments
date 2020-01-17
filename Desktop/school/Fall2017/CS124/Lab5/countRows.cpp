#include "lab.h"

int countRows(std::string f)
{   
    std::ifstream ifs(f.c_str());
    int n = 0;
    std::string s;
    while(getline(ifs,s)) n++;
    ifs.close();
    return n;
}
