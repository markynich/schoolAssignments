#include <iostream>
#include <cctype>
#include <string.h>

struct Morsecode 
{
    enum {N=7};
    char symbol;
    char code[N];
};

struct TNODE
{
    char symbol;
    TNODE* left;
    TNODE* right;
    TNODE() { // Constructor
        symbol = '*';
        left = 0;
        right = 0;
    }
};

class Telegraph
{
    enum {N=40};
    private:
        static Morsecode table[N];
        static TNODE* root;
        static void destroyTree(TNODE *node);
    public:
        static void open();
        static void close();
        void Encode(char text[], char morse[]);
        void Decode(char morse[], char text[]);
        static void destroyTree();        
};
