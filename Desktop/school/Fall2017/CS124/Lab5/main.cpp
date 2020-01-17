#include "lab.hpp"
int main() 
{
    //std::string s = getenv("QUERY_STRING");
    //e.g. s may be "o = Bubble"
    //std::cout << s << std::endl;
    QUICKSORT<AQIData> qt;
    MERGESORT<AQIData> ms;
    std::string f = "/home/debian/data/aqi.csv";
    int n = countRows(f);
    AQIData* aqi = new AQIData[n];
    readData(f,aqi,n);
    /**for(int i = 0;i < n; i++)
    {
        //std::cout << "n = " << n << " ";
        std::cout << aqi[i].county << " ";
        std::cout << aqi[i].AQI << "\n";
    }**/
    std::string s = getenv("QUERY_STRING");
    //e.g. s may be "o = Bubble"
    if(s == "o=Bubble")
    {
            
            auto t1 = std::chrono::high_resolution_clock::now();
            BubbleSort(aqi,n);
            for (int i = 0; i < n; i++)
                std::cout << "<html>" << aqi[i].county << " " << aqi[i].AQI<< "<br></html>";
            auto t2 = std::chrono::high_resolution_clock::now();
            auto time_span = 
            std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
            std::cout << time_span.count() << "\n";
    }
    else if(s == "o=Selection")
    {
        
            auto t1 = std::chrono::high_resolution_clock::now();
            SelectionSort(aqi,n);
            for (int i = 0; i < n; i++)
                std::cout << "<html>" << aqi[i].county << " " << aqi[i].AQI<< "<br></html>";
            auto t2 = std::chrono::high_resolution_clock::now();
            auto time_span = 
            std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
            std::cout << time_span.count() << "\n";   
    }
    else if(s == "o=Insertion")
    {
            auto t1 = std::chrono::high_resolution_clock::now();
            InsertionSort(aqi,n);
            for (int i = 0; i < n; i++)
                std::cout << "<html>" << aqi[i].county << " " << aqi[i].AQI<< "<br></html>";
            auto t2 = std::chrono::high_resolution_clock::now();
            auto time_span = 
            std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
            std::cout << time_span.count() << "\n";   
    }
    else if(s == "o=QuickSort")
    {       
            auto t1 = std::chrono::high_resolution_clock::now();
            qt.Sort(aqi,n);
            for (int i = 0; i < n; i++)
                std::cout << "<html>" << aqi[i].county << " " << aqi[i].AQI<< "<br></html>";
            auto t2 = std::chrono::high_resolution_clock::now();
            auto time_span = 
            std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
            std::cout << time_span.count() << "\n"; 
    }
    else if(s == "o=Merge")
    {
            auto t1 = std::chrono::high_resolution_clock::now();
            ms.Sort(aqi,n);
            for (int i = 0; i < n; i++)
                std::cout << "<html>" << aqi[i].county << " " << aqi[i].AQI<< "<br></html>";
            auto t2 = std::chrono::high_resolution_clock::now();
            auto time_span = 
            std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
            std::cout << time_span.count() << "\n"; 
    }
} 

