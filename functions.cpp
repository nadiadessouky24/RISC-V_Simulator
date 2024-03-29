// #pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdint> // or #include <cinttypes>
#include "instructionClass.h"
#include "global.h"
#include "functions.h"
#include <cctype> // for tolower function
#include <bitset>


using namespace std; 

vector<Instructions> instructions;


void convertToLowerCase(char str[]) {
    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Convert each character to lowercase
        str[i] = std::tolower(str[i]);
    }
}


void readFile(string FileName)
{
    FILE *fp = fopen(FileName.c_str(), "r");
    char line[100];
    char op[100];
    while (fgets(line, 100, fp) != NULL)
     {
        Instructions inst;
        sscanf(line, "%s", op);
        convertToLowerCase(op);
        inst.op = op;
        if (inst.op == "add" || inst.op == "sub" || inst.op == "and" || inst.op == "slt" || inst.op == "sltu" || inst.op == "slli" || inst.op == "srli" || inst.op == "srai" || inst.op == "sll" || inst.op == "xor" || inst.op == "srl"|| inst.op == "sra"|| inst.op == "or" || inst.op == "xor")  //R-type 
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
         else if (inst.op == "sw" || inst.op == "sb" || inst.op == "sh") //S-type 
        {
            //S-type
            sscanf(line, "%s x%d, %d(x%d)", op, &inst.rt, &inst.imm, &inst.rs);
        } 
        else if (inst.op == "jal")//J-type
        {
            //J-type
            sscanf(line, "%s x%d, %d", op, &inst.rd,&inst.imm);
        } 
        else if(inst.op == "lui"|| inst.op == "auipc") 
        {
            //U-type
            sscanf(line, "%s %d", op, &inst.rd, &inst.imm);
        }
        else if(inst.op == "ecall"|| inst.op == "ebreak"|| inst.op == "fence") 
        {
            sscanf(line, "%s", op);
        }
        else
        {
            cout<<"error:unknown instruction";
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
    {
        cout<<" x"<<i<<"(in decimal)"<<"  :"<<registers[i]<<"    ";
        cout<<"  x"<<i<<"(in hexadecimal)"<<hex<<uppercase<<(registers[i])<<"    ";
        cout<<"  x"<<i<<"(in binary)"<<bitset<sizeof(int) * 8>(registers[i])<<endl;
        cout << dec;
    }
    else if (i>=10)
    {
        cout<<" x"<<i<<"(in decimal)"<<" :"<<registers[i]<<"     ";
        cout<<"  x"<<i<<"(in hexadecimal)"<<hex<<uppercase<<(registers[i])<<"   ";
        cout<<"  x"<<i<<"(in binary)"<<bitset<sizeof(int) * 8>(registers[i])<<endl;
        cout << dec;
    }
}
cout<<"----------------------------------------\n";
cout<<"Memory File: \n";
    for (auto& it:memory)
    {
    cout<<it.first <<":"<<it.second<<endl;
    cout<<it.first <<":"<<hex<<uppercase<<it.second<<endl;
    cout << dec;
    cout<<bitset<sizeof(int) * 8>(it.first) <<":"<<it.second<<endl;
    }
cout<<"----------------------------------------\n";

}

void add ()
{
    if (instructions[i].rd == 0)
    {
       registers[instructions[i].rd] = 0;
    }
    else 
    {
        registers[instructions[i].rd] = registers[instructions[i].rs] + registers[instructions[i].rt];
    }
    i++;
    
}

void addi()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;
    }
    else
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] + instructions[i].imm;
    }
    i++;
}

void sub()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] - registers[instructions[i].rt];
    }
    i++;
}

void orfunc()
{
   if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] | registers[instructions[i].rt];
    }
    i++;
}

void ori()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] | instructions[i].imm;
    }
    i++;
}

void sll()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] * (2* registers[instructions[i].rt]);
    }
    i++;
}

void slli()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] * (2* instructions[i].imm);
    }
    i++;
}
void xorfunc()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] ^ registers[instructions[i].rt];
    
    }
    i++;
}
void xori()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] ^ instructions[i].imm;
    }
    i++;

}
void sra()
{
  if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] >> registers[instructions[i].rt];
    }
    i++;
}
void srai()
{
  if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] >> instructions[i].imm;
    }
    i++;
}

