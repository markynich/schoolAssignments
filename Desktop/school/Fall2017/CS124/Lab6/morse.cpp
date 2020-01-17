#include "morse.h"

Morsecode Telegraph::table[] = {
  {'A', ".-"},     {'B', "-..."},    {'C', "-.-."},   {'D', "-.."},
  {'E', "."},      {'F', "..-."},    {'G', "--."},    {'H', "...."},
  {'I', ".."},     {'J', ".---"},    {'K', "-.-"},    {'L', ".-.."},
  {'M', "--"},     {'N', "-."},      {'O', "---"},    {'P', ".--."},
  {'Q', "--.-"},   {'R', ".-."},     {'S', "..."},    {'T', "-"},
  {'U', "..-"},    {'V', "...-"},    {'W', ".--"},    {'X', "-..-"},
  {'Y', "-.--"},   {'Z', "--.."},
  {'0', "-----"},  {'1', ".----"},   {'2', "..---"},  {'3', "...--"},
  {'4', "....-"},  {'5', "....."},   {'6', "-...."},  {'7', "--..."},
  {'8', "---.."},  {'9', "----."},
  {'.', ".-.-.-"}, {',', "--..--"},  {'?', "..--.."},
  {'\0', ""}
};
TNODE* Telegraph::root = 0; // Initializes root to null
/**
\brief open creates the morse code table
*/
void Telegraph::open()
{
    char* dd;
    Telegraph::root = new TNODE;
    TNODE* node; TNODE* nextnode;
    for (int i = 0 ; i < N; i++)
    {
        node = root;
        for(dd = table[i].code; *dd ; dd++)
        {   // loops through each char of code
            if(*dd == '.')
            {
                nextnode = node->left;
                if(not nextnode)
                { 
                    nextnode = new TNODE;
                    node->left = nextnode;
                }
            }
            else if(*dd == '-')
            {
                nextnode = node->right;
                if(not nextnode)
                { 
                    nextnode = new TNODE;
                    node->right = nextnode;
                }
            }
            else std::cerr << "unknown morse code" << std::endl;
            node = nextnode;
        }   // not dash, not dot, therefore 
        // it must be null, so assign symbol
        node->symbol = table[i].symbol;
    }
}

void Telegraph::destroyTree(TNODE *root)
{
    if(root)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void Telegraph::close()
{
    destroyTree(root);
    root = 0;
}

void Telegraph::Encode(char text[], char morse[])
// Converts text into Morse code.
{
	 int i;
	 char c, *t, *dd; // t points to text;
	 // dd points to a string of dots and dashes.
	 for (t = text; *t; t++) {
		 c = toupper(*t);
		 // If space, add a space to the morse string:
		 if (c == ' ') {
			 *morse++ = ' ';
			 continue;
		 }
		 // Find this symbol in the MORSECODE table;
		 // skip this symbol if not found:
		 for (i = 0; table[i].symbol; i++)
		 	if (table[i].symbol == c) break;
		 if (!table[i].symbol) continue;
		 // Copy its code into the morse string:
		 dd = table[i].code;
		 while (*dd) *morse++ = *dd++;
		 // Add one space to separate letters:
		 *morse++ = ' ';
		 }
	 *morse = '\0';
}
void Telegraph::Decode(char morse[], char text[])
// Converts Morse code into text.
{
	 char *dd;
	 TNODE *node;
	 node = root;
	 //char *t;
	 // For each char in the encoded message (can be
	 // a dot, a dash, or a space):
	 for (dd = morse; *dd; dd++) {
	 	if(*dd == '.')
	 		node = node->left;
		else if(*dd == '-')
			node = node->right; 
		else {
			*text++ = node->symbol; 
            node = root;
        }
	 }
	 *text = '\0';
}


