#include "functions.h"
#include "instructionClass.h"
#include "global.h"
#include "memory.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main()
{
       
    cout<<"enter starting address: ";
    cin>>i;
    initialize_map();
    readFile("input.txt");

    while(true)
    {
        if (i == instructions.size())
        {
            cout<<"End of all instructions";
            break;
        }

        Instructions inst = instructions[i];

        if( inst_map.find(inst.op) == inst_map.end() ) // didn't find the key --> unsupported instruction
        {
            cout <<"Found unsupported instruction. Exiting...";
            break;
        }

        (*inst_map[inst.op])(); //call the function

        int pc = i*4; //program counter 
        print();
    };
    return 0;
}