void srl()
{
  if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] / (2* registers[instructions[i].rt]);
    }
    i++;
}

void srli()
{
  if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] / (2* instructions[i].rt);
    }
    i++;
}

void andfunc()
{
  if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
    registers[instructions[i].rd] = registers[instructions[i].rs] & registers[instructions[i].rt];
    }
    i++;
}

void andi()
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
    {
       registers[instructions[i].rd] = (signed int)registers[instructions[i].rs] & (signed int)instructions[i].imm;
    }
    i++;
}


////////////////// SHIFTS/////////////////

void slt() 
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
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
    i++;
}

void sltu()
 {
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
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
    i++;
}

void slti() 
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
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
    i++;
}

void sltiu() 
{
    if (instructions[i].rd == 0)
    {
        registers[instructions[i].rd] = 0;

    }
    else 
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
    i++;
}



///////////////// Jumps /////////////////////////////////////
void jal()
{
    registers[instructions[i].rd] = (i+1)*4;
    i = i + ((instructions[i].imm*2)/4);
}

void jalr() 
{
    registers[instructions[i].rd] = (i+1)*4; 
    i = ((instructions[i].imm*2)/4) + instructions[i].rs;
}


///////////////////////////////// BRANCHES/////////////////////////////////////
void blt()
{
    if (registers[instructions[i].rd] < registers[instructions[i].rs])
    {
        i = i + ((instructions[i].imm*2)/4);
    }
    i++;
}

void bge()
{
    if (registers[instructions[i].rd] >= registers[instructions[i].rs])
    {
        i = i + ((instructions[i].imm*2)/4);
    }
    i++;
}

void bltu() 
{
    if (static_cast<uint32_t>(registers[instructions[i].rd]) < static_cast<uint32_t>(registers[instructions[i].rs]))
    {
        i = i + ((instructions[i].imm*2)/4);
    }
    i++;
}

void bgeu()
{
    if (static_cast<uint32_t>(registers[instructions[i].rd]) > static_cast<uint32_t>(registers[instructions[i].rs]))
    {
        i = i + ((instructions[i].imm*2)/4);
    }
     i++;
}


void beq()
{
    if (registers[instructions[i].rd] == registers[instructions[i].rs])
    {
        i = i + ((instructions[i].imm*2)/4);
    }
    i++;
}

void bne()
{
    if (registers[instructions[i].rd] != registers[instructions[i].rs])
    {
        i = i + ((instructions[i].imm*2)/4);
    }
    i++;
}

//////////////////// LOAD AND STORE /////////////////////////

void lh() 
{
    int address = registers[instructions[i].rs] + instructions[i].imm;

    int loadedValue = (memory[address] << 16) >> 16;  // Sign-extend to 32 bits

    registers[instructions[i].rt] = loadedValue;
    i++;
}

void lhu() 
{
    int address = registers[instructions[i].rs] + instructions[i].imm;
    unsigned short loadedValue = memory[address] | (memory[address + 1] << 8);
    registers[instructions[i].rt] = loadedValue;
    i++;
}

void lb()
{
    registers[instructions[i].rt] = (memory[registers[instructions[i].rs] + instructions[i].imm] & 0xFF);
    i++;
}

void lbu() 
{
    registers[instructions[i].rt] = static_cast<uint32_t>(memory[registers[instructions[i].rs] + instructions[i].imm] & 0xFF);
}


void sw() 
{ 
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


void sb()
 {
    memory[registers[instructions[i].rs]] =(memory[instructions[i].imm]& 0xFFFFFF00) | registers[instructions[i].rt]; 
    i++;
}

void sh() 
{
    memory[registers[instructions[i].rs]] = (memory[instructions[i].imm]& 0xFFFF0000) | registers[instructions[i].rt]; 
    i++;
}


//////////////////////////////// LUI and AUPIC //////////////////////////////////

void lui() //load upper immediate
{
    registers[instructions[i].rd] = instructions[i].imm << 12;
    i++;
}

void auipc() //add upper immediate to program counter
{
    registers[instructions[i].rd] = i*4 + (instructions[i].imm << 12);
    i++;
}

void finishtheporgram()
{
    i = instructions.size();
}


