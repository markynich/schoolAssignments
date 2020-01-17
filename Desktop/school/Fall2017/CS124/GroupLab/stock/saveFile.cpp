#include "Stock.h"

void saveFile(std::string f, std::vector<double> &v) {
    std::ofstream ofs;
    ofs.open(f);
    for(int i = 0; i < v.size(); i++) {
        //std::cout << "Save File: " << v[i] << std::endl;
        ofs << v[i];
    }
    ofs.close();
}
