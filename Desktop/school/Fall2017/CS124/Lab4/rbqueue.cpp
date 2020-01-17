// RBQUEUE.cpp

#include "rbqueue.h"

bool RBQUEUE::Insert (std::string s)
{
    if (isFull()) return false;
    buf[rear] = s;
    rear = nextIndex(rear);
    return true;
}

bool RBQUEUE::Remove  (std::string &s)
{
    if (isEmpty()) return false;
    s = buf[front];
    front = nextIndex(front);
    return true;
}

