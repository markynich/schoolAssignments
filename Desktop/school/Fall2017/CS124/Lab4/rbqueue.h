//RBQueue.h
#include <string>
const int BUFSIZE = 256;

class RBQUEUE {
    private:
        std::string buf[BUFSIZE];
        int front;
        int rear;
        int nextIndex(int index) { 
            if(++index == BUFSIZE) index = 0; 
            return index;
        }
        std::string driverName;
    public:
        RBQUEUE() {front = rear = 0;}
        ~RBQUEUE() { }
        bool Insert (std::string s);
        bool Remove (std::string &s);
        bool isEmpty() {return (front == rear);}
        bool isFull() {return (nextIndex(rear) == front);}
        void setDriverName(std::string str) { driverName = str; }
        std::string getDriverName() {return driverName; }
        std::string getFirstDriver() {return buf[front];}
};
    
        
