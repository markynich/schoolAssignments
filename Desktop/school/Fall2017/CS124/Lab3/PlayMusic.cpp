#include "lab3.h"

void PlayMusic (MUSICELMT music[], float tempo)
{
    
    const int MAXSTACK = 400, MAXARRAY = 9999;
    STACK stack;
    PLAY type;
    
    if (Create(stack, MAXSTACK) == FAILED)
        {
            std::cerr << "*** MUSIC: Stack allocation error. ***\n" << std::endl;
            return;
        }
    
    int current = 0;
    int finish = MAXARRAY;
    
    
    while (OK) 
        {
    
            type = music[current].type;
            if (current <= finish && type != PLAYSTOP)
                {
                    if (type == PLAYNOTE)
                        PlayNote(music[current++].note, tempo);
                    else if (type == PLAYFRAGMENT)
                        {
                            Push(stack, current+1);
                            Push(stack, finish);
                            finish = music[current].fragment.finish;
                            current = music[current].fragment.start;
                        }
                }
            else if (!isEmpty(stack))
                {
                  Pop(stack, finish);
                  Pop(stack, current);  
                }
            else
                //nothing else to do
                break;
    
        }
    Destroy(stack);
}
