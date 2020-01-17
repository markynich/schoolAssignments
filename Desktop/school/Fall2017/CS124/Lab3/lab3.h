#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>


struct STACK {
    int size;
    int *buf;
    int sp;
};
enum PLAY {PLAYNOTE,PLAYFRAGMENT, PLAYSTOP};
enum STATUS {FAILED, OK};

STATUS Create(STACK &stack, int size);
STATUS Push(STACK &stack, int item);
STATUS Pop(STACK &stack, int &item);
void Destroy(STACK &stack);

inline bool isEmpty(STACK &stack) {
        return bool(stack.sp ==0);
}

inline bool isFull(STACK &stack) {
        return bool(stack.sp ==stack.size);
}

inline int NoElements(STACK &stack) {
        return stack.sp;
}

struct NOTE
{
        char tone;
        int duration;
};
struct FRAGMENT
{
    int start;
    int finish;
};

struct MUSICELMT {
    PLAY type;
    union {
        NOTE note;
        FRAGMENT fragment;
    };
}; 

//function prototypes
void readSong(std::ifstream &f, MUSICELMT music[], int n);
void PlayMusic(MUSICELMT music[], float tempo);
void PlayNote(NOTE &note, float tempo);
int numberOfChars(std::ifstream &f);
