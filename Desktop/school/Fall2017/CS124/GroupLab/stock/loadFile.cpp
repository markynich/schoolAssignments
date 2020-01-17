#include "Stock.h"

void loadFile(std::string f, std::vector<double> &v) {
    std::ifstream ifs(f);
    double x;
    while(ifs >> x) {
        //std::cout << "From file: " << x << std::endl;
        v.push_back(x);
    }
    ifs.close();
}
        
