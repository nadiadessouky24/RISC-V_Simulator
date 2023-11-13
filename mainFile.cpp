#include <iostream>
#include <vector>
#include <map>
#include "functions.h"
#include "instructionClass.h"
#include "global.h"
using namespace std;



int main()
{
    readFile("input.txt");

    while(true)
    {
        if (i == instructions.size())
        {
            cout<<"gootpi";
            break;
        }
        
        // or(done), ori(done), SLL(done), SLLI(done), BNE, BNEQ, LUI, AUIPC, LB, LBU,SW
        int pc = i*4;
        if (instructions[i].op == "add")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] + registers[instructions[i].rt];
            i++;
        }
        
        else if (instructions[i].op == "addi")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] + instructions[i].imm;
            i++;
        }

        else if (instructions[i].op == "sub")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] - registers[instructions[i].rt];
            i++;
        }

        else if (instructions[i].op == "or")
        {
             registers[instructions[i].rd] = registers[instructions[i].rs] | registers[instructions[i].rt];
             i++;
        }

        else if (instructions[i].op == "ori")
        {
             registers[instructions[i].rd] = registers[instructions[i].rs] | instructions[i].imm;
             i++;
        }
       
        else if (instructions[i].op == "sll")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] * (2* registers[instructions[i].rt]);
            i++;
        }

        else if (instructions[i].op == "slli")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] * (2* instructions[i].imm);
            i++;
        }
        else if (instructions[i].op == "xor")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] ^ registers[instructions[i].rt];
            i++;
        }
        else if (instructions[i].op == "xori")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] ^ instructions[i].imm;
            i++;
        }
        else if (instructions[i].op == "sll")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] * (2 * registers[instructions[i].rt]);
            i++;
        }

        else if (instructions[i].op == "slli")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] * (2 * instructions[i].imm);
            i++;
        }
        else if (instructions[i].op == "sra")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] >> registers[instructions[i].rt];
            i++;
        }
        else if (instructions[i].op == "srai")
        {
            registers[instructions[i].rd] = registers[instructions[i].rs] >> instructions[i].imm;
            i++;
        }
        else if (instructions[i].op == "jal")
        {
            executeJAL(instructions[i], i, registers);
            i++;
        }

        print();

    };

    return 0;
}

