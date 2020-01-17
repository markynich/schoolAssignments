#include "lab3.h"


void readSong(std::ifstream &f, MUSICELMT music[], int n)
{
    int i = 0; char type;
    while(f >> type)
    {
        //type = music[i].type;
        if (type == 'n')
            {
            f >> music[i].note.tone >> music[i].note.duration;
            music[i].type = PLAYNOTE;
            }
        else if (type == 'f')
            {
            f >> music[i].fragment.start >> music[i].fragment.finish;
            music[i].type = PLAYFRAGMENT;
            }
        i++;
    }
    music[i].type = PLAYSTOP;
}
