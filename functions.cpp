#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "instructionClass.h"
#include "global.h"
#include "functions.h"
using namespace std; 

vector<Instructions> instructions;


void readFile(string FileName)
{
    FILE *fp = fopen(FileName.c_str(), "r");
    char line[100];
    Instructions inst;
    char op[100];
    while (fgets(line, 100, fp) != NULL)
     {
        sscanf(line, "%s", op);
        inst.op = op;
        if (inst.op == "add" || inst.op == "sub" || inst.op == "and" || inst.op == "slt" || inst.op == "sltu") 
        {
            sscanf(line, "%s x%d, x%d, x%d", op, &inst.rd, &inst.rs, &inst.rt);
        } 
        else if (inst.op == "addi" || inst.op == "andi" || inst.op == "slti" || inst.op == "lb" || inst.op == "lbu")  //check format of lb and lbu
        {
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rd, &inst.rs, &inst.imm);
        } 
        else if (inst.op == "beq") 
        {
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rs, &inst.rt, &inst.imm);
        } 
        else if (inst.op == "j")
        {
            sscanf(line, "%s %d", op, &inst.imm);
        }

         else if (inst.op == "lw" || inst.op == "sw" || inst.op == "sb" || inst.op == "sh") 
        {
            sscanf(line, "%s x%d, %d(x%d)", op, &inst.rt, &inst.imm, &inst.rs);
        } 

        else if (inst.op == "jr") 
        {
            sscanf(line, "%s x%d", op, &inst.rs);
        } 
        else if (inst.op == "jal")
        {
            sscanf(line, "%s %d", op, &inst.imm);
        } 
        else if (inst.op == "halt")
         {
            sscanf(line, "%s", inst.op);
        }
        else if (inst.op == "nop")
        {
            sscanf(line, "%s", inst.op);
        }
        else {
            cout << "Error: Unknown instruction: " << inst.op << endl;
            exit(1);
        }
        instructions.push_back(inst);
    
    }
}


void print()
{
cout<<"Program Counter: "<<i*4<<endl;
cout<<"Register File: \n";
for (int i=0;i<32;i++)
{
    if (i<10)
        cout<<" x"<<i<<"  :"<<registers[i]<<endl;
    else
        cout<<" x"<<i<<" :"<<registers[i]<<endl;
}
cout<<"----------------------------------------\n";

}

void add ()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] + registers[instructions[i].rt];
    i++;
}

void addi()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] + instructions[i].imm;
    i++;
}

void sub()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] - registers[instructions[i].rt];
    i++;
}

void orfunc()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] | registers[instructions[i].rt];
    i++;
}

void ori()
{
        registers[instructions[i].rd] = registers[instructions[i].rs] | instructions[i].imm;
        i++;
}

void sll()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] * (2* registers[instructions[i].rt]);
    i++;
}

void slli()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] * (2* instructions[i].imm);
    i++;
}
void xorfunc()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] ^ registers[instructions[i].rt];
    i++;
}
void xori()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] ^ instructions[i].imm;
    i++;
}
void sra()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] >> registers[instructions[i].rt];
    i++;
}
void srai()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] >> instructions[i].imm;
    i++;
}

void srl()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] / (2* registers[instructions[i].rt]);
    i++;
}

void srli()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] / (2* instructions[i].rt);
    i++;

}

void sb()
 {
    memory[registers[instructions[i].rs]] =(memory[instructions[i].imm]& 0xFFFFFF00) | registers[instructions[i].rt]; 
}

void sh() 
{
    memory[registers[instructions[i].rs]] =(memory[instructions[i].imm]& 0xFFFF0000) | registers[instructions[i].rt]; 
}

void and()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] & registers[instructions[i].rt];
    i++;
}

void andi()
{
    registers[instructions[i].rd] = registers[instructions[i].rs] & instructions[i].rt;
    i++;
}

void lb()
{
    registers[instructions[i].rt] = (memory[registers[instructions[i].rs] + instructions[i].imm] & 0xFF);
}

void sw() 
{
    memory[registers[instructions[i].rs]] = (memory[instructions[i].imm] & 0xFFFFFFF0) | (registers[instructions[i].rt] & 0xF);
}

//double check
void slt() 
{
    if(registers[instructions[i].rs] < registers[instructions[i].rt])
    {
        registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }
}

void sltu()
 {
    
    if(static_cast<uint32_t>(registers[instructions[i].rs]) < static_cast<uint32_t>(registers[instructions[i].rt]))
    {
        registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }

}

void slti() 
{
        if(registers[instructions[i].rs] < instructions[i].imm)
        {
        registers[instructions[i].[rd]] = 1;
    }
    else
    {
        registers[instructions[i].[rd]] = 0;
    }
}

void sltiu() 
{
    if(static_cast<uint32_t>(registers[instructions[i].rs]) < static_cast<uint32_t>(instructions[i].imm))
    {
        registers[instructions[i].[rd]] = 1;
    }
    else
    {
        registers[instructions[i].[rd]] = 0;
    }
}

void lbu() 
{
    registers[instructions[i].rt] = static_cast<uint32_t>(memory[registers[instructions[i].rs] + instructions[i].imm] & 0xFF);
}



// void BGEU() {
//     if ( static_cast<uint32_t>(registers[instructions[i].rs1]) >= static_cast<uint32_t>(registers[instructions[i].rs2])){
//         pointer_address += imm;
//     }
// }


// void BLTU() 
// {
//     if (static_cast<uint32_t>(registers[instructions[i].rs1]) < static_cast<uint32_t>(registers[instructions[i].rs2]))
//     {
//         pointer_address += imm;
//     }
// }

// void executeJAL(Instructions& inst, int& pc, int* registers) 
// {   
//         registers[inst.rd] = pc; //saves return address (counter i) in rd
//         pc += inst.imm; //updates the program counter to target address
// }

// void jal()
// {
//     executeJAL(instructions[i], i, registers);
//     i++;
// }