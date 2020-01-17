#include "lab3.h"

int main()
{   
    const float tempo = 1.2;
    std::ifstream inputFile("music");
    int n = numberOfChars(inputFile);
    std::cout << "Music has " << n << " Characters\n";
    inputFile.close();
    MUSICELMT *music;
    music = new MUSICELMT[n];
    inputFile.open("music");
    readSong(inputFile, music, n);
    PlayMusic(music, tempo);
    inputFile.close();

}
