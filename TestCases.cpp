#include <iostream>
#include "LinkedList.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{
    if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./hello <INPUT FILE> <OUTPUT FILE>"); // throw error
    }

    ifstream input; // stream for input file
    ofstream output; // stream for output file

    input.open(argv[1]); // open input file
    output.open(argv[2]); // open output file

    string command; // to store the next command and operation
    char *com, *dummy, *valstr, *op; // for using with strtok, strtol
    int val; // the value from the command

    LinkedList myList; // initializing the linked list
        

    while(getline(input,command)) // get next line of input, store as repeat
    {
        if (command.length() == 0) // command is empty
            continue;
        com = strdup(command.c_str()); // annoying, first copy string into a "C-style" string
        op = strtok(com, " \t"); //tokenize command on whitespace, first token is operation

        // We first check if command is to print, since we do not need further parsing of command
        if(strcmp(op,"p") == 0) // print list
        {
            output << myList.print() << endl; // write printed list to file, and add new line
            cout << "Printing" << endl;
            cout << myList.print()+"\n" << endl; // printing to console
            continue; // move on to next command
        }

        valstr = strtok(NULL, " \t"); // next token is value, as string (check out documentation on strtok, to understand the parsing)
        if(valstr != NULL) // first check if there is actually anything to convert into int
            val = strtol(valstr, &dummy, 10); // convert initial portion of valstr into an integer val, with base 10. Check out documentation on strtol for more details. 
    
        if(strcmp(op,"i") == 0) // insert into list
        {
            cout << "Insert "+to_string(val) << endl;
            myList.insert(val);
        }
        if(strcmp(op,"d") == 0) // delete from list
        {
            cout << "Delete "+to_string(val) << endl;
            myList.deleteNode(val);
        }
        if(strcmp(op,"del") == 0) // reverse list
        {
            cout << "Delete Last Instance "+to_string(val) << endl;
            myList.DeleteLast(val);
        }
        if(strcmp(op,"pal") == 0) // reverse list
        {
            cout << "List is Palindrome? "+to_string(myList.isPalindrome()) << endl;
        }
        if(strcmp(op,"rot") == 0) // reverse list
        {
            cout << "Rotate "+to_string(val) << endl;
            myList.Rotate(val);
        }
        if(strcmp(op,"hot") == 0) // head rotate
        {
            cout << "Rotating "+to_string(val)+" to Head" << endl;
            myList.HeadRotate(val);
        }
        if(strcmp(op,"ret") == 0) // reverse
        {
            cout << "Reversing "+to_string(val)+" to Tail" << endl;
            myList.ReverseTail(val);
        }
        if(strcmp(op,"dea") == 0) // reverse
        {
            cout << "Deleting Duplicates of "+to_string(val) << endl;
            myList.Dedup(val);
        }
        if(strcmp(op,"rev") == 0) // reverse
        {
            cout << "Reverse " << endl;
            //myList.Reverse();
        }
     }

     input.close();
     output.close();
}
