#include "lab3.h"

void PlayNote(NOTE &note, float tempo)
{
    std::ifstream inputFile("music");
    int n = numberOfChars(inputFile);
    std::cout << "Music has " << n << " Characters\n";
    inputFile.close();
    MUSICELMT *music;
    music = new MUSICELMT[n];
    inputFile.open("music");
    readSong(inputFile, music, n);
    inputFile.close();
        for(int i=0; i< n; i++)
        {
            if(music[i].type == 'n')
            std::cout << music[i].note.tone << " "
            << music[i].note.duration << std::endl;
        else if(music[i].type == 'f')
            std::cout << music[i].fragment.start << " "
                << music[i].fragment.finish << std::endl;
        }
        std::string s1 = "play -qn synth ";
        std::string s2 = " pluck ";
        for (int i = 0; i < n; i++)
        {
        std::string ms = s1 + std:: to_string(music[i].note.duration/16.0)
                        + s2 + music[i].note.tone;
        std::cout << ms << std::endl;
        system(ms.c_str());
        
    }
}

