#include "llqueue.h"

bool LLQUEUE::Insert (ORDER &info)
{
    NODE *newnode = new NODE;
    if(!newnode) return false;
    newnode->info = info;
    newnode->next = 0;
    if (rear == 0) front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }
    return true;
}

bool LLQUEUE::Remove (ORDER &info)
{
    if(front == 0) return false;
    info = front->info;
    
    NODE *next = front->next;
    delete front;
    front = next;
    if (front == 0) rear = 0;
    return true;
}

LLQUEUE::~LLQUEUE ()
{
    NODE *next;
    while (front) {
        next = front->next;
        delete front;
        front = next;
    }
}
