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
    initialize_map();
    readFile("input.txt");

    while(true)
    {
        if (i == instructions.size())
        {
            cout<<"gootpi";
            break;
        }
        Instructions inst = instructions[i];

        // inst_map[inst.op]

        if( inst_map.find(inst.op) ==inst_map.end() ) // didn't find the key
        {
            break;
        }

        (*inst_map[inst.op])(); //call the function


        // BNE, BNEQ, LUI, AUIPC, LB, LBU,SW
        //BLT, BGT, LW ? i think ~nour
        
        int pc = i*4; //program counter 
        print();

    };

    return 0;
}

