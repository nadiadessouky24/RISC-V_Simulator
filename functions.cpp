// #pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdint> // or #include <cinttypes>
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
        if (inst.op == "add" || inst.op == "sub" || inst.op == "and" || inst.op == "slt" || inst.op == "sltu" || inst.op == "slli" || inst.op == "srli" || inst.op == "srai" || inst.op == "sll" || inst.op == "xor" || inst.op == "srl"|| inst.op == "sra"|| inst.op == "or")  //R-type 
        {
            //R-type
            sscanf(line, "%s x%d, x%d, x%d", op, &inst.rd, &inst.rs, &inst.rt);
        } 
    
        else if (inst.op == "addi" || inst.op == "andi" || inst.op == "slti" || inst.op == "lb" || inst.op == "lbu" || inst.op == "blt" || inst.op == "bge" || inst.op == "bltu" || inst.op == "bgeu" || inst.op == "jalr"|| inst.op == "xori"|| inst.op == "ori"|| inst.op == "sltiu"|| inst.op == "lh"|| inst.op == "lw"|| inst.op == "lhu"|| inst.op == "jalr") //I-type 
        {
            //I-type
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rd, &inst.rs, &inst.imm);
        } 
        else if (inst.op == "beq"|| inst.op == "bne"|| inst.op == "blt"|| inst.op == "bge"|| inst.op == "bltu"|| inst.op == "bgeu") //B-type
        {
            //B-type
            sscanf(line, "%s x%d, x%d, %d", op, &inst.rs, &inst.rt, &inst.imm);
        } 
        // else if (inst.op == "j")
        // {
        //     sscanf(line, "%s %d", op, &inst.imm);
        // }

         else if (inst.op == "sw" || inst.op == "sb" || inst.op == "sh") //S-type //lw is not s-type i removed it ~nour
        {
            //S-type
            sscanf(line, "%s x%d, %d(x%d)", op, &inst.rt, &inst.imm, &inst.rs);
        } 

        // else if (inst.op == "jr") 
        // {
        //     sscanf(line, "%s x%d", op, &inst.rs);
        // } 
        else if (inst.op == "jal")//J-type
        {
            //J-type
            sscanf(line, "%s %d", op, &inst.imm);
        } 
        else if(inst.op == "lui"|| inst.op == "auipc") 
        {
            //U-type
            sscanf(line, "%s %d", op, &inst.rd, &inst.imm);
        }
        // else if (inst.op == "halt")
        //  {
        //     sscanf(line, "%s", inst.op);
        // }
        else
        {
            cout<<"error";
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
cout<<"Memory File: \n";
for (int i=0;i<32;i++)
{
    if (i<10)
        cout<<" x"<<i<<"  :"<<memory[i]<<endl;
    else
        cout<<" x"<<i<<" :"<<memory[i]<<endl;
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
    i++;
}

void sh() 
{
    memory[registers[instructions[i].rs]] =(memory[instructions[i].imm]& 0xFFFF0000) | registers[instructions[i].rt]; 
    i++;
}

void andfunc()
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
    i++;
}

// void sw() //there is an error here see it 
// {
//     int effectiveAddress = registers[instructions[i].rs] + (instructions[i].imm) % 4;

//     // Store the word from the source register to the calculated memory address
//     memory[effectiveAddress] = (memory[effectiveAddress] & 0xFFFFFFF0) | (registers[instructions[i].rt] & 0xF);

//     // Increment the instruction index
//     i++;
// }

void sw() //new sw 
{ //theres something wrong with the offset i dont understand 
    int baseAddress = registers[instructions[i].rs];
    int effectiveAddress = baseAddress + instructions[i].imm;

    // Store the value from the source register to memory
    memory[effectiveAddress] = registers[instructions[i].rt];

    i++;
}



void lw() 
{
    int effectiveAddress = registers[instructions[i].rs] + instructions[i].imm;

    registers[instructions[i].rt] = memory[effectiveAddress];
    i++;
}


void jal()
{
    
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
    registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }
}

void sltiu() 
{
    if(static_cast<uint32_t>(registers[instructions[i].rs]) < static_cast<uint32_t>(instructions[i].imm))
    {
        registers[instructions[i].rd] = 1;
    }
    else
    {
        registers[instructions[i].rd] = 0;
    }
}

void lbu() 
{
    registers[instructions[i].rt] = static_cast<uint32_t>(memory[registers[instructions[i].rs] + instructions[i].imm] & 0xFF);
}

void jal()
{
    registers[instructions[i].rd] = i;
    i = i + (instructions[i].imm/4);
    i++;
}

void jalr() 
{
    registers[instructions[i].rd] = i;
    i = instructions[i].imm + instructions[i].rs;

}

void blt()
{
    registers[instructions[i].rd] = i;
    if (registers[instructions[i].rd] < registers[instructions[i].rs])
    {
        i = i + (instructions[i].imm/4);
    }
    i++;
}

void bge()
{
    registers[instructions[i].rd] = i;
    if (registers[instructions[i].rd] > registers[instructions[i].rs])
    {
        i = i + (instructions[i].imm/4);
    }
    i++;
}

void bltu() 
{
    registers[instructions[i].rd] = i;
    if (static_cast<uint32_t>(registers[instructions[i].rd]) < static_cast<uint32_t>(registers[instructions[i].rs]))
    {
       i = i + (instructions[i].imm/4);
    }
    i++;
}

void bgeu()
{
    registers[instructions[i].rd] = i;
    if (static_cast<uint32_t>(registers[instructions[i].rd]) > static_cast<uint32_t>(registers[instructions[i].rs]))
    {
       i = i + (instructions[i].imm/4);
    }
     i++;
}

void lh() 
{
    int address = registers[instructions[i].rs] + instructions[i].imm;

    int loadedValue = (memory[address] << 16) >> 16;  // Sign-extend to 32 bits

    registers[instructions[i].rt] = loadedValue;
    i++;
}


// void executeLHU(const Instructions &inst) // Load halfword unsigned 
// {
//         int baseAddress = registers[inst.rs];
//         int offset = inst.imm;
//         int effectiveAddress = baseAddress + offset;

//         // Check if the effective address is aligned to a 32-bit boundary
//         if (effectiveAddress % 4 == 0) {
//             int loadedValue = memory[effectiveAddress / 4];
//             registers[inst.rd] = loadedValue & 0xFFFF;
//         } 
//         else 
//         {
//             exit(1); 
//         }
// }
// void lhu()
// {
//     executeLHU(instructions[i]);
//     i++; 
// }
// void executeLW(const Instructions &inst)
// {
//     int baseAddress = registers[inst.rs];
//     if (baseAddress % 4 == 0) 
//         {
//             // Load the 32-bit value from memory into the destination register
//             registers[inst.rd] = memory[baseAddress / 4];
//         } 
//         else 
//         {
//             exit(1);
//         }
// }


// void executeLW(const Instructions &inst) 
// {
//     int baseAddress = registers[inst.rs];
//     if (baseAddress % 4 == 0) 
//         {
//             // Load the 32-bit value from memory into the destination register
//             registers[inst.rd] = memory[baseAddress / 4];
//         } 
//         else 
//         {
//             exit(1);
//         }
// }




