#include "lab.h"

void readData(std::string f, AQIData aqi[], int n)
{

    std::ifstream ifs(f.c_str());
    std::string s; char comma;
    for(int i = 0; i < n; i++)
    {
        getline(ifs,s,',');//reads state
        getline(ifs,aqi[i].county,',');//reads county
        getline(ifs,s,',');//ignores county and reads year
        getline(ifs,s,',');
        getline(ifs,s,',');
        getline(ifs,aqi[i].AQI,',');//ignore year and readsDays
        
        //ifs >> aqi[i].AQI >> comma;
        getline(ifs,s);
    }
    //aqi[0].county = s;
    ifs.close();
    

}
