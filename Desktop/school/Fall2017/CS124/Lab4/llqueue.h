// LLQUEUE.h

#include <string>

/*
struct ORDER {
    std::string address;
    std::string items;
};
*/

struct ORDER
{
    std::string info;
    std::string addr;
    int size;
    void setInfo(std::string i) { info = i; }
    std::string getInfo() { return info; }
};

struct NODE {
    ORDER info;
    NODE *next;
};

class LLQUEUE {
    private:
        NODE *front;
        NODE *rear;
    public:
        LLQUEUE() {front = rear = 0;}
        ~LLQUEUE();
        bool Insert (ORDER &info);
        bool Remove (ORDER &info);
        bool isEmpty() {return (front == 0);}
};
