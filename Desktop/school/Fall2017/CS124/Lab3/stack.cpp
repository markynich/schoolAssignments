#include "lab3.h"


/*
    Allocates a stack buffer of the specified size
    and initializes the stack.
*/

STATUS Create(STACK &stack, int size)
{
    stack.buf = new int[size];
    if (!stack.buf)
        return FAILED;
    stack.size = size;
    stack.sp = 0;
    return OK;
}
/*
  Returns OK if "item" is successfully pushed on stack,
  FAILED if the stack was full.  
*/
STATUS Push(STACK &stack, int item)
{

    if (stack.sp == stack.size)
        return FAILED;
    stack.buf[stack.sp] = item;
    stack.sp++;
    return OK;
}

STATUS Pop(STACK &stack, int &item)
{
    
    if (stack.sp == 0)
        return FAILED;
    stack.sp--;
    item = stack.buf[stack.sp];
    return OK;

}

void Destroy(STACK &stack)
{
    delete [] stack.buf;
}
